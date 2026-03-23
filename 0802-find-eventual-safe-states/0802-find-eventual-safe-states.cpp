class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
	    vector<vector<int>> adj(V);
	    vector<int> indegree(V, 0);
	
	    for (int i = 0; i < V; i++) {
		    for (int it : graph[i]) {
			    adj[it].push_back(i);
			    indegree[i]++;
		    }
	    }
	
	    queue<int> q;
	    for (int i = 0; i < V; i++) {
		    if (indegree[i] == 0) {
			    q.push(i);
		    }
	    }
	
	    vector<int> ans;
	
	    while (!q.empty()) {
		    int node = q.front();
		    q.pop();
		
		    ans.push_back(node);
		
		    for (int it : adj[node]) {
			    indegree[it]--;
			    if (indegree[it] == 0) {
				    q.push(it);
			    }
		    }
	    }

        sort(ans.begin(), ans.end());
	
	    return ans;
    }
};