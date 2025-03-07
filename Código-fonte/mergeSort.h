#ifndef MERGESORT_H
#define MERGESORT_H
#include "diretorio.h"
#include "vetor.h"

void merge( int *vetor, int comeco, int meio, int fim ) {
    int com1 = comeco;
	int com2 = meio+1;
	int comAux = 0;
	int tam = fim-comeco+1;
    int *vetAux = NULL;
    
    aloca_Memoria( &vetAux, tam );

    while( com1 <= meio && com2 <= fim ) {
        if( vetor[com1] < vetor[com2] ) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while( com1 <= meio ) {  
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while( com2 <= fim ) {   
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for( comAux = comeco; comAux <= fim; comAux++ ) {    
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free( vetAux );
}

double mergeSort( int *vetor, int comeco, int fim ) {
	double tempo;
    clock_t StartC, EndC;
    StartC = clock();
    
    if ( comeco < fim ) {
        int meio = ( fim+comeco ) / 2;

        mergeSort( vetor, comeco, meio );
        mergeSort( vetor, meio+1, fim );
        merge( vetor, comeco, meio, fim );
    }
    
    EndC = clock();
	tempo = ( EndC - StartC ) / ( double )CLOCKS_PER_SEC;
	//printf( "\t---Tempo gasto para ordenar elementos do vetor: %f---\t\n", tempo );
	return tempo;
}

#endif
