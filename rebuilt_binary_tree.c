/*重建二叉树*/

#include<stdio.h>
#include<stdlib.h>

struct BinaryTreeNode {
    int     m_nKey;
    struct BinaryTreeNode *left, *right;
};

BinaryTreeNode *
Construct(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder)
{
    int rootValue = startInOrder[0];
    
    BinaryTreeNode *root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    root->m_nKey = rootValue;
    root->left = root->right = NULL;
    
    if(startPreOrder == endPreOrder) {
        if(startPreOrder == endInOrder && *startInOrder == *startPreOrder) 
            return root;
    }
    
    int *InOrderRoot = startInOrder;
    while(*startInOrder != rootValue)
        ++InOrderRoot;
    if(InOrderRoot == endInOrder && *InOrderRoot != rootValue) {
        return NULL;
    }
    
    int left_lenth = InOrderRoot - startInOrder;
    if(left_lenth > 0)
        root->left = Construct(startPreOrder+1, startPreOrder + left_lenth, startInOrder, InOrderRoot - 1);
    if(left_lenth < endPreOrder - startPreOrder)
        root->right = Construct(startPreOrder + left_lenth + 1, endPreOrder, InOrderRoot + 1, endInOrder);
        
    return root;    
}

BinaryTreeNode *
rebuilt(int *preOrder, int *inOrder, int length)
{
    if(!preOrder || !inOrder || length <= 0)
        return NULL;
        
    return Construct(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}