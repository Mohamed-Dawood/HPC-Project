// محمد بسيوني رمضان داود D4

#include <iostream>
#include "mpi.h"

using namespace std;

int main() {
    int rank, size, data = 1;

    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the rank of the process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Get the number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Define the next and previous ranks in a circular manner
    int next = (rank + 1) % size;
    int prev = (rank - 1 + size) % size;

    // Send data to the next process and receive data from the previous process
    MPI_Send(&data, 1, MPI_INT, next, 0, MPI_COMM_WORLD);
    MPI_Recv(&data, 1, MPI_INT, prev, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    // Output the received data
    printf("Rank %d received data %d from Rank %d\n", rank, data, prev);

    // Finalize the MPI environment
    MPI_Finalize();

    return 0;
}
