class Solution {
    float distance(vector<int> &A, vector<int> &B)
    {
        int x1 = A[0];
        int y1 = A[1];
        int x2 = B[0];
        int y2 = B[1];
        return sqrt( pow((x2-x1),2) + pow((y2-y1),2) );
    }

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int side=0, diag=0;
        unordered_map <float, int> m;
        m[distance(p1,p2)]++;
        m[distance(p1,p3)]++;
        m[distance(p1,p4)]++;
        m[distance(p2,p3)]++;
        m[distance(p2,p4)]++;
        m[distance(p3,p4)]++;
        for(auto it: m)
        {
            if(it.second == 4)
                side = it.first;
            else if(it.second == 2)
                diag = it.first;
        } 
        if(diag && side) 
            return true;
        return false;      
    }
};
