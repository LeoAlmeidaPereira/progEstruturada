#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


int main(){
	
	char harmoniaFinal[7], *ptr_Harmonia;
	int semitom[3], *ptr_semitom, harmoniaInt[7], *ptr_harmoniaInt, i;
	
	/*printf("TOM ORIGINAL DA HARMONIA:\n");
	scanf("%c", &tomOriginal);
	printf("TOM IDEAL DA HARMONIA:\n");
	fflush(stdin);
	scanf("%c", &tomAtual);*/
	
	ptr_semitom = &semitom;//Guardar o tomOriginal, tomAtual e a distância deles, tudo em Int
	ptr_Harmonia = &harmoniaFinal;
	ptr_harmoniaInt = &harmoniaInt;
	//char str_notas[12] = {'A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#'};

	distanciaTonal(ptr_semitom, 'D', 'f');//Converter os tons de Char pra Int
	
	criarHarmonicoInt(semitom[1], harmoniaInt);
	
	campoHarmonico(ptr_harmoniaInt); //Passar vetor semitom e printar o campo harmonico desejado, convertendo de int para char
	
	return 0;
}
