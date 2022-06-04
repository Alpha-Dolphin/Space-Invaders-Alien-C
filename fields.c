/*Ben Elleman*/

#include <stdio.h>

#include "define.h"

#include "fields.h"

/*Function to collect user input for color*/
int colorF(struct alienData *aD){
	if (aD->m->speak) printf("-------\n0 for red, 1 for green, 2 for yellow, 3 for blue,\n"
		"4 for purple, 5 for light blue, 6 for white\n-------\n");
	do scanf("%d", &(aD->color));
	while (aD->m->rV != aD->color && (aD->color < 0 || aD->color > 6));
	/*Since for some reason numbering starts at 1 for color*/
	if (aD->m->rV != aD->color) aD->color++;
	return 1;
}

/*Function to collect user input for type*/
int typeF(struct alienData *aD){
	/*I don't know what the one alien is, so I just call him Gerald*/
	if (aD->m->speak) printf("-------\n0 for conehead, 1 for Gerald, 2 for squid, 3 for ufo, 4 for bomb\n"
		"-------\n");
	do scanf("%d", &(aD->type));
	while (aD->m->rV != aD->type && (aD->type < 0 || aD->type > 4));
	return 1;
}

/*Function to collect user input for points*/
int pointsF(struct alienData *aD){
	if (aD->m->speak) printf("-------\nEnter a positive point value between 0 and 511\n-------\n");
	do scanf("%d", &(aD->points));
	while (aD->m->rV != aD->points && (aD->points < 0 || aD->points > 511));
	return 1;
}

/*Function to collect user input for x*/
int xF(struct alienData *aD){
	if (aD->m->speak) printf("-------\nEnter an x value between 0.0 and +-40.0\n-------\n");
	do scanf("%lf", &(aD->x));
	/*Only forcing a hard limit on values since the simulation will freak out every frame otherwise*/
	while (aD->m->rV != aD->x && (aD->x < -40.0 || aD->x > 40.0));
	return 1;
}

/*Function to collect user input for y*/
int yF(struct alienData *aD){
	if (aD->m->speak) printf("-------\nEnter a y value between 0.0 and 40.0\n-------\n");
	do scanf("%lf", &(aD->y));
	/*Only forcing a hard limit on values since the simulation will freak out every frame otherwise*/
	while (aD->m->rV != aD->y && (aD->y < -0.0 || aD->y > 40.0));
	return 1;
}

/*Function to collect user input for vX*/
int vxF(struct alienData *aD){
	if (aD->m->speak) printf("-------\nEnter any vx value\n-------\n");
	scanf("%lf", &(aD->vX));
	return 1;
}

/*Function to collect user input for vY*/
int vyF(struct alienData *aD){
	if (aD->m->speak) printf("-------\nEnter any vy value, but be aware that a positive value can result in an"
		" infinite simulation running time\n-------\n"); 
	scanf("%lf", (&aD->vY));
	return 1;
}

