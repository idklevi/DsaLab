#include <stdio.h>
#define MAX 100

int A[3][MAX], B[3][MAX], C[3][MAX], T[3][MAX];

void read(int m[3][MAX]) {
    printf("Rows, Cols, Terms: ");
    scanf("%d %d %d", &m[0][0], &m[1][0], &m[2][0]);
    printf("Enter %d terms (row col val):\n", m[2][0]);
    for(int i = 1; i <= m[2][0]; i++)
        scanf("%d %d %d", &m[0][i], &m[1][i], &m[2][i]);
}

void display(int m[3][MAX]) {
    printf("Row\tCol\tVal\n%d\t%d\t%d\n", m[0][0], m[1][0], m[2][0]);
    for(int i = 1; i <= m[2][0]; i++)
        printf("%d\t%d\t%d\n", m[0][i], m[1][i], m[2][i]);
}

void transpose(int A[3][MAX], int B[3][MAX]) {
    B[0][0] = A[1][0]; B[1][0] = A[0][0]; B[2][0] = A[2][0];
    int k = 1;
    for(int i = 0; i < A[1][0]; i++)
        for(int j = 1; j <= A[2][0]; j++)
            if(A[1][j] == i) {
                B[0][k] = A[1][j]; B[1][k] = A[0][j]; B[2][k] = A[2][j];
                k++;
            }
}

void add(int A[3][MAX], int B[3][MAX], int C[3][MAX]) {
    int i = 1, j = 1, k = 1;
    C[0][0] = A[0][0]; C[1][0] = A[1][0];
    
    while(i <= A[2][0] && j <= B[2][0]) {
        if(A[0][i] < B[0][j] || (A[0][i] == B[0][j] && A[1][i] < B[1][j])) {
            C[0][k] = A[0][i]; C[1][k] = A[1][i]; C[2][k] = A[2][i];
            i++; k++;
        }
        else if(A[0][i] > B[0][j] || (A[0][i] == B[0][j] && A[1][i] > B[1][j])) {
            C[0][k] = B[0][j]; C[1][k] = B[1][j]; C[2][k] = B[2][j];
            j++; k++;
        }
        else {
            C[0][k] = A[0][i]; C[1][k] = A[1][i]; C[2][k] = A[2][i] + B[2][j];
            i++; j++;
            if(C[2][k] != 0) k++;
        }
    }
    
    while(i <= A[2][0]) {
        C[0][k] = A[0][i]; C[1][k] = A[1][i]; C[2][k] = A[2][i];
        i++; k++;
    }
    while(j <= B[2][0]) {
        C[0][k] = B[0][j]; C[1][k] = B[1][j]; C[2][k] = B[2][j];
        j++; k++;
    }
    C[2][0] = k - 1;
}

int main() {
    printf("Matrix A:\n");
    read(A);
    printf("\nMatrix A:\n");
    display(A);
    
    printf("\nMatrix B:\n");
    read(B);
    printf("\nMatrix B:\n");
    display(B);
    
    transpose(A, T);
    printf("\nTranspose of A:\n");
    display(T);
    
    if(A[0][0] != B[0][0] || A[1][0] != B[1][0])
        printf("\nAddition not possible - dimensions don't match.\n");
    else {
        add(A, B, C);
        printf("\nA + B:\n");
        display(C);
    }
    
    return 0;
}