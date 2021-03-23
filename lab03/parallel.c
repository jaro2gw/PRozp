#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>
#include <mpi.h>

/* 4 literowe
aa5UYq6trT5u.
bahAZ9Hk7SCf6
ddoo3WocSpthU
jkmD2RlhoMyuA
zzm4NUIIb7VIk
kkv864igyJC9o

5 literowe
aaSPfLTmjh3fU

6 literowe
aaLTdQr7DyHuU
*/


int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);
    int size, rank;

    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    char *password = "aaLTdQr7DyHuU";

    char cmp[7] = {0};
    char salt[3] = {0};
    salt[0] = password[0];
    salt[1] = password[1];

    for (int c1 = 'a' + rank; c1 <= 'z'; c1 += size) {
        cmp[0] = c1;
        for (int c2 = 'a'; c2 <= 'z'; ++c2) {
            cmp[1] = c2;
            for (int c3 = 'a'; c3 <= 'z'; ++c3) {
                cmp[2] = c3;
                for (int c4 = 'a'; c4 <= 'z'; ++c4) {
                    cmp[3] = c4;
                    for (int c5 = 'a'; c5 <= 'z'; ++c5) {
                        cmp[4] = c5;
                        for (int c6 = 'a'; c6 <= 'z'; ++c6) {
                            cmp[5] = c6;

                            char *x = crypt(cmp, salt);
                            if ((strcmp(x, password)) == 0) {
                                printf("Udało sie: %s %s %s\n", cmp, x, password);
                                MPI_Abort(MPI_COMM_WORLD, 0);
                                exit(0);
                            }
                        }
                    }
                }
            }
        }
    }
}
