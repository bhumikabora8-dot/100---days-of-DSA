#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x)
{
    pq[size++] = x;

    // Sort to maintain priority (smallest first)
    for(int i = 0; i < size-1; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(pq[i] > pq[j])
            {
                int temp = pq[i];
                pq[i] = pq[j];
                pq[j] = temp;
            }
        }
    }
}

int delete()
{
    if(size == 0)
        return -1;

    int val = pq[0];

    for(int i = 1; i < size; i++)
        pq[i-1] = pq[i];

    size--;
    return val;
}

int peek()
{
    if(size == 0)
        return -1;

    return pq[0];
}

int main()
{
    int n, x;
    char op[10];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "insert") == 0)
        {
            scanf("%d", &x);
            insert(x);
        }
        else if(strcmp(op, "delete") == 0)
        {
            printf("%d\n", delete());
        }
        else if(strcmp(op, "peek") == 0)
        {
            printf("%d\n", peek());
        }
    }

    return 0;
}