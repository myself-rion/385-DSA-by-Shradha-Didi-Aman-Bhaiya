class Solution {
public:
    void solveFloodFill(vector<vector<int>>& image, int i, int j, int row, int col, int sCLR, int nCLR){
        if(i<0 || i>=row || j<0 || j>=col || image[i][j]!=sCLR) return; //base case
        
        image[i][j]=nCLR;
        
        int x[]={1,0,0,-1}; //down, left, right, up
        int y[]={0,-1,1,0};
        
        for(int index=0; index<4; index++){
            solveFloodFill(image, i+x[index], j+y[index], row, col,sCLR, nCLR);
        }
        
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        
        int n=image.size(), m=image[0].size();
        int sourceColor= image[sr][sc];
        
        if(sourceColor==newColor) return image; //no where to color
        
        solveFloodFill(image, sr, sc,n,m, sourceColor, newColor);
        
        return image;
    }
};