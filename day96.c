#include <stdio.h>

int merge(int arr[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int temp[right - left + 1];
    int inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); // count inversions
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // copy back
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }

    return inv_count;
}

int mergeSort(int arr[], int left, int right) {
    int inv_count = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        inv_count += mergeSort(arr, left, mid);
        inv_count += mergeSort(arr, mid + 1, right);
        inv_count += merge(arr, left, mid, right);
    }

    return inv_count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int result = mergeSort(arr, 0, n - 1);

    printf("%d\n", result);
    return 0;
}