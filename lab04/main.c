#include <mpi.h>
#include <stdlib.h>
#include <stdio.h>

#define ROOT 0
#define RESULT 1
#define BATCH_SIZE 1000000

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);
    int size, rank;

    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == ROOT) {
        long long int circle = 0;
        long long int square = 0;
        int result;
        long double pi;
        for (int child = 1; child < size; ++child) {
            MPI_Recv(&result, 1, MPI_INT, child, RESULT, MPI_COMM_WORLD, &status);
            circle += result;
            square += BATCH_SIZE;
            pi = 4.0 * circle / square;
            printf("%d: %Lf\n", child, pi);
        }
    } else {
        srand(rank);
        int circle = 0;
        double x;
        double y;
        for (int j = BATCH_SIZE; j > 0; --j) {
            x = (double) rand() / RAND_MAX;
            y = (double) rand() / RAND_MAX;
            circle += (x * x + y * y) <= 1;
        }
        MPI_Send(&circle, 1, MPI_INT, ROOT, RESULT, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}