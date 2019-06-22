//Bit converting program

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 128

int toBinary(int decimal);
int getline(char s[], int lim);
int main() {

	int decimalNum;
	int binaryNum;
	int complementBin;
	char complementDec;
	char buffer[MAX];
	printf("Type in a decimal number: \n");

	getline(buffer, MAX);		//getting input
	decimalNum = atoi(buffer);	//converting the char input to integer

	printf("Input: %d\n", decimalNum);
	binaryNum = toBinary(decimalNum);	//converting the decimal to binary
	printf("Output: %d\n", binaryNum);

	complementDec = itoa(binaryNum, buffer, 2);
	printf("%s", complementDec);

	printf("Explanation: %d is '%d' in binary, with complement '%d' in binary which is '%d' in base-10", decimalNum, binaryNum, complementBin, complementDec);

	getchar();
	return 0;
}

int getline(char s[], int lim)		//getline for the input
{
	int i, c;
	for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i) s[i] = c;
	s[i] = '\0';
	while (c != EOF && c != '\n') c = getchar();
	return i;
}

//Convert a number to binary
int toBinary(int decimal) {
	//If the number is '0' or '1'
	if (decimal < 2) {	
		return decimal;
	}
	// Recursive, so always going until there are '1'-s or '0'-s
	return toBinary(decimal / 2) * 10 + decimal % 2;
}
