#include "Tree.h"

typedef struct {
    int type; // Type of the file (1 for movies)
    char title[MAX_KEY_SIZE]; // Movie title
    int year; // Launch year
    char subtitle[MAX_KEY_SIZE]; // Subtitle of the movie, if it has one
    char prox[MAX_KEY_SIZE]; // Pointer to the next movie in the list (name of the next movie's archive name .dat)
 
} Movie;


 char* getMovieFileName(char* title, int year, char* indexFile); //Returns the name of the file where the movie is stored. If the movie is not found, returns NULL.