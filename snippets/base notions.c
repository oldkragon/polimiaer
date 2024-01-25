// Cypher, finite memory filter, to base 10, to binary,  check prime, filter primes, solve quadratic in R and in C
//GCD (Euclid's algorithm),

#include <stdio.h>
#include <math.h>

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