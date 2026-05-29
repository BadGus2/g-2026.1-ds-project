#include "Tree.h"


typedef struct {

    int type; // Type of the file (2 for people)
    char name[MAX_KEY_SIZE]; // Person's name
    int year; // Person's birth year
    char prox[MAX_KEY_SIZE]; // Pointer to the next person in the list (name of the next person's archive name .dat)

} Person;
