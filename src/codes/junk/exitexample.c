/* exit example */
#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int d;
  FILE * pFile;
  pFile = fopen ("myfile.txt","r");
  if (pFile==NULL)
  {
    printf ("Error opening file");
    exit (1);
  }
  else
  {
    /* file operations here */
  }
  scanf("%d",&d);
  system("pause");
  return 0;
}
