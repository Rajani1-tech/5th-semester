#include <stdio.h>
int main() {
    int i, n, t1 = 0, t2 = 1, nextTerm;
    printf("Rajani Lamichhane, Roll no.25796");
    printf("\nEnter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    printf("%d",t1);
    for (i = 1; i <= n-1; ++i) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        printf(",%d", t1);
    }
    return 0; 
}
