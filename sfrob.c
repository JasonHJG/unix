#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int compare(void const* first, void const* second)
{

  const char *w1 = *((const char**) first);
  const char *w2 = *((const char**) second);
  int i= 0;

  while((w1[i] != ' ' && w2[i] != ' ') && w1[i] == w2[i])
    i++;

  return (w1[i] ^ 42) - (w2[i] ^ 42);
      
}

void errMsg()
{
  fprintf(stderr, "Memory allocation error.\n");
  exit(1);
}


int main(int argc, char **argv)
{
  char holder;
  int charCount=0;
  int wordCount=0;
  char* word= malloc(charCount * sizeof(char));
  char** words= malloc(wordCount * sizeof(char*));

  //read the line

  while((holder=getchar())!=EOF)
    {
    
     
      //if read in char
      if (holder!=' ')
	{
	  charCount++;
	  word=realloc(word, charCount * sizeof(char));

	  if(!word)
	    errMsg();

	  word[charCount-1]=holder;

	}

      //if read in ' '
      else
	{
	  //if read in start of a line
	  if(wordCount==0 && charCount==0)
	    continue;
	  else
	    {
	      //first attach ' '
	      charCount++;
	      word=realloc(word, charCount * sizeof(char));

	      if(!word)
		errMsg();

	      word[charCount-1]=' ';

	      //reloc the memory
	      charCount=0;
	      wordCount++;
	      words= realloc(words, wordCount * sizeof(char*));

	      if(!words)
		errMsg();

	      words[wordCount-1] = word;


	      //clear the word pointer
	      word=malloc(0);
	    }

	  //or it is the first char of a line
	  
	    

	} 
  } 



  //end of line
  if(charCount!=0 && word[charCount-1]!=' ')
    {
      charCount++;
      word=realloc(word, charCount * sizeof(char));

      if(!word)
	errMsg();

      word[charCount-1]=' ';

      wordCount++;
      words= realloc(words, wordCount * sizeof(char*));

      if(!words)
	errMsg();

      words[wordCount-1] = word;


    }



  //sort
  qsort(words, wordCount, sizeof(char*), compare);


  int i;
  for (i=0; i!=wordCount; i++)
    {
      char* ptr=words[i];
      while(*ptr != ' ')
	{
	  printf("%c",*ptr);
	  ptr++;
	}
      printf("%c",*ptr);

    }

  //free memory
  if(words)
    {
      int i;
      for(i = 0; i < wordCount; i++)
	free(words[i]);
      free(words);

    }

  exit(0);

}
