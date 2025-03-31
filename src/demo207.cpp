#include "utils/common.cpp"

class Solution {
public:
    bool flag;
    vector<vector<int>> edges;
    // 0未搜索，1搜索中，2已完成
    vector<int> visited;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 边集
        edges = vector<vector<int>>(numCourses);
        visited = vector<int>(numCourses, 0);
        flag = true;

        for (vector<int> prerequisite : prerequisites)
        {
            edges[prerequisite[1]].push_back(prerequisite[0]);
        }
        
        // 从任意节点出发，遍历所有节点，不管当前节点是否有前继节点
        for (int i = 0; i < numCourses && flag; i++)
        {
            if (visited[i] == 0) {
                dfs(i);
            }
        }
        return flag;
        
    }

    void dfs(int u) {
        // 搜索中
        visited[u] = 1;
    
        for (int v : edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
            } else if (visited[v] == 1) {
                
                flag = false;
                return;
            }
        }
        // 节点u搜索完成，此时为最后一个节点
        visited[u] = 2;
    }
};


int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisite = {{0, 1}};
    cout << Solution().canFinish(numCourses, prerequisite);
    return 0;
}