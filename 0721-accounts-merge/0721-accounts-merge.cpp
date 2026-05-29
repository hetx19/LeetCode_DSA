class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int V) {
        parent.resize(V);
        size.resize(V, 1);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node]) {
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int V = accounts.size();
        unordered_map<string, int> mapMailNode;

        DisjointSet ds(V);

        for (int i = 0; i < V; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if (mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<vector<string>> mergedMails(V);
        for (auto &it : mapMailNode) {
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergedMails[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for (int i = 0; i < V; i++) {
            if (mergedMails[i].size() == 0) {
                continue;
            }

            sort(mergedMails[i].begin(), mergedMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto &it : mergedMails[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};