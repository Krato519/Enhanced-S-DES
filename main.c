#include <stdio.h>
#include "S-DES.h"
#include "Dictionary.h"
int main(){
	int binary[9], i;
	char letter = 'a', code;
	ToBinary(letter, binary);
	code = ToLetter(binary);
	for(i=0;i<8;i++){
		printf("%d", binary[i]);
	}
	printf("\n%c", code);
	Encrypt(binary);
	return 0;
}
