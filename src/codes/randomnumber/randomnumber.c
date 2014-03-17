#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
  int iSecret, iGuess;
  srand ( time(NULL) );
  char c=' ';

  while(c != 47){
    iSecret = rand() % 100 + 1;
    printf ("random number %d \n",iSecret);
    scanf("enter char %c",&c);
    printf ("char is %d \n",c);

  }

  return 0;
}
