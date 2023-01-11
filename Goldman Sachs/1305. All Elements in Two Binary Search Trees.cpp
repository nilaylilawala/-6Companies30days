class Solution {
public:
    void t(TreeNode* root,vector<int>& ans) {
        if(root) {
            t(root->left,ans);
            ans.push_back(root->val);
            t(root->right,ans);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b, res;
        t(root1,a);
        t(root2,b);
        int i=0,j=0;
        while(i<a.size() && j<b.size()) {
            if(a[i] <=b[j]) {
                res.push_back(a[i++]);
            }
            else res.push_back(b[j++]);
        }
        while(i<a.size()) res.push_back(a[i++]);
        while(j<b.size()) res.push_back(b[j++]);
        return res;
    }
};
