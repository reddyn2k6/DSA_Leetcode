class Solution {
public:
    int helper(TreeNode* root, int &ans) {
        if (root == NULL) return 0;

        int left = helper(root->left, ans);
        int right = helper(root->right, ans);

        int temp = left + right + root->val;

        ans = max(ans, temp);

        return max(0,root->val+max(left,right));

    }

    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }
};