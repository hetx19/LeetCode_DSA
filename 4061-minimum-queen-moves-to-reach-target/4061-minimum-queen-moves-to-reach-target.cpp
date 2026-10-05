class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if (source == target) {
            return 0;
        }

        if (source[0] == target[0] || source[1] == target[1]) {
            return 1;
        }

        int dx = source[0] - target[0];
        int dy = source[1] - target[1];

        return (abs(dx) == abs(dy)) ? 1 : 2;
    }
};