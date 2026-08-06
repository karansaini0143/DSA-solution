class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        int n=num.size();
        string ans="";
        if(k>=n){
            return "0";
        }
        for(int i=0;i<n;i++){
            while(!s.empty()&&(s.top()-'0')>(num[i]-'0')&&k>0){
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k>0){
            s.pop();
            k--;
        }
        
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        
        while(ans.size()!=0&&ans.back()=='0'){
            ans.pop_back();
        }
        if(ans.size()==0){
            return "0";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};