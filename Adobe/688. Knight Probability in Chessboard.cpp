class Solution {
public:
    vector<int> dx, dy;
    Solution(){
        dx = {-2, -1, 1, 2, 2, 1, -1, -2};
        dy = {1, 2, 2, 1, -1, -2, -2, -1};
    }
    double helper(int i, int j, int n, int k, vector<vector<vector<double>>> &DP){
        if(i >= n || j >= n || i < 0 || j < 0) return 0.0;
        if(DP[i][j][k] != -1) return DP[i][j][k];
        if(k == 0) return 1.0;
        double prob = 0;
        for(int l=0; l<8; l++){
            prob += helper(i+dx[l], j+dy[l], n, k-1, DP);
        }
        return DP[i][j][k] = prob/8;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> DP(n, vector<vector<double>>(n, vector<double>(k+1, -1)));
        return helper(row, column, n, k, DP);
    }
};
