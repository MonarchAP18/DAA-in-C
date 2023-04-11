#include <stdio.h>

int countIntersections(int n, int* p, int* q)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((p[i] < p[j] && q[i] > q[j] && q[j] > p[i]) ||
                (p[j] < p[i] && q[j] > q[i] && q[i] > p[j])) {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n, p[100], q[100];
    printf("Enter the number of lines: ");
    scanf("%d", &n);
    printf("Enter the starting and ending points of all the lines: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p[i], &q[i]);
    }
    int intersections = countIntersections(n, p, q);
    printf("Number of line segment intersections: %d\n", intersections);
    return 0;
}