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
  int x, y, spots[5]={0,0,0,0,0}, color[5]={0,0,0,0,0};
  for (x = 0; x < 5; x++)
    {
      if (a[x] == g[x])
      {
        spots[x]=1;
        color[x]=1;
      }
    }
    for(y=0; y<5; y++) //go through user guess letters
    {
      if (color[y] != 0)
      {  
        continue;        //move on to the next letter in guess
      }
      for(x=0;x<5;x++) //go through solution letters and compare with guess
      {
      if (y==x)  //you already compared guess with same position in solution
        {          //in the for loop where you added 1's for correct match in correct position
         continue;
        }
        else if (g[y]==a[x]) //a guess letter matched a solution letter
        {
          if (spots[x] != 0)
          { //the match is for a letter you already gave feedback on
          continue;         //move on to the next possible solution letter
          }
          spots[x]=1;
          color[y]=2;
          break;
        }
      } 
    }  
    for (x = 0; x <= 5; x++)
    {
      if (color[x]==1)
      {
        printf ("\e[1;32m%c", g[x]);  //green font, correct spot
      }
      else if (color[x]==2)
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
