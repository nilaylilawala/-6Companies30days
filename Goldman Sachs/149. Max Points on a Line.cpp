class Solution {
public:
    float slope(vector<int> &p1, vector<int> &p2)
    {   
        if(p2[0] - p1[0] == 0)
            return INT_MAX;

        return (float)(p2[1] - p1[1]) / (p2[0] - p1[0]);
    }

    int maxPoints(vector<vector<int>>& points) {

        int ans = 1;

        for(int i=0; i<points.size(); i++)
        {
            unordered_map<float, int> m;
            int maxPoints = INT_MIN;

            for(int j=i+1; j<points.size(); j++)
                m[slope(points[i], points[j])]++;

            for(auto it : m)
                maxPoints = max(it.second + 1, maxPoints);

            ans = max(ans, maxPoints);
        }

        return ans;
    }
};
