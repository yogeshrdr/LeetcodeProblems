class Solution {
public:
  
    int maxScore(vector<int>& cardPoints, int k) {
              
        int leftsum = 0;
        int rightsum = 0;
        int n = cardPoints.size();

        for (int i=0;i<k;i++)
            leftsum += cardPoints[i];
        
        int score = leftsum;

        for (int i=k-1;i>=0;i--) {
            rightsum += cardPoints[n-k+i];
            leftsum -= cardPoints[i];
            score = max(score, rightsum + leftsum);
        }

        return score;
        
    }
};