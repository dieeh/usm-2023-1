#include <stdio.h>
#include <sys/stat.h>
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
            sprintf(fileNames[fileQuantity++],"%s", dir->d_name);
        }
        closedir(d);
    }
    char fileCategory[fileQuantity][100];
    FILE *fp;
    const unsigned MAX_LENGTH = 256;
    char buffer[MAX_LENGTH];
    char pathTemp[MAX_LENGTH];
    int k = 0, j = 0;
    for (int i = 0; i < fileQuantity; i++){
        strcpy(pathTemp, "./Archivos_Prueba/");
        strcat(pathTemp ,fileNames[i]);
        fp = fopen(pathTemp, "r");
        fgets(buffer, MAX_LENGTH, fp);
        fgets(buffer, MAX_LENGTH, fp);
        fgets(buffer, MAX_LENGTH, fp);
        for (int j; j < fileQuantity; j++){
            if (strcmp(fileCategory[j],buffer) == 0){
                break;
            }else{
                sprintf(fileCategory[k++],"%s", buffer);
                break;
            }
        }
    }
    
    for (int i = 0; i < k; i++)
    {
        puts(fileCategory[i]);
    }
    
    

    return 0;
}