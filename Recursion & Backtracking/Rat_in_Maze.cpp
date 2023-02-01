class Solution{
    private:
    int isSafe(vector<vector<int>>m,int x,int y,int n,vector<vector<int>>visited){
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]!=0){
            return 1;
        }
        else{
            return 0;
        }
        
    }
    void solve(int x,int y,vector<string> &ans,vector<vector<int>>visited,string output, vector<vector<int>>m,int n){
        if(x==n-1 && y==n-1){
            ans.push_back(output);
            return;
        }
        visited[x][y]= 1;
        //Down Direction
        int newX= x+1;
        int newY= y;
        if(isSafe(m,newX,newY,n,visited)){
            output.push_back('D');
            solve(newX,newY,ans,visited,output,m,n);
            output.pop_back();
        }
        //Left Direction
        newX= x;
        newY= y-1;
        if(isSafe(m,newX,newY,n,visited)){
            output.push_back('L');
            solve(newX,newY,ans,visited,output,m,n);
            output.pop_back();
        }
        //Right Direction
        newX= x;
        newY= y+1;
        if(isSafe(m,newX,newY,n,visited)){
            output.push_back('R');
            solve(newX,newY,ans,visited,output,m,n);
            output.pop_back();
        }
        //Up Direction
        newX= x-1;
        newY= y;
        if(isSafe(m,newX,newY,n,visited)){
            output.push_back('U');
            solve(newX,newY,ans,visited,output,m,n);
            output.pop_back();
        }
        visited[x][y]=0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        int x=0;
        int y=0;
        vector<string> ans;
        if(m[x][y]==0){
            return ans;
        }
        vector<vector<int>> visited(n,vector<int> (n,0));
        string output="";
        solve(x,y,ans,visited,output,m,n);
        return ans;
    }
};