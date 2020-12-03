#include <stdio.h>
#include <stdlib.h>
#include "leonardo.h"

void printArray(int *arr, int size){
    int i;
    
	printf("Tamanho do array: %i \n\n", size);

    printf("Array: ");
    for (i = 0; i < size; i++){
        // *(ptr + i) is equivalent to arr[i]
        printf("%d, ", *(arr + i));
    }
    printf("\n\n");
}

int nMaior(int n1, int n2){
	if (n1>n2){
		return n1;
	}else{
		return n2;
	}
}

int notaInt(char a){
	switch (a) {
		case 'A':
			return 0;
			break;
		case 'a':
			return 1;
			break;
		case 'B':
			return 2;
			break;
		case 'C':
			return 3;
			break;
		case 'c':
			return 4;
			break;
		case 'D':
			return 5;
			break;
		case 'd':
			return 6;
			break;
		case 'E':
			return 7;
			break;
		case 'F':
			return 8;
			break;
		case 'f':
			return 9;
			break;
		case 'G':
			return 10;
			break;
		case 'g':
			return 11;
			break;
	}	
}

char notaChar(int n){
	if (nMaior(n, 12) == n){
		n = n - 12;
	}		
	switch (n) {
		case 0:
			return 'A';
			break;
		case 1:
			return 'a';
			break;
		case 2:
			return 'B';
			break;
		case 3:
			return 'C';
			break;
		case 4:
			return 'c';
			break;
		case 5:
			return 'D';
			break;
		case 6:
			return 'd';
			break;
		case 7:
			return 'E';
			break;
		case 8:
			return 'F';
			break;
		case 9:
			return 'f';
			break;
		case 10:
			return 'G';
			break;
		case 11:
			return 'g';
			break;
	}
}

void distanciaTonal (int *ptr, char a, char b){
	
	int tomInicial, tomFinal;

	tomInicial = notaInt(a);
	tomFinal = notaInt(b);

	if(nMaior(tomInicial, tomFinal) == tomInicial){
		*ptr = tomInicial;
		*(ptr+1) = tomFinal;
		*(ptr+2) = tomInicial - tomFinal;
	}else{
		*ptr = tomInicial;
		*(ptr+1) = tomFinal;
		*(ptr+2) = tomFinal - tomInicial;
	}
}

void criarHarmonicoInt(int tomFinal, int * harmoniaInt){
	
	*(harmoniaInt + 0) = tomFinal;

	*(harmoniaInt + 1) = tomFinal + 2;

	*(harmoniaInt + 2) = tomFinal + 4;
	
	*(harmoniaInt + 3) = tomFinal + 5;

	*(harmoniaInt + 4) = tomFinal + 7;

	*(harmoniaInt + 5) = tomFinal + 9;
	
	*(harmoniaInt + 6) = tomFinal + 11;
}

void campoHarmonico(int *ptr){
	
	int i;
	char aux;
	
	for(i=0; i<=6;i++){
		
		aux = notaChar(*(ptr + i));
	
		switch (aux){
			case 'a':
				printf("|  A#");
				break;
			case 'c':
				printf("|  C#");
				break;
			case 'd':
				printf("|  D#");
				break;
			case 'f':
				printf("|  F#");
				break;
			case 'g':
				printf("|  G#");
				break;
			default:
				printf("|  %c", aux);
		}
		switch(i){
			case 0:
				printf("  |");
				break;
			case 1:
				printf("m  |");
				break;
			case 2:
				printf("m  |");
				break;
			case 3:
				printf("  |");
				break;
			case 4:
				printf("  |");
				break;
			case 5:
				printf("m  |");
				break;
			case 6:
				printf("m7(b5) |");
				break;
		}	
	}
}

void campoHarmonicoRec(int *ptr, int ctrl){
	char aux;
	if(ctrl>6){
		exit(0);
	}else{
			
		aux = notaChar(*(ptr + ctrl));
		
		switch (aux){
			case 'a':
				printf("|  A#");
				break;
			case 'c':
				printf("|  C#");
				break;
			case 'd':
				printf("|  D#");
				break;
			case 'f':
				printf("|  F#");
				break;
			case 'g':
				printf("|  G#");
				break;
			default:
				printf("|  %c", aux);
		}
		switch(ctrl){
			case 0:
				printf("  |");
				break;
			case 1:
				printf("m  |");
				break;
			case 2:
				printf("m  |");
				break;
			case 3:
				printf("  |");
				break;
			case 4:
				printf("  |");
				break;
			case 5:
				printf("m  |");
				break;
			case 6:
				printf("m7(b5) |");
				break;
		}	
		return campoHarmonicoRec(ptr, ctrl+1);
	}
}
