/* Ben Elleman */

void alienPrint(const struct alienData *aD) ;
void clearStruct(struct alienData *aD) ;
int freeAcc(struct alienData *aD, int (*jT[])(struct alienData*)) ;
int main(int argc, char *argv[]) ;
int outWrite(struct alienData *aD) ;
int seqAcc(struct alienData *aD, int (*jT[])(struct alienData*)) ;
