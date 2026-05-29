#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct node{
    char type[10]; // movie or person
    char name[50]; // person's or movie's name
    int year; // year element was born
    int next; // next element's address
    int isValid; // 0->DEAD  ||   1->ALIVE
    int subtitleOffset; // Points to separate subtitle storage (-1 if none)
}Node;

//FEITO!!!!!!!!!!!!!!!!!!!!!! 5
int abs(int value);

int HashThisShii(char* name, int TableSize);

void start(char* hashFile, int TableSize, char* indexFile, char* subtitleFile);

Node* searchByName(char* hashFile, int TableSize, char* indexFile, char* name);
// Need to implement subtitle check for movies

void insertFull(char* hashFile, int TableSize, char* indexFile, char* type, char* name, int year, char* subtitle);
// Need to implement subtitle check for movies


//FALTA FAZER!!!!!!!!!!!!!!!!!! 3
Node* searchByYear(char* hashFile, char* indexFile, int year);

Node* searchByYandT(char* hashFile, char* indexFile, char* type, int year);

Node* nodeAloc(char* type, char* name, int year);

void insertMovie(char* hashFile, int TableSize, char* indexFile, char* type, char* name, int year, char* subtitle);