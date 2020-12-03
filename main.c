#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main(){
	
	char harmoniaFinal[7], *ptr_Harmonia, tomOriginal, tomFinal;
	int semitom[3], *ptr_semitom, harmoniaInt[7], *ptr_harmoniaInt, i;
	
	printf("INSIRA OS TONS USANDO A SIMBOLOGIA DE LETRAS E ASSUMA QUE OS TONS SUSTENIDOS SERAO SUBSTITUIDOS PELA LETRA MINUSCULA DO TOM NATURAL QUE O ANTECEDE	EX: F# = f\n\n");
	printf("TOM ORIGINAL DA HARMONIA:\n");
	scanf(" %c", &tomOriginal);
	printf("TOM IDEAL DA HARMONIA:\n");
	scanf(" %c", &tomFinal);
	
	ptr_semitom = semitom;//Guardar o tomOriginal, tomAtual e a distância deles, tudo em Int
	ptr_Harmonia = harmoniaFinal;
	ptr_harmoniaInt = harmoniaInt;
	
	distanciaTonal(ptr_semitom, tomOriginal, tomFinal);//Converter os tons de Char pra Int
	
	criarHarmonicoInt(semitom[1], harmoniaInt);
	
	campoHarmonico(ptr_harmoniaInt); //Passar vetor semitom e printar o campo harmonico desejado, convertendo de int para char
	printf("\n");
	campoHarmonicoRec(ptr_harmoniaInt, 0);
	
	return 0;
}
