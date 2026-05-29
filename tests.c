#include "hashtable.h"
#define N 35

int main(){
    char* hashFile = "hash.dat";
    char* indexFile = "index.dat";
    char* subtitleFile = "subt.dat";
    start(hashFile, N, indexFile, subtitleFile);
    return 0;
}
