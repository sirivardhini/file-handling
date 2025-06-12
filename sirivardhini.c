#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char data[1000];

    // 1. Create and Write to a File
    fp = fopen("myfile.txt", "w");  // "w" creates or overwrites the file
    if (fp == NULL) {
        printf("❌ Error creating file!\n");
        return 1;
    }

    printf("📝 Enter text to write into the file:\n> ");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("✅ Data written successfully to myfile.txt.\n\n");

    // 2. Read from the File
    fp = fopen("myfile.txt", "r");  // "r" for reading
    if (fp == NULL) {
        printf("❌ Error reading file!\n");
        return 1;
    }

    printf("📄 Contents of the file:\n");
    while (fgets(data, sizeof(data), fp) != NULL) {
        printf("%s", data);
    }
    fclose(fp);
    printf("\n");

    // 3. Append to the File
    fp = fopen("myfile.txt", "a");  // "a" for appending
    if (fp == NULL) {
        printf("❌ Error opening file for appending!\n");
        return 1;
    }

    printf("📝 Enter text to append into the file:\n> ");
    fgets(data, sizeof(data), stdin);
    fputs(data, fp);
    fclose(fp);
    printf("✅ Data appended successfully.\n");

    return 0;
}

