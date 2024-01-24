#include <stdio.h>
#define MAX_WORD 25

typedef struct {
    char name[MAX_WORD];
    char surname[MAX_WORD];
    int day;
    int month;
    int year;
    float height;
} wine;

float meanHeight(FILE *f);

int main() {
    char name[200];

    wine c;

    scanf("%s", name);
    FILE *f = fopen(name, "r");
    if(f == NULL) return 0;

    float mean = meanHeight(f);
    fseek(f, 0, SEEK_SET);

    while (fscanf(f, "%[^;];%[^;];%f;%d;%d;%d\n", c.name, c.surname, &c.height, &c.day, &c.month, &c.year) == 6){
        if(c.height >= mean) printf("%s %s\n", c.name, c.surname);
    }
    fclose(f);
    return 0;
}

float meanHeight(FILE *f){
    wine c;
    int count = 0;
    float ans = 0;
    while (fscanf(f, "%[^;];%[^;];%f;%d;%d;%d\n", c.name, c.surname, &c.height, &c.day, &c.month, &c.year) == 6){
        ans += c.height;
        count++;
    }
    ans /= count;
    return ans;
}