//This is a collection of useful function to operate on arrays
//min, max, invert, swap two el, sort, check symmetry, fill matrix, scan matrix, print matrix, make symmetric matrix
//create transposed matrix, all partial sums, sum of two matrices element by element an as nums, create cartesian product, remove duplicates
//diagonal sum, join arrays
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100
#define M 100

int Min(int *a, int l) {
    int m = *a;
    int index_min = 0;
    for (int i = 1; i < l; i++) {
        if (m > *(a + i)) {
            index_min = i;
            m = *(a + i);
        }
    }
    return index_min;
}

int Max(int *a, int l) {
    int m = *a;
    int index_max = 0;
    for (int i = 1; i < l; i++) {
        if (m < *(a + i)) {
            index_max = i;
            m = *(a + i);
        }
    }
    return index_max;
}

void Invert(char *s, int l) {
    for (int i = 0; i < l / 2; i++) {
        char t = *(s + i);
        *(s + i) = *(s + l - i);
        *(s + l - i) = t;
    }
}

void Swap(int *a, int *b){
    int t = *b;
    *b = *a;
    *a = t;
}

void BubbleSort(int *a, int l) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

//Not 100% sure it'll work
void Sort(int *v, int l){
    int index_min = -1;
    for (int i = 0; i < l; i++)
    {
        index_min = Min(v+i, l-i);
        Swap(v+i, v+index_min);
    }

}

int CheckSymmetry(int m[N][N]) {

    int sim = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; ++j) {
            if (m[i][j] != m[j][i])
                sim = 0;
        }
    }
    return sim;
}

void FillMatrix(int m[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &m[i][j]);
        }
    }
}

int* scanMatrix(int n, int m){
    int *p = (int*) malloc(n*m*sizeof(int));
    if(p != NULL){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", p + i*m + j);
            }
        }
    }
    return p;
}


void PrintMatrix(int v[N*M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%3d", *(v+N*i+j));
        }
        printf("\n");
    }
}
// void printMat(int *p, int n, int m); with ptr

int CheckPal(char *s, int l) {
    char *t;
    t = &s[l / 2];
    Invert(t, l / 2);
    int ans = strncmp(s, t, l / 2);
    return ans;
}

void MakeSymmetricalMatrix(int v[N * M], int t[M * N]) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            *(t + N * j + i) = *(v + M * i + j);
        }
    }
}

int* CreateTransposedMatrix(int *p, int n, int m){
    int *t = (int*) malloc(n*m*sizeof(int));
    if(t != NULL){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                *(t + j*m + i) = *(p + i*m +j);
            }
        }
    }
    return t;
}

void AllPartialSums(int *v, int l, int *sums) {
    int sum = 0;
    for (int i = 0; i < l; i++) {
        sum += v[i];
        sums[i] = sum;
    }
}

int* SumOfTwoMatrices(int *m1, int *m2, int n, int m){
    int *p = (int*) malloc(n*m*sizeof(int));
    if(p != NULL){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                *(p + i*m + j) = *(m1 + i*m + j) + *(m2 + i*m + j);
            }
        }
    }
    return p;
}

int SumAsNumbers(int a[N], int b[N], int c[N]) {
    int remainder = 0, err = 0;
    for (int i = 0; i < N-1; ++i) {
        c[i] = (a[i]+b[i]+remainder);
        if(c[i]>1){
            remainder = 1;
            c[i] -= 2;
        } else remainder = 0;
    }
    c[N-1] = remainder-a[N-1]-b[N-1];
    if(c[N-1]<-1 || c[N-1]>0) {
        c[N-1] = c[N-1] % 2;
        err = 1;
    }
    if(c[N-1] == -1) c[N-1] = 1;
    for (int i = N-1; i >= 0; i--)
        printf("%d", c[i]);

    return err;
}

int* CreateCartesianProd(int *p1, int *p2, int d1, int d2, int d3){
    int *p = (int*) malloc(d1*d3*sizeof(int));
    if(p != NULL){
        for (int i = 0; i < d1; i++) {
            for (int j = 0; j < d3; j++) {
                int sum = 0;
                for (int k = 0; k < d2; k++) {
                    sum += *(p1 + i*d2 + k)* *(p2 + k*d3 + j);
                }
            }
        }
    }
    return p;
}

//v has to be sorted
int RemoveDuplicates(int *v, int l, int *p) {
    int count = 0;
    for (int i = 0; i < l; i++)
    {
        if (i == 0 || *(v+i) != *(v+i-1))
        {
            *(p+count) = *(v+i);
            count++;
        }
    }
    return count;
}

//a has to be sorted, might return wrong variable
int BinarySearch(int *a, int l, int key) {
    int high = *a;
    int low = *(a + l);
    int mid = *(a+l/2);
    while (mid != key && low < high)
    {
        if(mid < key) {
            low = mid;
            mid = (high + low)/2;
        }
        else {
            high = mid;
            mid = (high + low) / 2;
        }
    }
    return mid;
}

void DiagonalSum(int m[N][N], int n[2*N-1]){
    /*BAD ASSISTANT SOLUTION
     * for (int i = 0; i < ; ++i) {
     * int sum = 0
     *   for (int j = 0; j < i+1; j++) {
     *       for (int k = 0; k < i+1; k++){
     *           if(j==k){
     *               sum += m[j + N - i - 1][k];
     *           }
     *       }
     *   }
     * for (int i = 0; i < ; ++i) {
     * int sum = 0
     *   for (int j = 0; j < N-i; j++) {
     *       for (int k = 0; k < N-i; k++){
     *           if(j==k){
     *               sum += m[j][i+k];
     *           }
     *       }
     *   }
     * */
    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < i +1; j++) {
            count += m [N-j-1][i-j];
        }
        n[i] = count;
    }
    for (int i = 1; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N-i; j++) {
            count += m[j][j+i];
        }
        n[N+i-1 ] = count;
    }
}

void  JoinArr(int *p1, int *p2, int *p3, int l) {
    for (int i = 0; i < l; i++) {
        *(p3 + 2*i) = *(p1 + i);
        *(p3 + 2*i + 1) = *(p2 + i);
    }
}