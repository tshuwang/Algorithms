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
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
        // write your code here
        vector<vector<int>> res;
        vector<int> path;
        dfs(root,res,path,0,target);
        return res;
    }
    
    void dfs(TreeNode *root,vector<vector<int>> &res , vector<int> path ,int len ,int target)
    {
        if(root==NULL)
        {
            return;
        }
        path.push_back(root->val);
        len+=root->val;
        
        if(root->left==NULL&&root->right==NULL&&len==target)
        {
            res.push_back(path);
        }
        
        dfs(root->left,res,path,len,target);
        
        dfs(root->right,res,path,len,target);
        
        len-=root->val;
        path.pop_back();
        
    }
};