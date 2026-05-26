#include "hashtable.h"
#define N 35

int abs(int value){
    if(value>=0) return value;
    return value * (-1);
}


int hash_this_shii(char* name, int TableSize){
    int hash = 5381;
    for(int i = 0; name[i] != '\0'; i++){
        hash = ((hash << 5) + hash) + (int)name[i];
    }
    return abs(hash) % TableSize;
}


void start(char* hashFile, int TableSize, char* dataFile){
    FILE* fp = fopen(hashFile, "wb");
    if(!fp) exit(1);

    int address = -1, i;
    for(i = 0; i < TableSize; i++){
        fwrite(&address, sizeof(int), 1, fp);
    };
    printf("Arquivo de hash inicializado com sucesso!\n");
    fclose(fp);

    fp = fopen(dataFile, "wb");
    if(!fp) exit(1);
    printf("Arquivo de dados inicializado com sucesso!\n");
    fclose(fp);
}


Node* searchByName(char* hashFile, int TableSize, char* dataFile, char* name){
    FILE* fp = fopen(hashFile, "rb");
    if(!fp) exit(1);

    int position;
    position = hash_this_shii(name, TableSize) * sizeof(int);
    fseek(fp, position, SEEK_SET);
    fread(&position, sizeof(int), 1, fp);
    fclose(fp);

    fp = fopen(dataFile, "rb");
    if(!fp) exit(1);

    Node aux;
    while(position != -1){

        fseek(fp, position, SEEK_SET);    
        fread(&aux, sizeof(Node), 1, fp);

        if((strcmp(aux.name, name) == 0) && aux.isValid){
            fclose(fp);
            Node* resp ;//= nodeAloc(aux.type, aux.name, aux.year);
            return resp;
        }

        position = aux.next;
    }
    fclose(fp);
    return NULL;
}