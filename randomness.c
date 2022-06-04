/*Ben Elleman*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#    define M_PI 3.14159265
#endif

#include "define.h"

#include "randomness.h"

/*Function to generate a Gaussian or linear random value for X*/
double aRandX(int boolean) {
	double value;	
	if (boolean) {
		/*Having a Gaussian x spread doesn't seem all too useful*/
		/*Centered on 0, SD of 15*/
		value = fmod(boxMuller() * 15.0, 40.0);
		/*Statistically, value validation not needed but why not*/
	} else value = rand() % 40 - 20;
	return value;
}

/*Function to generate a Gaussian or linear random value for Y*/
double aRandY(int boolean) {
	double value;
	if (boolean) {
		/*Centered on 20, SD of 5*/
		value = fmod(boxMuller() * 5.0 + 20, 40.0);
		/*Statistically, value validation not needed but why not*/
	} else	value = rand() % 40;
	return value;
}

/*Function to generate a Gaussian or linear random value for VX*/
double aRandVX(int boolean) {
	double value;
	if (boolean) {
		/*Centered on 0, SD of 2*/
		value = boxMuller() * 2;
	} else 	value = (rand() % 10 - 5 ) / 2;
	return value;
}
/*Function to generate a Gaussian or linear random value for VY*/
double aRandVY(int boolean) {
	double value;
	if (boolean) {
		/*Centered on -2, SD of 1*/
		value = boxMuller() - 2;
		/*To prevent positive vY or negative but very small vY*/
		if (value > -1) value = -1;
		/*Statistically, value validation not needed but could be particularly disasterous for an invalid vY*/
	} else 	value = rand() % 5 / 2 - 3;
	return value;
}

/*Generates 2 Gaussian random numbers according to the Box-Muller transformation method*/
double boxMuller() {
	double x, y;
	x = r();
	y = r();
	/*It might make more practical sense to fmod() the result*/
	return sqrt(-2 * log(x)) * cos(2 * M_PI * y);
	/*return sqrt(-2 * log(y)) * cos(2 * M_PI * x);*/
}

/*Returns a random double between 0 and 1, both inclusive*/
double r() {
	return (double) rand() / (double) RAND_MAX;
}
