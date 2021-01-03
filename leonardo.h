#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

void printArray(int *arr, int size);
int nMaior(int n1, int n2); //Compara e retorna o maior numero
int notaInt(char a); //Converte uma nota de char para int
char notaChar(int n); //Converte uma nota de int para char
void distanciaTonal (int *ptr, char a, char b); //Retorna o tom atual e o tom desejado em int, alem de retornar a distancia de semitons entre elas
int *geraSemitom (char a, char b); //distanciaTonal com alocação
void campoHarmonico (int *ptr, char *ptr_menor);
int *criarHarmonicoInt(int tomFinal);
void campoHarmonicoRec(int *ptr, int ctrl);
char *criaRelativoMenor(int *ptr_maior);
void mostraRelativoMenor(char *ptr_menor);
void mostraRelativoMenorRec(char *ptr_menor, int ctrl);

#endif
