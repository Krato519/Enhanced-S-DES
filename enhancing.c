#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define cols_num 3
#define rows_num(sz) (1+((sz-1)/cols))

/* function declaration */
char* sctt(char* plain_text);
char* plain(char* text);

int main () {
   /* local variable definition */
   char *text,*plain_text;

   printf( "Enter a value: ");
   text = (char*)malloc(sizeof(char)*100);
   gets(text);

   plain_text = plain(text);

   text = sctt(plain_text);

   puts(sctt(text));

   return 0;
}

 
/* function returning the max between two numbers */
char* sctt(char* plain_text) {

   const unsigned int transposition[3] = {1,2,0};
   int i;

   unsigned int cols = cols_num;
   unsigned int rows = rows_num(strlen(plain_text));
   char **grid = (char**)malloc(rows * sizeof(char*));
   for (int i = 0; i < rows; i++)
      grid[i] = (char*)malloc(cols * sizeof(char));
   
   i = 0;
   for (int x = 0; x < rows; x++) {
      for (int y = 0; y < cols; y++) {
         if (i<strlen(plain_text)){
            grid[x][y] = plain_text[i];
            i++;
         }
         else{
            grid[x][y] = ' ';
         }
      }
   }

   for (int x = 0; x < rows; x++) {
      for (int y = 0; y < cols; y++) {
         printf("%c ",grid[x][y]);
      }
      printf("\n");
   }
   
   printf("\n");

   char* cipher_text;
   cipher_text = (char*)malloc(sizeof(char)*strlen(plain_text));

   i = 0;
   for (int y = 0; y < cols; y++) {
      for (int x = 0; x < rows; x++) {
         if (grid[x][transposition[y]] != ' '){
            *(cipher_text+i) = grid[x][transposition[y]];
            i++;
         }
      }
   }
   *(cipher_text+i) = '\0';

   return cipher_text;
}

char* plain(char* text){

   char *plain_text;
   int j = 0;

   plain_text = (char*)malloc(sizeof(char)*strlen(text));
   for (int i=0;i<strlen(text);i++){
      if (
         text[i] != ' ' && 
         text[i] != ',' && 
         text[i] != ';' && 
         text[i] != '.' &&
         text[i] != ':' &&
         text[i] != '-' &&
         text[i] != '_' 
      ){
         *(plain_text+j) = text[i];
         j++;
      }
   }
   *(plain_text+j) = '\0';

   return plain_text;
}