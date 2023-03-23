#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "color.h"
#include "define.h"

//git commit -a
// i, insert declaration, :wq
// git push and you enter log in shit 

// functions declaration
char word ();
void correct();
void cmp (char[], char[]);

int
main ()
{
  FILE *ptr = fopen ("prowords.txt", "r");
  char answer[6], guess[50];
  int x, y, i;			// x is successful scans, y is rand number, i is incrementing
  char words[SIZE][6];		//array storing all the words from prowords.txt

  //seeding and variable for random word from list
  srand (time (NULL));
  y = rand () % 489;

  //creating array of 5 letter words from prowords.txt (fileIO)
  do
    {
      x = fscanf (ptr, "%s", words[i]);
      if (x > 0)
	{
	  //printf("read: %s\n", words[i]); //shows if all were scanned in (yes)
	  i++;
	}
    }
  while (x > 0);
  fclose (ptr);

  //getting "answer" word for the game
  strcpy (answer, words[y]);

  //asking for inputs
  printf ("word=%s\n", answer);	//simply shows "answer" word DELETE LINE LATER

  printf
    ("Welcome to WORDLE!\nYou have six guesses to get the word.\nIt is 5 letters.\nSTART\n");
  for (i = 1; i < 7; i++)
    {

      fgets (guess, 50, stdin);
      guess[strcspn(guess,"\n")] = 0;
      while(strlen(guess) != 5) //guess length is 6 bc newline or null(?) FIX PORTION BELOW
      { 
        printf("Not 5 letters\nTry again\n\n");
        fgets (guess, 50, stdin);
        guess[strcspn(guess,"\n")] = 0;
      } 
      for(x=0; x<6; x++)
      {
        guess[x]= tolower(guess[x]);
      }
      guess[5] = '\0';
      //printf("Guess #%d: \"%s\"",i,guess);

      //function for color change
      cmp (answer, guess);

      if (strncmp (guess, answer, 5) == 0)
      {
        correct();
	    break;
	  }
      if(i==6)
      {
        printf("You did not guess the word.\nThe word was %s\n", answer);
      }
    }
  return 0;
}

void correct()
{
   printf("CONGRATS! You guessed it!\n");
}

// FUNCTION to compare guess and answer and change it accordingly color wise

/* 
void cmp (char a[], char g[])
{
  int x;
  for (x = 0; x <= 5; x++)
    {
      if (a[x] == g[x])
	{
	  printf ("\e[1;32m%c", g[x]);	//green font, correct spot
	}
      else if (a[0] == g[x] || a[1] == g[x] || a[2] == g[x] || a[3] == g[x]
	       || a[4] == g[x])
	{
	  printf ("\e[1;33m%c", g[x]);	// yellow, good letter, wrong spot
	}
      else
	{
	  printf ("\e[0m%c", g[x]);	//white 
	}
    }
  printf ("\e[0m\n");
  printf ("\n");
}
 */
