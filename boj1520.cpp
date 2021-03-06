# include "stdafx.h"
# include <memory.h>
# include <windows.h>

int n, m;
int map[501][501];
int visited[501][501];
int a[4] = { 1, 0, -1, 0 };
int b[4] = { 0, 1, 0, -1 };


int dfs(int x, int y) {

	if (visited[x][y] != -1) { return visited[x][y]; }
	if (x < 0 || y < 0 || x >= n || y >= m) { return 0; }

	visited[x][y] = 0;

	if (map[x][y] > map[x + 1][y]) visited[x][y] += dfs(x + 1, y);
	if (map[x][y] > map[x - 1][y]) visited[x][y] += dfs(x - 1, y);
	if (map[x][y] > map[x][y + 1]) visited[x][y] += dfs(x, y + 1);
	if (map[x][y] > map[x][y - 1]) visited[x][y] += dfs(x, y - 1);

	return visited[x][y];
}

int main() {
	scanf_s("%d %d", &n, &m, sizeof(n), sizeof(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &map[i][j]);
		}
	}
	memset(visited, -1, sizeof(visited));

	printf("%d", dfs(0, 0));
	Sleep(1000);
}
