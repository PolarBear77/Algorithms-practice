#include <stdio.h>
#include <iostream>

/*
Time limit: 5s
Mem. lmiit: 256MB

Test cases <= 50
Numbers - 2 <= N <= 100,000
Additions - 0 <= P <= N-1
Subtractions - 0 <= M < N-1
(given M + P = N - 1 )

*/

using namespace std;

int numbers[100000] = { 0, };
long int MAX = -9876543210;
int N = 0;


void solve (int depth, int plus, int minus, int current) {
	
	// 기저케이스 - 마지막 숫자인 경우
	depth += 1;
	if (depth == N) {
		MAX = current > MAX ? current : MAX;
		return;
	}

	// 재귀
	if (plus > 0)  { solve(depth, plus - 1, minus, current + numbers[depth]); }
	if (minus > 0) { solve(depth, plus, minus - 1, current - numbers[depth]); }


}

int main() {
	
	int tc = 0;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		int plus = 0;
		int minus = 0;
		MAX = -9876543210;

		// reset numbers array
		for (int i = 0 ; i < N; i++) { numbers[i] = 0; }

		// input test case params
		cin >> N >> plus >> minus;

		// get N numbers
		for (int i = 0; i < N; i++) { cin >> numbers[i]; }

		// exhaustive search
		solve(0, plus, minus, numbers[0]);


		cout << "#" << t+1 << " " << MAX;
	}
}