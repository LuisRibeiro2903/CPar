#include<omp.h> 
#include <unistd.h>
#include <stdio.h> 

 
int main() { 
    printf("master thread\n"); 
    int O = 0, I = 0;

#pragma omp parallel num_threads(2)
    {
        #pragma omp for schedule(guided)
        for(int i=0;i<100;i++) { 
            int id = omp_get_thread_num();
            printf("T%d:i%d ", id, i);         
            if (id == 0) {
                O++;
            } else {
                I++;
            }
        }
    }
    printf("\nO = %d, I = %d\n", O, I);
    printf("master thread\n"); 
}