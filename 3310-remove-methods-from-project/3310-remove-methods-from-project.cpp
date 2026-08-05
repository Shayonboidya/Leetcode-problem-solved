class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        // adj list u -> v
        vector<vector<int>> adj(n);
        vector<int> indeg(n, 0);
        vector<bool> suspisious(n, false);

        // u -> v
        for (auto edg : invocations) {
            int u = edg[0];
            int v = edg[1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        // bfs
        queue<int> q;
        q.push(k);
        suspisious[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int& ngbr : adj[curr]) {
                indeg[ngbr]--;
                if (!suspisious[ngbr]) {
                    q.push(ngbr);
                    suspisious[ngbr] = true;
                }
            }
        }

        vector<int> res;
        bool canNotRemoved = false;
        for (int i = 0; i < n; i++) {
            if (suspisious[i] && indeg[i] > 0) {
                canNotRemoved = true;
                break;
            }
            if (!suspisious[i]) {
                res.push_back(i);
            }
        }

        if (canNotRemoved) {
            vector<int> v;
            for (int i = 0; i < n; i++) {
                v.push_back(i);
            }
            return v;
        }
        return res;
    }
};