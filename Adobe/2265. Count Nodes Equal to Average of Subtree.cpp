class Solution {
public:
    // {sum,number of nodes}
    int count = 0;
    pair<int,int> solve(TreeNode*root){
        if(!root) return {0,0};
        int nodes = 0;
        int sum = root->val;
        pair<int,int> pl = solve(root->left);
        pair<int,int> pr = solve(root->right);
        sum += pl.first+pr.first;
        nodes = 1+pl.second+pr.second;
        if(sum/nodes==root->val) count++;
        return {sum,nodes};
    }
    
    int averageOfSubtree(TreeNode* root) {
        
        solve(root);
        return count;
    }
};
