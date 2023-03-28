#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GENRES 100 // maximum number of different genres

int main() {
    char genres[MAX_GENRES][256]; // array to store the different genres
    int num_genres = 0; // counter for the number of different genres found
    char folder_name[] = "Archivos_Prueba"; // name of the folder
    char filename[256]; // variable to store the name of each file
    char line[256]; // variable to store each line of the file
    char *genre; // pointer to the genre string in each file
    FILE *file; // file pointer

    // open the folder
    FILE *folder = popen("ls Archivos_Prueba/*.txt", "r");
    if (!folder) {
        perror("popen");
        return EXIT_FAILURE;
    }

    // read each filename in the folder
    while (fgets(filename, sizeof(filename), folder)) {
        // remove the newline character at the end of the filename
        filename[strcspn(filename, "\n")] = '\0';

        // open the file
        file = fopen(filename, "r");
        if (!file) {
            perror(filename);
            continue; // skip to the next file if this one cannot be opened
        }

        // read the genre from the third line of the file
        for (int i = 0; i < 2; i++) {
            if (!fgets(line, sizeof(line), file)) {
                // there should be at least 2 lines in the file
                fprintf(stderr, "%s: invalid format\n", filename);
                break;
            }
        }
        if (fgets(line, sizeof(line), file)) {
            // remove the newline character at the end of the line
            line[strcspn(line, "\n")] = '\0';
            // check if the genre has already been found
            int found = 0;
            for (int i = 0; i < num_genres; i++) {
                if (strcmp(genres[i], line) == 0) {
                    found = 1;
                    break;
                }
            }
            // add the genre to the array if it has not been found yet
            if (!found && num_genres < MAX_GENRES) {
                strncpy(genres[num_genres], line, sizeof(genres[num_genres]));
                num_genres++;
            }
        } else {
            fprintf(stderr, "%s: invalid format\n", filename);
        }

        // close the file
        fclose(file);
    }

    // close the folder
    if (pclose(folder) == -1) {
        perror("pclose");
        return EXIT_FAILURE;
    }

    // print the different genres found
    printf("Different genres found:\n");
    for (int i = 0; i < num_genres; i++) {
        printf("%s\n", genres[i]);
    }

    return EXIT_SUCCESS;
}
