#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

// Function to search for a substring in a file
int searchFile(const char *filename, const char *substring) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    char buffer[256];
    int found = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        if (strstr(buffer, substring) != NULL) {
            printf("Found in '%s': %s", filename, buffer);
            found = 1;
            break;
        }
    }

    fclose(file);
    return found;
}

// Recursive function to search for files with a substring in a directory and its subdirectories
void searchDirectory(const char *dirPath, const char *substring) {
    DIR *directory = opendir(dirPath);
    if (directory == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;

    while ((entry = readdir(directory)) != NULL) {
        // Skip "." and ".." entries to avoid infinite recursion
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dirPath, entry->d_name);

        if (entry->d_type == DT_DIR) {
            // Recurse into subdirectories
            searchDirectory(path, substring);
        } else if (entry->d_type == DT_REG) {
            // Search for the substring in regular files
            searchFile(path, substring);
        }
    }

    closedir(directory);
}

int main() {
    char dirPath[1024];
    char substring[256];

    printf("Enter directory path to search: ");
    scanf("%s", dirPath);

    printf("Enter substring to find in files: ");
    scanf("%s", substring);

    searchDirectory(dirPath, substring);

    return 0;
}
