class Solution {
private:
    bool dfsCheck(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &pathVisited, int node, vector<bool> &check) {
	    visited[node] = true;
	    pathVisited[node] = true;
	    check[node] = false;
	
	    for (int it : adj[node]) {
		    if (!visited[it]) {
			    if (dfsCheck(adj, visited, pathVisited, it, check)) {
                    check[node] = false;
				    return true;
			    }
		    } else if (pathVisited[it]) {
			    check[node] = false;
			    return true;
		    }
	    }
	
	    check[node] = true;
	    pathVisited[node] = false;
	    return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
	    int V = graph.size();
    
        vector<bool> visited(V, false);
        vector<bool> pathVisited(V, false);
        vector<bool> check(V, false);
    
        vector<int> ans;
    
        for (int i = 0; i < V; i++) {
	        if (!visited[i]) {
		        dfsCheck(graph, visited, pathVisited, i, check);
	        }
        }
    
        for (int i = 0; i < V; i++) {
	        if (check[i]) {
		        ans.push_back(i);
	        }
        }
    
        return ans;
    }
};