#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define EVER ;;

void childhandler(int signo);

int delay = 5; // Botando delay do pai manualmente

int main(int argc, char *argv[]){
  pid_t pid1, pid2;
  int status;

  if ((pid1 = fork()) < 0){
    fprintf(stderr, "Erro ao criar filho\n");
    exit(-1);
  }
  else if (pid1 == 0){
    execlp("./ex5p1", "ex5p1", NULL);
    perror("execlp");
    exit(EXIT_FAILURE);
  }

  if ((pid2 = fork()) < 0){
    fprintf(stderr, "Erro ao criar filho\n");
    exit(-1);
  }
  else if (pid2 == 0){
    execlp("./ex5p2", "ex5p2", NULL);
    perror("execlp");
    exit(EXIT_FAILURE);
  }

  // parent
  sleep(2);
  printf("Parando processos ====================\n");

  if (kill(pid1, SIGSTOP) == -1){
    perror("kill");
    exit(EXIT_FAILURE);
  }
  if (kill(pid2, SIGSTOP) == -1){
    perror("kill");
    exit(EXIT_FAILURE);
  }

  for (int i = 15; i >= 0; i--){
    printf("Child 1 iniciate: %d\n", pid1);
    if (kill(pid1, SIGCONT) == -1){
      perror("kill");
      exit(EXIT_FAILURE);
    }
    sleep(2);
    if (kill(pid1, SIGSTOP) == -1){
      perror("kill");
      exit(EXIT_FAILURE);
    }
    printf("Child 1 stopped: %d\n\n", pid1);

    printf("Child 2 iniciate: %d\n", pid2);
    if (kill(pid2, SIGCONT) == -1){
      perror("kill");
      exit(EXIT_FAILURE);
    }
    sleep(2);
    if (kill(pid2, SIGSTOP) == -1){
      perror("kill");
      exit(EXIT_FAILURE);
    }
    printf("Child 2 stopped: %d\n\n", pid2);
  }

  return 0;
}

