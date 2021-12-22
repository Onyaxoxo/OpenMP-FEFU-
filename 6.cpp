#include <omp.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;
int main(int argc, char* argv[])
{
    double start_time, end_time, effect_start, effect_stop;
    srand(time(0)); 
    int n = atoi(argv[1]);
    double A[n][n];
    double B[n][n];
    double C[n][n];
    int i, l, g;

    int N = (n > 5 ? 5 : n);
    for(l = 0;l<n;l++)
        for (i = 0; i<n; i++){
            A[l][i] = rand()%10;
            B[l][i] = rand()%10;
        }


    for(int k = 1; k <= 10; k++){
        int cntThreads = k;
  

        if(k == 1){
            start_time = omp_get_wtime();
        }else{
            effect_start = omp_get_wtime();
        }

        omp_set_dynamic(0); 
        omp_set_num_threads(cntThreads);
        #pragma omp parallel shared(A, B, C) private(i,l,g)
        {
            
            g = omp_get_thread_num();
            #pragma omp for
            for(l = 0;l<n;l++)
                for (i = 0;i<n; i++)
                {
                    C[l][i] = A[l][i] * B[l][i];
                }

            if(k == 1){
                end_time = omp_get_wtime();
            }else{
                effect_stop = omp_get_wtime();
            }
        }
    

        cout.precision(9);
        cout << "Потоков: " << cntThreads << "\n";
        if(k != 1){
            printf("Затрачено %f секунд\n", (effect_stop-effect_start));
            printf("Эффективность %f\n", (end_time-start_time)/(effect_stop-effect_start));
        }else{
            printf("Затрачено %f секунд\n", (end_time-start_time));
        }
        
        cout << endl;
    }
}