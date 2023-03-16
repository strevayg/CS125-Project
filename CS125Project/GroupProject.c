#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 488
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
 int x,y,i;
 char words[SIZE][6]; //array storing all the words 
 
 //seeding random letters
 srand(time(NULL));
 //creating random word
 
 y= rand()%489;
 do
 {
  x= fscanf(ptr, "%s", words[i]);
  if(x > 0)
  {
   //printf("read: %s\n", words[i]);
   i++;
  }
 }
 while(x > 0);
 fclose(ptr);

 printf("%s\n", words[y]);
 //getting answer word
 strcpy(answer, words[y]);


 //asking for inputs
 printf("word=%s\n", answer);
 printf("Welcome to WORDLE!\nYou have six guesses to get the word. START\n");
 fgets(guess,6,stdin);
 
 //function for color change
 cmp(answer, guess);
 
 return 0;
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
