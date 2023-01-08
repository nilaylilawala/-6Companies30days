class Solution {
public:
    int trailingZeroes(int n) {
        
        int cnt=0,div=5;
        while(n>=div)
        {
            cnt+=n/div;
            div*=5;
        }
        return cnt;

    }
};
