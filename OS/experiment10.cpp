#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_NAME_LENGTH 50

// Structure to represent a file
typedef struct File {
    char name[MAX_NAME_LENGTH];
    int size;
} File;

// Structure to represent a directory
typedef struct Directory {
    char name[MAX_NAME_LENGTH];
    int numFiles;
    File files[MAX_FILES];
} Directory;

// Single level directory
Directory singleLevelDirectory;

// Two level directory
Directory twoLevelDirectory[MAX_FILES];

// Function to create a file in a single-level directory
void createFileSingleLevel(char* filename, int size) {
    if (singleLevelDirectory.numFiles < MAX_FILES) {
        strcpy(singleLevelDirectory.files[singleLevelDirectory.numFiles].name, filename);
        singleLevelDirectory.files[singleLevelDirectory.numFiles].size = size;
        singleLevelDirectory.numFiles++;
        printf("File '%s' created successfully in single-level directory\n", filename);
    } else {
        printf("Cannot create file. Single-level directory is full.\n");
    }
}

// Function to delete a file from a single-level directory
void deleteFileSingleLevel(char* filename) {
    int i;
    for (i = 0; i < singleLevelDirectory.numFiles; i++) {
        if (strcmp(singleLevelDirectory.files[i].name, filename) == 0) {
            int j;
            for (j = i; j < singleLevelDirectory.numFiles - 1; j++) {
                singleLevelDirectory.files[j] = singleLevelDirectory.files[j + 1];
            }
            singleLevelDirectory.numFiles--;
            printf("File '%s' deleted successfully from single-level directory\n", filename);
            return;
        }
    }
    printf("File '%s' not found in single-level directory\n", filename);
}

// Function to display files in a single-level directory
void displayFilesSingleLevel() {
    printf("Files in single-level directory:\n");
    int i;
    for (i = 0; i < singleLevelDirectory.numFiles; i++) {
        printf("%s\t%d bytes\n", singleLevelDirectory.files[i].name, singleLevelDirectory.files[i].size);
    }
}

// Function to create a file in a two-level directory
void createFileTwoLevel(char* dirname, char* filename, int size) {
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(twoLevelDirectory[i].name, dirname) == 0) {
            if (twoLevelDirectory[i].numFiles < MAX_FILES) {
                strcpy(twoLevelDirectory[i].files[twoLevelDirectory[i].numFiles].name, filename);
                twoLevelDirectory[i].files[twoLevelDirectory[i].numFiles].size = size;
                twoLevelDirectory[i].numFiles++;
                printf("File '%s' created successfully in directory '%s' of two-level directory\n", filename, dirname);
                return;
            } else {
                printf("Cannot create file. Directory '%s' is full.\n", dirname);
                return;
            }
        }
    }
    printf("Directory '%s' not found in two-level directory\n", dirname);
}

// Function to delete a file from a two-level directory
void deleteFileTwoLevel(char* dirname, char* filename) {
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(twoLevelDirectory[i].name, dirname) == 0) {
            int j;
            for (j = 0; j < twoLevelDirectory[i].numFiles; j++) {
                if (strcmp(twoLevelDirectory[i].files[j].name, filename) == 0) {
                    int k;
                    for (k = j; k < twoLevelDirectory[i].numFiles - 1; k++) {
                        twoLevelDirectory[i].files[k] = twoLevelDirectory[i].files[k + 1];
                    }
                    twoLevelDirectory[i].numFiles--;
                    printf("File '%s' deleted successfully from directory '%s' of two-level directory\n", filename, dirname);
                    return;
                }
            }
            printf("File '%s' not found in directory '%s' of two-level directory\n", filename, dirname);
            return;
        }
    }
    printf("Directory '%s' not found in two-level directory\n", dirname);
}

// Function to display files in a two-level directory
void displayFilesTwoLevel(char* dirname) {
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        if (strcmp(twoLevelDirectory[i].name, dirname) == 0) {
            printf("Files in directory '%s' of two-level directory:\n", dirname);
            int j;
            for (j = 0; j < twoLevelDirectory[i].numFiles; j++) {
                printf("%s\t%d bytes\n", twoLevelDirectory[i].files[j].name, twoLevelDirectory[i].files[j].size);
            }
            return;
        }
    }
    printf("Directory '%s' not found in two-level directory\n", dirname);
}

int main() {
    singleLevelDirectory.numFiles = 0;

    int choice;
    while (1) {
        printf("\nDirectory Simulation\n");
        printf("1. Single-level Directory - Create File\n");
        printf("2. Single-level Directory - Delete File\n");
        printf("3. Single-level Directory - Display Files\n");
        printf("4. Two-level Directory - Create File\n");
        printf("5. Two-level Directory - Delete File\n");
        printf("6. Two-level Directory - Display Files\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        char filename[MAX_NAME_LENGTH], dirname[MAX_NAME_LENGTH];
        int size;

        switch (choice) {
            case 1:
                printf("Enter file name: ");
                scanf("%s", filename);
                printf("Enter file size (in bytes): ");
                scanf("%d", &size);
                createFileSingleLevel(filename, size);
                break;
            case 2:
                printf("Enter file name to delete: ");
                scanf("%s", filename);
                deleteFileSingleLevel(filename);
                break;
            case 3:
                displayFilesSingleLevel();
                break;
            case 4:
                printf("Enter directory name: ");
                scanf("%s", dirname);
                printf("Enter file name: ");
                scanf("%s", filename);
                printf("Enter file size (in bytes): ");
                scanf("%d", &size);
                createFileTwoLevel(dirname, filename, size);
                break;
            case 5:
                printf("Enter directory name: ");
                scanf("%s", dirname);
                printf("Enter file name to delete: ");
                scanf("%s", filename);
                deleteFileTwoLevel(dirname, filename);
                break;
            case 6:
                printf("Enter directory name: ");
                scanf("%s", dirname);
                displayFilesTwoLevel(dirname);
                break;
            case 7:
                break;
            }
        }
}

/*Expected Output 
Directory Simulation
1. Single-level Directory - Create File
2. Single-level Directory - Delete File
3. Single-level Directory - Display Files
4. Two-level Directory - Create File
5. Two-level Directory - Delete File
6. Two-level Directory - Display Files
7. Exit
Enter your choice: 1
Enter file name: aiml
Enter file size (in bytes): 120
File 'aiml' created successfully in single-level directory

Directory Simulation
1. Single-level Directory - Create File
2. Single-level Directory - Delete File
3. Single-level Directory - Display Files
4. Two-level Directory - Create File
5. Two-level Directory - Delete File
6. Two-level Directory - Display Files
7. Exit
Enter your choice: 3
Files in single-level directory:
aiml    120 bytes
*/
