class Solution {
public:
	vector<int> getBiggestThree(vector<vector<int>>& grid) {
		priority_queue<int> pq;
		int m = grid.size(), n = grid[0].size();

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				for(int k=0; i+k<m && i-k>=0 && j+2*k<n; k++){
					int si=i, sj=j, ti=i-k, tj=j+k, di=i+k, dj=j+k, ri=i, rj = j+2*k;
					int s1=0, s2=0, s3=0, s4=0;
					for(int l=0;l<k;l++){
						s1 += grid[si-l][sj+l];                        
						s2 += grid[ti+l][tj+l];
						s3 += grid[ri+l][rj-l];
						s4 += grid[di-l][dj-l];
					}
					int s = s1+s2+s3+s4;
					pq.push(max(s,grid[i][j]));
				}
			}
		}

		vector<int> ans;
		while(!pq.empty() && ans.size()<3){
			if(!ans.empty() && pq.top() == ans.back()){
				pq.pop();                
			} else {
				ans.push_back(pq.top());
				pq.pop();   
			}
		}
		return ans;
	}
};
