#include <stdio.h>
#include <stdlib.h>

int fatorial(int numero){
    if(numero<=1)
        return 1;
    return numero*fatorial(numero-1);
}

int main()
{
    printf("Fatorial de 3 é: %d", fatorial(3));
}
