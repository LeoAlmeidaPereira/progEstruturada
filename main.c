#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main(){
	
	char harmoniaFinal[7], *ptr_Harmonia, tomOriginal, tomFinal,  *ptr_harmoniaMenorRelativa;
	int *ptr_semitom, *ptr_harmoniaInt, i;
	
	printf("INSIRA OS TONS USANDO A SIMBOLOGIA DE LETRAS E ASSUMA QUE OS TONS SUSTENIDOS SERAO SUBSTITUIDOS PELA LETRA MINUSCULA DO TOM NATURAL QUE O ANTECEDE	EX: F# = f\n\n");
	printf("TOM ORIGINAL DA HARMONIA:\n");
	scanf(" %c", &tomOriginal);
	printf("TOM IDEAL DA HARMONIA:\n");
	scanf(" %c", &tomFinal);
	
	ptr_Harmonia = harmoniaFinal;
	ptr_semitom = geraSemitom(tomOriginal, tomFinal);	
	
	ptr_harmoniaInt = criarHarmonicoInt(ptr_semitom[1]);
	ptr_harmoniaMenorRelativa = criaRelativoMenor(ptr_harmoniaInt);
	
	free(ptr_semitom);
	//printf("\n");
	//campoHarmonico(ptr_harmoniaInt, ptr_harmoniaMenorRelativa); //Passar vetor semitom e printar o campo harmonico desejado, convertendo de int para char
	
	
	campoHarmonicoRec(ptr_harmoniaInt, 0);
	printf("\n\n");
	printf("Campo harmonico relativo menor do campo harmonico final: \n");
	mostraRelativoMenorRec(ptr_harmoniaMenorRelativa, 0);
	
	return 0;
}
