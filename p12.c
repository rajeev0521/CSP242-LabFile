#include <stdio.h>
#define MAX_SIZE 100 // Maximum size of the queue

int queue[MAX_SIZE]; // Array to store the queue elements
int front = -1, rear = -1; // Indices to keep track of front and rear elements

void insert(int value) 
{
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear + 1 == front)) 
    {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else if (rear == MAX_SIZE - 1) {
        rear = 0;
    } else {
        rear++;
    }

    queue[rear] = value;
    printf("Inserted %d into the queue\n", value);
}

int delete() 
{
    int value;
    if (front == -1) 
    {
        printf("Queue is empty\n");
        return -1;
    }

    value = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX_SIZE - 1) {
        front = 0;
    } else {
        front++;
    }

    printf("Deleted %d from the queue\n", value);
    return value;
}

void display() 
{
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[i]);
}

int main() {
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 1;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}