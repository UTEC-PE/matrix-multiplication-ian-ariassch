#include <iostream>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;
mutex mtx;
#define NUM_THREADS 10


void multiplicar(int *row, int **matriz2, int **result) {
    mtx.lock();
    result[0][0]= 1;
    mtx.unlock();
}

int main(int argc, char *argv[]) {


    int matriz1[3][3]={(1,2,3),(4,5,6),(7,8,9)};
    int matriz2[3][3]={(3,2,1),(6,5,4),(9,8,7)};
    int result[3][3];
    int *row;



    cout << "===========================================================" << endl;
    cout << "\tThreads" << endl;
    cout << "===========================================================" << endl << endl;

    thread threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads[i] = thread(multiplicar, matriz1[x] , matriz2, result);
    }

    // We have to wait for the threads, otherwise the main thread may finish first
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads[i].join();
    }

    return EXIT_SUCCESS;
}






}

// TODO
// Multiplicación de matrices en paralelo