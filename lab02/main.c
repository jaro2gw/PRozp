#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>

#define ROOT 0
#define SORT 1
#define END 2
#define TABSIZE 100

void swap(int *x, int *y) {
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int size, rank;

    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc < 2) {
        MPI_Finalize();
        printf("Za malo argumentow\n");
        exit(0);
    }

    int num;
    if (rank == ROOT) {
        /* Root nie uczestniczy bezpośrednio w sortowaniu */
        printf("Otwieram plik\n");
        FILE *file;
        file = fopen(argv[1], "r");

        /* Wczytuje i przekazuje pierwszemu wątkowi w łańcuchu liczby z pliku */
        printf("Wczytałem: ");
        for (int index = 0; index < TABSIZE; ++index) {
            fscanf(file, "%d", &num);
            printf("%d ", num);
            MPI_Send(&num, 1, MPI_INT, 1, SORT, MPI_COMM_WORLD);
        }
        printf("\n");

        /* Daje znać, że więcej liczb nie będzie */
        MPI_Send(&num, 1, MPI_INT, 1, END, MPI_COMM_WORLD);

        /* Wypisuje informacje zwrotne od wątków */
        printf("Dostałem: ");
        for (int index = 1; index <= TABSIZE; ++index) {
            MPI_Recv(&num, 1, MPI_INT, index, SORT, MPI_COMM_WORLD, &status);
            printf("%d ", num);
        }
        printf("\n");
    } else {
        int min = 0x7FFFFFFF;
        int prev = rank - 1;
        int next = rank + 1;
        while (1) {
            /* Czeka na komunikaty od poprzednika */
            MPI_Recv(&num, 1, MPI_INT, prev, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

            if (status.MPI_TAG == END) {
                /* Daj znać następnikowi, że on też ma już skończyć */
                if (rank < TABSIZE) MPI_Send(&num, 1, MPI_INT, next, END, MPI_COMM_WORLD);

                /* Zwróć wartość do roota */
                MPI_Send(&min, 1, MPI_INT, ROOT, SORT, MPI_COMM_WORLD);

                break;
            } else {
                /* Podmienia wartości */
                if (num < min) swap(&num, &min);

                /* Przekaż wartość następnikowi */
                if (rank < TABSIZE) MPI_Send(&num, 1, MPI_INT, next, SORT, MPI_COMM_WORLD);
            }
        }
    }

    MPI_Finalize();
}
