/*Ben Elleman*/

#include <stdio.h>

#include "define.h"

#include "settings.h"

/*Settings menu function*/
void settings(struct modes *m) {
	static void (*modeFlip[]) (struct modes*) = {freeFlip, speakFlip, alienSpeakFlip, keepFlip,
		gaussFlip, confirmFlip/*, rVSet*/, dTRFlip};
	int choice;
	do {
		if (m->speak) printf("-------\n"
			"0 for free/seq (%d)\t1 for speak/silent (%d)\t 2 for say current alien (%d)\n"
			"3 for save alien (%d)\t4 for Gaussian/linear random (%d)\t5 for confirm printing (%d)\n"
			/*"6 to change rV (%d)\n"*/
			"6 to change defaultToRand (%d)\n-1 to return\n--------\n"
			, m->free, m->speak, m->alienSpeak, m->keep, m->gauss, m->confirm/*, m->rV*/, m->dTR);
		scanf("%d", &choice);
		if (choice  >= 0 && choice < /*8*/ 7) modeFlip[choice](m);
	} while (choice != -1);
}

/*Flips the free setting*/
void freeFlip (struct modes *m) {
	m->free = !m->free;
}

/*Flips the speak setting*/
void speakFlip (struct modes *m) {
	m->speak = !m->speak;
}

/*Flips the alienSpeak setting*/
void alienSpeakFlip (struct modes *m) {
	m->alienSpeak = !m->alienSpeak;
}

/*Flips the keep setting*/
void keepFlip (struct modes *m) {
	m->keep = !m->keep;
}

/*Flips the gauss setting*/
void gaussFlip (struct modes *m) {
	m->gauss = !m->gauss;
}

/*Flips the confirm setting*/
void confirmFlip (struct modes *m) {
	m->confirm = !m->confirm;
}

/*Removed due to the fact that I don't see any practical use for changing the value of the random variable 
 * mid-execution considering it can always be set to something out of the bounds of reasonable input and changing it
 * while having an alien loaded would require a sanity check of every current alienData field, meaning the mode 
 * struct would have to be able to be access and change the alienData struct. Doable, but unnecessary*/
/*Due to this fact the m.rV field could be removed and replaced with the #define if desired*/
/*void rVSet (struct modes *m) {
	printf("-------\nEnter a new random value int:\n-------\n");
	scanf("%d", &m->rV);
}
*/
/*Flips the default to random setting*/
void dTRFlip (struct modes *m) {
	m->dTR = !m->dTR;
}

