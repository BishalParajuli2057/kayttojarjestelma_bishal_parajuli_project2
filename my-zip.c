#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "wzip: cannot open file\n");
            exit(1);
        }

        int count = 0;
        int prev = fgetc(fp);
        if (prev == EOF) {
            fclose(fp);
            continue;
        }

        count = 1;
        int curr;
        while ((curr = fgetc(fp)) != EOF) {
            if (curr == prev) {
                count++;
            } else {
                fwrite(&count, sizeof(int), 1, stdout);
                fwrite(&prev, sizeof(char), 1, stdout);
                count = 1;
                prev = curr;
            }
        }

        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&prev, sizeof(char), 1, stdout);

        fclose(fp);
    }

    return 0;
}
