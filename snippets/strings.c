//This is a collection of useful function to operate on strings
//concatenate(StrCat), delete a char, extend, sum

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR 100

char* Concatenate(char* str1, char *str2) {
    int l1 = strlen(str1);
    int l2 = strlen(str2);
    char *str3 = (char*) malloc((l1+l2+1)*sizeof(char));
    if(str3!=NULL) {
        strcpy(str3, str1);
        strcpy(str3 + l1, str2);
    }
    return str3;
}

char* DeleteAChar(char* s, char c) {
    int count = 0, pos = 0;
    for (int i = 0; s[i] != '\0';  i++) {
        if(s[i]==c) count++;
    }
    char* s2 = (char*) malloc((strlen(s)-count+1)*sizeof(char));
    if(s2!=NULL){
        for (int i = 0; s[i]!='\0'; i++) {
            if(s[i]!=c){
                s2[pos++] = s[i];
            }
        }
        s2[pos] = '\0';
    }
    return s2;
}

//string is at the end
char* Extend(char* s, int n) {
    char *r = (char*) malloc((n+1)*sizeof(char));
    if(r ==NULL)return NULL;
    for (int i = 0; i < n; i++) {
        r[i] = '0';
    }
    r[n] = '\0';
    strcpy(r+n-strlen(s), s);
    return r;
}

//strings are numbers in base 10
char* Sum(char *x, char *y) {
    int l1 = strlen(x);
    int l2 = strlen(y);
    int max_l = l1 > l2 ? l1 : l2;
    char *x_ext = Extend(x, max_l);
    char *y_ext = Extend(y, max_l);
    if(x_ext==NULL) return NULL;
    if(y_ext==NULL) return NULL;
    char *r = (char*) malloc((max_l+1)*sizeof(char));
    r[max_l] = '\0';
    int report = 0;
    for (int i = max_l-1; i >= 0; i--) {
        int a = x_ext[i]-'0';
        int b = y_ext[i]-'0';
        int s = a+b+report;
        if(s >= 10){
            s -= 10;
            report = 1;
        }
        r[i] = s+'0';
    }
    free(x_ext);
    free(y_ext);
    if (report!=0){
        char *temp = (char*) malloc((max_l+1+1)*sizeof(char));
        if(temp==NULL){
            free(r);
            return NULL;
        }
        temp[0] = report+'0';
        strcpy(temp+1, r);
        r = temp;
    }
    return r;
}