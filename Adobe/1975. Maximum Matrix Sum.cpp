class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int minimum_element=INT_MAX;
        int count_negative=0;
        for(auto it:matrix)
        {
            for(auto element:it)
            {
                if(element<0)
                count_negative++;
                sum+=abs(element);
                minimum_element=min(minimum_element,abs(element));
            }
            
        }
        if(count_negative%2==0)
            return sum;
        else
            return sum-2*minimum_element;

    }
};
