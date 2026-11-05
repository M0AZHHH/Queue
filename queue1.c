#include <stdio.h>

int queue[7];
int front = -1;
int rear =-1;

int isfull(){
    return rear == 6;
    }
int isempty(){
    return front == -1 || front > rear;
}
void enqueue(int value){
    if(isfull()){
        printf("queue is full\n");
        return;
    }
    if(isempty()){
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("enqueued %d\n",value);
}
void dequeue(){
    if(isempty()){
        printf("queue is empty\n");
        return;
    }
    printf("dequeued %d\n",queue[front]);
    front++;

    // kuyrugu sifirleme//
    if(front > rear){
        front = -1;
        rear = -1;
    }
}    
    void peek(){
        if(isempty()){
            printf("queue is empty\n");
            return;
        }
        printf("peeked %d\n", queue[front]);
}
    void cleanqueue(){
        front = -1;
        rear = -1;
        printf("queue cleaned\n");
    }
    int main(){
        int x , value;
        while(1){
            printf("choose an operation:\n");
            printf("1. enqueue\n");
            printf("2. dequeue\n");
            printf("3. peek\n");
            printf("4. cleanqueue\n");
            printf("5. exit\n");
            printf("enter your choice: ");
            scanf("%d",&x);
        switch(x){
            case 1:
                printf("enter value to enqueue: ");
                scanf("%d",&value);
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
                printf("invalid choice\n");
        }
    }
}