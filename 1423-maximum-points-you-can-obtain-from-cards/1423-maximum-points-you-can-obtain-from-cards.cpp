class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0, rightSum = 0;

        for (int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }

        int score = leftSum;
        for (int i = 0; i < k; i++) {
            leftSum -= cardPoints[k - i - 1];
            rightSum += cardPoints[n - 1 - i];

            score = max(score, leftSum + rightSum);
        }

        return score;
    }
};