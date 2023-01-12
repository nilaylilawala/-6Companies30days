class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        string ans = "";
        if ((numerator>0 && denominator<0 )|| (denominator>0 && numerator<0)) ans += '-';
        long long num = labs(numerator), den = labs(denominator);
        long long q = num / den;
        long long r = num % den;
        ans += to_string(q);
        
        if(r == 0) return ans;
        
        ans += '.';
        unordered_map<long long , int> mp;
        while(r != 0){
            if(mp.find(r) != mp.end()){
                int pos = mp[r];
                ans.insert(pos, "(");
                ans += ')';
                break;
            }
            else{
                mp[r] = ans.length();
                r *= 10;
                q = r / den;
                r = r % den;
                ans += to_string(q);
            }
        }
        return ans;
    }
};
