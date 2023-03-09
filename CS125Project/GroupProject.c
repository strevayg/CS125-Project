#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//git commit -a
// i, insert declaration, :wq
// git push and you enter log in shit 

// functions declaration
char word();
void cmp(char[], char[]);

int main()
{
 FILE *ptr= fopen("prowords.txt", "r");
 char answer[6], guess[6];
 int x;
 //seeding random letters
 srand(time(NULL));
 //creating random word
 x= rand()%25+1;
 fscanf(ptr, "%s", answer);
 //asking for inputs
 printf("word=%s\n", answer);
 printf("Welcome to WORDLE!\nYou have six guesses to get the word. START\n");
 fgets(guess,6,stdin);
 
 //function for color change
 cmp(answer, guess);
 
 return 0;
}
//fixed

// function to create a word 
char word()
{
 char x;
 x=rand()%26+97;
 return x;
}
// function to compare guess and answer and change it accordingly color wise
void cmp(char a[], char g[])
{
 int x;
 for(x=0;x<=5;x++)
 {
  if(a[x] == g[x])
  {
    printf("\e[1;32m%c", g[x]); //green font, correct spot
  }
  else if(a[0] == g[x] || a[1] == g[x] || a[2] == g[x] || a[3] == g[x] || a[4] == g[x] )
  {
   printf("\e[1;33m%c", g[x]);  // yellow, good letter, wrong spot
  }
  else 
  {
   printf("\e[0m%c", g[x]); //white 
  }
 }

 //printf("%s\n", g);
}
