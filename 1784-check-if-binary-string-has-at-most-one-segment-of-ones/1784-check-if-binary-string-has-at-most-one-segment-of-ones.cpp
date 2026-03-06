class Solution {
public:
    bool checkOnesSegment(string s) {
        bool hasSegment = (s.find("01") == string::npos);

        return hasSegment;
    }
};