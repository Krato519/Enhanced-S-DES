#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/* Simple Columnar Transposition Technique */
char* sctt(char* plain_text) {

   /* Variables for table, transposition and cipher text */
   unsigned int cols = 3;
   unsigned int rows = 1+((strlen(plain_text)-1)/cols);
   const unsigned int transposition[3] = {1,2,0};
   char *cipher_text, **grid;
   int i;

   /* Initialization of 2D array for transposition table  */
   grid = (char**)malloc(rows * sizeof(char*));
   for (int i = 0; i < rows; i++){
      grid[i] = (char*)malloc(cols * sizeof(char));
   }

   /* Setting of transposition table */
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

   /* Inicialization of array for Cipher text */
   cipher_text = (char*)malloc(sizeof(char)*strlen(plain_text));

   /* Setting of Cipher text */
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

   /* Printing of Transposition table */
   puts("Table for columnar transposition");
   for (int x = 0; x < rows; x++) {
      for (int y = 0; y < cols; y++) {
         printf("%c ",grid[x][y]);
      }
      printf("\n");
   }

   /* Printing of Cipher text */
   puts("");
   puts("Simple Columnar Transposition Technique");
   puts(cipher_text);
   puts("");

   return cipher_text;
}

/* Shift Row Stage */
char* srs(char* plain_text) {

   /* Variables for rows and cipher text */
   unsigned int rows = 3;
   unsigned int cols = 1+((strlen(plain_text)-1)/rows);
   char *cipher_text, *row, temp;
   int i,k;

   /* Table is not actually created but its 3 rows as separated strings */

   /* Inicialization of array for rows creation and array for Cipher text */
   cipher_text = (char*)malloc(strlen(plain_text) * sizeof(char));
   row = (char*)malloc((cols+1) * sizeof(char));
   
   /* Part of the printing of the table representation*/
   puts("Table with shifted rows");
   
   /* Setting loop */
   i = k = 0;
   for (int y = 0; y < rows; y++) {

      /* Setting of rows */
      for (int x = 0; x < cols; x++) {
         *(row+x) = plain_text[i];
         i++;
         if (x == cols-1 || plain_text[i] == '\0') {
            *(row+(x+1)) = '\0';
            break;
         }
      }

      /* Shifting of rows */
      switch (y) {
         case 1:
            temp = row[0];
            for (int j = 0; j < strlen(row); j++)
               row[j] = row[j + 1];
            row[strlen(row)] = temp;
            break;
         case 2:
            temp = row[strlen(row)-1];
            for (int j = strlen(row)-1; j > 0; j--){
               row[j] = row[j - 1];
            }
            row[0] = temp;
            break;
         default:
            break;
      }

      /* Printing of table representation */
      for (int j=0;j<strlen(row);j++) {
         printf("%c ",row[j]);
      }
      printf("\n");

      /* Setting of Cipher text */
      for (int j=0;j<strlen(row);j++) {
         *(cipher_text+k) = row[j];
         k++;
      }

      /* Breaking loop when 3 rows have been processed */
      if (plain_text[i] == '\0') {
         break;
      }
   }
   *(cipher_text+k) = '\0';

   /* Printing of Cipher text */
   puts("");
   puts("Shift Rows Stage");
   puts(cipher_text);
   puts("");

   return cipher_text;
}

/* Text plaining */
char* plain(char* text) {

   /* Variables for plain text */
   char *plain_text;
   int j = 0;

   /* Inicialization of array for Plain text */
   plain_text = (char*)malloc(sizeof(char)*strlen(text));

   /* Setting of Plain text */
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

   /* Printing of Plain text */
   puts("");
   puts("Plained text");
   puts(plain_text);
   puts("");

   return plain_text;
}