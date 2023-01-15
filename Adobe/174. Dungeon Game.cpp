class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dung) {
        int m=dung.size(), n=dung[0].size();
        for(int i=m-2; i>=0; i--)dung[i][n-1]+=dung[i+1][n-1]<0?dung[i+1][n-1]:0;
        for(int j=n-2; j>=0; j--)dung[m-1][j]+=dung[m-1][j+1]<0?dung[m-1][j+1]:0;
        for(int i=m-2; i>=0; i--){
            for(int j=n-2; j>=0; j--){
                int mx=max(dung[i+1][j], dung[i][j+1]);
                if(mx<0){
                    dung[i][j]+=mx;
                }
            }
        }
        return 1+(dung[0][0]<0?abs(dung[0][0]):0);
    }
};
