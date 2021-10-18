#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "enhancing.h"

int main () {

   char *text,*plain_text;

   printf( "Enter a value: ");
   text = (char*)malloc(sizeof(char)*500);
   gets(text);

   plain_text = plain(text);
   plain_text = sctt(plain_text);
   plain_text = sctt(plain_text);
   plain_text = srs(plain_text);
   plain_text = inv_srs(plain_text);
   plain_text = inv_sctt(plain_text);
   plain_text = inv_sctt(plain_text);

   return 0;
}