#include <stdio.h>

int queue[7];
int front = 0;
int rear = -1;
int count = 0;

int isempty(){
    return count == 0;
}
int isfull(){
    return count == 7;
}
void enqueue(int value){
    if(isfull()){
        printf("Queue is full\n");
        return;    
    }
    rear = (rear + 1) % 7;
    queue[rear] = value;
    count++;
    printf("Enqueued %d\n", value);
}
void dequeue(){
    if(isempty()){
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued %d\n", queue[front]);
    front = (front + 1) % 7;
    count--;
}
void peek(){
    if(isempty()){
        printf("Queue is empty\n");
        return;
    }
    printf("peeked %d\n", queue[front]);
}
void cleanqueue(){
    front = 0;
    rear = -1;
    count = 0;
    printf("queue cleaned\n");
}
int main(){
    int value, x;
    while(1){
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Clean Queue\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &x);
    switch(x){
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            cleanqueue();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
    
        }
    }
}