#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main(){
	
	char harmoniaFinal[7], *ptr_Harmonia, tomOriginal, tomFinal,  *ptr_harmoniaMenorRelativa;
	//char harmoniaMenorRelativa[8];
	int *ptr_semitom, *ptr_harmoniaInt, i;
	//int semitom[3], harmoniaInt[7];
	
	printf("INSIRA OS TONS USANDO A SIMBOLOGIA DE LETRAS E ASSUMA QUE OS TONS SUSTENIDOS SERAO SUBSTITUIDOS PELA LETRA MINUSCULA DO TOM NATURAL QUE O ANTECEDE	EX: F# = f\n\n");
	printf("TOM ORIGINAL DA HARMONIA:\n");
	scanf(" %c", &tomOriginal);
	printf("TOM IDEAL DA HARMONIA:\n");
	scanf(" %c", &tomFinal);
	
	//ptr_semitom = semitom;//Guardar o tomOriginal, tomAtual e a distância deles, tudo em Int
	ptr_Harmonia = harmoniaFinal;
	//ptr_harmoniaInt = harmoniaInt;
	//ptr_harmoniaMenorRelativa = harmoniaMenorRelativa;
	
	ptr_semitom = geraSemitom(tomOriginal, tomFinal);	
	//distanciaTonal(ptr_semitom, tomOriginal, tomFinal);//Converter os tons de Char pra Int
	
	//criarHarmonicoInt(ptr_semitom[1], harmoniaInt);
	ptr_harmoniaInt = criarHarmonicoInt(ptr_semitom[1]);
	//criaRelativoMenor(ptr_harmoniaInt, ptr_harmoniaMenorRelativa);
	ptr_harmoniaMenorRelativa = criaRelativoMenor(ptr_harmoniaInt);
	
	free(ptr_semitom);
	
	//################## BLOCO FINAL TRADICIONAL ##############################
	
	//printf("\n");
	//campoHarmonico(ptr_harmoniaInt, ptr_harmoniaMenorRelativa); //Passar vetor semitom e printar o campo harmonico desejado, convertendo de int para char
	
	//##########################################################################
	
	//################ BLOCO FINAL DE FORMA RECURSIVA ##########################
	FILE *arq;
	arq = fopen("./CampoHarmonico.txt", "w");
	if (arq == NULL)
	{
	   printf("Problemas na CRIACAO do arquivo\n");
	   return;
	}
	fclose(arq);
	
	campoHarmonicoRec(ptr_harmoniaInt, 0);
	printf("\n\n");
	printf("Campo harmonico relativo menor do campo harmonico final: \n");
	mostraRelativoMenorRec(ptr_harmoniaMenorRelativa, 0);
	//#########################################################################
	return 0;
}
