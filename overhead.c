/*Ben Elleman*/

#include <stdio.h>

#include "define.h"

#include "overhead.h"

#include "fields.h"
#include "encode.h"
#include "settings.h"
#include "randomness.h"

int main(int argc, char *argv[]) {
	static int (*jT[])(struct alienData*) = {outWrite, colorF, typeF, pointsF, xF, yF, vxF, vyF};
	struct modes m = {NULL, !seq, !silent, sayAlien, save, gaussRand, safety, randValue, defaultToRand};
	struct alienData aD = m.dTR ? (struct alienData) {&m, m.rV, m.rV, m.rV, m.rV, m.rV, m.rV, m.rV} 
		: (struct alienData) {&m};
	if (argc < 2) printf("Must include output file\n");
	else {
		m.output = fopen(argv[1], "w");
		/*If free is 1 do freeAcc else do sequential. If either of those functions return with a value that is
		 *not -1, call settings*/
		while ((m.free ? freeAcc(&aD, jT) : seqAcc(&aD, jT)) != -1) settings(&m);
		fclose(m.output);
	}
	return EXIT_SUCCESS;
}

/*Function that allows free access to any alien fields*/
int freeAcc(struct alienData *aD, int (*jT[])(struct alienData*)) {
	int input;
	do {
		if (aD->m->speak) printf("-------\n0 for settings\n1 to write\n"
			"2 for color, 3 for type, 4 for points\n"
			"5 for X, 6 for Y, 7 for VX, 8 for VY\n\n-1 to input\n-------\n");
		if (aD->m->alienSpeak) alienPrint(aD);
		scanf("%d", &input);
		if (input > 0 && input < 9) {
			/*If function returns 2 i.e. alien printed and keep is off overwrite current alien*/
			if ((jT[input - 1](aD)) == 2 && !aD->m->keep) clearStruct(aD);
		}
	} while (input > 0);
	return input;
}

/*Function that gives sequential access to alien fields*/
int seqAcc(struct alienData *aD, int (*jT[])(struct alienData*)) {
	int quit;
	do {
		quit = 1;
		while (quit < 9) {
			/*If function returns 2 i.e. alien printed and keep is off overwrite current alien*/
			if ((jT[quit % 8](aD)) == 2 & !aD->m->keep) clearStruct(aD);
			/*Since the user has to enter a value for every field and in short succession, I decided
			 * that it would be best not to display the current alien*/
			quit++;
		}	
		if(aD->m->speak) printf("-------\nEnter -1 to quit, 0 for settings, and enter any other int to"
			" continue\n-------\n");
		scanf("%d", &quit);
	} while (quit > 0);
	return quit;
}

/*Writes alien to output file*/
int outWrite(struct alienData *aD) {
	int asking;
	static int alienCount = 0;
	if (aD->m->confirm) {
		if (aD->m->speak) printf("-------\nConfirm that you'd like to print the following alien:\n\n");
		alienPrint(aD);
		if (aD->m->speak) printf("\n0 for no, any other int for yes\n-------\n");
		scanf("%d", &asking);
		if (!asking) return 0;
	}
	fprintf(aD->m->output, "%X %lf %lf %lf %lf\n", alienHex(aD), aD->x - aD->m->rV ? aD->x : aRandX(aD->m->gauss)
		, aD->y - aD->m->rV ? aD->y : aRandY(aD->m->gauss), aD->vX - aD->m->rV ? aD->vX : 
		aRandVX(aD->m->gauss), aD->vY - aD->m->rV ? aD->vY : aRandVY(aD->m->gauss));
	alienCount++;
	if (aD->m->speak) printf("-------\nAlien printed, %d total\n-------\n", alienCount);
	return 2;
}

/*Clears the aD struct sans the modes struct pointer*/
void clearStruct(struct alienData *aD) {
	struct alienData mPointer = aD->m->dTR ? (struct alienData){aD->m, aD->m->rV, aD->m->rV, aD->m->rV, aD->m->rV
		, aD->m->rV, aD->m->rV, aD->m->rV} : (struct alienData) {aD->m};
	*aD = mPointer;
}

/*Shows the current alien data*/
void alienPrint(const struct alienData *aD) {
	printf("-------\nCOLOR:");
	printf(aD->color == aD->m->rV ? "RAND" : aD->color == 1 ? "RED" : aD->color == 2 ? "GREEN" : aD->color == 3
		? "YELLOW": aD->color == 4 ? "BLUE" : aD->color == 5 ? "PURPLE" : aD->color==6 ? "LIGHT BLUE" : 
		"WHITE");
	printf("\tTYPE:");
	printf(aD->type == aD->m->rV ? "RAND" :aD->type == 0 ? "CONEHEAD" : aD->type == 1 ? "GERALD" : aD->type == 2
		? "SQUID" : aD->type == 3 ? "UFO" : "BOMB"); 
	printf("\tPOINTS:%d\nX:%lf\tY:%lf\tVX:%lf\tVY:%lf\nRAND VALUE:%d\n-------\n", 
		aD->points, aD->x, aD->y, aD->vX, aD->vY, aD->m->rV);
}

