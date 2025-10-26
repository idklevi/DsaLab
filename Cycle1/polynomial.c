#include <stdio.h>
struct Term { int c, e; };
int read(struct Term p[]) {
    int n, i;
    printf("Enter number of terms: "); 
    scanf("%d", &n);
    printf("Enter terms (coefficient exponent):\n");
    for (i = 0; i < n; i++) {
        scanf("%d%d", &p[i].c, &p[i].e);
    }
    return n;
}
void show(struct Term p[], int n) {
    for (int i = 0; i < n; i++) {
        if (p[i].c == 0) continue;
        if (i > 0 && p[i].c > 0) printf(" + ");
        else if (p[i].c < 0) printf(" - ");
        int coeff = (p[i].c > 0) ? p[i].c : -p[i].c;
        if (coeff != 1 || p[i].e == 0) printf("%d", coeff);
        if (p[i].e > 0) { printf("x"); if (p[i].e > 1) printf("^%d", p[i].e); }
    }
}
int add(struct Term a[], int n1, struct Term b[], int n2, struct Term r[]) {
    int i=0,j=0,k=0;
    while (i<n1 && j<n2) {
        if (a[i].e > b[j].e) r[k++] = a[i++];
        else if (a[i].e < b[j].e) r[k++] = b[j++];
        else {
            int sum = a[i].c + b[j].c;
            if (sum) r[k++] = (struct Term){sum, a[i].e};
            i++; j++;
        }
    }
    while (i<n1) r[k++] = a[i++];
    while (j<n2) r[k++] = b[j++];
    return k;
}
int main() {
    struct Term p1[10], p2[10], res[20];
    int n1, n2, n3;
    printf("Polynomial 1:\n"); n1 = read(p1);
    printf("\nPolynomial 2:\n"); n2 = read(p2);
    n3 = add(p1, n1, p2, n2, res);
    printf("\nSum: "); show(res, n3); printf("\n");
}