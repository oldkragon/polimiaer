#include <stdio.h>
#include <stdlib.h>

int elementNum(int n);
int* getLine(int *p, int line);
void fillLine(int *p, int line);

int main(){
    int n;
    scanf("%d", &n);
    int *p = (int*) malloc(elementNum(n)*sizeof(int));
    if(p == NULL){
        return -1;
    }
    for (int i = 1; i <= n; i++) {
        fillLine(p, i);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int *pLine = getLine(p, i);
            printf("%d ", pLine[j]);
        }
        printf("\n");
    }
    free(p);
    return 0;
}

int elementNum(int n) {
    return n*(n+1)/2;
}

void fillLine(int *p, int line) {
    int *pLine = getLine(p, line);
    pLine[0] = 1;
    pLine[line-1] = 1;
    if(line >= 2) {
        for (int i = 1; i < line-1; i++) {
            int *pPrev = getLine(p, line-1);
            pLine[i] = pPrev[i-1] + pPrev[i];
        }
    }
}

int* getLine(int *p, int line){
    if(line == 1) return p;
    return p + elementNum(line-1);
}
