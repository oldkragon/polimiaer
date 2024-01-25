// Cypher, finite memory filter, to base 10, to binary, from base 12,  check prime, filter primes, solve quadratic in R and in C
//GCD (Euclid's algorithm), read a line containing name and frequency of object untill an empty line is given (2 funcs needed)


#include <stdio.h>
#include <math.h>
#define N 100

int Cypher(char c, int n){
    if (c>= 'A' && c < 'Z' || c>= 'a' && c < 'z'){
        c += n; // NOLINT(*-narrowing-conversions)
        if (c > 'Z' && c < 'a' || c > 'z' ){
            c -= 26;
        }
    }
    return c;
}

int FiniteMemoryFilter(){
    int buffer, ans = 0;
    do {
        scanf("%d", &buffer);
        ans += buffer;
    } while (buffer != 0);
    printf("Sum is %d", ans);
    return 0;
}

int ToBase10() {
    char c;
    int ans = 0;
    scanf("%c", &c);
    while (c != '\n') {
        if (c <'0' || c > '9') {
            printf("Invalid char");
            return 1;
        } else {
            ans = 10*ans + c - '0';
        }
        scanf("%*c%c", &c);
    }
    return ans;
}

int ToBinary(int v, char *res, int l) {
    int pos = 0;
    do {
        if (pos >= l -1) return 0;
        int remainder = v%2;
        res[pos++] = '0' + remainder;
        v /= 2;
    } while (v != 0);
    for (int i = 0; i <= pos/2; i++) {
        char temp = res[i];
        res[i] = res[pos - i - 1];
        res[pos - i -1] = temp;
    }
    return 1;
}

int FromBase12(){
    char num12[N+1];
    int num10 = 0, sign = 1, l;
    scanf("%8s", num12);
    l = strlen(num12);
    for (int i = 0; i < 8 && num12[i] != '\0'; i++) {
        switch (num12[i]) {
            case '+':
                continue;
            case '-':
                sign = -1;
                continue;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                num12[i] -= '0';
                break;
            case 'a':
            case 'b':
                num12[i] -= 'a';
                num12[i] += 10;
                break;
            default:
                return -1*pow(12, 7);
        }
        num10 += num12[i] * pow(12, l - i - 1);
    }
    num10 *= sign;
    return num10;
}

void C2Inverse(char *s, int l){
    for (int i = 0; i < l; i++)
    {
        if(s[i]== 0) s[i]=1;
        else s[i] = 0;
    }
    int r =1;
    for (int i = 0; i < l && r; i++)
    {
        s[i]+=1;
        if(s[1]>i) s[i]-= 2;
        else r = 0;
    }
}

int CheckPrime(int n) {
    if(n == 1 || n == 0) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int FilterPrimes(int *in, int l, int *filtered) {
    int found = 0;
    for (int i = 0; i < l; i++) {
        if(CheckPrime(in[i]) == 1) filtered[found++] = in[i]; // post increment happens after use
    }
    return found;
}

void SolveQuadraticInR(float a, float b, float c, float *ans) {
    float delta = pow(b, 2) - 4*a*c;
    if (delta < 0) ans[0] = INFINITY;
    else {
        ans[0] = (-b - sqrt(delta))/2*a;
        ans[1] = (-b + sqrt(delta))/2*a;
    }
    if(ans[0] > ans[1]){
        float temp = ans[0];
        ans[0] = ans[1];
        ans[1] = temp;
    }
}

typedef struct {
    float re;
    float im;
} complex;

void SolveQuadraticInC(float a, float b, float c, complex *ans) {
    float delta = pow(b, 2) - 4*a*c;
    if (delta < 0) {
        delta *= -1;
        ans[0].re = -b/2*a;
        ans[1].re = -b/2*a;
        ans[0].im = -1*sqrt(delta)/2*a;
        ans[1].im = sqrt(delta)/2*a;
    }
    else {
        ans[0].re = (-b - sqrt(delta))/2*a;
        ans[1].re = (-b + sqrt(delta))/2*a;
        ans[0].im = 0;
        ans[1].im = 0;
    }
    if(ans[0].re > ans[1].re){
        complex temp = ans[0];
        ans[0] = ans[1];
        ans[1] = temp;
    } else if(ans[0].re == ans[1].re && ans[0].im > ans[1].im) {
        complex temp = ans[0];
        ans[0] = ans[1];
        ans[1] = temp;
    }
}

int GCD(int x, int y) {
    while (y > 0) {
        int temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

typedef struct _data {
    char name[128];
    int arr[N];
} data;

int ReadLineAndHash(data *dt) {
    int i = 0;
    char t[128], *s, *r;
    r = NULL;
    memset(dt->arr, 0, sizeof(data));
    r = fgets(t, 128, stdin);
    if(!r||r[0]=='\n') return 0;
    int read = sscanf(t, "%s", dt->name);
    s = t + strlen(dt->name);
    while (sscanf(s, "%d", &i) == 1) {
        dt->arr[i] = 1;
        do {s++;} while (*s>='0'&&*s<='9');
    }
    return read;
}

data *ReadUntillEmpryLine() {
    data *ex = malloc(sizeof(data) * N);
    int i = 0;
    while (ReadLineAndHash(ex+i)){
        i++;
    }
    memset((ex+i)->arr, 0, sizeof(data));
    strcpy((ex+i)->name, "\0");
    return ex;
}