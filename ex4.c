#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void childhandler(int signo);


int main (int argc, char *argv[]){
  //float num1,num2;
  int num1,num2;
  printf("Digite dois numeros:");
  scanf("%d %d",&num1,&num2);

  // Chama o sinal SIGCHLD para ligar o alerta
  signal(SIGFPE, childhandler);

  /*
  printf("%f\n", num1);
  printf("%f\n", num2);
  printf("%f\n", num1 + num2);
  printf("%f\n", num1 - num2);
  printf("%f\n", num1 * num2);
  printf("%f\n", num1 / num2);
  */

  printf("%d\n", num1);
  printf("%d\n", num2);
  printf("%d\n", num1 + num2);
  printf("%d\n", num1 - num2);
  printf("%d\n", num1 * num2);
  printf("%d\n", num1 / num2);
  //printf("Program %s exceeded limit of %d seconds!\n", argv[1]);
  
}

void childhandler(int signo) // Executed if Floating-point exceptions
{
  //printf("Tentou calcular divisao de float com 0");
  printf("Tentou calcular divisao de intero com 0");
  exit(0);
}