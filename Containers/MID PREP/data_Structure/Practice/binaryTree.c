// Tree traversal in C

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* left;
    struct node* right;
};

struct node *makeRootOfTree(int value)
{
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->info = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}

struct node *InsertAValueAnyWhere(struct node *root, int value)
{
    if(root==NULL)
    {
        return makeRootOfTree(value);
    }
    else if(value < root->info)
    {
        root->left = InsertAValueAnyWhere(root->left, value);
    }
    else if(value > root->info)
    {
        root->right = InsertAValueAnyWhere(root->right, value);
    }

    return root;
}

struct node *SearchNode(struct node *root, int key)
{
    if(root==NULL || root->info == key)
    {
        return root;
    }
    else if(root->info <key)
    {
        return SearchNode(root->right, key);
    }
    else if(root->info > key)
    {
        return SearchNode(root->left, key);
    }

    return root;
}
// Inorder traversal
void inorderTraversal(struct node* root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ->", root->info);
    inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node* root)
{
    if (root == NULL) return;
    printf("%d ->", root->info);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root)
{
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->info);
}

void destroyTree(struct node *root)
{
    if(root !=0)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}

struct node * findMin(struct node *root)
{
    if(root !=NULL)
    {
        return findMin(root->left);
    }
    else
    {
        printf("Min Node is : %d", root->info);
        return root;
    }
}
struct node * findMax(struct node *root)
{
    if(root !=NULL)
    {
        return findMax(root->right);
    }
    else
    {
        printf("Min Node is : %d", root->info);
        return root;
    }
}


/*
// Create a new Node
struct node* createNode(value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}

*/

int main()
{
    int ch, value, traversal;
    struct node * temp;
    while(1)
    {
        printf("Select from Below\n");
        printf("\n1. Make Tree\n2. Insert Value\n3. Display Tree\n4. Find Min\n5.Exit\n");
        printf("Choice:");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("Enter The root value:");
            scanf("%d", &value);
            temp = makeRootOfTree(value);
            break;
        case 2:
            printf("Enter a value to insert:");
            scanf("%d", &value);
            InsertAValueAnyWhere(temp, value);
            break;
        case 3:
            printf("Please choose Traversal Method \n1. Inorder \n2.Preorder\n3.PostOrder\n");
            printf("Choice:");
            scanf("%d", &traversal);
            switch(traversal)
            {
            case 1:
                inorderTraversal(temp);
                break;
            case 2:
                preorderTraversal(temp);
                break;
            case 3:
                postorderTraversal(temp);
                break;
            }

        case 4:
            findMin(temp);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Choice, Please try again later!");
            break;

        }
    }
    return 0;
}