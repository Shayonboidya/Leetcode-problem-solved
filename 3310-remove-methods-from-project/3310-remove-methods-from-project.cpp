class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        // Adjacency list where u -> v means method u invokes method v
        vector<vector<int>> adj(n);

        // indeg[i] = number of incoming calls to method i
        vector<int> indeg(n, 0);

        // Marks whether a method is suspicious (reachable from k)
        vector<bool> suspisious(n, false);

        // Build the graph and calculate indegree of every node
        for (auto edg : invocations) {
            int u = edg[0];
            int v = edg[1];

            adj[u].push_back(v);
            indeg[v]++;
        }

        // BFS starting from the suspicious method k
        queue<int> q;
        q.push(k);
        suspisious[k] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // Visit all methods invoked by the current method
            for (int &ngbr : adj[curr]) {

                // Remove the contribution of the current suspicious method
                indeg[ngbr]--;

                // If not already marked suspicious,
                // add it to the BFS queue
                if (!suspisious[ngbr]) {
                    q.push(ngbr);
                    suspisious[ngbr] = true;
                }
            }
        }

        vector<int> res;
        bool canNotRemoved = false;

        // Check whether suspicious methods can be removed safely
        for (int i = 0; i < n; i++) {

            // If a suspicious method still has an incoming edge,
            // it is called by a non-suspicious method,
            // so removal is not possible.
            if (suspisious[i] && indeg[i] > 0) {
                canNotRemoved = true;
                break;
            }

            // Collect all non-suspicious methods
            if (!suspisious[i]) {
                res.push_back(i);
            }
        }

        // If removal is impossible, return all methods
        if (canNotRemoved) {
            vector<int> v;
            for (int i = 0; i < n; i++) {
                v.push_back(i);
            }
            return v;
        }

        // Otherwise, return only the remaining (non-suspicious) methods
        return res;
    }
};