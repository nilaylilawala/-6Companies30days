class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int size(nums.size());
        int cur{};
        for(int i=1;i<size;i++){
            cur+=i*nums[i];
        }

        int prev(cur),sum(accumulate(nums.begin(),nums.end(),0));
        int maxi(cur);
        for(int i=size-1;i>0;i--){
            cur=prev+sum-(size*nums[i]);
            prev=cur;
            maxi=max(maxi,cur);
        }
        return maxi;
    }
};
