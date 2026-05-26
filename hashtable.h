#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    char* type; // movie or person
    char* name; // person's or movie's name
    int year; // year element was born
    int next; // next element's address
    int isValid; // 0 -> DEAD     1 -> ALIVE
}Node;

//FEITO!!!!!!!!!!!!!!!!!!!!!! 4
int abs(int value);

int hash_this_shii(char* name, int TableSize);

void start(char* hashFile, int TableSize, char* dataFile);

Node* searchByName(char* hashFile, int TableSize, char* dataFile, char* name);


//FALTA FAZER!!!!!!!!!!!!!!!!!! 4
void insert(char* hashFile, char* dataFile, char* type, char* name, int year);

Node* searchByYear(char* hashFile, char* dataFile, int year);

Node* searchByYandT(char* hashFile, char* dataFile, char* type, int year);

Node* nodeAloc(char* type, char* name, int year);