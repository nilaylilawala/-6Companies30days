class Solution {
public:
    int d;
    long long cnt = 0;
    void mergeSort(vector<int>&v,int st,int mid,int en){
        int i = st;
        int j = mid + 1;
        int n1 = mid-st+1;
        int n2 = en-mid;
        vector<int>a(n1);
        vector<int>b(n2);

        for(int ii=0;ii<n1;ii++){
            a[ii] = v[ii+st];
        }
        for(int ii=0;ii<n2;ii++){
            b[ii] = v[ii+mid+1];
        }

        while(i<=mid and j<=en){
            if(v[i] <= v[j] + d){
                cnt += (en-j+1);
                i++;
            }
            else{
                j++;
            }
        }
        i = 0;
        j = 0;
        int k = st;
        while(i<n1 and j<n2){
            if(a[i]<=b[j]){
                v[k] = a[i];
                i++;
                k++;
            }
            else{
                v[k] = b[j];
                j++;
                k++;
            }
        }

        while(i<n1){
            v[k++] = a[i++];
        }
        while(j<n2){
            v[k++] = b[j++];
        }
      

        return;
    }

    void merge(vector<int>&v,int st,int en){
        if(st<en){
            int mid = st + (en-st)/2;
            merge(v,st,mid);
            merge(v,mid+1,en);
            mergeSort(v,st,mid,en);
        }
        return ;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int>v;
        d = diff;
        for(int i=0;i<nums1.size();i++){
            v.push_back(nums1[i] - nums2[i]);
        }
        merge(v,0,v.size()-1);
        return cnt;
    }
};
