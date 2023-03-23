#include <stdio.h>

void cmp (char a[], char g[])
{
  int x;
  for (x = 0; x <= 5; x++)
    {
      if (a[x] == g[x])
    {
      printf ("\e[1;32m%c", g[x]);  //green font, correct spot
    }
      else if (a[0] == g[x] || a[1] == g[x] || a[2] == g[x] || a[3] == g[x]
           || a[4] == g[x])
    {
      printf ("\e[1;33m%c", g[x]);  // yellow, good letter, wrong spot
    }
      else
    {
      printf ("\e[0m%c", g[x]); //white
    }
    }
  printf ("\e[0m\n");
  printf ("\n");
}
