#include <stdio.h>
#include "S-DES.h"
#include "Dictionary.h"
int main(){
	int binary[9], i, result[9];
	char letter = 'a', code;
	ToBinary(letter, binary);
	for(i=0;i<8;i++){
		printf("%d", binary[i]);
	}
	printf("\n%c", code);
	Encrypt(binary, result);
	printf("\n\n");
	for(i=0;i<8;i++){
		printf("%d", result[i]);
	}
	Decrypt(result, result);
	printf("\n\n");
	for(i=0;i<8;i++){
		printf("%d", result[i]);
	}
	printf("\n\n");
	code = ToLetter(result);
	printf("\n%c", code);
	return 0;
}
