#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertAtBeginning(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}
void insertAtEnd(int data){
    struct Node* newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        return;
    }
    struct Node* p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = newnode;
}
void insertAtPosition(int data, int pos){
    if(pos < 1){
        printf("Invalid Input Made\n");
        return;
    }
    if(pos == 1){
        insertAtBeginning(data);
        return;
    }
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node* p = head;
    for(int i = 1; p != NULL && i < pos-1; i++){
        p = p->next;
    }
    if(p == NULL){
        printf("IndexOutOfBounds Error\n");
        free(newnode);
        return;
    }
    newnode->next = p->next;
    p->next = newnode;
}
void deleteAtBeginning(){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}
void deleteAtEnd(){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    struct Node* p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}
void deleteAtPosition(int pos){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    struct Node* p = head;
    for(int i = 1; p != NULL && i < pos-1; i++){
        p = p->next;
    }
    if(p == NULL){
        printf("IndexOutOfBound Error\n");
        return;
    }
    struct Node* temp = p->next;
    p->next = p->next->next;
    free(temp);
}
void display(){
    if(head == NULL){
        printf("List is Empty\n");
        return;
    }
    struct Node* p = head;
    while(p!=NULL){
        printf("%d->",p->data);
        p = p->next;
    }
    printf("NULL\n");
}
int main(){
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtPosition(15, 2);
    display();
    deleteAtBeginning();
    display();
    deleteAtEnd();
    display();
    deleteAtPosition(2);
    display();
}
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;
void insertAtBeginning(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    if(head == NULL){
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode; 
        return;
    }
    newnode->prev = head->prev;
    head->prev = newnode;
    newnode->next = head;
    newnode->prev->next = newnode;
}
void insertAtEnd(int data){
    if(head == NULL){
        insertAtBeginning(data);
        return;
    }
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    struct Node* p = head;
    while(p->next != head){
        p = p->next;
    }
    newnode->next = head;
    newnode->prev = p;
    p->next = newnode;
    head->prev = newnode;
}
void insertAtPosition(int data, int pos){
    if (pos < 1){
        printf("Invalid Entry Made\n");
        return;
    }
    if (pos == 1){
        insertAtBeginning(data);
        return;
    }
    struct Node *p = head;
    for (int i = 1; i < pos - 1; i++){
        p = p->next;
        if (p == head){
            printf("IndexOutOfBounds Error\n");
            return;
        }
    }
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = p->next;
    newnode->prev = p;
    p->next->prev = newnode;
    p->next = newnode;
}
void deleteAtBeginning(){
    if(head == NULL){
        printf("Empty List\n");
        return;
    }  
    if(head->next == head){
        free(head);
        head = NULL;
    }
    struct Node* temp = head;
    head->prev->next = head->next;
    head->next->prev = head->prev;
    head = head->next;
    free(temp);
}
void deleteAtEnd(){
    if(head == NULL){
        printf("Empty List\n");
        return;
    }
    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }
    struct Node* p = head->prev->prev;
    free(p->next);
    p->next = head;
    head->prev = p;
}
void deleteAtPosition(int pos){
    if (head == NULL || pos < 1){
        printf("Empty List or invalid position\n");
        return;
    }
    if (pos == 1){
        deleteAtBeginning();
        return;
    }
    struct Node *p = head;
    for (int i = 1; i < pos; i++){
        p = p->next;
        if (p == head){
            printf("Index out of bounds\n");
            return;
        }
    }
    p->prev->next = p->next;
    p->next->prev = p->prev;
    free(p);
}
void display(){
    if(head == NULL){
        printf("Empty List\n");
    }
    struct Node* p = head->next;
    printf("%d<->",head->data);
    while(p!= head){
        printf("%d<->",p->data);
        p = p->next;
    }
    printf("%d\n",head->data);
}
int main(){
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtPosition(15, 2);
    display();
    deleteAtBeginning();
    display();
    deleteAtEnd();
    display();
    deleteAtPosition(2);
    display();
}
struct poly{
    int coeff;
    int power;
    struct poly* next;
};
struct poly *create(struct poly *head, struct poly *newnode){
    if(head == NULL){
        newnode->next = NULL;
        return newnode;
    }
    struct poly* p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = newnode;
    newnode->next = NULL;
    return head;
}
struct poly* add(struct poly* a, struct poly* b){
    struct poly* ptra = a;
    struct poly* ptrb = b;
    struct poly* res = NULL;
    while(ptra != NULL && ptrb != NULL){
        struct poly* curr = (struct poly *)malloc(sizeof(struct poly));
        if(ptra->power == ptrb->power){
            curr->coeff = ptra->coeff+ptrb->coeff;
            curr->power = ptra->power;
            ptra = ptra->next;
            ptrb = ptrb->next;
        }else if(ptra->power < ptrb->power){
            curr->coeff = ptrb->coeff;
            curr->power = ptrb->power;
            ptrb = ptrb->next;
        }else{
            curr->coeff = ptra->coeff;
            curr->power = ptra->power;
            ptra = ptra->next;
        }
        curr->next = NULL;
        res = create(res,curr);
    }
    while(ptra != NULL || ptrb != NULL){
        struct poly* curr = (struct poly*)malloc(sizeof(struct poly));
        if(ptra != NULL){
            curr->coeff = ptra->coeff;
            curr->power = ptra->power;
            ptra = ptra->next;
        }else{
            curr->coeff = ptrb->coeff;
            curr->power = ptrb->power;
            ptrb = ptrb->next;
        }
        curr->next = NULL;
        res = create(res,curr);
    }
    return res;
}
struct poly* mulltiply(struct poly* a,  struct poly* b){
    struct poly *ptra = a;
    struct poly *ptrb = b;
    struct poly *res = NULL;
    while (ptra != NULL && ptrb != NULL)
    {
        struct poly *curr = (struct poly *)malloc(sizeof(struct poly));
        if (ptra->power == ptrb->power)
        {
            curr->coeff = ptra->coeff * ptrb->coeff;
            curr->power = ptra->power + ptrb->power;
            ptra = ptra->next;
            ptrb = ptrb->next;
        }
        else if (ptra->power < ptrb->power)
        {
            curr->coeff = ptrb->coeff;
            curr->power = ptrb->power;
            ptrb = ptrb->next;
        }
        else
        {
            curr->coeff = ptra->coeff;
            curr->power = ptra->power;
            ptra = ptra->next;
        }
        curr->next = NULL;
        res = create(res, curr);
    }
    while (ptra != NULL || ptrb != NULL)
    {
        struct poly *curr = (struct poly *)malloc(sizeof(struct poly));
        if (ptra != NULL)
        {
            curr->coeff = ptra->coeff;
            curr->power = ptra->power;
            ptra = ptra->next;
        }
        else
        {
            curr->coeff = ptrb->coeff;
            curr->power = ptrb->power;
            ptrb = ptrb->next;
        }
        curr->next = NULL;
        res = create(res, curr);
    }
    return res;
}
struct poly *sub(struct poly *a, struct poly *b){
    struct poly *ptra = a;
    struct poly *ptrb = b;
    struct poly *res = NULL;
    while (ptra != NULL && ptrb != NULL)
    {
        struct poly *curr = (struct poly *)malloc(sizeof(struct poly));
        if (ptra->power == ptrb->power)
        {
            curr->coeff = ptra->coeff - ptrb->coeff;
            curr->power = ptra->power;
            ptra = ptra->next;
            ptrb = ptrb->next;
        }
        else if (ptra->power < ptrb->power)
        {
            curr->coeff = -ptrb->coeff;
            curr->power = ptrb->power;
            ptrb = ptrb->next;
        }
        else
        {
            curr->coeff = ptra->coeff;
            curr->power = ptra->power;
            ptra = ptra->next;
        }
        curr->next = NULL;
        res = create(res, curr);
    }
    while (ptra != NULL || ptrb != NULL)
    {
        struct poly *curr = (struct poly *)malloc(sizeof(struct poly));
        if (ptra != NULL)
        {
            curr->coeff = ptra->coeff;
            curr->power = ptra->power;
            ptra = ptra->next;
        }
        else
        {
            curr->coeff = -ptrb->coeff;
            curr->power = ptrb->power;
            ptrb = ptrb->next;
        }
        curr->next = NULL;
        res = create(res, curr);
    }
    return res;
}
struct poly* differentiation(struct poly* a){
    struct poly* res = NULL;
    while(a!=NULL){
        if(a->power == 0){
            // a = a->next;
            continue;
        }
        struct poly* curr = (struct poly*)malloc(sizeof(struct poly));
        curr->coeff = a->coeff*a->power;
        curr->power = a->power-1;
        res = create(res,curr);
        a = a->next;
    }
    return res;
}
void display(struct poly* head){
    if(head == NULL){
        printf("Empty Equation");
        return;
    }
    struct poly* p = head;
    while(p!=NULL){
        printf("%d^x%d",p->coeff,p->power);
        p = p->next;
        if(p != NULL){
            printf(" + ");
        }
    }
}
struct poly* createNode(int coeff, int power){
    struct poly* res = (struct poly*)malloc(sizeof(struct poly));
    res->coeff = coeff;
    res->power = power;
    res->next = NULL;
    return res;
}
int main(){
    struct poly* a = NULL;
    struct poly* b = NULL;
    a = create(a,createNode(5,3));
    a = create(a,createNode(6,2));
    a = create(a,createNode(7,1));
    b = create(b,createNode(3,3));
    b = create(b,createNode(3,2));
    b = create(b,createNode(4,1));
    b = create(b,createNode(7,0));
    struct poly* ans = sub(a,b);
    display(ans);
    ans = add(a, b);
    display(ans);
    ans = mulltiply(a, b);
    display(ans);
    ans = differentiation(a);
    display(ans);
}
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct Queue{
    int size;
    int arr[MAX];
    int front, rear;
    int* arr;
};
struct Queue* createQueue(int size){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->rear = -1;
    q->front = -1;
    q->arr = (int*)malloc(sizeof(int)*size);
    return q;
}
void enqueue(struct Queue* q, int data){
    if(q->rear == q->size-1){
        printf("Queue Overflow");
        return;
    }
    if(q->front == -1){
        q->front = 0;
    }
    q->arr[++q->rear] = data;
}
int dequeue(struct Queue* q){
    if(q->front == -1 || q->front > q->rear){
        printf("Queue Underflow");
        return -1;
    }
    q->front++;
    return q->arr[q->front-1];
}
void display(struct Queue* q){
    for(int i = q->front; i <= q->rear; i++){
        printf("%d ",q->arr[i]);
    }
}
int main(){
    struct Queue *q = createQueue(5);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Queue{
    struct Node* front;
    struct Node* rear;
};
struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}
void enqueue(struct Queue *q, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL){
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}
int dequeue(struct Queue* q){
    if(q->front == NULL){
        printf("Queue Underflow");
        return -1;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL){
        q->rear = NULL;
    }
    return data;
}
void display(struct Queue* q){
    if(q->front == NULL){
        printf("EMPTY");
        return;
    }
    struct Node* p = q->front;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}
