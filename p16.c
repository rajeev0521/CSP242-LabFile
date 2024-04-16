/*
P16: Write a menu-based program to perform operations for a binary 
search tree (BST).
a. Search an element
b. Find minimum
c. Find maximum
d. Insertion
e. Deletion
*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) 
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) 
{
    if (root == NULL) {
        return createNode(data);
    }

    else if (data < root->data) 
    {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// struct node* search(struct node* root, int data) {
//     if (root == NULL || root->data == data) {
//         return root;
//     }
//     else if (root->data < data) {
//         return search(root->right, data);
//     }
//     else if(root -> data > data){
//         return search(root->left, data);
//     }
// }

struct node* min(struct node* root) {
    if (root == NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* max(struct node* root){
    if(root == NULL){
        return NULL;
    }
    while(root -> right != NULL){
        root = root -> right;
    }
    return root;
}

struct node* deleteNode(struct node* root, int data) {
    if (root == NULL) {
        return NULL;
    }
    if (data < root->data) {
        root -> left = deleteNode(root -> left, data);
    }
    else if (data > root->data) {
        root -> right = deleteNode(root -> right, data);
    }
    else {
        if (root -> left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root -> right == NULL) {
            struct Node* temp = root -> left;
            free(root);
            return temp;
        }
        struct node* temp = min(root -> right);
        root -> data = temp -> data;
        root -> right = deleteNode(root -> right, temp -> data);
    }
    return root;
}

void main(){
    struct node *root = NULL;
    int choice, data;

    while (1)
    {
        printf("Choose the option: \n");
        printf("\n1. Searching\n2. Minimum\n3. Maximum\n4. Insertion\n5. Deletion\n6. Exist");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to Search: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                
        }
    }
    
}