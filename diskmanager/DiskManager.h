#include "../types/movie/Movie.h"
#include "../types/person/Person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void DiskManager_Init(); // Initializes the disk manager
void DiskManager_ReadFile(char* filename, int type); // Reads a file from the output directory (leaf -> output/leaf_*.bin) Ignores index.bin file
void DiskManager_WriteFile(char* filename, int type); // Writes a file to the output directory (leaf -> output/leaf_*.bin) Ignores index.bin file
void DiskManager_DeleteFile(char* filename); // Deletes a file from the output directory (leaf -> output/leaf_*.bin) Ignores index.bin file
void DiskManager_ListFiles(); // Lists all files in the output directory (leaf -> output/leaf_*.bin) Ignores index.bin file
