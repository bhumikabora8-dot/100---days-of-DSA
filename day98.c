#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting by start time
int compare(const void* a, const void* b) {
    int* x = (int*)a;
    int* y = (int*)b;
    return x[0] - y[0];
}

void mergeIntervals(int intervals[][2], int n) {
    // Step 1: Sort intervals
    qsort(intervals, n, sizeof(intervals[0]), compare);

    int result[n][2];
    int index = 0;

    // Step 2: Add first interval
    result[index][0] = intervals[0][0];
    result[index][1] = intervals[0][1];

    // Step 3: Merge
    for (int i = 1; i < n; i++) {
        // If overlapping
        if (intervals[i][0] <= result[index][1]) {
            if (intervals[i][1] > result[index][1]) {
                result[index][1] = intervals[i][1];
            }
        } else {
            index++;
            result[index][0] = intervals[i][0];
            result[index][1] = intervals[i][1];
        }
    }

    // Step 4: Print result
    for (int i = 0; i <= index; i++) {
        printf("%d %d\n", result[i][0], result[i][1]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int intervals[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    mergeIntervals(intervals, n);

    return 0;
}