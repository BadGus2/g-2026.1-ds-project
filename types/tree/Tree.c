#include "tree.h"

char* correctName(char* name){
    char* correctedName = (char*)malloc(sizeof(char) * MAX_KEY_SIZE);
    strcpy(correctedName, name);
    int i = 0;
    while(correctedName[i] != '\0'){
        correctedName[i] = tolower(correctedName[i]);
        i++;
    }
    return correctedName;
}

int compareName(char* name1, char* name2){
    return strcmp(correctName(name1), correctName(name2));
}

void startTree(char* indexFile, int t){
    FILE* indexFp = fopen(indexFile, "wb");
    if(!indexFp){
        printf("Error opening index file in startTree() function\n");
        exit(1);
    }
    int balanceFactor = t;
    long rootPosition = -1;
    fwrite(&rootPosition, sizeof(long), 1, indexFp);
    fwrite(&balanceFactor, sizeof(int), 1, indexFp);
    fclose(indexFp);
    printf("B+ tree started with an empty root node!\nBalance factor %d\n", balanceFactor);
}


TreeNode* createNode(int t){
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->nKeys = 0;
    node->isValid = 1;
    for(int i = 0; i < MAX_KEYS; i++){
        node->keys[i][0] = '\0';
        node->sons[i] = -1;
    }
    return node;
}

char* searchNode(char* indexFile, char* name, int year){ //Searches for a node in the B+ tree and returns the name of the file where the data is stored.
    FILE* indexFp = fopen(indexFile, "rb");
    if(!indexFp) {
        printf("Error opening index file in searchNode() function\n");
        exit(1);
    }
    long rootPosition; 
    fread(&rootPosition, sizeof(long), 1, indexFp);
    if(rootPosition == -1) {
        printf("Node not found (The tree is empty)\n");
        fclose(indexFp);
        return NULL;
    }

    TreeNode node;
    fseek(indexFp, rootPosition, SEEK_SET);
    fread(&node, sizeof(TreeNode), 1 , indexFp);

    while(node.sons[0] != -1) {
        int i = 0;
        while(i < node.nKeys && compareName(name, node.keys[i]) >= 0){
            i++;
        }
        fseek(indexFp, node.sons[i], SEEK_SET);
        fread(&node, sizeof(TreeNode), 1, indexFp);
    }

    for(int i = 0; i < node.nKeys; i++){
        if(compareName(name, node.keys[i]) == 0){
            char* data = (char*)malloc(sizeof(char) * MAX_KEY_SIZE);
            strcpy(data, node.keys[i]);
            fclose(indexFp);
            return data;
        }
    }
    
    fclose(indexFp);
    printf("Node not found\n");
    return NULL;
}

long searchSonsNode(char* indexFile, char* name){ //Searches for the position of the first son of the node that shoud contain the name.
    FILE* hashFp = fopen(hashFile, "rb");
    if(!hashFp) {
        printf("Error opening hash file in searchSonsNode() function\n");
        exit(1);
    }
    

    long position = HashThisShii(name, TableSize);
    fseek(hashFp, position * sizeof(int), SEEK_SET);
    fread(&position, sizeof(int), 1, hashFp);
    if(position == -1) {
        printf("Node not found\n");
        fclose(hashFp);
        return NULL;
    }
    fclose(hashFp);

    TreeNode node;
    FILE* indexFp = fopen(indexFile, "rb");
    if(!indexFp) {
        printf("Error opening index file in searchSonsNode() function\n");
        exit(1);
    }

    fseek(indexFp, position * sizeof(TreeNode), SEEK_SET);
    fread(&node, sizeof(TreeNode), 1 , indexFp);


    while(node.sons[0] != -1) {
        int i = 0;
        while(i < node.nKeys && compareName(name, node.keys[i]) >= 0){
            i++;
        }
        fseek(indexFp, node.sons[i], SEEK_SET);
        position = ftell(indexFp);
        fread(&node, sizeof(TreeNode), 1, indexFp);
    }
    return position;
}
    



void insertNode(TreeNode* node, char* key, int sonPosition){
    if(node->nKeys == MAX_KEYS) {
        printf("Node is full, cannot insert key\n");
        return;
    }
    
}
