#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_KEYS 100
#define MAX_KEY_SIZE 160

typedef struct {
    int t; // Maximum number of keys
    int nKeys; // Number of keys
    char keys[MAX_KEYS][MAX_KEY_SIZE]; // Array of keys (names of the movies or people) '\0' if empty
    int sons[MAX_KEYS + 1]; // Array of sons (positions in the data file of the first node of each son) -1 if leaf
    int isValid; // 1 if the node is valid, 0 otherwise 
    
}TreeNode;

void startTree(char* indexFile); //Starts the B+ tree with an empty root node.

char* correctName(char* name);

int compareName(char* name1, char* name2);

TreeNode* createNode(int t);

char* searchNode(char* indexFile, char* name); //Returns a node in the B+ tree and returns the name of the file where the data is stored.

long searchSonsNode(char* indexFile, char* name); //Returns the position of the first son of the node that shoud contain the name.

void insertNode(TreeNode* node, char* key, int sonPosition); //Inserts a key in the leeve node and the position of the son in the data file. If the node is full, it should split and insert the key in the parent node. If the parent node is full, it should split as well and so on until it finds a node that is not full or it creates a new root node.

 