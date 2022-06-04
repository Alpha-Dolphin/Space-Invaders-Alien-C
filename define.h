/*Ben Elleman*/

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define FALSE 0
#define ERROR -1
#define TRUE 1

#define seq 0 
#define silent 0
#define sayAlien 1
#define save 0
#define gaussRand 1
#define safety 0
#define randValue 1024
#define defaultToRand 1

struct modes {FILE* output; int free; int speak; int alienSpeak; int keep; int gauss; int confirm; int rV; int dTR;};
struct alienData {struct modes* m; int type; int color; int points; double x; double y; double vX; double vY;};