int main()
{
    struct Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    printf("Dequeued: %d\n", dequeue(q));
    display(q);
}
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct CQueue{
    int front,rear;
    int arr[MAX];
};
void init(struct CQueue* q){
    q->front = -1;
    q->rear = -1;
}
int isFull(struct CQueue* q){
    return ((q->front == 0 && q->rear == MAX - 1) ||
            (q->rear == (q->front - 1) % (MAX - 1)));
}
int isEmpty(struct CQueue* q){
    return q->front == -1;
}
void enqueue(struct CQueue *q, int val){
    if (isFull(q)){
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1){
        q->front = q->rear = 0;
    }
    else if (q->rear == MAX - 1 && q->front != 0){
        q->rear = 0; 
    }
    else{
        q->rear++;
    }
    q->arr[q->rear] = val;
}
int dequeue(struct CQueue *q)
{
    if (isEmpty(q)){
        printf("Queue Underflow\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear){
        q->front = q->rear = -1;
    }
    else if (q->front == MAX - 1){
        q->front = 0; // wrap
    }
    else{
        q->front++;
    }
    return val;
}
void display(struct CQueue *q){
    if (isEmpty(q)){
        printf("Queue Empty\n");
        return;
    }
    printf("Queue: ");
    if (q->rear >= q->front){
        for (int i = q->front; i <= q->rear; i++)
            printf("%d ", q->arr[i]);
    }
    else{
        for (int i = q->front; i < MAX; i++)
            printf("%d ", q->arr[i]);
        for (int i = 0; i <= q->rear; i++)
            printf("%d ", q->arr[i]);
    }
    printf("\n");
}
int main(){
    struct CQueue q;
    init(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);
    enqueue(&q, 50);
    enqueue(&q, 60);
    display(&q);
    enqueue(&q, 70);
}