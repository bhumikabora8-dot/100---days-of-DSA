#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* m1 = (int*)a;
    int* m2 = (int*)b;
    return m1[0] - m2[0]; // sort by start time
}

int minRooms(int intervals[][2], int n) {
    // Step 1: sort by start time
    qsort(intervals, n, sizeof(intervals[0]), compare);

    int heap[1000]; // simple array as min heap
    int size = 0;

    for (int i = 0; i < n; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // if earliest meeting ends before current starts
        if (size > 0 && heap[0] <= start) {
            heap[0] = end; // replace root
        } else {
            heap[size++] = end; // new room
        }

        // simple heapify (min heap)
        for (int j = size/2 - 1; j >= 0; j--) {
            int parent = j;
            int left = 2*j + 1;
            int right = 2*j + 2;
            int smallest = parent;

            if (left < size && heap[left] < heap[smallest])
                smallest = left;
            if (right < size && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != parent) {
                int temp = heap[parent];
                heap[parent] = heap[smallest];
                heap[smallest] = temp;
            }
        }
    }

    return size;
}

int main() {
    int n;
    scanf("%d", &n);

    int intervals[n][2];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    printf("%d\n", minRooms(intervals, n));
    return 0;
}