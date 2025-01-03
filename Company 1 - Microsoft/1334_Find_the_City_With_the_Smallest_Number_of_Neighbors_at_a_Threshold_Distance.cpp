#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<pair<int, int>>> &graph, vector<int> &visited, int s, int cost, int Thres)
    {
        for (auto &ngb : graph[s])
        {
            int nxt = ngb.first, curCost = ngb.second;
            if (cost + curCost <= Thres && cost + curCost < visited[nxt])
            {
                visited[nxt] = cost + curCost;
                dfs(graph, visited, nxt, cost + curCost, Thres);
            }
        }
    }
    int findTheCity(int n, vector<vector<int>> &edges, int Thres)
    {
        // adjacency matrix
        vector<vector<pair<int, int>>> graph(n);
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        int minCityCount = n, city = -1;
        for (int i = 0; i < n; i++)
        {
            vector<int> visited(n, INT_MAX);
            visited[i] = 1;
            dfs(graph, visited, i, 0, Thres);
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (visited[i] != INT_MAX)
                    cnt++;
            }
            if (cnt <= minCityCount)
                minCityCount = cnt, city = i;
        }

        return city;
    }
};