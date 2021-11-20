class Solution {
public:
    bool flag;
    int vis[202][202];

    void DFS(int i, int j, vector<vector<char>> &board, vector<pair<int,int>> &v, int n, int m)
    {
        if(i < 0 || j < 0 || i == n || j == m || board[i][j] == 'X') return;
        if(vis[i][j]) return;
        if(i == 0 || j == 0 || i == n-1 || j == m-1) flag = false;

        v.push_back({i, j});
        vis[i][j] = 1;

        DFS(i+1, j, board, v, n, m);
        DFS(i-1, j, board, v, n, m);
        DFS(i, j+1, board, v, n, m);
        DFS(i, j-1, board, v, n, m);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        memset(vis, 0, sizeof(vis));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && board[i][j] == 'O' && i && j && i != n-1 && j != m-1){
                    flag = true;
                    vector<pair<int,int>> v;

                    DFS(i, j, board, v, n, m);

                    if(flag){
                        for(auto it : v){
                            board[it.first][it.second] = 'Y';
                        }
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'Y') board[i][j] = 'X';
            }
        }
    }
};