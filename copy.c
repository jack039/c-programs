#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *src, *dest;
    char filename[100], c;

    // Reading the source filename
    printf("Enter the source filename: ");
    scanf("%s", filename);
    src = fopen(filename, "r");
    if (!src) {
        printf("Cannot open source file.\n");
        return 1;
    }

    // Reading the destination filename
    printf("Enter the destination filename: ");
    scanf("%s", filename);
    dest = fopen(filename, "w");
    if (!dest) {
        printf("Cannot open destination file.\n");
        fclose(src);
        return 1;
    }

    // Copying contents from source to destination
    while ((c = fgetc(src)) != EOF) {
        fputc(c, dest);
    }

    printf("File copied successfully.\n");

    fclose(src);
    fclose(dest);
    return 0;
}
