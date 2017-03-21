#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void visit_node(struct TreeNode *node)
{
    printf(" %d ", node->val);
}

void inorder_traversal(struct TreeNode *root)
{
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    visit_node(root);
    inorder_traversal(root->right); 
}

void preorder_traversal(struct TreeNode *root)
{
    if (root == NULL)
        return;
    visit_node(root);
    preorder_traversal(root->left);
    preorder_traversal(root->right); 
}

void postorder_traversal(struct TreeNode *root)
{
    if (root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right); 
    visit_node(root);
}

int main()
{
    struct TreeNode n1;
    n1.val = 1;
    struct TreeNode n2;
    n2.val = 2;
    struct TreeNode n3;
    n3.val = 3;
    n1.left = &n2;
    n1.right= &n3;
    struct TreeNode n4;
    n4.val = 4;
    struct TreeNode n5;
    n5.val = 5;
    n2.left = &n4;
    n2.right = &n5;
    struct TreeNode n6;
    n6.val = 6;
    struct TreeNode n7;
    n7.val = 7;
    n3.left = &n6;
    n3.right = &n7;
    n4.left = NULL;
    n5.left = NULL;
    n6.left = NULL;
    n7.left = NULL;
    n4.right = NULL;
    n5.right = NULL;
    n6.right = NULL;
    n7.right = NULL;
    preorder_traversal(&n1);
    printf("\n");
    /*
    inorder_traversal(&n1);
    printf("\n");
    postorder_traversal(&n1);
    printf("\n");
    */
    return 0;
}
