#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Safe compare function for qsort
int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    // Edge case: need at least two elements
    if (n < 2) {
        printf("Array must have at least two elements");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int minSum = abs(arr[left] + arr[right]);
    int x = arr[left], y = arr[right];

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < minSum) {
            minSum = abs(sum);
            x = arr[left];
            y = arr[right];
        }

        if (sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", x, y);
    return 0;
}

