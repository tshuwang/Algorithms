/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of the tree
     * @return: the total sum of all root-to-leaf numbers
     */
    int sumNumbers(TreeNode * root) {
        // write your code here
        int res;
        res=dfs(root,0);
        return res;
    }
    
    int dfs(TreeNode * root,int pre)
    {
        if(root==NULL)
        return 0;
        
        int sum=root->val+pre*10;
        if(root->left==NULL&&root->right==NULL)
        {
            return sum;
        }
        
        return dfs(root->left,sum)+dfs(root->right,sum);
    }
};