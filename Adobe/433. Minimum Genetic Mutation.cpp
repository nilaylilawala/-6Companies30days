class Solution {
public:
    int res=INT_MAX;
    void check(vector<string>& bank, string s2, string &end, int count, unordered_map<string, int> &visited) {
        
        if(s2 == end) {
            res = min(res, count);
            return;
        }
        for(int j=0;j<bank.size();j++) {
            if(!visited[bank[j]]) {
                int diff=0;
                for(int i=0;i<8;i++) {
                    if(bank[j][i] != s2[i]) diff++;
                }
                if(diff==1) {
                    visited[s2] = 1;
                    check(bank, bank[j], end, count+1, visited);  
                    visited[s2] = 0;
                }
            }
        }
    }
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, int> visited;
        check(bank, start, end, 0, visited);
        if(res == INT_MAX) return -1;
        return res;
    }
};
