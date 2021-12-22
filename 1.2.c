#include <stdio.h>
#include <omp.h>
int main(int argc, char *argv[])
{
    int count, num;
    printf("Последовательная область #1\n\n");
    #pragma omp parallel
    {
        count=omp_get_num_threads();
        num=omp_get_thread_num();
		printf("Параллельная область #%d\n", num);
		printf("Всего нитей: %d\n\n", count);
	}
    printf("Последовательная область #2\n");
}
