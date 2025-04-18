
// C program to demonstrate various tree traversal methods
// including in-order, pre-order, post-order, and breadth-first traversal.

/*
***************************Sample Input/Output:********************************************************

Create a binary tree (enter -1 for NULL nodes):
Enter node data (-1 for NULL): 1
Enter left child of 1
Enter node data (-1 for NULL): 2
Enter left child of 2
Enter node data (-1 for NULL): 4
Enter left child of 4
Enter node data (-1 for NULL): -1
Enter right child of 4
Enter node data (-1 for NULL): -1
Enter right child of 2
Enter node data (-1 for NULL): 5
Enter left child of 5
Enter node data (-1 for NULL): -1
Enter right child of 5
Enter node data (-1 for NULL): -1
Enter right child of 1
Enter node data (-1 for NULL): 3
Enter left child of 3
Enter node data (-1 for NULL): -1
Enter right child of 3
Enter node data (-1 for NULL): -1
*/

/*
In tree Explanation of above input

    1
   / \
  2   3
 / \
4   5

*/


#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Tree node structure
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Queue structure for breadth-first traversal
struct Queue {
    struct TreeNode* items[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

// Create a new tree node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Queue functions
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isQueueEmpty(struct Queue* queue) {
    return queue->front == -1;
}

int isQueueFull(struct Queue* queue) {
    return queue->rear == MAX_QUEUE_SIZE - 1;
}

void enqueue(struct Queue* queue, struct TreeNode* node) {
    if (isQueueFull(queue)) {
        printf("Queue is full!\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = node;
}

struct TreeNode* dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty!\n");
        return NULL;
    }
    struct TreeNode* node = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return node;
}

// In-order traversal (Left -> Root -> Right)
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Pre-order traversal (Root -> Left -> Right)
void preOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Post-order traversal (Left -> Right -> Root)
void postOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Breadth-first (level-order) traversal
void breadthFirstTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    while (!isQueueEmpty(queue)) {
        struct TreeNode* currentNode = dequeue(queue);
        printf("%d ", currentNode->data);

        if (currentNode->left != NULL) {
            enqueue(queue, currentNode->left);
        }
        if (currentNode->right != NULL) {
            enqueue(queue, currentNode->right);
        }
    }

    free(queue);
}

// Free tree memory
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Create tree with user input
struct TreeNode* createTree() {
    int data;
    printf("Enter node data (-1 for NULL): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct TreeNode* node = createNode(data);
    printf("Enter left child of %d\n", data);
    node->left = createTree();
    printf("Enter right child of %d\n", data);
    node->right = createTree();

    return node;
}

// Main function
int main() {
    printf("Create a binary tree (enter -1 for NULL nodes):\n");
    struct TreeNode* root = createTree();

    printf("\nIn-Order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-Order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    printf("Breadth-First Traversal: ");
    breadthFirstTraversal(root);
    printf("\n");

    // Free allocated memory
    freeTree(root);

    return 0;
}