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
		case 12:
			return 'A';
			break;
		case 13:
			return 'a';
			break;
		case 14:
			return 'B';
			break;
		case 15:
			return 'C';
			break;
		case 16:
			return 'c';
			break;
		case 17:
			return 'D';
			break;
		case 18:
			return 'd';
			break;
		case 19:
			return 'E';
			break;
		case 20:
			return 'F';
			break;
		case 21:
			return 'f';
			break;
		case 22:
			return 'G';
			break;
		case 23:
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
	int i;
	for(i=0;i<=6;i++){
		switch(i){
			case 0:
				*(harmoniaInt + i) = tomFinal;
				break;
			case 1:
				*(harmoniaInt + i) = tomFinal + 2;
				break;
			case 2:
				*(harmoniaInt + i) = tomFinal + 4;
				break;
			case 3:
				*(harmoniaInt + i) = tomFinal + 5;
				break;
			case 4:
				*(harmoniaInt + i) = tomFinal + 7;
				break;
			case 5:
				*(harmoniaInt + i) = tomFinal + 9;
				break;
			case 6:
				*(harmoniaInt + i) = tomFinal +11;
				break;
		}
	}
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
