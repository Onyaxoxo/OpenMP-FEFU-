#include <iostream>
#include <iomanip>
#include <sys/times.h>
#include <cmath>
#include <omp.h>
#include <cstdlib>
#include <stdio.h>

using namespace std;
int main(int argc,char* argv[])
{
    const unsigned long numSteps=atoi(argv[1]);                     
    
    double step=0;
    double PI25DT = 3.141592653589793238462643;
    double pi=0.00000000;
    double sum=0.00000000;
    double x;
    int cntThreads = 1;
	
	
	#pragma omp parallel
    {
    #pragma omp master
        {
            cntThreads=1;
            cout<<"\n Выполнение в однопоточном режиме"<<endl;
        }
    }
	
	//Засекаем время
    double start_time, end_time, tick;
    step = 1./static_cast<double>(numSteps);
    start_time = omp_get_wtime();
		
	//Вычисляем значения каждого i-го знака
    #pragma omp parallel for num_threads(cntThreads) private (x), reduction (+:sum)
    for (int i=0; i<numSteps; i++)
    {
        x = (i + .5)*step;
        sum = sum + 4.0/(1.+ x*x);
    }
	
	//Объединяем всё в одно число
    pi = sum*step;
	
	//Выключаем таймер
    end_time = omp_get_wtime();
    cout.precision(9);
    cout << "\t Pi = " << pi << endl;
    printf("\t Время вычисления %f секунд\n", end_time-start_time);
    
	
	//Сброс
    step=0;
    pi=0.00000000;
    sum=0.00000000;



    #pragma omp parallel
    {
    #pragma omp master
        {
            cntThreads=omp_get_num_threads();
			printf("\n Вычисление в %d потоков\n", cntThreads);
        }
    }

    step = 1./static_cast<double>(numSteps);
    start_time = omp_get_wtime();
    #pragma omp parallel for private (x), reduction (+:sum)
    for (int i=0; i<numSteps; i++)
    {
        x = (i + .5)*step;
        sum = sum + 4.0/(1.+ x*x);
    }
    pi = sum*step;
    end_time = omp_get_wtime();
    cout.precision(9);
    cout << "\t Pi = " << pi << "\n\t Погрешность = " << fabs(pi - PI25DT) << endl;
    printf("\t Время вычисления %f секунд\n\n", end_time-start_time);
    return 0;
}