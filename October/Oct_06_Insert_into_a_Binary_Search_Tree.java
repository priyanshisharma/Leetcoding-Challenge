/*
https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3485/
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        return insertRec(root,val);     
    }
    public TreeNode insertRec(TreeNode root,int val)
    {
        if(root==null)
        {
            TreeNode node = new TreeNode(val);
            return node;
        }
        if(val<root.val)
            root.left = insertRec(root.left,val);
        else
            root.right = insertRec(root.right,val);
        return root;
    }
}