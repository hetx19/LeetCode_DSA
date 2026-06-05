class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int V) {
        parent.resize(V + 1);
        size.resize(V + 1, 1);

        for(int i = 0; i <= V; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(parent[node] == node) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
	    int pu = findParent(u), pv = findParent(v);

        if (pu == pv) {
            return;
        }

        if (size[pu] > size[pv]) {
	        parent[pv] = pu;
	        size[pu] += size[pv];
        } else {
	        parent[pu] = pv;
	        size[pv] += size[pu];
        }
    }
};

class Solution {
  public:
	int removeStones(vector<vector<int>>& stones) {
		int V = stones.size();
		int maxRow = 0, maxCol = 0;
		
		for (auto &stone : stones) {
			maxRow = max(maxRow, stone[0]);
			maxCol = max(maxCol, stone[1]);
		}
		
		unordered_map<int, int> stoneNodes;
		DisjointSet ds(maxRow + maxCol + 1);
		
		for (auto &stone : stones) {
			int nodeRow = stone[0];
			int nodeCol = stone[1] + maxRow + 1;
			
			ds.unionBySize(nodeRow, nodeCol);
			stoneNodes[nodeRow] = 1;
			stoneNodes[nodeCol] = 1;
		}
		
		int count = 0;
		for (auto &stone : stoneNodes) {
			if (ds.findParent(stone.first) == stone.first) {
				count++;
			}
		}
		
		return V - count;
	}
};