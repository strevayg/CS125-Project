/* Contributors: Lily, Jules, Gabby
   Description: This program compares each letter in the user's guess
                with each letter in the chosen word (answer), printing
                the letter in green if it is in the same spot in the guess
                and answer, in yellow if it is in a different spot in the
                guess than in the answer, or in white if it is in the guess
                but not in the answer.    */

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
