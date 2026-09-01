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
    void helper(int row,int col,TreeNode*root,map<int,map<int,multiset<int>>>&mp) {
        if(root==NULL) return;
       
       mp[col][row].insert(root->val);

       helper(row+1,col-1,root->left,mp);
       helper(row+1,col+1,root->right,mp);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        //col,row,set
        map<int,map<int,multiset<int>>>mp;

        helper(0,0,root,mp);

        for(auto i:mp) {
            vector<int>temp;
            for(auto j:i.second) {
                for(auto k:j.second) {
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};