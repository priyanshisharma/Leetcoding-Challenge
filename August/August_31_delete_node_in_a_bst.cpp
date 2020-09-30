#include <iostream>
#include <algorithm>
using namespace std;
class node {
    public:
    int data;
    node* left;
    node* right;

    node (int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
}; 

node* build (node* root, int *arr, int s, int e)
{
    if (s>e) return NULL;
    int mid = (s+e)/2;
        root = new node (arr[mid]);
        root->left = build (root->left, arr, s, mid-1);
        root->right = build (root->right, arr, mid+1, e);
        return root;
}
node* insert(node* root, int value){
    if(root==NULL){
        node *nn = new node(value);
        return nn;
    }
    if(value>root->data){
        root->right=insert(root->right, value);
    }else if(value<root->data){
        root->left=insert(root->left, value);
    }
    return root;
}

node* ArrToBST(int* arr, node* root, int n){
    for(int i=0; i<n; i++){
        root = insert(root,arr[i]);
    }
    return root;
}

node* deleteBST (node* root, int key)
{
    if (root==NULL) return NULL;
    else if (key < root->data) {
        root->left =  deleteBST (root->left, key);
        return root; }
    else if (key > root->data) {
        root->right = deleteBST (root->right, key);
        return root; }
    else {
        if (root->left==NULL && root->right==NULL) {
            delete root;
            return NULL;
        } else if (root->left==NULL && root->right!=NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right==NULL && root->left!=NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        } else {
            node * replace = root->left;
            while (replace ->right!=NULL)
            {
                replace = replace->right;
            }
            root->data = replace ->data;
            root->left = deleteBST (root->left, replace->data);
            return root;
        }
    }
}

void printPre (node* root)
{
    if (root==NULL) return;
    cout << root->data <<" ";
    printPre (root->left);
    printPre (root->right);
}

int main ()
{
        int n;
        cin >> n;
        int arr [n];
        for (int i=0; i<n; i++)
        {
            cin >> arr[i];
        }
        node* root=new node(arr[0]);
        root = ArrToBST(arr,root,n);
        int d;
        cin >> d;
        root = deleteBST(root, d);
        printPre (root);
        return 0;
}