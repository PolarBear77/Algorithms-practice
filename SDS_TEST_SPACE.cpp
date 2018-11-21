#include <stdio.h>
#include <iostream>

using namespace std;

long int MIN = 9876543210;
int n = 0;
int m = 0;

void solve(int depth, int r1, int c1, int r2, int c2) {

	//int visited[= { 0, };

	// Base cases
	if (depth > MIN) { // bad path!
		return;
	}

	// Teleport
	if (r1 == -1) { r1 = n - 1; } // upwards!
	if (c1 == -1) { c1 = m - 1; } // leftwards?
	if (r1 == n) { r1 = 0; }     // downwards!
	if (c1 == m) { c1 = 0; }     // rightward
								 
    // arrived
	if (r1 == r2 && c1 == c2) {
		MIN = depth < MIN ? depth : MIN;
		return;
	}


	// Up, down, left, right
	depth += 1;
	solve(depth, r1 - 1, c1, r2, c2);
	solve(depth, r1 + 1, c1, r2, c2);
	solve(depth, r1, c1 - 1, r2, c2);
	solve(depth, r1, c1 + 1, r2, c2);

}

int main() {
	int tc;
	cin >> tc;

	for (int t = 0; t < tc; t++) {

		int r1, c1, r2, c2 = 0;
		cin >> n >> m >> r1 >> c1 >> r2 >> c2;
		MIN = (abs(r1 - r2) + abs(c1 - c2));
		solve(0, r1, c1, r2, c2);
		cout << "#" << t + 1 << " " << MIN << "\n";
	}

	return 1;
}