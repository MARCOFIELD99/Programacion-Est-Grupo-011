#include <stdio.h>

/*minuscula, mayuscula, digito y especiales*/


int main(){
	char caracter='4';
	int valor_ascii = (int) caracter;


if(valor_ascii >=48 && valor_ascii <=57){
	printf("El dato ingresado %c un digito \n",caracter);

}else{
if(valor_ascii >=65 && valor_ascii <=90){
	printf("El dato ingresado %c es una letra Mayuscula \n",caracter);

}else{
if(valor_ascii >=97 && valor_ascii <=122){
	printf("El dato ingresado %c es una letra minuscula \n",caracter);

}else{
printf("El dato ingresado %c es un caracter especial \n",caracter);

}
}
}
return 0;

}
