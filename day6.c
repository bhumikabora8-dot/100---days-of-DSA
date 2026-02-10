#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    if (n == 0)
        return 0;
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int j = 1;  
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[j] = arr[i];
            j++;
        }
    }
    for (int i = 0; i < j; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
