#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

void printArray(int *arr, int size);
int nMaior(int n1, int n2); //Compara e retorna o maior numero
int notaInt(char a); //Converte uma nota de char para int
char notaChar(int n); //Converte uma nota de int para char
void distanciaTonal (int *ptr, char a, char b); //Retorna o tom atual e o tom desejado em int, alem de retornar a distancia de semitons entre elas
void campoHarmonico (int *ptr);
void criarHarmonicoInt(int tomFinal, int *harmoniaInt);
void campoHarmonicoRec(int *ptr, int ctrl);

#endif
