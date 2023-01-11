class Solution {
public:
    const int N = 1e9+7;
    int countNicePairs(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++){
            string s = to_string(nums[i]);
            reverse(s.begin(),s.end());
            nums[i] = nums[i]-stoi(s);
        }
        unordered_map<int,long long> m;
        for(auto i : nums) {
            m[i]++;
        }
        long long ans=0;
        for (auto val: m){
            ans= (ans+((val.second)*(val.second-1))/2)%N;
            ans= ans%N;
        }
        return ans;
    }
};
