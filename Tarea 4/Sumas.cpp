#include <iostream>

int main()
{
int elementos_maximos=100;
int serie[elementos_maximos];
int indice = 1;

for(indice = indice * indice; indice <= elementos_maximos; indice++){
	serie[indice] = indice;
}

int sumatoria = 0;
for(indice = indice * indice; indice <= elementos_maximos; indice++){
	sumatoria = sumatoria + serie[indice];
}

	printf("Valores sumados: \n");
for(indice = indice * indice; indice <= elementos_maximos; indice++){
	printf("%d,",serie[indice]);
}

printf("Sumatoria %d \n",sumatoria);
int total_calculado = (elementos_maximos*(elementos_maximos+1)*(2*elementos_maximos+1))/6;
printf("Total calculado %d \n",total_calculado);
return 0;
}
