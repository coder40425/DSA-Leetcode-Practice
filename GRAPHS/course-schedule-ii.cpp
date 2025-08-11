/* There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites
where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. 
If it is impossible to finish all courses, return an empty array.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].   */

class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& result){
        if(visited[node] == 1) return true; //cycle detected
        if(visited[node] == 2) return false; //already processed

        visited[node] = 1; //mark as visiting

        for(int neighbor : adj[node]){
            if(dfs(neighbor, adj, visited, result)) return true;
        }

        visited[node] = 2; //mark as processed
        result.push_back(node); //post order push
        return false; //no cycle
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);
        vector<int> result;

        //build graph
        for(auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        for(int i=0; i<numCourses; i++){
            if(visited[i] == 0){
                if(dfs(i, adj, visited, result)){
                    return {}; //cycle found
                }
            }
        }
        reverse(result.begin(), result.end()); //because we added in post order
        return result;
    }
};

