#include <stdio.h>
#include <iostream>
#include <windows.h>

#define MINUS1     -1
#define ELEVEN1 MINUS1, MINUS1, MINUS1, MINUS1, MINUS1, MINUS1, MINUS1, MINUS1, MINUS1, MINUS1, MINUS1

using namespace std;
int map[11][11] = { // 원래 10 x 10이지만 패딩 추가
	ELEVEN1, ELEVEN1, ELEVEN1, ELEVEN1, ELEVEN1, ELEVEN1,
	ELEVEN1, ELEVEN1, ELEVEN1, ELEVEN1, ELEVEN1
}; 
int cities = 0;
int n = 0;
int moves[8][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0},
					{1, 1}, {1, -1}, {-1, 1}, {-1, -1} };


void seekShelter(int x, int y) {

	bool hasWater = false;
	bool hasMountain = false;
	bool hasMeadow = false;

	// 지금땅이 불모지인 경우
	if (map[x][y] == 0) {
		return;
	}


	for (int i = 0; i < 8; i++) {
		int x2 = x + moves[i][0];
		int y2 = y + moves[i][1]; 
		int current = map[x2][y2];

		// 불모지가 있는 경우 리턴
		if (current == 0) {
			return;
		}
		
		if (current == -1) {
			continue;
		}
		
		// 물, 산, 초원?
		if (current == 1) {
			hasWater = true;
			continue;
		} else if (current == 2) {
			hasMountain = true;
			continue;
		} else if (current == 3) {
			hasMeadow = true;
			continue;
		}

		// 젖과 꿀이 흐르는 땅이당
		if (hasWater && hasMountain && hasMeadow) {
			cities += 1;
			return;
		}
	
	}

}

int main() {
	int tc = 0;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		cin >> n;
		memset(map, -1, sizeof(map[0][0]) * n * n);
		cities = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i + 1][j + 1];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				seekShelter(i + 1, j + 1);
			}
		}

		cout << "#" << t + 1 << " " << cities << "\n";
	}

	Sleep(1000000);
	return 1;
}