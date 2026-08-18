class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        // mask where all nodes are visited
        int allVisited = (1 << n) - 1;
        
        // {current node, visited mask}
        queue<pair<int, int>> q;
        
        // visited[node][mask]
        vector<vector<bool>> visited(
            n, vector<bool>(1 << n, false)
        );
        
        // Start from every node
        for (int i = 0; i < n; i++) {
            
            int mask = (1 << i);
            
            q.push({i, mask});
            visited[i][mask] = true;
        }
        
        int steps = 0;
        
        while (!q.empty()) {
            
            int size = q.size();
            
            while (size--) {
                
                auto [node, mask] = q.front();
                q.pop();
                
                // All nodes visited
                if (mask == allVisited) {
                    return steps;
                }
                
                // Visit neighbours
                for (auto neighbour : graph[node]) {
                    
                    // Add neighbour to visited nodes
                    int newMask = mask | (1 << neighbour);
                    
                    if (!visited[neighbour][newMask]) {
                        
                        visited[neighbour][newMask] = true;
                        
                        q.push({
                            neighbour,
                            newMask
                        });
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};