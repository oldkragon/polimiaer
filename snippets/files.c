//file I/O, middle character, count words length

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100

int FileIO() {
    FILE *f = fopen("input.txt", "r");
    if(f == NULL) return -1;
    fclose(f);
    return 0;
}

char MiddleChar(FILE *f) {
    char c;
    fseek(f, 0, SEEK_END);
    long dim = ftell(f);
    fseek(f, (dim-1)/2, SEEK_SET);
    fscanf(f, "%c", &c);

    return c;
}

//file in r, ou w
void CountWordsLength(FILE* in, FILE* ou) {
    char c;
    int i = 0;
    while ((c = getc(in)) != EOF) {
        if(c != ' ') {
            i++;
        } else {
            if(i>0) {
                fprintf(ou, "%d ", i);
                i = 0;
            }
        }
    }
    fprintf(ou, "%d ", i);
}

//file in r, ou wb
void countLines(FILE* in, FILE* ou) {
    char buffer[N+2];
    while (fgets(buffer, N, in) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; //in python .index()
        int l = strlen(buffer);
        fwrite(&l, sizeof(int), l, ou);
    }
}

void Invert(FILE* ou) {
    int start, end, x, y;
    start = 0;
    fseek(ou, -1*sizeof(int), SEEK_END);
    end = ftell(ou);
    while (start<end) {
        fseek(ou, start, SEEK_SET);
        fread(&x, sizeof(int), 1, ou);
        fseek(ou, end, SEEK_SET);
        fread(&y, sizeof(int), 1, SEEK_SET);

        fseek(ou, start, SEEK_SET);
        fwrite(&y, sizeof(int), 1, ou);

        fseek(ou, end, SEEK_SET);
        fwrite(&x, sizeof(int), 1, ou);

        start += sizeof(int);
        end -= sizeof(int);
    }
}

char* FindLongestWord(FILE* f){
    char str[N+1];
    char *delim = ";,.'\"<>\n\t ";
    int max = 0;
    char* longest = (char*) malloc(sizeof(char)*(N+1));
    if(longest == NULL) return NULL;
    while (fgets(str, N, f) != NULL){
        char *s = strtok(str, delim);
        while (s != NULL){
            int l = strlen(s);
            if(l > max) {
                max = l;
                strcpy(longest, s);
            }
            s = strtok(NULL, delim);
        }
    }
    return longest;
}