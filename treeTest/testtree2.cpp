//if any problems/suggestion contact manish...
#include <iostream>
#include <vector>
#include <conio.h>
#include "../treeDebug/tree.hpp"
#include "../treeDebug/benchmark.hpp"
using namespace std;
struct node
{
    int val;
    node *left;
    node *right;
    node():left(nullptr),val(0),right(nullptr){}
    node(int value):left(nullptr),val(value),right(nullptr){}
};
node *insert(node *root,int n)
{
    if(root==nullptr)
    {
        return new node(n);
    }
    if(root->val>n)
    {
        root->left=insert(root->left,n);
    }
    if(root->val<n)
    {
        root->right=insert(root->right,n);
    }
    return root;
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
  
    return current;
}
node* deleteNode(node* root, int val)
{
    if (root == NULL)
        return root;
    if (val < root->val)
        root->left = deleteNode(root->left, val);
    else if (val > root->val)
        root->right = deleteNode(root->right, val);
    else {
        if (root->left==NULL && root->right==NULL)
            return NULL;
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}
int count_node(node *root)
{
    if(root==nullptr) return 0;
    return 1+count_node(root->left)+count_node(root->right);
}
int count_leaf(node *root)
{
    if(root==nullptr)
        return 0;
    if(root->left==nullptr && root->right==nullptr)
        return 1;
    return count_leaf(root->left)+count_leaf(root->right);
}
int main()
{
    node *root=NULL;
    root=insert(root, 8);
    insert(root, 4);
    insert(root, 12);
    insert(root, 2);
    insert(root, 6);
    insert(root, 10);
    insert(root, 14);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);
    insert(root, 9);
    insert(root, 11);
    insert(root, 13);
    insert(root, 15);
    cout<<"Total No of node\t: "<<count_node(root)<<endl;
    //cout<<"root  : "<<root->val<<endl;
    cout<<"Total No of leaf node   : "<<count_leaf(root)<<endl;
    {
        Timer t;
        PrintTree<int>(root,2);
        PrintTreeHorizontally<int>(root,5);
    }
    getch();
    return 0;
}