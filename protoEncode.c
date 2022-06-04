/*Ben Elleman*/

#include <stdio.h>

#include "define.h"

#include "protoEncode.h"

int main() {
	struct alienData aD = {NULL, 15, 2, 3, 4, 5, 6, 7};
	int result = 0;
	result = alienHex(&aD);
	return EXIT_SUCCESS;
}


/*Generate the hex number to output*/
int alienHex(const struct alienData* aD) {
	int result = 0;
	result = result | encodePoints(aD->points);
	result = result | encodeType(aD->type);
	result = result | encodeColor(aD->color);
	printf("%X\n", result);
	return result;
}

/*Function to encode alien points to hexdata*/
int encodePoints(int data) {
        /*Bitwise & data to appropiate bit size and shift right to properly align*/
        int ptc = (data & 0b111111111) << 20;
	printf("%d\n", ptc);
        return ptc;
}

/*Function to encode alien type to hexdata*/
int encodeType(int data) {
        /*Bitwise & data to appropiate bit size and shift right to properly align*/
        int ptc = (data & 0b111) << 12;
        return ptc;
}

/*Function to encode alien color to hexdata*/
int encodeColor(int data) {
        /*Bitwise & data to make appropiate bit size and shift right to properly align*/
        int ptc = (data & 0b111) << 3;
        return ptc;
}

