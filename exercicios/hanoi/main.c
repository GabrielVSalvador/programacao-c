#include <stdio.h>
#include <stdlib.h>

void hanoi( int num_discos, char torre_A, char torre_B, char torre_C)
{
    if(num_discos > 0)
    {
        hanoi(num_discos-1, torre_A, torre_C, torre_B);
        printf("Mover %c -> %c \n", torre_A, torre_B);
        hanoi(num_discos-1, torre_C, torre_B, torre_A);
    }
}

int main()
{
    hanoi(3,'A','B','C');
}
