#include <stdio.h>
int key[11] = {1,0,1,0,0,0,0,0,1,0}, key_p10[11], key_p10_LS1[11], key_p10_LS2[11], subkey1[9], 
subkey2[9], plaintext[9] = {1,2,3,4,5,6,7,8}, left[5], right[5], ciphertext[9], iptext[9], inverse_ip[9];
void P10(int key[], int key_p10[]){
	int i;
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
	printf("\n\n");
	for(i=0;i<10;i++){
		printf("%d", key_p10[i]);	
	}
}

void LS_1(int key_p10[], int key_p10_LS1[]){
	printf("LS1 working...");
	int temp, i;
	temp = key_p10[0];
	for(i=0; i<4; i++){
		key_p10_LS1[i] = key_p10[i+1];
	}
	key_p10_LS1[4] = temp;
	temp = key_p10[5];
	for(i=5; i<9; i++){
		key_p10_LS1[i] = key_p10[i+1];
	}
	key_p10_LS1[9] = temp;
	printf("\n\n");
	for(i=0;i<10;i++){
		printf("%d", key_p10_LS1[i]);	
	}
}

void LS_2(int key_p10_LS1[], int key_p10_LS2[]){
	printf("LS2 working...");
	int temp1, temp2, i;
	temp1 = key_p10_LS1[0];
	temp2 = key_p10_LS1[1];
	for(i=0; i<3; i++){
		key_p10_LS2[i] = key_p10_LS1[i+2];
	}
	key_p10_LS2[3] = temp1;
	key_p10_LS2[4] = temp2;
	temp1 = key_p10_LS1[5];
	temp2 = key_p10_LS1[6];
	for(i=5; i<8; i++){
		key_p10_LS2[i] = key_p10_LS1[i+2];
	}
	key_p10_LS2[8] = temp1;
	key_p10_LS2[9] = temp2;
	printf("\n\n");
	for(i=0;i<10;i++){
		printf("%d", key_p10_LS2[i]);	
	}
}
void P8(int key[], int subkey[]){
	int i;
	printf("Generating subkey");
	subkey[0] = key[5];
	subkey[1] = key[2];
	subkey[2] = key[6];
	subkey[3] = key[3];
	subkey[4] = key[7];
	subkey[5] = key[4];
	subkey[6] = key[9];
	subkey[7] = key[8];
	printf("\n\n");
	for(i=0;i<8;i++){
		printf("%d", subkey[i]);	
	}
}
void SubkeyGeneration(int key[]){
	int i;
	printf("Original key:\n\n");
	for(i=0;i<10;i++){
		printf("%d", key[i]);	
	}
	printf("\n\n");
	P10(key, key_p10);
	printf("\n\n");
	LS_1(key_p10, key_p10_LS1);
	printf("\n\n");
	LS_2(key_p10_LS1, key_p10_LS2);
	printf("\n\n");
	P8(key_p10_LS1, subkey1);
	printf("\n\n");
	P8(key_p10_LS2, subkey2);
	printf("\n\n");
}
void IP(int text[]){
	printf("Initial permutation...");
	int i;
	iptext[0] = text[1];
	iptext[1] = text[5];
	iptext[2] = text[2];
	iptext[3] = text[0];
	iptext[4] = text[3];
	iptext[5] = text[7];
	iptext[6] = text[4];
	iptext[7] = text[6];
	printf("\n\n");
	for(i=0;i<8;i++){
		printf("%d", iptext[i]);
	}
}
void Inverse_IP(int text[]){
	printf("\n\n");
	printf("Undoing initial permutation...");
	int i;
	inverse_ip[0] = text[3];
	inverse_ip[1] = text[0];
	inverse_ip[2] = text[2];
	inverse_ip[3] = text[4];
	inverse_ip[4] = text[6];
	inverse_ip[5] = text[1];
	inverse_ip[6] = text[7];
	inverse_ip[7] = text[5];
	printf("\n\n");
	for(i=0;i<8;i++){
		printf("%d", inverse_ip[i]);
	}
}
int main(){
	SubkeyGeneration(key);
	IP(plaintext);
	Inverse_IP(iptext);
	return 0;
}


