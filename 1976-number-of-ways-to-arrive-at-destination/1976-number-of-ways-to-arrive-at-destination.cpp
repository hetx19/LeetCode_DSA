using ll = long long;

class Solution {
  public:
	int countPaths(int n, vector<vector<int>> &roads) {
		const int MOD = 1e9 + 7;
		vector<vector<pair<int, int>>> adj(n);
		
		for (auto road : roads) {
			adj[road[0]].push_back({road[1], road[2]});
			adj[road[1]].push_back({road[0], road[2]});
		}
		
		priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
		
		vector<ll> distance(n, LLONG_MAX);
		vector<int> ways(n, 0);
		
		distance[0] = 0;
		pq.push({0, 0});
		ways[0] = 1;
		
		while (!pq.empty()) {
			int node = pq.top().second;
			ll dis = pq.top().first;
			pq.pop();
			
			for (auto it : adj[node]) {
				int adjNode = it.first;
				int edgeWeight = it.second;
				
				if (dis + edgeWeight < distance[adjNode]) {
					distance[adjNode] = dis + edgeWeight;
					pq.push({distance[adjNode], adjNode});
					ways[adjNode] = ways[node];
				} else if (dis + edgeWeight == distance[adjNode]) {
					ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
				}
			}
		}
		
		return ways[n - 1] % MOD;
	}
};