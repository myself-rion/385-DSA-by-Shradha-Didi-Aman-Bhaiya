class Solution {
  public:
  bool detectCycle_bfs(int src, vector<int> adj[], int vis[]){
      vis[src]= true;
      
      queue<int> q;
      q.push(src);
      
      while(!q.empty()){
          int node= q.front();
          q.pop();
          int count=0; //to check the cycle
          
          for(auto &adjNodes: adj[node]){
              if(!vis[adjNodes]){
                  vis[adjNodes]= true;
                  q.push(adjNodes);
              }
              else{
                  count++;
              }
              
          }
          if(count>1) return true; //count=1 is normal because for an undirected graph the parent is visited, but if count>1 that means our next neighbour node has been visited already from another path which forms a cycle
      }
      
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={false};
        
        for(int i=0; i<V; ++i){
            if(!vis[i]){
                if(detectCycle_bfs(i, adj, vis)) return true;
            }
        }
        
        return false;
    }
};