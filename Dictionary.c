#include <stdio.h>
int binary[9], selection;
char character;
void ToBinary(char letter){
	switch (letter){
		case 'A': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 0;binary[5] = 0;binary[6] = 0;binary[7] = 1;
					break;
		case 'B': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 0;binary[5] = 0;binary[6] = 1;binary[7] = 0;
					break;
		case 'C': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 0;binary[5] = 0;binary[6] = 1;binary[7] = 1;
					break;
		case 'D': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 0;binary[5] = 1;binary[6] = 0;binary[7] = 0;
					break;
		case 'E': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 0;binary[5] = 1;binary[6] = 0;binary[7] = 1;
					break;
		case 'F': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 0;binary[5] = 1;binary[6] = 1;binary[7] = 0;
					break;
		case 'G': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 0;binary[5] = 1;binary[6] = 1;binary[7] = 1;
					break;
		case 'H': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 1;binary[5] = 0;binary[6] = 0;binary[7] = 0;
					break;
		case 'I': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 1;binary[5] = 0;binary[6] = 0;binary[7] = 1;
					break;
		case 'J': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 1;binary[5] = 0;binary[6] = 1;binary[7] = 0;
					break;
		case 'K': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 1;binary[5] = 0;binary[6] = 1;binary[7] = 1;
					break;
		case 'L': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 1;binary[5] = 1;binary[6] = 0;binary[7] = 0;
					break;
		case 'M': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 1;binary[5] = 1;binary[6] = 0;binary[7] = 1;
					break;
		case 'N': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 1;binary[5] = 1;binary[6] = 1;binary[7] = 0;
					break;
		case 'O': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 0;binary[4] = 1;binary[5] = 1;binary[6] = 1;binary[7] = 1;
					break;
		case 'P': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 1;binary[4] = 0;binary[5] = 0;binary[6] = 0;binary[7] = 0;
					break;
		case 'Q': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 1;binary[4] = 0;binary[5] = 0;binary[6] = 0;binary[7] = 1;
					break;
		case 'R': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 1;binary[4] = 0;binary[5] = 0;binary[6] = 1;binary[7] = 0;
					break;
		case 'S': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 1;binary[4] = 0;binary[5] = 0;binary[6] = 1;binary[7] = 1;
					break;
		case 'T': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 1;binary[4] = 0;binary[5] = 1;binary[6] = 0;binary[7] = 0;
					break;
		case 'U': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 1;binary[4] = 0;binary[5] = 1;binary[6] = 0;binary[7] = 1;
					break;
		case 'V': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 1;binary[4] = 0;binary[5] = 1;binary[6] = 1;binary[7] = 0;
					break;
		case 'W': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 1;binary[4] = 0;binary[5] = 1;binary[6] = 1;binary[7] = 1;
					break;
		case 'X': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 1;binary[4] = 1;binary[5] = 0;binary[6] = 0;binary[7] = 0;
					break;
		case 'Y': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 1;binary[4] = 1;binary[5] = 0;binary[6] = 0;binary[7] = 1;
					break;
		case 'Z': 	binary[0] = 0;binary[1] = 1;binary[2] = 0;binary[3] = 1;binary[4] = 1;binary[5] = 0;binary[6] = 1;binary[7] = 0;
					break;
		case 'a': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 0;binary[5] = 0;binary[6] = 0;binary[7] = 1;
					break;
		case 'b': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 0;binary[5] = 0;binary[6] = 1;binary[7] = 0;
					break;
		case 'c': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 0;binary[5] = 0;binary[6] = 1;binary[7] = 1;
					break;
		case 'd': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 0;binary[5] = 1;binary[6] = 0;binary[7] = 0;
					break;
		case 'e': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 0;binary[5] = 1;binary[6] = 0;binary[7] = 1;
					break;
		case 'f': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 0;binary[5] = 1;binary[6] = 1;binary[7] = 0;
					break;
		case 'g': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 0;binary[5] = 1;binary[6] = 1;binary[7] = 1;
					break;
		case 'h': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 1;binary[5] = 0;binary[6] = 0;binary[7] = 0;
					break;
		case 'i': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 1;binary[5] = 0;binary[6] = 0;binary[7] = 1;
					break;
		case 'j': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 1;binary[5] = 0;binary[6] = 1;binary[7] = 0;
					break;
		case 'k': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 1;binary[5] = 0;binary[6] = 1;binary[7] = 1;
					break;
		case 'l': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 1;binary[5] = 1;binary[6] = 0;binary[7] = 0;
					break;
		case 'm': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 1;binary[5] = 1;binary[6] = 0;binary[7] = 1;
					break;
		case 'n': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 1;binary[5] = 1;binary[6] = 1;binary[7] = 0;
					break;
		case 'o': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 0;binary[4] = 1;binary[5] = 1;binary[6] = 1;binary[7] = 1;
					break;
		case 'p': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 1;binary[4] = 0;binary[5] = 0;binary[6] = 0;binary[7] = 0;
					break;
		case 'q': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 1;binary[4] = 0;binary[5] = 0;binary[6] = 0;binary[7] = 1;
					break;
		case 'r': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 1;binary[4] = 0;binary[5] = 0;binary[6] = 1;binary[7] = 0;
					break;
		case 's': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 1;binary[4] = 0;binary[5] = 0;binary[6] = 1;binary[7] = 1;
					break;
		case 't': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 1;binary[4] = 0;binary[5] = 1;binary[6] = 0;binary[7] = 0;
					break;
		case 'u': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 1;binary[4] = 0;binary[5] = 1;binary[6] = 0;binary[7] = 1;
					break;
		case 'v': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 1;binary[4] = 0;binary[5] = 1;binary[6] = 1;binary[7] = 0;
					break;
		case 'w': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 1;binary[4] = 0;binary[5] = 1;binary[6] = 1;binary[7] = 1;
					break;
		case 'x': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 1;binary[4] = 1;binary[5] = 0;binary[6] = 0;binary[7] = 0;
					break;
		case 'y': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 1;binary[4] = 1;binary[5] = 0;binary[6] = 0;binary[7] = 1;
					break;
		case 'z': 	binary[0] = 0;binary[1] = 1;binary[2] = 1;binary[3] = 1;binary[4] = 1;binary[5] = 0;binary[6] = 1;binary[7] = 0;
					break;
		default :	printf("Letter not recognized.");				
	}
}

