class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<vector<pair<string,int>>> v;
        for(int i=nums[0].size()-1;i>=0;i--) {
            vector<pair<string, int>> temp;
            for(int j=0;j<nums.size();j++) {
                string st(nums[j].begin()+i, nums[j].end());
                temp.push_back({st, j});
            }
            sort(temp.begin(), temp.end());
            v.push_back(temp);
        }
        vector<int> ans;
        for(auto i: queries) {
            ans.push_back(v[i[1]-1][i[0]-1].second);
        }
        return ans;
    }
};
