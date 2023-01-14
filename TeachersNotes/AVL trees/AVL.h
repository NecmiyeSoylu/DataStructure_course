#include <stdio.h>//listeyse başa orrtaya sona ekelme eğer bir düğüm varsa boş olma durumu
#include <stdlib.h>
struct node
{
    int data;
    int height;
    struct node *right;
    struct node *left;
};
typedef struct node AVLTree;
AVLTree* createNode(int data)
{
    AVLTree *node=(AVLTree*)malloc(sizeof(AVLTree));
    node->data=data;
    node->right=NULL;
    node->left=NULL;
    node->height=1;
    return node;
}
int max(int a, int b)
{
    return (a>b) ? a:b;
}
int height(AVLTree *node)
{
    if(node==NULL) return 0;
    return node->height;
}
AVLTree* rightRotate(AVLTree *z)
{
    AVLTree *y=z->left;
    
    z->left=y->right;
   y->right=z;

    z->height=max(z->left->height,z->right->height);
    y->height=max(y->left->height,y->right->height);

    return y;
}
AVLTree* leftRotate(AVLTree *z)
{
    AVLTree *x=z->right;
    
    z->right=x->left;
    x->left=z;

    x->height=1+max(x->left->height,x->right->height);
    z->height=1+max(z->left->height,z->right->height);

    return x;
}
int getBalance(AVLTree *node)
{
    if(node==NULL) return 0;
    return height(node->left)-height(node->right);
}
AVLTree* insert(AVLTree *node, int data)
{
    //NULL olma durumu yeni node creating
    if(node==NULL)
    {
        return createNode(data);
    }
    
    //doğru yeri bulma ve ekleme
    if(node->data>data)
        node->left=insert(node->left,data);
    else if(node->data<data)
        node->right=insert(node->right,data);
    
    //yükseklik güncelleme
    node->height=1+max(height(node->left), height(node->right));
    
    //denge hesabı
    int b=getBalance(node);

    //left left rotation
    if(b>1 && data < node->left->data)
        return rightRotate(node);
   
    //right right rotation
    if(b < -1 && data > node->right->data)
        return leftRotate(node);
    
    //left right rotation
    if(b>1 && data > node->left->data)
    {
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }

    //right left rotation
    if(b<-1 && data < node->right->data)
    {
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void preOrder(AVLTree *node)
{
    if(node!=NULL)
    {
        printf("\n%d",node->data);
        preOrder(node->left);
        preOrder(node->right);
    } 

}
