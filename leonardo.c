#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int *geraSemitom (char a, char b){
	
	int tomInicial, tomFinal, *vet;
	vet = (int *)malloc( 3 * sizeof(int) );
	if(vet == NULL){
	printf("ERRO\n");
	return NULL;
	}
	
	tomInicial = notaInt(a);
	tomFinal = notaInt(b);

	if(nMaior(tomInicial, tomFinal) == tomInicial){
		*vet = tomInicial;
		*(vet+1) = tomFinal;
		*(vet+2) = tomInicial - tomFinal;
	}else{
		*vet = tomInicial;
		*(vet+1) = tomFinal;
		*(vet+2) = tomFinal - tomInicial;
	}
	return vet;
}

void criarHarmonicoInt(int tomFinal, int *harmoniaInt){
	
	*(harmoniaInt + 0) = tomFinal;

	*(harmoniaInt + 1) = tomFinal + 2;

	*(harmoniaInt + 2) = tomFinal + 4;
	
	*(harmoniaInt + 3) = tomFinal + 5;

	*(harmoniaInt + 4) = tomFinal + 7;

	*(harmoniaInt + 5) = tomFinal + 9;
	
	*(harmoniaInt + 6) = tomFinal + 11;
}

void campoHarmonico(int *ptr, char *ptr_menor){
	
	int i;
	char aux;
	
	
	FILE *arq;

	arq = fopen("C:/Users/Leonardo/Documents/Projeto P.E/CampoHarmonico.txt", "w");
	if (arq == NULL)
	{
	   printf("Problemas na CRIACAO do arquivo\n");
	   return;
	}
	
	for(i=0; i<=6;i++){
		
		aux = notaChar(*(ptr + i));
	
		switch (aux){
			case 'a':
				printf("|  A#");
				fprintf(arq, "|  A#");
				break;
			case 'c':
				printf("|  C#");
				fprintf(arq, "|  C#");
				break;
			case 'd':
				printf("|  D#");
				fprintf(arq, "|  D#");
				break;
			case 'f':
				printf("|  F#");
				fprintf(arq, "|  F#");
				break;
			case 'g':
				printf("|  G#");
				fprintf(arq, "|  G#");
				break;
			default:
				printf("|  %c", aux);
				fprintf(arq, "|  %c", aux);
		}
		switch(i){
			case 0:
				printf("  |");
				fprintf(arq, "  |");
				break;
			case 1:
				printf("m  |");
				fprintf(arq, "m  |");
				break;
			case 2:
				printf("m  |");
				fprintf(arq, "m  |");
				break;
			case 3:
				printf("  |");
				fprintf(arq, "  |");
				break;
			case 4:
				printf("  |");
				fprintf(arq, "  |");
				break;
			case 5:
				printf("m  |");
				fprintf(arq, "m  |");
				break;
			case 6:
				printf("m7(b5) |");
				fprintf(arq, "m7(b5) |");
				break;
		}	
	}
	fclose(arq);
	mostraRelativoMenor(ptr_menor);
}

void campoHarmonicoRec(int *ptr, int ctrl){
	char aux;
	
	FILE *arq;

	arq = fopen("C:/Users/Leonardo/Documents/Projeto P.E/CampoHarmonico.txt", "w");
	if (arq == NULL)
	{
	   printf("Problemas na CRIACAO do arquivo\n");
	   return;
	}
	
	if(ctrl>6){
		fclose(arq);
		return;
	}else{
			
		aux = notaChar(*(ptr + ctrl));
		
		switch (aux){
			case 'a':
				printf("|  A#");
				fprintf(arq, "|  A#");
				break;
			case 'c':
				printf("|  C#");
				fprintf(arq, "|  C#");
				break;
			case 'd':
				printf("|  D#");
				fprintf(arq, "|  D#");
				break;
			case 'f':
				printf("|  F#");
				fprintf(arq, "|  F#");
				break;
			case 'g':
				printf("|  G#");
				fprintf(arq, "|  G#");
				break;
			default:
				printf("|  %c", aux);
				fprintf(arq, "|  %c", aux);
		}
		switch(ctrl){
			case 0:
				printf("  |");
				fprintf(arq, "  |");
				break;
			case 1:
				printf("m  |");
				fprintf(arq, "m  |");
				break;
			case 2:
				printf("m  |");
				fprintf(arq, "m  |");
				break;
			case 3:
				printf("  |");
				fprintf(arq, "  |");
				break;
			case 4:
				printf("  |");
				fprintf(arq, "  |");
				break;
			case 5:
				printf("m  |");
				fprintf(arq, "m  |");
				break;
			case 6:
				printf("m7(b5) |");
				fprintf(arq, "m7(b5) |");
				break;
		}
		return campoHarmonicoRec(ptr, ctrl+1);
	}
}

void criaRelativoMenor(int *ptr_maior, char *ptr_menor){
	*(ptr_menor+0) = notaChar(*(ptr_maior+5));
	*(ptr_menor+1) = notaChar(*(ptr_maior+6));
	*(ptr_menor+2) = notaChar(*(ptr_maior+0));
	*(ptr_menor+3) = notaChar(*(ptr_maior+1));
	*(ptr_menor+4) = notaChar(*(ptr_maior+2));
	*(ptr_menor+5) = notaChar(*(ptr_maior+3));
	*(ptr_menor+6) = notaChar(*(ptr_maior+4));
}

void mostraRelativoMenor(char *ptr_menor){
	printf("\n\n");
	printf("Campo harmonico relativo menor do campo harmonico final: \n");
	int i;
	for(i=0; i<=6;i++){
		switch (*(ptr_menor+i)){
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
				printf("|  %c", *(ptr_menor+i));
		}
		switch(i){
			case 0:
				printf("m  |");
				break;
			case 1:
				printf("m7(b5)  |");
				break;
			case 2:
				printf("  |");
				break;
			case 3:
				printf("m  |");
				break;
			case 4:
				printf("m  |");
				break;
			case 5:
				printf("  |");
				break;
			case 6:
				printf(" |");
				break;
		}	
	}
}

void mostraRelativoMenorRec(char *ptr_menor, int ctrl){
	if(ctrl>6){
		return;
	}else{
		switch (*(ptr_menor+ctrl)){
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
				printf("|  %c", *(ptr_menor+ctrl));
		}
		switch(ctrl){
			case 0:
				printf("m  |");
				break;
			case 1:
				printf("m7(b5)  |");
				break;
			case 2:
				printf("  |");
				break;
			case 3:
				printf("m  |");
				break;
			case 4:
				printf("m  |");
				break;
			case 5:
				printf("  |");
				break;
			case 6:
				printf(" |");
				break;
		}	
		return mostraRelativoMenorRec(ptr_menor, ctrl+1);
	}
}
