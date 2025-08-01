/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
 You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.            */

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        if (visited[node] == 1) return true;   // cycle found
        if (visited[node] == 2) return false;  // already processed

        visited[node] = 1; // mark as visiting

        for (int neighbor : adj[node]) {
            if (dfs(neighbor, adj, visited)) return true;
        }

        visited[node] = 2; // mark as processed
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // build graph: b → a
        }

        vector<int> visited(numCourses, 0); // 0: unvisited

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (dfs(i, adj, visited)) return false; // cycle found
            }
        }

        return true; // no cycles found
    }
};
