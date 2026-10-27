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
    map<int, map<int, multiset<int>>> lvlorder(TreeNode* node){
        map<int, map<int, multiset<int>>> mp;
        if(node==nullptr){
            return mp;
        }
        queue<pair<TreeNode*,int>>q;
        q.push({node,0});
        int y=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto [root,d]=q.front();
                q.pop();
                mp[d][y].insert(root->val);
                if(root->left){
                    q.push({root->left,d-1});
                }
                if(root->right){
                    q.push({root->right,d+1});
                }
            }
            y++;
        }
        return mp;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int, multiset<int>>>mp=lvlorder(root);
        vector<vector<int>>ans;
        for (auto &col : mp) {
            vector<int>lvl;
            for (auto &row : col.second) {
                for (int val : row.second) {
                    lvl.push_back(val);
                }
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};