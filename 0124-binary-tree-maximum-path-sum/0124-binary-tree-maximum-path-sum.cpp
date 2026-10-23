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
    int maxPathSum(TreeNode* root) {
        long long maxi=INT_MIN;
        maxsum(root,maxi);
        return maxi;
    }
    long long maxsum(TreeNode* node,long long& maxi){
        if(node==NULL)  return 0;
        long long lsum=max(0LL,maxsum(node->left,maxi));
        long long rsum=max(0LL,maxsum(node->right,maxi));
        
        maxi=max(maxi,node->val + lsum + rsum);
        
        return node->val + max(lsum,rsum);
    }
};