class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		int E = flights.size();
		vector<vector<pair<int, int>>> adj(n);
		
		for (auto &flight : flights) {
			adj[flight[0]].push_back({flight[1], flight[2]});
		}
		
		queue<pair<int, pair<int, int>>> q;
		vector<int> distance(n, INT_MAX);
		distance[src] = 0;
		q.push({0, {src, 0}});
		
		while (!q.empty()) {
			int stops = q.front().first;
			int node = q.front().second.first;
			int cost = q.front().second.second;
			q.pop();
			
			if (stops > k) {
				continue;
			}
			
			for (auto it : adj[node]) {
				int adjNode = it.first;
				int edgeWeight = it.second;
				
				if (cost + edgeWeight < distance[adjNode] && stops <= k) {
					distance[adjNode] = cost + edgeWeight;
					q.push({stops + 1, {adjNode, distance[adjNode]}});
				}
			}
			
		}
		
		return (distance[dst] == INT_MAX) ? -1 : distance[dst];
	}
};