void ToLetter(int binary[]){
	selection += binary[7];
	selection += binary[6]*10;
	selection += binary[5]*100;
	selection += binary[4]*1000;
	selection += binary[3]*10000;
	selection += binary[2]*100000;
	selection += binary[1]*1000000;
	switch(selection){
		case 1000001:	character = 'A';
						break;
		case 1000010:	character = 'B';
						break;
		case 1000011:	character = 'C';
						break;
		case 1000100:	character = 'D';
						break;
		case 1000101:	character = 'E';
						break;
		case 1000110:	character = 'F';
						break;
		case 1000111:	character = 'G';
						break;
		case 1001000:	character = 'H';
						break;
		case 1001001:	character = 'I';
						break;
		case 1001010:	character = 'J';
						break;
		case 1001011:	character = 'K';
						break;
		case 1001100:	character = 'L';
						break;
		case 1001101:	character = 'M';
						break;
		case 1001110:	character = 'N';
						break;
		case 1001111:	character = 'O';
						break;
		case 1010000:	character = 'P';
						break;
		case 1010001:	character = 'Q';
						break;
		case 1010010:	character = 'R';
						break;
		case 1010011:	character = 'S';
						break;
		case 1010100:	character = 'T';
						break;
		case 1010101:	character = 'U';
						break;
		case 1010110:	character = 'V';
						break;
		case 1010111:	character = 'W';
						break;
		case 1011000:	character = 'X';
						break;
		case 1011001:	character = 'Y';
						break;
		case 1011010:	character = 'Z';
						break;
		case 1100001:	character = 'a';
						break;
		case 1100010:	character = 'b';
						break;
		case 1100011:	character = 'c';
						break;
		case 1100100:	character = 'd';
						break;
		case 1100101:	character = 'e';
						break;
		case 1100110:	character = 'f';
						break;
		case 1100111:	character = 'g';
						break;
		case 1101000:	character = 'h';
						break;
		case 1101001:	character = 'i';
						break;
		case 1101010:	character = 'j';
						break;
		case 1101011:	character = 'k';
						break;
		case 1101100:	character = 'l';
						break;
		case 1101101:	character = 'm';
						break;
		case 1101110:	character = 'n';
						break;
		case 1101111:	character = 'o';
						break;
		case 1110000:	character = 'p';
						break;
		case 1110001:	character = 'q';
						break;
		case 1110010:	character = 'r';
						break;
		case 1110011:	character = 's';
						break;
		case 1110100:	character = 't';
						break;
		case 1110101:	character = 'u';
						break;
		case 1110110:	character = 'v';
						break;
		case 1110111:	character = 'w';
						break;
		case 1111000:	character = 'x';
						break;
		case 1111001:	character = 'y';
						break;
		case 1111010:	character = 'z';
						break;
	}
}

int main(){
	int i;
	char letter = 'k';
	ToBinary(letter);
	ToLetter(binary);
	return 0;
}