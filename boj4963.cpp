#include <iostream>
#include <vector>
#define MAX 51
#define DEBUG 1

#ifdef DEBUG
#include <Windows.h>
#endif

using namespace std;

int islands[MAX][MAX] = { 0, };
int answer = 0;

vector<pair<int, int>> directions = { {1,0}, {1,1}, {0,1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

void dfs(int i, int j) {
	
	if (!islands[i][j]) return;
	
	// mark as zero so DFS isn't called on neighboring cells
	islands[i][j] = 0; 

	for (int d = 0; d < directions.size(); d++) {
		
		int dx = i + directions[d].first;
		int dy = j + directions[d].second;

		if (islands[dx][dy]) {
			dfs(dx, dy);
		}
	}
	return;
}


int main() {
	while (true) {
		int width, height;
		int answer = 0;
		cin >> width >> height;

		if ((width > 50) || (height > 50)) {
			cout << "Input over 50, exiting";
		}
		else if ((width < 1) || (height < 1)) {
			cout << "Input under 1, exiting";
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				int inpt;
				cin >> inpt;
				islands[i][j] = inpt;
			}
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (islands[i][j]) { dfs(i, j); answer++; }
			}
		}

		cout << "Islands: " << answer;

	} // while

	#ifdef DEBUG
		Sleep(1000000);
	#endif

	return 0;
}