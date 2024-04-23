class Solution {
public:
    bool isSafe(vector<vector<int>>& track, int x, int y, int n){
        return (x>=0 && x<n && y>=0 && y<n && track[x][y]== -1);
    }

    bool solveProb(vector<vector<int>>& track, int x, int y, int xd[], int yd[], int steps, int n) {
        if(steps==n*n) return true;
        int next_x, next_y;

        for(int k=0; k<8; ++k){
            next_x= x+xd[k];
            next_y= y+yd[k];

            if(isSafe(track,next_x,next_y, n)){
                track[next_x][next_y]= 0;
                if(solveProb(track, next_x, next_y,xd,yd, steps+1, n)== true) return true;
                else track[next_x][next_y]= -1;
            }
        }


        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0)
            return false;

        int row = grid.size(), col = grid.size();
        vector<vector<int>> track(row, vector<int>(col, -1));

        track[0][0]= 0;

        // all possible directions
        int x_dir[8] = {1, -1, 1, -1, 2, 2, -2, -2};
        int y_dir[8] = {-2, -2, 2, 2, -1, 1, -1, 1};

        if(solveProb(track, 0, 0, x_dir, y_dir, 1, row)) return true;
        else return false;
    }
};