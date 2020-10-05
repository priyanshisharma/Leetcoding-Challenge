class Solution {
    
    public int diameterOfBinaryTree(TreeNode root) {
        //base case
        if(root == null){
            return 0;
        }
        
        // if the diameter lies on left side
        int leftDiameter=diameterOfBinaryTree(root.left);
        
        // if the diameter lies on right side
        int rightDiameter=diameterOfBinaryTree(root.right);
        
       //if the diameter passes through root
        int rootDiameter=height(root.left)+height(root.right)+2;
        
        int diameter=Math.max(rootDiameter,Math.max(leftDiameter,rightDiameter));
        return diameter;
    }
    
    public static int height(TreeNode node){
        //base case
        if(node == null){
            return -1;
        }
        
        int leftHeight=height(node.left);// height of left subtree
        int rightHeight=height(node.right);// height of right subtree
        int ans=Math.max(leftHeight,rightHeight)+1;
        return ans;
    }
}
