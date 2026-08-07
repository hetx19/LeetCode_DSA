class Solution {
  public:
	int numDistinct(string s, string t) {
		int n1 = s.size(), n2 = t.size();
		vector<double> prev(n2 + 1, 0), current(n2 + 1, 0);
		
		prev[0] = current[0] = 1;
		
		for (int index1 = 1; index1 <= n1; index1++) {
			for (int index2 = 1; index2 <= n2; index2++) {
				if (s[index1 - 1] == t[index2 - 1]) {
					current[index2] = prev[index2 - 1] + prev[index2];
				} else {
					current[index2] = prev[index2];
				}
			}
			prev = current;
		}
		
		return (int)(prev[n2]);
	}
};