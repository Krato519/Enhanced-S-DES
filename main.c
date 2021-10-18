#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "S-DES.h"
#include "Dictionary.h"
#include "enhancing.h"

int main(){

	int binary[9], i, result[9], j, k;
	char *text,*plain_text,*cipher_text,*decrypted_text,letter, code;

	printf( "Enter a value: ");
	text = (char*)malloc(sizeof(char)*500);
	gets(text);
	
	/* Text Encryption with Enhancing section of E-S-DES  */
	plain_text = plain(text);
	cipher_text = sctt(plain_text);
	cipher_text = sctt(cipher_text);
	cipher_text = srs(cipher_text);
	int cipher_message[strlen(plain_text)][8];
	decrypted_text = (char*)malloc(sizeof(char)*500);
	/* Initialization of 2D array for cipher message  */
	/*cipher_message = (int**)malloc(strlen(cipher_text) * sizeof(int*));
	for (j = 0; j < strlen(cipher_text); j++){
		cipher_message[j] = (int*)malloc(sizeof(char) * sizeof(int));
	}*/
	/* Letter by Letter Encryption with S-DES  */
	for (j=0;j<strlen(plain_text);j++) {
		
		letter = cipher_text[j];
		ToBinary(letter, binary);
		//printf("\n\nbinary array:\t");
		/*for(i=0;i<8;i++){
			printf("%d", binary[i]);
		}*/
		
		Encrypt(binary, result);
		printf("\n\n");	
		for (k=0;k<8;k++) {
			cipher_message[j][k] = result[k];
			printf("%d", cipher_message[j][k]);
		}

		printf("\n\n");
		/*for(i=0;i<8;i++){
			printf("%d", result[i]);
		}*/
	}

	/* Letter by Letter Decryption with S-DES  */
	for (j=0;j<strlen(plain_text);j++) {
		
		for (k=0;k<8;k++) {
			result[k] = cipher_message[j][k];
		}

		Decrypt(result, result);

		printf("\n\n");
		for(i=0;i<8;i++){
			printf("%d", result[i]);
		}
		printf("\n\n");

		code = ToLetter(result);
		decrypted_text[j] = code;
		printf("\n%c", code);
	}
	decrypted_text[strlen(cipher_text)] = '\0';
	
	decrypted_text = inv_srs(decrypted_text);
	decrypted_text = inv_sctt(decrypted_text);
	decrypted_text = inv_sctt(decrypted_text);

	return 0;
}
