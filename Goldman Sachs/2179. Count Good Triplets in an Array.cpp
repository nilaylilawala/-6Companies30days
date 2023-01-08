class Solution {
public:
    vector<int>seg;
    
    void update(int ind, int low ,int high, int val)
    {
        if(low == high && low ==val)
        {
            seg[ind] = 1;
            return;
        }
        if(high<val || low> val)
        {
            return;
        }
        int mid = (low+high)/2;
        update(ind*2+1, low, mid, val);
        update(ind*2+2, mid+1, high, val);
        seg[ind] = seg[ind*2+1]+ seg[ind*2+2];
    }
    
    int query(int ind, int low, int high, int l, int r)
    {
        if(low>=l && high<=r)
        {
            return seg[ind];
        }
        if(high<l || low>r )
            return 0;
        int mid = (low+high)/2;
        return query(ind*2+1, low, mid, l, r) + query(ind*2+2, mid+1, high, l,r);
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) 
    {
        int  n = nums1.size();
         vector<int> map(n, 0);
        
        for (int i = 0; i < n; ++i) {
            map[nums2[i]] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            nums2[map[nums1[i]]] = i;
            nums1[i] = i;
        }
          vector<int>b ;
        seg.resize(4*n,0);
        for(int i = 0;i<n;i++)
        {
           b.push_back(nums2[i]);
        }
        
        update(0,0,n-1, b[0]);
        long long ans  =0;
        for(int  i = 1;i<n-1;i++)
        {
            long long int small = query(0, 0, n-1, 0, b[i]-1);
            long long int bb = (n-1) - b[i];
            long long int bigg  = bb - (i - small);
            ans  += (small)*bigg;
            update(0,0, n-1, b[i]);
        }
        
        
        return ans;
    }
};
