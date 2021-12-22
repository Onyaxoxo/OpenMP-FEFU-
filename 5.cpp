#include <omp.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;
int main(int argc, char* argv[])
{
    double start_time, end_time, tick;
    srand(time(0)); 
    int n = atoi(argv[1]);
    double arr[n];
    double max_val = 0.0;
    int i;

    int N = (n > 10 ? 10 : n);

    for (i = 0; i<n; i++){
        arr[i] = rand()%n;
    }

	printf("Вектор:\n");
     for (i = 0; i<N; i++){
         cout << arr[i] << " ";
     }
    if(n > 10)
        cout << "..."; 
    int index = 0;
    cout << endl;
    cout << endl;
    int cntThreads = 1;
    start_time = omp_get_wtime();
    #pragma omp parallel for num_threads(cntThreads) reduction(max : max_val)
        for (i = 0;i<n; i++)
        {
            if (arr[i] > max_val)
            {
                max_val = arr[i];
                index = i;
            }
        }
    end_time = omp_get_wtime();
    cout << "Потоков " << cntThreads << "\n";
    cout << "Наибольшее: " << max_val << "\n";
    printf("Затрачено  %f секунд\n", end_time-start_time);
    cout << endl;



    max_val = 0.0;
    N = (n > 10 ? 10 : n);
    index = 0;
    cntThreads = 3;
    start_time = omp_get_wtime();
    #pragma omp parallel for num_threads(cntThreads) reduction(max : max_val)
        for (i = 0;i<n; i++)
        {
            if (arr[i] > max_val)
            {
                max_val = arr[i];
                index = i;
            }
        }

    end_time = omp_get_wtime();
    cout << "Потоков " << cntThreads << "\n";
    cout << "Наибольшее: " << max_val << "\n";
    printf("Затрачено  %f секунд\n", end_time-start_time);
	
	
	
	    max_val = 0.0;
    N = (n > 10 ? 10 : n);
    index = 0;
    cntThreads = 5;
    start_time = omp_get_wtime();
    #pragma omp parallel for num_threads(cntThreads) reduction(max : max_val)
        for (i = 0;i<n; i++)
        {
            if (arr[i] > max_val)
            {
                max_val = arr[i];
                index = i;
            }
        }

    end_time = omp_get_wtime();
    cout << "Потоков " << cntThreads << "\n";
    cout << "Наибольшее: " << max_val << "\n";
    printf("Затрачено  %f секунд\n", end_time-start_time);
	
	
	
	
	
	    max_val = 0.0;
    N = (n > 10 ? 10 : n);
    index = 0;
    cntThreads = 8;
    start_time = omp_get_wtime();
    #pragma omp parallel for num_threads(cntThreads) reduction(max : max_val)
        for (i = 0;i<n; i++)
        {
            if (arr[i] > max_val)
            {
                max_val = arr[i];
                index = i;
            }
        }

    end_time = omp_get_wtime();
    cout << "Потоков " << cntThreads << "\n";
    cout << "Наибольшее: " << max_val << "\n";
    printf("Затрачено  %f секунд\n", end_time-start_time);
}