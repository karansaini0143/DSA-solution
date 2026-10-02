class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int n=cardPoints.size();
        
        int tsum=0;
        for(int i=0;i<n;i++) tsum+=cardPoints[i];
        for(int i=0;i<n-k;i++){
            sum+=cardPoints[i];
        }
        int mini=sum;
        for(int i=n-k;i<n;i++){
            sum+=cardPoints[i];
            sum-=cardPoints[i-(n-k)];
            mini=min(mini,sum);
        }
        return tsum-mini;
    }
};