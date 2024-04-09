#include <stdio.h>
#include <math.h>

int Equilibrium(int n) {
    double i = sqrt((double)(n * n + n) / 2);
    if (i == (int)i) {
        return (int)i;
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int equilibrium = Equilibrium(n);
    if (equilibrium != -1) {
        printf("Equilibrium index: %d\n", equilibrium);
    } else {
        printf("No equilibrium index found.\n");
    }

    return 0;
}
