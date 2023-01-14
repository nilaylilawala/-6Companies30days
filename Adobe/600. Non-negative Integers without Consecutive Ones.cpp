class Solution {
public:
    vector<vector<int>> dp;
    int fun(int n,int prev){
        if(n==0)
            return 1;
        if(dp[n][prev]!=-1)
            return dp[n][prev];
        if(prev==0)
            return dp[n][prev]=fun(n-1,0)+fun(n-1,1);
        else
            return dp[n][prev]=fun(n-1,0);
    }
    int real(int n){
        if(n==0 || n==1)
            return n+1;
        if(n==2 || n==3)
            return 3;
        int count=0,a=n;
        while(a>0){
            count++;
            a=a>>1;
        }
        int ans=0,max=0;
        ans=fun(count-1,0);
        int p=pow(2,count-1),q;
        q=p;
        while(p>0){
            max+=p;
            p/=4;
        }
        max=min(max,n);
        max=max-q;
        ans+=real(max);
        return ans;
    }
    int findIntegers(int n) {
        int count=0,a=n;
        while(n>0){
            count++;
            n=n>>1;
        }
        dp.resize(count+1,vector<int>(2,-1));
        return real(a);
    }
};
