#include<stdio.h>
#include<stdlib.h>

struct Calificaciones{
	char mat[10];
	float par[7];
}cal[29];


void alumnos(float *calfin, int *par_noapro) {
		int i, j;
	  for(i=0; i<29; i++){
	  			*calfin=0;
	  			*par_noapro=0;
		for(j=0; j<7; j++){
				*calfin=*calfin+cal[i].par[j];
					if(cal[i].par[j]<7){
						*par_noapro= *par_noapro+1;
						
			}
			
		}
		
		*(par_noapro)++;
		*calfin=*calfin/7;
	    *(calfin)++;
	}
	
}


void cal_par(int *prompar, int *noaproXpar){
	int i, j;
	for(j=0; j<7; j++){
		*prompar=0;
		*noaproXpar=0;
		for(i=0; i<29; i++){
		    *prompar=*prompar+cal[i].par[j];
		   	if(cal[i].par[j]<7){
		       *noaproXpar=*noaproXpar+1;
	     }
	     
      }
      
   			*prompar=*prompar/29;	
   			prompar++;
			noaproXpar++;
  }
   
}


int grupo2(float *calfin){
    	int repro=0;
    	int indice=0;
        for(indice = 0; indice < 29; indice++){
	    if(calfin[indice]<7){
        		repro=repro+1;
		}
        }
	return repro;
}
	
void grupo( float calfin[29], float *promgrp){
	int i;
	promgrp=0;
	for(i=0; i<29; i++){
        *promgrp=*promgrp+calfin[i];
	}	
	
	*promgrp = *promgrp / 29;
}	
	
int main(){
	
	int i, j;
	FILE *ap;
	FILE *nu;
	int prompar[7];
	int noaproXpar[7];
	float calfin[29];
	int par_noapro[29];
	float promgrp;
    char encabezado[255];
	int repro=0;
	char mat[50], par1[50], par2[50], par3[50], par4[50], par5[50], par6[50], par7[50];
	ap=fopen("C://Users/Zambrano/Desktop/PIA Progra/calificaciones_pia_pe.csv", "r");
	if(ap == NULL){
			printf("Error\n");
			
	}else{
		
	printf("El archivo fue abierto\n");
	
   }
   
    fflush(stdin);
	//fscanf(ap, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,\n]\n", mat, par1, par2, par3, par4, par5, par6, par7);
	fgets(encabezado,255,ap);
	for(i=0; i<29; i++){
		fscanf(ap,"%[^,],", cal[i].mat);
		  for(j=0; j<7; j++){
		  		fscanf(ap,"%f,", &cal[i].par[j]);
	  }
	  fprintf(ap, "\n");
    }
    
	fclose(ap);
	nu=fopen("C://Users/Zambrano/Desktop/PIA Progra/ArchivoN.csv", "w+");
		if(nu == NULL){
		printf("Error\n");
		
	}else{
		
	printf("El archivo fue creado \n");
   }
   
   fprintf(nu,"Matricula, Parcial1, Parcial2, Parcial3, Parcial4, Parcial5, Parcial6, Parcial7, Promedio de calificaciones parciales, No Aprobados\n");
   alumnos(calfin, par_noapro);
   for(i=0; i<29; i++){
     int k=3;
     fprintf(nu,"%c",02);
     while(k<7){
       fprintf(nu,"%c", cal[i].mat[k]);
       k++;
     }
     fprintf(nu, ",");
     for(j=0; j<7; j++){
       fprintf(nu,"%.0f,", cal[i].par[j]);
     }
     fprintf(nu, "%.0f,", calfin[i]);
     fprintf(nu, "%d,", par_noapro[i]);
     fprintf(nu, "\n");
    }
    /*
    cal_par(prompar, noaproXpar);
    grupo(calfin, &promgrp);
    repro = grupo2( calfin);
    printf("%d\n", repro);
    printf("%.0f", promgrp);
    fprintf(nu, "Promedios, Promedio Parcial1, Promedio Parcial2, Promedio Parcial3, Promedio Parcial4, Promedio Parcial5, Promedio Parcial6, Promedio Parcial7, Promedio del grupo\n,");
    for(j=0; j<7; j++){
    		fprintf(nu, "%d,", prompar[j]);
     }
     
    fprintf(nu, "%.0f", promgrp);
    fprintf(nu, "\n");
    fprintf(nu, "No aprobados, Cantidad de alumnos que no aprobaron el parcial1, Cantidad de alumnos que no aprobaron el parcial2, Cantidad de alumnos que no aprobaron el parcial3, Cantidad de alumnos que no aprobaron el parcial4, Cantidad de alumnos que no aprobaron el parcial5, Cantidad de alumnos que no aprobaron el parcial6, Cantidad de alumnos que no aprobaron el parcial7, Total de no aprobados\n,");
    for(j=0; j<7; j++){
    	fprintf(nu, "%d,", noaproXpar[j]);
     }
     
     fprintf(nu, "%d\n", repro);*/
	fclose(nu);
	return 0;
}

