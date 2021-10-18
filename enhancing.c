#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function declaration */
char* sctt(char* plain_text);
char* srs(char* plain_text);
char* plain(char* text);

int main () {

   char *text,*plain_text;

   printf( "Enter a value: ");
   text = (char*)malloc(sizeof(char)*100);
   gets(text);

   plain_text = plain(text);
   text = sctt(plain_text);
   plain_text = plain(text);
   text = sctt(plain_text);
   plain_text = plain(text);
   text = srs(plain_text);
   puts(text);

   return 0;
}
 
/* function returning the Simple Columnar Transposition Cipher Text */
char* sctt(char* plain_text) {

   unsigned int cols = 3;
   unsigned int rows = 1+((strlen(plain_text)-1)/cols);
   const unsigned int transposition[3] = {1,2,0};
   char *cipher_text, **grid;
   int i;

   grid = (char**)malloc(rows * sizeof(char*));
   for (int i = 0; i < rows; i++){
      grid[i] = (char*)malloc(cols * sizeof(char));
   }

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

char* srs(char* plain_text){

   unsigned int rows = 3;
   unsigned int cols = 1+((strlen(plain_text)-1)/rows);
   char *cipher_text, **grid, **shift_grid;
   int i;

   grid = (char**)malloc(rows * sizeof(char*));
   for (int i = 0; i < rows; i++){
      grid[i] = (char*)malloc(cols * sizeof(char));
   }

   i = 0;
   for (int x = 0; x < rows; x++) {
      for (int y = 0; y < cols; y++) {
         if (i<strlen(plain_text)){
            grid[x][y] = plain_text[i];
            i++;
         } else {
            grid[x][y] = ' ';
         }
      }
   }

   shift_grid = (char**)malloc(rows * sizeof(char*));
   for (int i = 0; i < rows; i++){
      shift_grid[i] = (char*)malloc(cols * sizeof(char));
   }

   for (int x = 0; x < rows; x++) {
      for (int y = 0; y < cols; y++) {
         switch (x){
            case 0:
               shift_grid[x][y] = grid[x][y];
               break;
            case 1:
               if (y == cols-1){
                  shift_grid[x][y] = grid[x][0];
               } else {
                  shift_grid[x][y] = grid[1][y+1];
               }
               break;
            case 2:
               if (y == 0){
                  shift_grid[x][y] = grid[2][cols-1];
               } else {
                  shift_grid[x][y] = grid[2][y-1];
               }
               break;
            default:
               break;
         }
      }
   }

   cipher_text = (char*)malloc(sizeof(char)*strlen(plain_text));

   i = 0;
   for (int x = 0; x < rows; x++) {
      for (int y = 0; y < cols; y++) {
         if (shift_grid[x][y] != ' '){
            *(cipher_text+i) = shift_grid[x][y];
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
         text[i] != '_' &&
         text[i] != '!' &&
         text[i] != '?' 
      ){
         *(plain_text+j) = text[i];
         j++;
      }
   }
   *(plain_text+j) = '\0';

   return plain_text;
}