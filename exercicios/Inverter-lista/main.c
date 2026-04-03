void inverter_Lista ( int lista[], int tamanho)
{
    int i, aux;
    for (i=0 ;i < tamanho/2 ;)
    {
        aux = lista(i);
        lista(i)= lista(tamanho - i -1);
        lista(tamanho-i-1)= aux;
