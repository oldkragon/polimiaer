//scarto, biscarto, metagramma, parole che differiscono per due lettere scambiate
#include <stdio.h>
#include <string.h>
#define N 100 

int Scarto(char *s, char *t, int p, int l) {
    if (strlen(t) + l != strlen(s)) return 0;
    for (int i = 0, j = 0; i <strlen(t); i++, j++) {
        if (j == p)j += l;
        if (s[j] != t[i]) return 0;
    }
    return 1;
}

int Biscarto(char *s1, char *s2, char *s3) {
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int l3 = strlen(s3);
    int p1, p2, i;

    if ((l1 + l2 - l3) % 2) return -1;

    char* sdup = strdup(s3);

    int lscarto = (l1 + l2 - l3) / 2;
    for (i = 1; i < l3 - 1; i++) {
        sdup[i] = '\0';
        int r1, r2;
        for (p1 = 0;  p1 <= l1-lscarto ; p1++) {
            r1 =Scarto(s1, sdup, p1, lscarto);
            if(!r1) continue;
            for (p2 = 0; p2 <= l2 - lscarto; p2++) {
                r2 = Scarto(s2, &s3[i], p2, lscarto);
                if(!r2) continue;
                if(strncmp(&s1[p1], &s2[p2], lscarto)==0){
                    free(sdup);
                    return i;
                }
            }

        }
        strcpy(sdup, s3);
    }
    free(sdup);
    return -1;
}

int Metagramma(char m[][N], int righe) {
    int count = 0;
    for (int i = 1; i < righe; i++) {
        for (int j = 0; j < N; j++) {
            if( m[i][j] != m[i-1][j]) {
                count++;
                if(count > 1) return i;
            }
        }
        count = 0;
    }
    return righe;
}

int Isogramma(char *s) {
    int l = strlen(s);
    int frequencies[26] = {0};
    for (int i = 0; i < l; i++) {
        if(s[i]<= 'z' && s[i] >= 'a')
            s[i] -= 'a';
        if(s[i]<= 'Z' && s[i] >= 'A')
            s[i] -= 'A';
        frequencies[s[i]]++;
    }
    int freq;
    for (int i = 0; i < 26; i++) {
        if(frequencies[i]!= 0) {
            freq = frequencies[i];
            break;
        }
    }
    for (int i = 0; i < 26; i++) {
        if(frequencies[i]!= 0) {
            if(frequencies[i] != freq)
                return 0;
        }
    }
    return freq;
}

void swap(int i, int j, char* s) {
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

int TwoLettersSwapped(char* first, char* second) {
    int ans = 0;
    for (int i = 0; i < strlen(first); i++) {
        for (int j = i + 1; j < strlen(second); j++) {
            swap(i, j, second);
            if(!strcmp(first, second))
                ans++;
            swap(i, j, second);
        }
    }
    if (ans == 1)
        return 1;
    else
        return 0;
}

int Anagramma(char *s1, char *s2) {
    int freq1[26] = {0};
    int freq2[26] = {0};
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    if(l1 != l2) return 0;
    if(!strcmp(s1, s2)) return 0;
    for (int i = 0; i < l1; i++)
    {
        if(s1[i]<= 'z' && s1[i] >= 'a')
            s1[i] -= 'a';
        if(s1[i]<= 'Z' && s1[i] >= 'A')
            s1[i] -= 'A';
        freq1[s1[i]]++;
    }

    for (int i = 0; i < l2; i++)
    {
        if(s2[i]<= 'z' && s2[i] >= 'a')
            s2[i] -= 'a';
        if(s2[i]<= 'Z' && s2[i] >= 'A')
            s2[i] -= 'A';
        freq2[s2[i]]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if(freq1[i]!=freq2[i]) return 0;
    }
    return 1;
}

char Zeppa(char *s, char *t){

    int ls = strlen(s);
    int lt = strlen(t);

    if(lt - ls != 1)
        return 0;

    char *temp = malloc(sizeof(char)*(ls+1));
    temp[ls] = '\0';

    for (int i = 0, j = 0; i < ls; i++, j++) {
        if(s[i] != t[j]) j++;
        temp[i] = t[j];

    }

    if(!strcmp(s, temp))
        return 1;

    return 0;
}