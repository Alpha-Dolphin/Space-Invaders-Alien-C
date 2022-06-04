/*Ben Elleman*/

#include <stdio.h>
#include <stdlib.h>

#include "define.h"

#include "encode.h"

/*Generate the hex number to output*/
int alienHex(const struct alienData* aD) {
	int result = 0;
	result = result | encodePoints(aD->points - aD->m->rV ? aD->points : rand() % 50 * 10);
	/*randType could be changed to mod 4 to disallow the random assignment of bombs*/
	result = result | encodeType(aD->type - aD->m->rV ? aD->type : rand() % 5);
	result = result | encodeColor(aD->color - aD->m->rV ? aD->color : rand() % 6 + 1);
	return result;
}

/*Function to encode alien points to hexdata*/
int encodePoints(int data) {
        /*Bitwise & data to appropiate bit size and shift right to properly align*/
        int ptc = (data & 0b111111111) << 20;
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
	int ptc = (data & 0b111) << 4;
        return ptc;
}

