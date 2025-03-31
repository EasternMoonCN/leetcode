#include "utils/common.cpp"

class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int nvars = 0;
        unordered_map<string, int> variables;   // 图的各个顶点 和 坐标

        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            if (variables.find(equations[i][0]) == variables.end())
            {
                variables[equations[i][0]] = nvars++;
            }
            if (variables.find(equations[i][1]) == variables.end())
            {
                variables[equations[i][1]] = nvars++;
            }
        }

        // 对于每个点，存储其直接连接到的所有点及对应的权值
        vector<vector<pair<int, double>>> edges(nvars);
        for (int i = 0; i < n; i++)
        {
            int va = variables[equations[i][0]], vb = variables[equations[i][1]];
            edges[va].push_back(make_pair(vb, values[i]));
            edges[vb].push_back(make_pair(va, 1.0 / values[i]));
        }

        vector<double> ret;
        // 遍历每一个问题
        for (const auto &q : queries)
        {
            double result = -1.0;
            // 判断所求问题节点是否存在
            if (variables.find(q[0]) != variables.end() && variables.find(q[1]) != variables.end())
            {
                // 所求问题索引
                int ia = variables[q[0]], ib = variables[q[1]];
                // 所求问题索引节点相同，直接为0
                if (ia == ib)
                {
                    result = 1.0;
                }
                // 寻找ia到ib到路径
                else
                {
                    // 保存当前节点可以遍历到到节点
                    queue<int> points;
                    points.push(ia);
                    // 初始化路径
                    vector<double> ratios(nvars, -1.0);
                    ratios[ia] = 1.0;
                    // 还存在节点为遍历 且 未到达终点
                    while (!points.empty() && ratios[ib] < 0)
                    {
                        int x = points.front();
                        points.pop();
                        // 遍历当前节点x可以遍历到到到节点
                        for (pair<int, double> edge : edges[x])
                        {
                            // 如果没有遍历过，记录遍历
                            if (ratios[edge.first] < 0)
                            {
                                // 遍历到到节点权重 = 上一个节点 * 边到权重
                                ratios[edge.first] = ratios[x] * edge.second;
                                // 将遍历到到节点加入待遍历中
                                points.push(edge.first);
                            }
                        }
                    }
                    result = ratios[ib];
                }
            }
            // 保存最中节点
            ret.push_back(result);
        }
        return ret;
    }
};

int main()
{
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    common<double>::printVector(Solution().calcEquation(equations, values, queries));
    return 0;
}
