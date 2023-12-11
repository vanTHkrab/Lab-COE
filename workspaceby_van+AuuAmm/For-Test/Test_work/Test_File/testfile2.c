#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    const char *path = "FolderForTest";
    const char *File;
} File;

File *createFile(const char *path, const char *fileName) {
    File *file = malloc(sizeof(File));
    if (file == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for path and fileName
    file->path = strdup(path);
    file->File = strdup(fileName);

    if (file->path == NULL || file->File == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    return file;
}

void createFileInFolder(File *file) {
    char filePath[100];
    snprintf(filePath, sizeof(filePath), "%s/%s", file->path, file->File);

    FILE *file1 = fopen(filePath, "w");
    if (file1 != NULL) {
        fprintf(file1, "Hello, World!\n");
        fclose(file1);
        printf("File created successfully\n");
    } else {
        printf("Failed to create file\n");
    }
}

int main() {
    const char *folderPath = "FolderForTest";  // Replace with your folder path
    const char *fileName = "your_file.txt";       // Replace with your desired file name

    File *file = createFile(folderPath, fileName);

    createFileInFolder(file);

    // Don't forget to free allocated memory
    free((void *)file->path);
    free((void *)file->File);
    free(file);

    return 0;
}