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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        // write your code here
        vector<string> res;
        
        if(root==NULL)
        return res;
        
        if(root->left==NULL&&root->right==NULL)
        {
            res.push_back(to_string(root->val));
            return res;
        }
        
        if(root->left)
        {
            vector<string> leftString=binaryTreePaths(root->left);
            for(int i=0;i<leftString.size();i++)
            {
                res.push_back(to_string(root->val)+"->"+leftString[i]);
            }
        }
        
        if(root->right)
        {
            vector<string> rightString=binaryTreePaths(root->right);
            for(int i=0;i<rightString.size();i++)
            {
                res.push_back(to_string(root->val)+"->"+rightString[i]);
            }
        }
        
        return res;
    }
};