#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 10
typedef struct node {
    int data;
    struct node* next;
} Node;
typedef struct{
	int cnt;
	struct node* front;
	struct node* rear;
}queue;
void initialize(queue * q){
	q->cnt=0;
	q->front=q->rear=NULL;
	
}
void enqueue(queue *q , int x){
	if(q->cnt==QUEUE_SIZE){
		printf("Queue is full");
		return 1;
	}else{
		Node* temp=(Node*)malloc(sizeof(Node));
		temp->data=x;
		temp->next=NULL;
	 if (q->cnt == 0) {
            q->front = q->rear = temp;
        } else {
            q->rear->next = temp;
            q->rear = temp;
        }
		q->cnt++;
	}
}


int dequeue (queue *q){
	if(q->cnt== 0){
		printf("Queue is empty");
		return 0;
	}else{
		int x=q->front->data;
		Node* temp=q->front;
		q->front=temp->next;
		free(temp);
		q->cnt--;
		return x;
	}
}

void printQueue(queue* q) {
    printf("Queue elements: ");
    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
	queue myQueue;
    initialize(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printQueue(&myQueue);
    printf("Dequeued element: %d\n", dequeue(&myQueue));
    printQueue(&myQueue);
     
	return 0;
}
