#include <omp.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;
int main(int argc, char* argv[])
{
	cout << "Part 2.1 =========================\n\n";
	cout << "| Sample 4a\n";
	int count = 0;
	int num;
	#pragma omp parallel reduction (+: count)
    {
		num=omp_get_thread_num();
        count++;
		printf("#%d : count = %d\n", num, count);
	}
	cout << "Сумма всех count =  " << count << "\n\n";
	
	
	cout << "| Sample 18a\n";
	int	A[10],	B[10],	C[10], 	i,	n;
	for(	i=0; 	i<10; 	i++)
	{
		A[i] = i;
		B[i] = 2*i;
		C[i] = 0;
	}
	#pragma omp parallel shared(A, B, C) private(i, n)
	{
		n = omp_get_thread_num();
		#pragma omp for
		for (i=0; i<10; i++)
		{
			C[i] = A[i] + B[i];

			printf("Нить %d сложила элементы с номером %d\n", n, i);
		}
	}
	
	
	cout<<"\n\n";
	
	
	int length = 100;
	int D[length];
	int	sum= 0;
	for(i=0; 	i<length;	 i++)
	{
		D[i] = 1;
	}
	#pragma omp parallel for shared(sum) num_threads(8)
	for(i=0; i<length; i++)
	{
		sum += D[i];
	}
	cout << "Результат обычного суммирования: " << sum << "\n";
	
	sum = 0;
	
	#pragma omp parallel for reduction (+: sum)
	for(i=0; i<length; i++)
	{
		sum += D[i];
	}
	cout << "Результат суммирования через Reduction: " << sum << "\n\n\n";
	
		
	cout << "Part 2.2 =========================\n\n";
	sum = 0;
	#pragma omp parallel
	{
		int local_sum = 0;
		#pragma omp for
		for(i=0; i<length; i++)
		{
			local_sum += D[i];
		}
		#pragma omp atomic
		sum += local_sum;
	}		
	cout << "Результат суммирования через Atomic:  " << sum << "\n";
	
	
	cout << "\n\nPart 2.3=========================\n\n";
	#pragma omp parallel
	{
		int sum =0;
		int local_sum = 0;
		#pragma omp for
		for(i=0; i<length; i++)
		{
			local_sum += D[i];
		}
		#pragma omp critical
		sum += local_sum;
	}
		cout << "Результат суммирования через Critical: " << sum << "\n\n";
	return 0;
}		