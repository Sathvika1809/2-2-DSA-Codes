#include <stdio.h>
#include <stdlib.h>
//To find Height of Tree
//Node structure
typedef struct Node{
    int data;
    struct Node* left,*right;
}Node;
Node* createNode(int val){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}
typedef struct Queue{
    Node** arr;
    int front,rear,size,capacity;
}Queue;
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->arr = (Node**)malloc(capacity * sizeof(Node*));
    return q;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, Node* node) {
    if (q->size == q->capacity) return;
    q->arr[q->rear] = node;
    q->rear = (q->rear + 1) % q->capacity;
    q->size++;
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    Node* node = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

int height(Node* root) {
    if (!root) return 0;

    // Initializing a queue to traverse
    // the tree level by level
    Queue* q = createQueue(100); 
    enqueue(q, root);
    int depth = 0;

    // Loop until the queue is empty
    while (!isEmpty(q)) {
        int levelSize = q->size;

        // Traverse all nodes at the current level
        for (int i = 0; i < levelSize; i++) {
            Node* curr = dequeue(q);
            
            // enqueue their child nodes 
            if (curr->left) enqueue(q, curr->left);
            if (curr->right) enqueue(q, curr->right);
        }

        // Increment depth after traversing each level
        depth++;
    }
    return depth - 1;
}
