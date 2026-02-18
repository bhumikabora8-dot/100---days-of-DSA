#include <stdio.h>

int main() {
    int n, k, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n], rotated[n];

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    k = k % n;   // handle case when k > n

    // place last k elements at the beginning
    for(i = 0; i < k; i++) {
        rotated[i] = arr[n - k + i];
    }

    // place remaining elements
    for(i = k; i < n; i++) {
        rotated[i] = arr[i - k];
    }

    printf("Rotated array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", rotated[i]);
    }

    return 0;
}
