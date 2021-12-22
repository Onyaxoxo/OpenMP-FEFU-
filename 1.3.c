#include <stdio.h>
#include <omp.h>
int main(int argc, char *argv[])
{
    int count, num;
    printf("Последовательная область #1\n\n");
    omp_set_num_threads(2);
    #pragma omp parallel num_threads(3)
    {
        count=omp_get_num_threads();
        num=omp_get_thread_num();
//        if (num == 0) printf("Потоков в первой группе: %d\n", count);
        printf("Поток #%d\n", num);
    }
	printf("\n");
    #pragma omp parallel
    {
        count=omp_get_num_threads();
        num=omp_get_thread_num();
 //       if (num == 0) printf("Потоков во второй группе: %d\n", count);
        printf("Поток #%d\n", num);
    }
    printf("\nПоследовательная область #2\n");
}
