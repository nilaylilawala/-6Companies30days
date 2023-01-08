class Solution {
public:
    vector<int> ans;
    map<int,int> dp;
    int mx=0;
    
    int func(int n,vector<int> &v,int mask,int rem,vector<int> &temp,int scr){
       if (scr>mx){
          mx=scr;
          ans=temp;
        }
        
        if (mask==(pow(2,12)-1) || rem==0){
            return 0;
        }
        
        if (dp.find(mask)!=dp.end()){
            return dp[mask];
        }
        
        int val=0;
        for (int i=0; i<v.size(); i++){
            if (mask&(1<<i)){
                continue;
            }
            
            if (rem>=v[i]+1){
              vector<int> ele=temp;
                ele[i]=v[i]+1;
              val=max(val,i+func(n,v,(mask|(1<<i)),rem-(v[i]+1),ele,scr+i));  
              
            }
        }
        
       return dp[mask]=val;
    }
    
    vector<int> maximumBobPoints(int n, vector<int>& v) {
        int i;
        vector<int> temp(12,0);
        
        func(n,v,0,n,temp,0);
        int val=0;
        
        for (i=0; i<ans.size(); i++){
            val+=ans[i];
        }
        
        int diff=n-val;
        cout<<diff<<endl;
        for (i=0; i<v.size(); i++){
           
               ans[i]+=diff; 
               break;
            
        }
        
        
     return ans;
    }
};
