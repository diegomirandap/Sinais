#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#define EVER ;;

void intHandler(int sinal);
void quitHandler(int sinal);

int main (void){
  
  void (*p)(int);// ponteiro para função que recebe int como parâmetro

  printf("Pid id: %d\n", getpid());

  printf("kill SIGKILL desabilitado\n");

  // Tenta interceptar o SIGKILL (kill -s KILL 'pid_id')
  p = signal(SIGKILL, intHandler);
  
  for(EVER);
}

void intHandler(int sinal){
  printf("Você tentou dar SIGKILL %d\n", sinal);
}