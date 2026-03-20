#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bfs(vector<vector<int>> adj, int V)
    {
        vector<int> adjLs[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (i != j && adj[i][j] == 1)
                {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(V, 0), ans;
        queue<int> q;
        q.push(0);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto &it : adjLs[node])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
        return ans;
    }

    void dfs(int r, int c, vector<pair<int, int>> &temp, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m, int row0, int col0)
    {
        if (r < 0 || c < 0 || r >= n || c >= m || vis[r][c] || grid[r][c] == 0)
            return;
        vis[r][c] = 1;
        temp.push_back({r - row0, c - col0});
        dfs(r + 1, c, temp, vis, grid, n, m, row0, col0);
        dfs(r - 1, c, temp, vis, grid, n, m, row0, col0);
        dfs(r, c + 1, temp, vis, grid, n, m, row0, col0);
        dfs(r, c - 1, temp, vis, grid, n, m, row0, col0);
    }

    void bfs(int r, int c, vector<pair<int, int>> &temp, vector<vector<int>> &vis, vector<vector<int>> &grid, int n, int m, int row0, int col0)
    {
        queue<pair<int, int>> q;
        q.push({r, c});
        while (!q.empty())
        {
            int row = q.front().first, col = q.front().second;
            q.pop();
            vis[row][col] = 1;
            temp.push_back({row - row0, col - col0});
            int delRow[] = {1, -1, 0, 0};
            int delCol[] = {0, 0, 1, -1};
            for (int i = 0; i < 4; i++)
            {
                int nr = row + delRow[i], nc = col + delCol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1)
                {
                    q.push({nr, nc});
                }
            }
        }
    }

    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> temp;
                    bfs(i, j, temp, vis, grid, n, m, i, j);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }

    bool bipartite(int src, vector<vector<int>> &graph, vector<int> &color)
    {
        queue<int> q;
        q.push(src);
        color[src] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto &it : graph[node])
            {
                if (color[it] == -1)
                {
                    color[it] = 1 - color[node];
                    q.push(it);
                }
                else if (color[it] == color[node])
                    return false;
            }
        }
        return true;
    }

    bool bipartiteDFS(int src, vector<vector<int>> &graph, vector<int> &color)
    {
        for (auto &it : graph[src])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[src];
                if (!bipartiteDFS(it, graph, color))
                    return false;
            }
            else if (color[it] == color[src])
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);
        // for (int i = 0; i < n; i++)
        // {
        //     if (color[i] == -1 && !bipartite(i, graph, color))
        //         return false;
        // }

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                color[i] = 0;
                if (!bipartiteDFS(i, graph, color))
                    return false;
            }
        }
        return true;
    }

    bool cycleCheckDFS(int src, vector<int> adj[], vector<int> &vis, vector<int> &visRec)
    {
        vis[src] = 1;
        visRec[src] = 1;
        for (auto &it : adj[src])
        {
            if (!vis[it] && cycleCheckDFS(it, adj, vis, visRec))
                return true;
            else if (visRec[it])
                return true;
        }
        visRec[src] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0), visRec(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && cycleCheckDFS(i, adj, vis, visRec))
                return true;
        }
        return false;
    }

    void topo(int src, vector<vector<int>> adj, vector<int> &vis, stack<int> &st)
    {
        vis[src] = 1;
        for (auto &it : adj[src])
        {
            if (!vis[it])
                topo(it, adj, vis, st);
        }
        st.push(src);
    }

    vector<int> topologicalSort(vector<vector<int>> adj)
    {
        int v = adj.size();
        vector<int> vis(v, 0), ans;
        stack<int> st;
        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
                topo(i, adj, vis, st);
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

    vector<int> topologicalSort(vector<vector<int>> adj)
    {
        int v = adj.size();
        queue<int> q;
        vector<int> inDegree(v, 0), ans;
        for (int i = 0; i < v; i++)
        {
            for (auto &it : adj[i])
            {
                inDegree[it]++;
            }
        }
        for (int i = 0; i < v; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto &it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }
};

int main()
{
}