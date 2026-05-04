#include <stdio.h>

int isPossible(int arr[], int n, int k, int mid) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid)
            return 0;

        if (time + arr[i] <= mid) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

int minTime(int arr[], int n, int k) {
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int low = max, high = sum, result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", minTime(arr, n, k));
    return 0;
}