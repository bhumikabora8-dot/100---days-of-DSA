#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int count = 0;

    // Using large array for hash map (adjust size if needed)
    int hash[20001] = {0};  
    int offset = 10000;   // To handle negative sums

    hash[offset] = 1;  // To count subarrays starting from index 0

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(hash[prefixSum + offset] > 0) {
            count += hash[prefixSum + offset];
        }

        hash[prefixSum + offset]++;
    }

    printf("%d\n", count);

    return 0;
}