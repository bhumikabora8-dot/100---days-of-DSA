#include <stdio.h>
#include <stdlib.h>

int maxLen(int arr[], int n) {
    int sum = 0, max_length = 0;

    // Hash map using array (simple approach)
    int hash[1000];
    for(int i = 0; i < 1000; i++)
        hash[i] = -2; // -2 means not visited

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        if(sum == 0) {
            max_length = i + 1;
        }

        // Shift index to handle negative sums
        int index = sum + 500;

        if(hash[index] != -2) {
            int length = i - hash[index];
            if(length > max_length)
                max_length = length;
        } else {
            hash[index] = i;
        }
    }

    return max_length;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));

    return 0;
}