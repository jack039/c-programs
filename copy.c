#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *src, *dest;
    char filename[100], c;

    printf("Enter the source filename: ");
    scanf("%s", filename);
    src = fopen(filename, "r");
    if (!src) {
        printf("Cannot open source file.\n");
        return 1;
    }

    printf("Enter the destination filename: ");
    scanf("%s", filename);
    dest = fopen(filename, "w");
    if (!dest) {
        printf("Cannot open destination file.\n");
        fclose(src);
        return 1;
    }

    while ((c = fgetc(src)) != EOF) {
        fputc(c, dest);
    }

    printf("File copied successfully.\n");

    fclose(src);
    fclose(dest);
    return 0;
}
