/*
 * actividad.c
 *
 *  Created on: Nov 21, 2021
 *      Author: usuari
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
void main(){
	int num,i,j,fil,col;
	char cab,let;
	int ordenador[SIZE][SIZE];
	printf("************************BATTLESHIP**************************\n");
	printf("1.- Fácil\n");
	printf("2.- Medio\n");
	printf("3.- Difícil\n");
	printf("4.- Salir\n");
	printf("************************************************************\n");
	printf("Bienvenido al juego de hundir la flota. Escoge la dificultad:\n");
	scanf("%d",&num);
	for (i=1;i<=3;i++){//validación de 3 intentos máximo
		if (num<1 || num>4){//condiciones para volver a pedir datos
		printf("Selecciona un número que aparezca en las opciones, tienes 3 intentos, este es el %dº:",i);
		scanf("%d",&num);
		}
	}
	switch(num){//selección de dificultad
	case 1:
		printf("Bien recluta, ¡ahora a demostrar lo que sabes!\n\n");
		for (cab='A';cab<='J';cab++){//cabecera
		        printf("|_%c",cab);
		        if(cab>='J'){//final de cabecera
		            printf("|\n");
		        }
		    }

	    for (i=0;i<SIZE;i++){//cuadrícula
	        	for (j=0;j<SIZE;j++){
	        		printf("|__");
	        		if (j+1>=SIZE){//final de fila
	        			printf("|");
	        		}
	        	}
	        	printf(" %d",i+1);
	        	printf("\n");
	        }
	    printf("\n");

	    	for (i=0;i<SIZE;i++){//iniciar la matriz a 0
	          for (j=0;j<SIZE;j++){
	        	  ordenador[i][j]=0;
	          }
	    	}

	    //colocación de los barcos
	    ordenador[2][2]=1;
	    ordenador[3][2]=1;
	    ordenador[4][2]=1;//barco de 3

	    ordenador[2][4]=1;
	    ordenador[2][5]=1;//barco de 2

	    ordenador[1][8]=1;
	    ordenador[2][8]=1;
	    ordenador[3][8]=1;//barco de 3

	    ordenador[4][4]=1;
	    ordenador[4][5]=1;
	    ordenador[4][6]=1;
	    ordenador[4][7]=1;//barco de 4

	    ordenador[8][2]=1;
	    ordenador[8][3]=1;
	    ordenador[8][4]=1;
	    ordenador[8][5]=1;
	    ordenador[8][6]=1;//barco de 5

	    do{//validación de la fila
			printf("Escoge la fila a la cual deseas disparar:\n");
			scanf("%d",&fil);
	    }while (fil<1 || fil>SIZE);
	    fil--; //els valors de la matriu es -1
	    do{//validación de la columna
			printf("Escoge la columna a la cual deseas disparar (en mayúscula):\n");
			scanf("%c",&let);
			scanf("%c",&let);//con un scanf se me repite el bucle, con dos no
	    }while (let<'A' || let>'J');
	    switch(let){
	    	case 'A': col=0;
	    	break;
	    	case 'B': col=1;
	    	break;
	    	case 'C': col=2;
	    	break;
	    	case 'D': col=3;
	    	break;
	    	case 'E': col=4;
	    	break;
	    	case 'F': col=5;
	    	break;
	    	case 'G': col=6;
	    	break;
	    	case 'H': col=7;
	    	break;
	    	case 'I': col=8;
	    	break;
	    	case 'J': col=9;
	    	break;
	    }
	    if(ordenador[fil][col]==1){
	    	printf("¡Tocado!\n");
	    	for (cab='A';cab<='J';cab++){//cabecera
	    	   	 printf("|_%c",cab);
	    	     if(cab>='J'){//final de cabecera
	                 printf("|\n");
	  		       }
	        }
	    	for (i=0;i<SIZE;i++){//cuadrícula
	    	      for (j=0;j<SIZE;j++){
	    	         if(ordenador[i][j]==0){
	    	    	  printf("|__");
	    	         }
	    	         else{
	    	        	  if(i==fil && j==col){
	    	        	     printf("|_x");
	    	        	  }
	    	        	   else{
	    	        	      printf("|_█");
	    	        	   }
	    	         }
	    	          if (j+1>=SIZE){//final de fila
	    	        	 printf("|");
	    	           }
	    	       }
	    	        printf(" %d",i+1);
	    	        printf("\n");
	    	        }
	    	    printf("\n");

	    }
	    else{
	    	printf("¡Fallado!\n");
	    	for (cab='A';cab<='J';cab++){//cabecera
	    		 printf("|_%c",cab);
	         if(cab>='J'){//final de cabecera
	               printf("|\n");
			        }
	    		    }
	    	  for (i=0;i<SIZE;i++){//cuadrícula
	            for (j=0;j<SIZE;j++){
	            	printf("|__");
	   	        	if (j+1>=SIZE){//final de fila
	   	        		printf("|");
	   	        	}
	    	       	}
	    	        printf(" %d",i+1);
	    	        printf("\n");
	    	        }
	    }
		break;
	case 2:
		printf("Bien marinero, ¡a ver de lo que eres capaz!\n");
		break;
	case 3:
		printf("¡Estás hecho todo un capitán! ¡Muestra lo que vales!\n");
		break;
	case 4:
		printf("¡Hasta luego!");
		break;
}
}
