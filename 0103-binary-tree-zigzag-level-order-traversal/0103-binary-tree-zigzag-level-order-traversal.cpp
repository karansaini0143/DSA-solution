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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        deque<TreeNode*> q;
        q.push_back(root);
        int height=0;
        while(!q.empty()){
            vector<int> lvl;
            int size=q.size();
            if(height%2==0){
                for(int i=0;i<size;i++){
                    TreeNode* node=q.front();
                    q.pop_front();
                    if(node->left!=NULL) q.push_back(node->left);
                    if(node->right!=NULL) q.push_back(node->right);
                    lvl.push_back(node->val);
                }
                ans.push_back(lvl);
            }
            else{
                for(int i=0;i<size;i++){
                    TreeNode* node=q.back();
                    q.pop_back();
                    if(node->right!=NULL) q.push_front(node->right);
                    if(node->left!=NULL) q.push_front(node->left);
                    lvl.push_back(node->val);
                }
                ans.push_back(lvl);
            }
            height++;
        }
        return ans;
    }
};