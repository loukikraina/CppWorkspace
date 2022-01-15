void solve(int x, int y, vector<vector<int>> &m, int n, string &ds, vector <string> &result,
    int dir[][2], char name[]){
        if(x==n-1 && y==n-1){
            result.push_back(ds);
            return;
        }
        if(m[x][y]==0) return;
        for(int i=0;i<4;i++){
            if(x+dir[i][0]>=0 && x+dir[i][0]<n && y+dir[i][1]>=0 && y+dir[i][1]<n && m[x+dir[i][0]][y+dir[i][1]]){
                
                ds.push_back(name[i]);
                int temp = m[x][y];
                m[x][y] = 0;
                solve(x+dir[i][0], y+dir[i][1], m, n, ds, result, dir, name);
                ds.pop_back();
                m[x][y] = temp;
            }
        }
    }
    
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        int dir[][2] = {{1,0},  {0,-1}, {0,1}, {-1,0}};
        char name[] = {'D','L','R','U'};
        string ds;
        vector <string> result;
        solve(0, 0, m, n, ds, result, dir, name);
        return result;
    }