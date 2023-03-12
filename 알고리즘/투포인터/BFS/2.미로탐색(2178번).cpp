//https://www.acmicpc.net/problem/2178

#include <bits/stdc++.h>
using namespace std;
#define MAX 101

int N, M;
int maze[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

queue<pair<int, int>> q;

void bfs(int x, int y)
{
    visited[x][y] = true;
    q.push(make_pair(x, y));
    dist[x][y]++;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (visited[nx][ny] == false && maze[nx][ny] == 1)
                {
                    visited[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        string row;
        cin >> row;
        for(int j=0; j<M; ++j) {
            maze[i][j] = row[j] -'0';
        }
    }
    bfs(0, 0);
    cout << dist[N-1][M-1];
}
