
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void childhandler(int signo);

int delay = 7; //Botando delay do pai manualmente

int main (int argc, char *argv[]){
  
  pid_t pid;
  
  signal(SIGCHLD, childhandler); //sinal que o filho passa pro pai quando termina
  
  if ((pid = fork()) < 0){
    printf("Erro ao criar filho\n");
    exit(-1);
  }
  
  if (pid == 0) { //child
    printf("%s\n", argv[1]);
    execvp(argv[1], argv); // Passamos pro execvp a funcao sleep5
  }
    
  else { // parent
 
    printf("Delay: %d\n", delay);
    sleep(delay); // delay que o pai espera a execucao do filho, esse delay substitui o papel do waitpid. Se passar do tempo, o pai mata o filho ao inves de esperar ele acabar
    printf("Program %s exceeded limit of %d seconds!\n", argv[1], delay);
    kill(pid, SIGKILL);
  }
  return 0;
}

void childhandler(int signo) // Executed if child dies before parent
{
  int status;
  pid_t pid = wait(&status);
  printf("Child %d terminated within %d seconds com estado %d.\n", pid, delay, status);
  exit(0);
}