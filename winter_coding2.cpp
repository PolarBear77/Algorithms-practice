#include <string>
#define N 10
using namespace std;

int board[N][N] = { 0 };
pair<int, int> current = { 4,4 };

bool checkValid(int x) {
	return (-1 < x && x < N) ? true : false;
}

int solution(string dirs) {
	int count = 0; // N of unique visits

	for (string::size_type i = 0; i <= dirs.size(); ++i) {

		// move robot, mark the board, +1 count if unique 
		if (board[current.first][current.second] != 1) {
			board[current.first][current.second] = 1;
			count += 1;
		}

		if (dirs[i] == 'U') {
			if (checkValid(current.first - 1)) { current.first -= 1; }
		}
		else if (dirs[i] == 'D') {
			if (checkValid(current.first + 1)) { current.first += 1; }
		}
		else if (dirs[i] == 'L') {
			if (checkValid(current.second - 1)) { current.second -= 1; }
		}
		else if (dirs[i] == 'R') {
			if (checkValid(current.second + 1)) { current.second += 1; }
		}
		
	}

	return count;
}

int main() {
	//solution("ULURRDLLU");
	solution("LURDLURDLURDLURDLURDLURDLURD");

	return 1;
}