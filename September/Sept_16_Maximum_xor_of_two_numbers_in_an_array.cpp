#define m 32
class Solution {
public:
    void make_tree(bitset<m>bs, TreeNode* &head){
        TreeNode* temp=head;
        // cout<<temp->val<<endl;
        for(int i=m-1;i>=0;i--){
            if(bs[i]==0){
                if(temp->left==NULL){
                    temp->left=new TreeNode(0);
                    temp=temp->left;                    
                }
                else
                    temp=temp->left;           
            }
            else{
                if(temp->right==NULL){
                    temp->right= new TreeNode(1);
                    temp=temp->right;
                }
                else
                    temp=temp->right;
            }
        }
    }
    void check_maxe(bitset<m>bs, TreeNode* &head, int &maxe){
        TreeNode* temp=head;
        bitset<m>bits;
        for(int i=m-1;i>=0;i--){
            if(bs[i]==0){
                // bs[i]=0 and we need 1 to make xor 1
                if(temp->right){
                    temp=temp->right;
                    bits[i]=1;
                }
                else{
                    bits[i]=0;
                    temp=temp->left;
                }
            }
            else{
                // bs[i]=1 and we need 0 to make xor 1
                if(temp->left){
                    bits[i]=1;
                    temp=temp->left;
                }
                else{
                    bits[i]=0;
                    temp=temp->right;
                }
            }
        }
        maxe=max(maxe, (int)bits.to_ulong());
        
    }
    int findMaximumXOR(vector<int>& v) {
        int n=v.size();
        if(n==0)
            return 0;
        
        
        bitset<m>bs;
        TreeNode* head= new TreeNode(-1);
        for(int i=0;i<n;i++){
            bs=v[i];
            make_tree(bs, head);
        }
        
        int maxe=0;
        for(int i=0;i<n;i++){
            bs=v[i];
            check_maxe(bs, head, maxe);
        }
        
        return maxe;
    }
};
