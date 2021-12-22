#include <omp.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;


int main(int argc, char* argv[])
{
    long double start_time, end_time, tick;
    srand(time(0)); 
    int n = atoi(argv[1]);
    long double A[n];
    long double B[n];
    long double C[n];
    int i;

    int N = (n > 10 ? 10 : n);


    for (i = 0; i<n; i++){
        A[i] = rand()%9;
        B[i] = rand()%9;
    }

//Цикл с увеличением числа потоков
    for(int k = 1; k <= 10; k++){
        int cntThreads = k;
        start_time = omp_get_wtime();
        #pragma omp parallel for num_threads(cntThreads)
        for (i = 0;i<n; i++)
        {
            C[i] = A[i] * B[i];
        }
        end_time = omp_get_wtime();
		printf("Проверка корректности:\n");
        for (i = 0; i<N; i++){
            cout <<"\t"<< A[i] << "*" << B[i] << "=" << C[i] << "\n";
        }

    cout << "Потоков: " << cntThreads << "\n";
    printf("Затраченное время: %Lf секунд\n\n", end_time-start_time);
    cout << endl;
    }
}