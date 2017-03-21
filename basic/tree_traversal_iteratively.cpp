#include <stack>
#include <cstdio>
using namespace std;

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

void preorder_traversal(struct TreeNode *root)
{
    if (root == NULL)
        return;
    stack<struct TreeNode*> stack;
    stack.push(root);
    while (!stack.empty()) {
        struct TreeNode *n = stack.top();
        stack.pop();
        visit_node(n);
        if (n->right)
            stack.push(n->right);
        if (n->left)
            stack.push(n->left);
    } 
}

void inorder_traversal(struct TreeNode *root)
{
    if (root == NULL)
        return;
    stack<struct TreeNode*> stack;
    stack.push(root);
    while (!stack.empty()) {
        struct TreeNode *n = stack.top(); 
        if (n->left == NULL && n->right == NULL) {
            stack.pop();
            visit_node(n);
            continue;
        }
        if (n->left) {
            stack.push(n->left);
            continue;
        }
        else {
            stack.pop();
            visit_node(n);
            stack.push(n->right);
            continue;
        }
    } 
}

void postorder_traversal(struct TreeNode *root)
{
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
    struct TreeNode n8;
    n8.val = 8;
    struct TreeNode n9;
    n9.val = 9;
    struct TreeNode n10;
    n10.val = 10;
    n3.left = &n6;
    n3.right = &n7;
    n4.left = NULL;
    n5.left = NULL;
    n6.left = NULL;
    n7.left = NULL;
    n4.right = &n8;
    n5.right = NULL;
    n6.right = NULL;
    n7.right = NULL;
    n8.left = &n9;
    n8.right = &n10;
    n9.left = NULL;
    n10.left = NULL;
    n9.right = NULL;
    n10.right = NULL;
    inorder_traversal(&n1);
    printf("\n");
    /*
    preorder_traversal(&n1);
    printf("\n");
    postorder_traversal(&n1);
    printf("\n");
    */
    return 0;
}
