class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int r=0;
        int n=s.size();
        int maxi=0;
        vector<int> vcc(256,-1);
        while(r<n){
            if(vcc[s[r]]>=l){
                l=vcc[s[r]]+1;

            }
            vcc[s[r]]=r;
            maxi=max(maxi,r-l+1);
            r++;
        }  
        return maxi;
    }
    
};