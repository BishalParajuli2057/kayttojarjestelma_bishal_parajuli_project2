#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    char *search = argv[1];

    if (argc == 2) {
        char *line = NULL;
        size_t len = 0;
        while (getline(&line, &len, stdin) != -1) {
            if (strstr(line, search)) {
                printf("%s", line);
            }
        }
        free(line);
    } else {
        for (int i = 2; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");
            if (fp == NULL) {
                fprintf(stderr, "wgrep: cannot open file\n");
                exit(1);
            }

            char *line = NULL;
            size_t len = 0;
            while (getline(&line, &len, fp) != -1) {
                if (strstr(line, search)) {
                    printf("%s", line);
                }
            }

            free(line);
            fclose(fp);
        }
    }

    return 0;
}
