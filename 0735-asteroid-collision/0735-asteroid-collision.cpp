class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        
        for(int i=0;i<n;i++){ 
            bool alive=true;
            while(alive && !st.empty() && st.top()>0 && asteroids[i]<0){
                if(st.top()<-asteroids[i]){
                    st.pop();
                }
                else if(st.top()==-asteroids[i]){
                    st.pop();
                    alive=false;
                }
                else{
                    alive=false;
                }
            }
            if(alive)
                st.push(asteroids[i]);
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};