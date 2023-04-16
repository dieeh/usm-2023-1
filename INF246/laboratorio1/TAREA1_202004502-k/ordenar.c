#include <stdio.h>
#include <stdlib.h>
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
    int k = 0;
    for (int i = 0; i < fileQuantity; i++){
        strcpy(pathTemp, "./Archivos_Prueba/");
        strcat(pathTemp ,fileNames[i]);
        fp = fopen(pathTemp, "r");
        fgets(buffer, MAX_LENGTH, fp);
        fgets(buffer, MAX_LENGTH, fp);
        fgets(buffer, MAX_LENGTH, fp);
        int j;
        for (j = 0; j < k; j++){
            if (strcmp(fileCategory[j],buffer) == 0){
                break;
            }
        }
        if (j == k){
            sprintf(fileCategory[k++],"%s", buffer);
        }
        fclose(fp);
    }
    char Categories[k][MAX_LENGTH];
    int count = 0, is_duplicate;
    for(int i = 0; i < k; i++) {
        is_duplicate = 0;
        for(int j = i + 1; j < k; j++) {
            if(strcmp(fileCategory[j], fileCategory[i]) == 0) {
                is_duplicate = 1;
                break;
            }
        }
        if(is_duplicate == 0) {
            strcpy(Categories[count], fileCategory[i]);
            count++;
        }
    }
    
    char genre[MAX_LENGTH];
    for (int i = 0; i < k; i++){
        strcpy(genre, Categories[i]);
        mkdir(genre, 0777);
        strcat(genre,"/Menor_a_40000");
        mkdir(genre, 0777);
        strcpy(genre, Categories[i]);
        strcat(genre,"/Entre_40000_y_80000");
        mkdir(genre, 0777);
        strcpy(genre, Categories[i]);
        strcat(genre,"/Mayor_a_80000");
        mkdir(genre, 0777);
    }

    int Actual_Mayor;
    printf("¿Desea ordenar por cantidad actual o mayor cantidad de jugadores?\n");
    printf("\t1.- Cantidad actual\n");
    printf("\t2.- Mayor cantidad\n");
    scanf("%d", &Actual_Mayor);

    char temp[MAX_LENGTH];
    int result = 0;
    for (int i = 0; i < fileQuantity; i++){
        strcpy(pathTemp, "./Archivos_Prueba/");
        strcat(pathTemp ,fileNames[i]);
        fp = fopen(pathTemp, "r");
        if (Actual_Mayor == 1){
            fgets(temp, MAX_LENGTH, fp);
            fgets(buffer, MAX_LENGTH, fp);
            fgets(buffer, MAX_LENGTH, fp);
        }else{
            fgets(temp, MAX_LENGTH, fp);
            fgets(temp, MAX_LENGTH, fp);
            fgets(buffer, MAX_LENGTH, fp);
        }
        
        char destPath[MAX_LENGTH];
        int numerito = atoi(temp);
        if (numerito < 40000){
            sprintf(destPath, "./%s/Menor_a_40000/%s", buffer, fileNames[i]);
            result = rename(pathTemp, destPath);
        } else if (numerito > 80000){
            sprintf(destPath, "./%s/Mayor_a_80000/%s", buffer, fileNames[i]);
            result = rename(pathTemp, destPath);
        } else{
            sprintf(destPath, "./%s/Entre_40000_y_80000/%s", buffer, fileNames[i]);
            result = rename(pathTemp, destPath);
        }
    }
    
    return 0;
}