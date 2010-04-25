#include <stdio.h>

int main(int argc, char *argv[]){
  volatile int *lock = (unsigned int *) 5242880;
  int i;
  
  for(i=0;i<9000;i++)
    printf("%d\n", *lock);

  exit(0); // To avoid cross-compiler exit routine
  return 0; // Never executed, just for compatibility
}

