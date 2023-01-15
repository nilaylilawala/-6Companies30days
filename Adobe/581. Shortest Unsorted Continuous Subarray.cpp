class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int cnt=0,ans=0;
        bool flag=false;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != v[i]) {
                flag=true;
                ans = ++cnt;
            }
            else if(flag) cnt++;
        }
        return ans;
    }
};
