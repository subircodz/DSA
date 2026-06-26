#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int height;
    int roll;
    char names[64];
    float marks;
    struct node *left;
    struct node *right;
} DataType_node;

// function to rotate right
DataType_node * rightRotate(DataType_node * root){
    DataType_node * newRoot = root->left;
    DataType_node * temp = newRoot->right;
    newRoot->right = root;
    root->left = temp;
    return newRoot;
}

// Funtion to left rotate
DataType_node * leftRotate(DataType_node * root){
    DataType_node * newRoot = root->right;
    DataType_node * temp = newRoot->left;
    newRoot->left = root;
    root->right = temp;
    return newRoot;
}

DataType_node *createStudent(int roll, const char names[], float marks)
{
    DataType_node *newNode = (DataType_node *)malloc(sizeof(DataType_node));
    if (!newNode)
        return NULL;
    newNode->roll = roll;
    strcpy(newNode->names, names);
    newNode->marks = marks;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
int findHeight(DataType_node *node){
    if (node == NULL){
        return 0;
    }
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    if (leftHeight > rightHeight){
        return leftHeight+1;
    }else{
        return rightHeight+1;
    }
}

// Function to get the balance factor of a node.
int getBalanceFactor(DataType_node * node){
    if(node == NULL){
        return 0;
    }
    return findHeight(node->left) - findHeight(node->right);
}



// insert nodes in BST
DataType_node *insert(DataType_node *root, int roll, const char names[], float marks)
{

    // checking if root is NULL; now root->right means root
    if (root == NULL)
    {
        return createStudent(roll, names, marks);
    }
    // comparing
    int compare = strcmp(names, root->names);
    if (compare < 0)
    {
        root->left = insert(root->left, roll, names, marks);
    }
    else if (compare > 0)
    {
        root->right = insert(root->right, roll, names, marks);
    }
    int bf = getBalanceFactor(root);
    printf("\nNode : %s\n", root->names);
    printf("Balance Factor: %d\n", bf);
    //if bf is not [-1, 0, 1] then balancing is required
    if(bf > 1){
        //"Abc bigger than Ais? No"
        if(strcmp(names, root->left->names) < 0){
            printf("Its left skewed\n");
            printf("LL Type Case\n");
            printf("Right rotation required: %s\n", root->names);
            // Ais will be the new root
            root = rightRotate(root);
            printf("My root is now: %s", root->names);
            
        }
        else{
            printf("LR case detected\n");
            printf("Left rotation required at %s\n", root->left->names);
            printf("Right rotation is required at %s\n", root->names);
        }
    }
    if(bf < -1){
        if(strcmp(names, root->right->names) > 0){
            printf("Its a right skewed tree\n");
            printf("RR case detected\n");
            printf("Left Rotation required at %s\n", root->names);
            root = leftRotate(root);
            printf("My root is now: %s\n", root->names);
        }
        else{
            printf("RL case detected\n");
            printf("Right rotation required at %s\n", root->right->names);
            printf("Left rotation required at %s\n", root->names);
        }
    }
    if ((bf == 0) || (bf == 1) || (bf == -1)){
        printf("The tree is balanced\n");
    }


    return root;
}

void inOrderPrinter(DataType_node *box)
{
    if (box == NULL)
    {
        return;
    }
    inOrderPrinter(box->left);
    printf("%d | %s | %.2f\n", box->roll, box->names, box->marks);
    inOrderPrinter(box->right);
}

void preOrderPrinter(DataType_node *box)
{
    if (box == NULL)
    {
        return;
    }
    printf("%d | %s | %.2f\n", box->roll, box->names, box->marks);
    preOrderPrinter(box->left);
    preOrderPrinter(box->right);
}

void postOrderPrinter(DataType_node *box)
{
    if (box == NULL)
    {
        return;
    }
    postOrderPrinter(box->left);
    postOrderPrinter(box->right);
    printf("%d | %s | %.2f\n", box->roll, box->names, box->marks);
}

void search(DataType_node *bst, const char name[])
{
    if (bst == NULL)
    {
        printf("%s is not found in BST\n", name);
        return;
    }
    int compare = strcmp(name, bst->names);
    if (compare == 0)
    {
        printf("%s is found in the tree\n", name);
        printf("Roll No: %d\n", bst->roll);
        printf("Marks: %.2f\n", bst->marks);
    }
    else if (compare < 0)
    {
        search(bst->left, name);
    }
    else
    {
        search(bst->right, name);
    }
}

int checkValidity(DataType_node *root, const char *min, const char *max)
{
    if (root == NULL)
    {
        return 1;
    }
    if (min != NULL && strcmp(root->names, min) < 0)
    {
        return 0;
    }
    if (max != NULL && strcmp(root->names, max) > 0)
    {
        return 0;
    }
    return checkValidity(root->left, min, root->names) &&
           checkValidity(root->right, root->names, max);
}
// This will find out the next node
DataType_node *findNext(DataType_node *node)
{
    if(node == NULL){
        return NULL;
    }
    while(node->left != NULL){
        node = node->left;
    }
    return node;
}

// Delete Operation
DataType_node *deleteNode(DataType_node *node, char name[]){
    if(node == NULL){
        return NULL;
    }
    int compare =strcmp(name, node->names); // -1, 0, +1
    if (compare < 0){
        node->left = deleteNode(node->left, name);
    }
    else if (compare > 0){
        node->right = deleteNode(node->right, name);
    }
    else{
        // node mill gaya
        // Case 1 is done
        if (node->left == NULL && node->right==NULL){
            //printf("%s deleted\n", node->names);
            free(node);
            return NULL;
        }
        // Case two single child parent.
        if(node->left == NULL){
            DataType_node *temp = node->right;
            printf("%s takes it place\n", temp->names);
            free(node);
            return temp;
        }
        if (node->right == NULL){
            DataType_node *temp = node->left;
            printf("%s takes it place\n",temp->names);
            free(node);
            return temp;
        }
        // Case 3
        DataType_node *nextNode = findNext(node->right);
        printf("%s got deleted\n", node->names);
        node->roll = nextNode->roll;
        strcpy(node->names, nextNode->names);
        node->marks = nextNode->marks;
        node->right = deleteNode(node->right, nextNode->names);
    }
    return node;
}

DataType_node *searchNode(DataType_node *node, char name[]){
    if (node == NULL){
        return NULL;
    }
    int compare = strcmp(name, node->names);
    if (compare == 0){
        return node;
    }
    else if (compare < 0){
        return searchNode(node->left, name);
    }
    else{
        return searchNode(node->right, name);
    }
}

int main()
{
    DataType_node *root = NULL;
    root = insert(root, 101, "Amit", 89.3);
    // root = insert(root, 106, "Aiswarya", 78.8);
    // root = insert(root, 104, "Abc", 68.8);
    // root = insert(root, 105, "Ajit", 78.8);
    root = insert(root, 102, "Kiran", 86.7);
    root = insert(root, 103, "Mary", 80.3);
    // root = insert(root, 104, "Nancy", 50.8);
    // root = insert(root, 105, "Subu", 78.8);
    // root = insert(root, 107, "Anupa", 78.8);
    // root = insert(root, 109, "Ani", 78.8);
    // root = insert(root, 108, "Mack", 78.8);
    printf("------ IN ORDER TRAVERSAL -----\n");
    inOrderPrinter(root);
    printf("------ PRE ORDER TRAVERSAL -----\n");
    preOrderPrinter(root);
    printf("------ POST ORDER TRAVERSAL -----\n");
    postOrderPrinter(root);
    // part 5
    search(root, "Subu");
    search(root, "Aiswarya");
    search(root, "Tushar");
    printf("\n");
    int check = checkValidity(root, NULL, NULL);
    if (check == 1)
    {
        printf("This is a valid BST\n");
    }
    else
    {
        printf("This is not a valid BST\n");
    }
    char del_Choice;
    printf("Do you want to delete? y/n: ");
    scanf("%c", &del_Choice);
    if (del_Choice == 'y'){
        char delete[] = "Aiswarya";
        root = deleteNode(root, delete);
        if(root != NULL){
            printf("Root is : %s\n", root->names);
        }
        else{
            printf("Tree does not exist");
        }
        inOrderPrinter(root);   

    } 
    // Finding height
    // char name[] = "Amit";
    // DataType_node *nodeName = searchNode(root, name);
    // if (nodeName != NULL){
    //     int treeHeight = findHeight(nodeName);
    //     printf("Height of %s is %d\n", name, treeHeight);
    // }else{
    //     printf("%s is not found\n", name);
    // }
    // Balance Factor
    // int bf = findHeight(nodeName->left) - findHeight(nodeName->right);
    // printf("Balance Factor of %s is %d\n", name, bf);


    return 0;
}
