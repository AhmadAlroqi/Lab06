#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, a, b;
    printf("Enter the size of vectors for (x,y,z)\n");
    scanf("%d", &n);

    int *x = (int *)malloc(n * sizeof(int)); 
    int *y = (int *)malloc(n * sizeof(int)); 
    int *z = (int *)malloc(n * sizeof(int)); 

    if (x == NULL || y == NULL || z == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  
    }

    printf("Enter Scaler a: \n");
    scanf("%d", &a);
    printf("Enter Scaler b: \n");
    scanf("%d", &b);

    printf("Enter elements of vector x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    printf("Enter elements of vector y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }

    for (int i = 0; i < n; i++) {
        z[i] = a * x[i] + b * y[i];
    }

    printf("Result of vector z:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", z[i]);
    }
    printf("\n");



    return 0;
}

