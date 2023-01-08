typedef pair<int,int> pi;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pi> caprof;
        priority_queue<int> pq;
        int n = profits.size();
        for(int i=0; i<n; i++) caprof.push_back({capital[i],profits[i]});
        sort(caprof.begin(), caprof.end());
        int i = 0;
        while(k--){
            while(caprof[i].first <= w && i < n) pq.push(caprof[i++].second);
            if(pq.empty()) return w;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
