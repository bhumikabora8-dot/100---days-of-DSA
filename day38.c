#include <stdio.h>
#define MAX 100

int dq[MAX];
int front = -1, rear = -1;

int empty()
{
    return (front == -1);
}

int size()
{
    if(empty()) return 0;
    return rear - front + 1;
}

void push_front(int x)
{
    if(front == -1)
        front = rear = 0;
    else if(front > 0)
        front--;
    else
    {
        printf("Deque Overflow\n");
        return;
    }

    dq[front] = x;
}

void push_back(int x)
{
    if(front == -1)
        front = rear = 0;
    else if(rear < MAX-1)
        rear++;
    else
    {
        printf("Deque Overflow\n");
        return;
    }

    dq[rear] = x;
}

void pop_front()
{
    if(empty())
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[front]);

    if(front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back()
{
    if(empty())
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[rear]);

    if(front == rear)
        front = rear = -1;
    else
        rear--;
}

void show_front()
{
    if(empty()) printf("-1\n");
    else printf("%d\n", dq[front]);
}

void show_back()
{
    if(empty()) printf("-1\n");
    else printf("%d\n", dq[rear]);
}

void clear()
{
    front = rear = -1;
}

void reverse()
{
    int i = front, j = rear;
    while(i < j)
    {
        int temp = dq[i];
        dq[i] = dq[j];
        dq[j] = temp;
        i++;
        j--;
    }
}

void sort()
{
    for(int i = front; i <= rear; i++)
    {
        for(int j = i+1; j <= rear; j++)
        {
            if(dq[i] > dq[j])
            {
                int temp = dq[i];
                dq[i] = dq[j];
                dq[j] = temp;
            }
        }
    }
}

int main()
{
    push_back(10);
    push_back(30);
    push_front(5);
    push_back(20);

    printf("Front: ");
    show_front();

    printf("Back: ");
    show_back();

    printf("Size: %d\n", size());

    pop_front();
    pop_back();

    printf("Size after pop: %d\n", size());

    reverse();
    sort();

    printf("Deque elements:\n");
    for(int i = front; i <= rear; i++)
        printf("%d ", dq[i]);

    return 0;
}