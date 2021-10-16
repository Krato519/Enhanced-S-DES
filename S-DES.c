#include <stdio.h>
int main(){
	int key[11] = {1,0,1,0,0,0,0,0,1,0}, key_p10[11], key_p10_LS1[11], key_p10_LS2[11];
	int i;
	for(i=0;i<10;i++){
		printf("%d", key[i]);	
	}
	printf("\n\n");
	P10(key, key_p10);
	printf("\n\n");
	for(i=0;i<10;i++){
		printf("%d", key_p10[i]);	
	}
	return 0;
}

void P10(int key[], int key_p10[]){
	printf("P10 working...");
	key_p10[0] = key[2];
	key_p10[1] = key[4];
	key_p10[2] = key[1];
	key_p10[3] = key[6];
	key_p10[4] = key[3];
	key_p10[5] = key[9];
	key_p10[6] = key[0];
	key_p10[7] = key[8];
	key_p10[8] = key[7];
	key_p10[9] = key[5];
}

void LS_1(int key_p10[]){
	
}


