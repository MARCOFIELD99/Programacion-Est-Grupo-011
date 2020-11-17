#include <stdio.h>
#include <stdlib.h>
 

long cache[100];
int contador = 0;
int contador_cache = 0;
 
long fibonacci(long num){
    contador++;
    if(num == 1 || num == 0){
        return 1;
    }else{
      return fibonacci(num - 1) + fibonacci(num - 2);
    }
}
 
long fibonacci_cached(long  num){
    contador_cache++;
    long valor_en_cache = cache[num];
    if(valor_en_cache <= 0){
        cache[num] = fibonacci_cached(num - 1) + fibonacci_cached(num - 2);
        valor_en_cache = cache[num];
    }
    return valor_en_cache;
}
 
int main(int numero_de_argumentos, char **valores){
    long posicion_a_calcular = 0;
    cache[0]=1;
    cache[1]=1;
    for(int i = 1; i < numero_de_argumentos; i++){
        posicion_a_calcular = atol(valores[i]);
        printf("n: %ld\tf: %ld\n", posicion_a_calcular, fibonacci(posicion_a_calcular));
    }
    printf("La funcion fibonacci fue llamada %d\n",contador);
 
    for(int i = 1; i < numero_de_argumentos; i++){
        posicion_a_calcular = atol(valores[i]);
        printf("n: %ld\tf: %ld\n", posicion_a_calcular, fibonacci_cached(posicion_a_calcular));
    }
    printf("La funcion fibonacci con memoria fue llamada %d\n",contador_cache);
    return 0;
}
