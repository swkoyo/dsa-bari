#include <stdio.h>

int fun(int n) {
    static int x = 0;

    if (n <= 0) {
        return 0;
    }

    x++;
    return fun(n - 1) + x;
}

int main() {
    int r;
    r = fun(5);
    printf("%d\n", r);
    return 0;
}
