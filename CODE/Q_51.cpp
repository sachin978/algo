class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> order;
        vector<bool> todo(numCourses, false), done(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !acyclic(g, todo, done, i, order)) {
                return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node, vector<int>& order) {
        if (todo[node]) {
            return false;
        }
        if (done[node]) {
            return true;
        }
        todo[node] = done[node] = true;
        for (int neigh : g[node]) {
            if (!acyclic(g, todo, done, neigh, order)) {
                return false;
            }
        }
        order.push_back(node);
        todo[node] = false;
        return true;
    }
};
