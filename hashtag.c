#include "hashtable.h"
#define N 35

int abs(int value){
    if(value>=0) return value;
    return value * (-1);
}


int HashThisShii(char* name, int TableSize){
    int hash = 5381;
    for(int i = 0; name[i] != '\0'; i++){
        hash = ((hash << 5) + hash) + (int)name[i];
    }
    return abs(hash) % TableSize;
}


void start(char* hashFile, int TableSize, char* dataFile, char*subtitleFile){
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

    fp = fopen(subtitleFile, "wb");
    if(!fp) exit(1);
    printf("Arquivo de subtitulo inicializado com sucesso!\n");
    fclose(fp);
}


Node* searchByName(char* hashFile, int TableSize, char* dataFile, char* name){
    FILE* fp = fopen(hashFile, "rb");
    if(!fp) exit(1);

    int position;
    position = HashThisShii(name, TableSize) * sizeof(int);
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


Node* nodeAloc(char* type, char* name, int year){
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->type, type);
    strcpy(newNode->name, name);
    newNode->year = year;
    return newNode;
}

void insert(char* hashFile, int TableSize, char* dataFile, char* type, char* name, int year, char* subtitle){
    FILE* fHash = fopen(hashFile, "rb+");
    if(!fHash) exit(1);
    
    FILE* fData = fopen(dataFile, "rb+");
    if(!fData) exit(1);

    int position = HashThisShii(name, TableSize) * sizeof(int);
    int posBefore = position;

    fseek(fHash, position, SEEK_SET);
    fread(&position, sizeof(int), 1, fHash);
    
    if (position == -1){
        fseek(fHash, posBefore, SEEK_SET);
        Node* nodeToInsert = nodeAloc(type, name, year);
        nodeToInsert->isValid = 1;
        nodeToInsert->next = -1;
        fseek(fData, 0, SEEK_END);
        position = ftell(fData);
        fwrite(nodeToInsert, sizeof(Node), 1, fData);
        free(nodeToInsert);

        fwrite(&position, sizeof(int), 1, fHash);
        fclose(fHash);
        fclose(fData);
        return;
    }
    
    Node aux;
    posBefore = position;

    while(position != -1){
        fseek(fData, position, SEEK_SET);
        fread(&aux, sizeof(Node), 1, fData);
        
        if((strcmp(aux.name, name) == 0) && (aux.isValid)){
            printf("%s already into the database!", name);
            fclose(fHash);
            fclose(fData);
            return;
        }

        if(!(aux.isValid)){
            Node* nodeToInsert = nodeAloc(type, name, year);
            nodeToInsert->isValid = 1;
            nodeToInsert->next = aux.next;
            
            fseek(fData, posBefore, SEEK_SET);
            fwrite(nodeToInsert, sizeof(Node), 1, fData);
            
            free(nodeToInsert);
            fclose(fHash);
            fclose(fData);
            return;
        }
        posBefore = position;
        position = aux.next;
    }

    fseek(fData, 0, SEEK_END);
    position = ftell(fData);
    Node* nodeToInsert = nodeAloc(type, name, year);
    nodeToInsert->isValid = 1;
    nodeToInsert->next = -1;
    fwrite(nodeToInsert, sizeof(Node), 1, fData);
    free(nodeToInsert);

    Node* correctAddress = nodeAloc(aux.type, aux.name, aux.year);
    correctAddress->isValid = aux.isValid;
    correctAddress->next = position;
    fseek(fData, posBefore, SEEK_SET);
    fwrite(correctAddress, sizeof(Node), 1, fData);
    free(correctAddress);

    fclose(fHash);
    fclose(fData);
    return;
}