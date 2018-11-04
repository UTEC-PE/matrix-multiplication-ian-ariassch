#include <iostream>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

#define SIZE 3


void multiplicar(int matriz1[SIZE][SIZE], int matriz2[SIZE][SIZE], int (result)[SIZE][SIZE], int R) {


    for(int i=0; i < SIZE; i++)
    {
        for(int j=0;j<SIZE; j++)
        {
            result[R][i] += matriz2[j][i] * matriz1[R][j];
        }

    }

}

int main(int argc, char *argv[]) {


    int matriz1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int matriz2[3][3]={{3,2,1},{6,5,4},{9,8,7}};
    int result[3][3]={{0,0,0},{0,0,0},{0,0,0}};




    cout << "===========================================================" << endl;
    cout << "\tThreads" << endl;
    cout << "===========================================================" << endl << endl;



    thread threads[SIZE];

    for (int R = 0; R < SIZE; ++R)
    {
        threads[R] = thread(multiplicar, matriz1, matriz2, result, R);
    }

    // We have to wait for the threads, otherwise the main thread may finish first
    for (int i = 0; i < SIZE; ++i) {
        threads[i].join();
    }

    for(int i=0; i < SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            cout<<result[i][j]<<endl;
        }
    }

    return EXIT_SUCCESS;
}







// TODO
// Multiplicación de matrices en paralelo
