#include <stdio.h>

void countingSort(int arr[], int n) {
    // Step 1: Find maximum
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Step 2: Create count array
    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Step 3: Store frequencies
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 4: Prefix sum
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Step 5: Build output array (stable)
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 6: Copy back
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    countingSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}