#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char word();
void cmp(char[], char[]);
int main()
{
 char answer[6], guess[6], guess1[6], guess2[6], guess3[6], guess4[6], guess5[6], guess6[6];
 int x;
 //seeding random letters
 srand(time(NULL));
 //creating random word
 for(x=0; x<5; x++)
 {
  answer[x]=word();
 }
 //asking for inputs
 printf("word=%s\n", answer);
 printf("Welcome to WORDLE!\nYou have six guesses to get the word. START\n");
 fgets(guess,6,stdin);
 
 //function for color change
 cmp(answer, guess);
 
 return 0;
}

char word()
{
 char x;
 x=rand()%26+97;
 return x;
}

void cmp(char a[], char g[])
{
 int x;
 for(x=0;x<5;x++)
 {
  if(a[x] == g[x])
  {
    printf("\e[1;32m%s, g[x]"); //green font, correct spot
  }
  else if(a[0] == g[x] || a[1] == g[x] || a[2] == g[x] || a[3] == g[x] || a[4] == g[x] )
  {
   printf("\e[1;33m%s, g[x]");  // yellow, good letter, wrong spot
  }
  else 
  {
   printf("\e[0m%s, g[x]"); //white 
  }
 }

 printf("%s\n", g);
}
