#include <stdio.h>
#include <unistd.h>
int main (){
  for(int i = 2;;i+=2){
      sleep(1);
      printf("%d\n", i);
    }
}