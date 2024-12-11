#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#define EVER ;;

void intHandler(int sinal);
void quitHandler(int sinal);

int main (void){
  
  void (*p)(int);// ponteiro para função que recebe int como parâmetro

  // signal intercepta quando le o comando SIGINT (Ctrl+c), e chama a funcao intHandler no lugar
  p = signal(SIGINT, intHandler);
  printf("Endereco do manipulador anterior %p\n", p);

  // signal intercepta o comando SIGQUIT (Ctrl+\), e executa a funcao quitHandler
  p = signal(SIGQUIT, quitHandler);
  printf("Endereco do manipulador anterior %p\n", p);
  printf("Ctrl-C desabilitado. Use Ctrl-\\ para terminar\n");
  
  for(EVER);
}

void intHandler(int sinal){
  printf("Você pressionou Ctrl-C (%d)\n", sinal);
}

void quitHandler(int sinal){
  printf("Terminando o processo...\n");
  exit (0);
}