class Solution {
private:
    struct Node {
        Node *left;
        Node *right;
    };
    void insert(int n, Node* root){
        Node* curr=root;
        for (int i=31;i>=0;i--){
            int b = ((n>>i)&(1));
            if (b==0){
                if (!curr->left)
                     curr->left=new Node();
                curr=curr->left;
            }
            else {
                if (!curr->right)
                    curr->right=new Node();
                curr=curr->right;
            }
        }
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        Node* root= new Node();
        for (int n:nums) insert(n,root);
        int max_xor=0;
        for (int n:nums) {
            int curr_xor=0;
            Node* curr=root;
            for (int i=31;i>=0;i--){
                int b=((1<<i)&n);
                if (b==0){
                    if (curr->right){
                        curr_xor+=(1<<i);
                        curr=curr->right;
                    }
                    else curr=curr->left;
                }
                else {
                    if (curr->left){
                        curr_xor+=(1<<i);
                        curr=curr->left;
                    }
                    else curr=curr->right;

                }
            }
            max_xor=max(max_xor,curr_xor);
        }
        return max_xor;
    }
};