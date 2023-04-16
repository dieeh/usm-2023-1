#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h> 
#include <string.h>

/**
 * int count_files(const char *dir_path)
 * 
 * Esta función recibe un string con un directorio, luego accede a ese 
 * directorio y cuenta la cantidad de archivos que se encuentren en su 
 * interior, para luego retornar como int el valor de la cantidad.
 * 
*/
int count_files(const char *dir_path) {
    DIR *dir;
    struct dirent *ent;
    int count = 0;

    dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Falla al abrir el directorio");
        exit(1);
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {
            count++;
        }
    }

    closedir(dir);

    return count;
}

int main(void) {
    DIR *dir;
    struct dirent *ent;
    char **folders = NULL;
    int count = 0;

    dir = opendir(".");
    if (dir == NULL) {
        perror("Falla al abrir el directorio");
        exit(1);
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_DIR) {
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 && strcmp(ent->d_name, "Archivos_Prueba") != 0) {
                count++;
                folders = realloc(folders, count * sizeof(char *));
                if (folders == NULL) {
                    perror("Falla de memoria");
                    exit(1);
                }
                folders[count - 1] = malloc(strlen(ent->d_name) + 1);
                if (folders[count - 1] == NULL) {
                    perror("Falla de memoria");
                    exit(1);
                }
                strcpy(folders[count - 1], ent->d_name);
            }
        }
    }
    closedir(dir);
    
    //int num_folders = sizeof(folders) / sizeof(folders[0]);
    char path[256];
    int menor4 = 0;
    int mayor8 = 0;
    int entre4y8 = 0;
    //printf("count: %d, num_folders: %d", count, num_folders);
    int Actual_Mayor;
    printf("Los juegos están ordenados por cantidad actual o mayor cantidad de jugadores?\n");
    printf("\t1.- Cantidad actual\n");
    printf("\t2.- Mayor cantidad\n");
    scanf("%d", &Actual_Mayor);

    if (Actual_Mayor == 1){
        for (int i = 0; i < count; i++) {
            printf("Cantidad de juegos de '%s':\n", folders[i]);
            snprintf(path, sizeof(path), "%s/Menor_a_40000", folders[i]);
            printf("\tJuegos con una cantidad de jugadores actuales menor a 40000: %d\n", count_files(path));
            menor4 += count_files(path);
            snprintf(path, sizeof(path), "%s/Mayor_a_80000", folders[i]);
            printf("\tJuegos con una cantidad de jugadores actuales mayor a 80000: %d\n", count_files(path));
            mayor8 += count_files(path);
            snprintf(path, sizeof(path), "%s/Entre_40000_y_80000", folders[i]);
            printf("\tJuegos con una cantidad de jugadores actuales entre 40000 y 80000: %d\n", count_files(path));
            entre4y8 += count_files(path);
        }

        printf("Del total de juegos:\n");
        printf("\tExisten %d con una cantidad de jugadores actuales menor a 400000\n", menor4);
        printf("\tExisten %d con una cantidad de jugadores actuales mayor a 800000\n", mayor8);
        printf("\tExisten %d con una cantidad de jugadores actuales entre 400000 y 80000\n", entre4y8);
    }else{
        for (int i = 0; i < count; i++) {
            printf("Cantidad de juegos de '%s':\n", folders[i]);
            snprintf(path, sizeof(path), "%s/Menor_a_40000", folders[i]);
            printf("\tJuegos con una mayor cantidad de jugadores menor a 40000: %d\n", count_files(path));
            menor4 += count_files(path);
            snprintf(path, sizeof(path), "%s/Mayor_a_80000", folders[i]);
            printf("\tJuegos con una mayor cantidad de jugadores mayor a 80000: %d\n", count_files(path));
            mayor8 += count_files(path);
            snprintf(path, sizeof(path), "%s/Entre_40000_y_80000", folders[i]);
            printf("\tJuegos con una mayor cantidad de jugadores entre 40000 y 80000: %d\n", count_files(path));
            entre4y8 += count_files(path);
        }

        printf("Del total de juegos:\n");
        printf("\tExisten %d con una mayor cantidad de jugadores menor a 400000\n", menor4);
        printf("\tExisten %d con una mayor cantidad de jugadores mayor a 800000\n", mayor8);
        printf("\tExisten %d con una mayor cantidad de jugadores entre 400000 y 80000\n", entre4y8);
    }
    

    

    for (int i = 0; i < count; i++) {
        free(folders[i]);
    }
    free(folders);

    return 0;
}