#include <stdio.h>

int sumNaturalNum(int n) {
    if (n <= 0) {
        return 0;
    }
    return sumNaturalNum(n - 1) + n;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return factorial(n - 1) * n;
}

int expo(int m, int n) {
    // if (n == 0) {
    //     return 1;
    // }
    // return expo(m, n - 1) * m;

    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0) {
        return expo(m * m, n / 2);
    }

    return m * expo(m * m, (n - 1) / 2);
}

double e(int x, int n) {
    // Taylor
    static double p = 1;
    static double f = 1;
    double r;

    if (n == 0) {
        return 1;
    }

    r = e(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}

double eh(int x, int n) {
    // HORNER
    static double s;

    if (n == 0) {
        return s;
    }

    s = 1 + x * s / n;
    return e(x, n - 1);
}

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 2) + fib(n - 1);
}

int fibM(int n, int *memo) {
    if (n <= 1) {
        memo[n] = n;
        return n;
    }

    if (memo[n - 2] == -1) {
        memo[n - 2] = fibM(n - 2, memo);
    }

    if (memo[n - 1] == -1) {
        memo[n - 1] = fibM(n - 1, memo);
    }

    return memo[n - 2] + memo[n - 1];
}

int nCr(int n, int r) {
    // PASCAL
    if (r == 0 || n == r) {
        return 1;
    }

    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

void TOH(int n, int A, int B, int C) {
    if (n > 0) {
        TOH(n - 1, A, C, B);
        printf("from %d to %d\n", A, C);
        TOH(n - 1, B, A, C);
    }
}

void foo(int n, int sum) {
    int k = 0, j = 0;

    if (n == 0)
        return;

    k = n % 10;

    j = n / 10;

    sum = sum + k;

    foo(j, sum);

    printf("%d", k);
}

int main() {
    int a = 2048, sum = 0;

    foo(a, sum);

    printf("%d\n", sum);
}

// int main() { TOH(3, 1, 2, 3); }
