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
    map<int,map<int,multiset<int>>> lvlorder(TreeNode* root){
        map<int,map<int,multiset<int>>>mpp;
        if(root==nullptr)
            return mpp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int y=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto [node,d]=q.front();
                q.pop();
                mpp[d][y].insert(node->val);
                if(node->left){
                    q.push({node->left,d-1});
                }
                if(node->right){
                    q.push({node->right,d+1});
                }
            }
            y++;
        }
        return mpp;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mpp=lvlorder(root);
        
        vector<vector<int>> ans;
        for(auto &col : mpp){
            vector<int> lvl;
            for(auto &row : col.second){
                for(auto &value : row.second){
                    lvl.push_back(value);
                }
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};