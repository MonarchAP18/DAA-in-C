#include <stdio.h>
#include<math.h>
int karatsuba(int x, int y) {
    if (x < 10 || y < 10) {
        return x * y;
    }

    int m = (x > y) ? x : y;
    int n = 0;
    while (m > 0) {
        m /= 10;
        n++;
    }

    int half = n / 2;

    int a = x / pow(10, half);
    int b = x % (int)pow(10, half);
    int c = y / pow(10, half);
    int d = y % (int)pow(10, half);

    int ac = karatsuba(a, c);
    int bd = karatsuba(b, d);
    int ad_bc = karatsuba(a + b, c + d) - ac - bd;

    return ac * (int)pow(10, 2 * half) + ad_bc * (int)pow(10, half) + bd;
}

int main() {
    int x ;
    int y ;
    printf("ENTER TWO NUMBERS");
    scanf("%d %d", &x, &y);
    int result = karatsuba(x, y);

    printf("Product of %d and %d is %d\n", x, y, result);
    return 0;
}