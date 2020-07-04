/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */


class Solution {
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
        // write your code here
        std::set<ParentTreeNode*> parentset;
        ParentTreeNode* cur=A;
        while(cur!=NULL)
        {
            parentset.insert(cur);
            cur=cur->parent;
        }
        
        cur=B;
        while(cur!=NULL)
        {
            if(parentset.find(cur)!=parentset.end())
            return cur;
            cur=cur->parent;
        }
        
        return NULL;
    }
};