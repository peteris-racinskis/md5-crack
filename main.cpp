#include <mpi.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>
#include <stdio.h>

using namespace std;
const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    // Split the task into blocks by first character
    int symbols_per_block = alphabet.length()/world_size;
    string charblocks [alphabet.length()/symbols_per_block];
    for (int i = charblocks.length()-1; i > 0; i--){
        charblocks[i] = alphabet.substr(alphabet.length()-symbols_per_block-1, symbols_per_block);
        alphabet = alphabet.substr(0, alphabet.length()-symbols_per_block);
    }


    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // Print off a hello world message
    printf("Hello world from processor %s, rank %d out of %d processors\n",
           processor_name, world_rank, world_size);

    // Finalize the MPI environment.
    MPI_Finalize();
}