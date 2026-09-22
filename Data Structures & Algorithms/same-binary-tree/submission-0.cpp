/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        TreeNode* p1=p;
        TreeNode* q1=q;
        if((!p1)&&(!q1))
        {
            return true;
        }
        
        if((!p1)||(!q1))
        {
            return false;
        }
        if(p1->val!=q1->val)
        {   
            return false;
        }

        return isSameTree(p1->left,q1->left)&& isSameTree(p1->right,q1->right) ;
    
    }
    
};
