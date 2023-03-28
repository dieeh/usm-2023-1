#include <stdio.h>
#include <stdlib.h>
//#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h> 
#include <string.h>

int main(){
    DIR *d;
    struct dirent *dir;
    int fileQuantity = 0;
    char fileNames[100][100];
    d = opendir("./Archivos_Prueba");
    if (d) {
    while ((dir = readdir(d)) != NULL) {
        if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0 && dir->d_type == DT_REG) {
            sprintf(fileNames[fileQuantity++], "%s", dir->d_name);
            }
        }
    closedir(d);
    }
    char fileCategory[fileQuantity][100];
    FILE *fp;
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    char pathTemp[MAX_LENGTH];
    int k = 0, found;
    for (int i = 0; i < fileQuantity; i++){
        strcpy(pathTemp, "./Archivos_Prueba/");
        strcat(pathTemp ,fileNames[i]);
        fp = fopen(pathTemp, "r");
        fgets(buffer, MAX_LENGTH, fp);
        fgets(buffer, MAX_LENGTH, fp);
        fgets(buffer, MAX_LENGTH, fp);
        for (int j = 0; j < k; j++){
            if (strcmp(fileCategory[j], buffer) == 0){
                found = 1;  // Set flag to indicate category was found
                break;
            }
        }
        if (!found){  // Check flag to see if category was not found
            sprintf(fileCategory[k++], "%s", buffer);
        }

    }
    char Categories[k][MAX_LENGTH];
    int count = 0, is_duplicate, j;
    for(int i = 0; i < k; i++) {
        is_duplicate = 0;
        for(j = i + 1; j < k; j++) {
            if(strcmp(fileCategory[i], fileCategory[j]) == 0) {
                is_duplicate = 1;
                break;
            }
        }
        if(is_duplicate == 0) {
            strcpy(Categories[count], fileCategory[i]);
            count++;
        }
    }
    
    for (int i = 0; i < k; i++)
    {
        puts(Categories[i]);
    }
    
    

    return 0;
}