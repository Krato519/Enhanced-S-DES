#include <stdio.h>
int key[11] = {0,1,0,0,0,0,0,0,0,1}, key_p10[11], key_p10_LS1[11], key_p10_LS2[11], subkey1[9], 
subkey2[9], plaintext[9], left[5], right[5], ciphertext[9], iptext[9], 
inverse_ip[9], xor_result[5], first[5], second[5], map_result[5], expansion[9], 
SK_add1[5], SK_add2[5], S0[5][5]={{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}},
S1[5][5]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}}, row, column, Sbox_result[5], s_decimal, s_binary[3];
int text[9] = {0,1,0,0,0,0,0,1};
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

void XOR(int first[], int second[]){
	int i;
	for(i=0;i<4;i++){
		if(first[i] != second[i])
			xor_result[i] = 1;
		else
			xor_result[i] = 0;
	}
}

void SW(int text[]){
	printf("\n\n");
	printf("Switch operation working...");
	int temp[5], i;
	temp[0] = text[0];
	temp[1] = text[1];
	temp[2] = text[2];
	temp[3] = text[3];
	for(i=0;i<4;i++){
		text[i] = text[i+4];
	}
	text[4] = temp[0];
	text[5] = temp[1];
	text[6] = temp[2];
	text[7] = temp[3];
	printf("\n\n");
	for(i=0;i<8;i++){
		printf("%d", text[i]);
	}
}

void fk(int iptext[], int subkey[]){
	printf("\n\n");
	printf("fk function being applied...");
	int i;
	for(i=0;i<4;i++){
		first[i] = iptext[i];
	}
	for(i=0;i<4;i++){
		second[i] = iptext[i+4];
	}
	F_mapping(second, subkey);
	XOR(first, map_result);
	for(i=0;i<4;i++){
		first[i] = xor_result[i];
	}
	for(i=0;i<8;i++){
		if(i<4)
			ciphertext[i] = first[i];
		else
			ciphertext[i] = second[i-4];
	}
	printf("\n\n");
	printf("fk result:");
	printf("\n\n");	  
	for(i=0;i<8;i++){
		printf("%d", ciphertext[i]);
	}
}

void EP(int expansion[], int R[]){
	int i;
	printf("\n\nExpanding Right side...");
    expansion[0] = R[3];
    expansion[1] = R[0];
    expansion[2] = R[1];
    expansion[3] = R[2];
    expansion[4] = R[1];
    expansion[5] = R[2];
    expansion[6] = R[3];
    expansion[7] = R[0];
    printf("\n\n");
    for(i=0;i<8;i++){
    	printf("%d", expansion[i]);
	}
}

void binaryTodecimal(int binary[]){
		if(binary[0] == 0){
			if(binary[3] == 0){
				row = 0;
			}else{
				row = 1;
			}
		}else{
			if(binary[3] == 0){
				row = 2;
			}else{
				row = 3;
			}
		}
		if(binary[1] == 0){
			if(binary[2] == 0){
				column = 0;
			}else{
				column = 1;
			}
		}else{
			if(binary[2] == 0){
				column = 2;
			}else{
				column = 3;
			}
		}
}

void decimalToBinary(int decimal){
	switch (decimal){
		case 0:	s_binary[0] = 0; s_binary[1] = 0;
				break;
		case 1:	s_binary[0] = 0; s_binary[1] = 1;
				break;
		case 2:	s_binary[0] = 1; s_binary[1] = 0;
				break;
		case 3:	s_binary[0] = 1; s_binary[1] = 1;
				break;
	}
		
}

void P4(int sbox[]){
	printf("\n\nPermutating sbox result values...");
	int i;
	map_result[0] = sbox[1];
	map_result[1] = sbox[3];
	map_result[2] = sbox[2];
	map_result[3] = sbox[0];
	printf("\n\n");
	printf("F mapping result:");
	printf("\n\n");
	for(i=0;i<4;i++){
		printf("%d",map_result[i]);
	}
}

void F_mapping(int R[], int SK[]){
	int xor1[5], xor2[5], xor_subkey1[5], xor_subkey2[5], i;
	EP(expansion, R);
	for(i=0;i<8;i++){
		if(i<4)
			xor_subkey1[i] = SK[i];
		else
			xor_subkey2[i-4] = SK[i];
	}
	for(i=0;i<8;i++){
		if(i<4)
			xor1[i] = expansion[i];
		else
			xor2[i-4] = expansion[i];
	}
	XOR(xor1, xor_subkey1);
	for(i=0;i<4;i++){
		SK_add1[i] = xor_result[i];
	}
	XOR(xor2, xor_subkey2);
	for(i=0;i<4;i++){
		SK_add2[i] = xor_result[i];
	}
	binaryTodecimal(SK_add1);
	s_decimal = S0[row][column];
	decimalToBinary(s_decimal);
	Sbox_result[0] = s_binary[0];
	Sbox_result[1] = s_binary[1];
	binaryTodecimal(SK_add2);
	s_decimal = S1[row][column];
	decimalToBinary(s_decimal);
	Sbox_result[2] = s_binary[0];
	Sbox_result[3] = s_binary[1];
	P4(Sbox_result);
}

void Encrypt(int text[]){
	int i;
	for(i=0;i<8;i++){
		plaintext[i] = text[i];
	}
	SubkeyGeneration(key);
	IP(plaintext);
	fk(iptext, subkey1);
	SW(ciphertext);
	fk(ciphertext, subkey2);
	Inverse_IP(ciphertext);
	printf("\n\n");
	printf("Ciphertext:\t");
	for(i=0;i<8;i++){
		printf("%d", inverse_ip[i]);
	}
}

void Decrypt(int text[]){
	int i;
	SubkeyGeneration(key);
	IP(text);
	fk(iptext, subkey2);
	SW(ciphertext);
	fk(ciphertext, subkey1);
	Inverse_IP(ciphertext);
	printf("\n\n");
	printf("Plaintext:\t");
	for(i=0;i<8;i++){
		printf("%d", inverse_ip[i]);
	}
}



