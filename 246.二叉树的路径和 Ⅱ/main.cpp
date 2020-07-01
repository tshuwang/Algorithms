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
    vector<vector<int>> binaryTreePathSum2(TreeNode * root, int target) {
        // write your code here
        vector<vector<int>> res;
        vector<int> path;
        findsum(root,res,0,target,path);
        return res;
    }
    
    void findsum(TreeNode *root,vector<vector<int>>&res,int level,int sum,vector<int>&path)
    {
        if(root==NULL) return;
        int tmp=sum;
        path.push_back(root->val);
        for(int i=level;i>=0;i--)
        {
            tmp-=path[i];
            if(tmp==0)
            {
                vector<int> vi;
                for(int j=i;j<=level;j++)
                {
                    vi.push_back(path[j]);
                }
                res.push_back(vi);
            }
        }
        findsum(root->left,res,level+1,sum,path);
        findsum(root->right,res,level+1,sum,path);
        path.pop_back();
    }
};