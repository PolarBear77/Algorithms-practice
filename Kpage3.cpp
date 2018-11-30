#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> first, second;

	int m, n, k, temp = 0;


	// get two arrays
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		first.push_back(temp);
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		second.push_back(temp);
	}


	cin >> k;
	if (k > n + m) {  // corner cases
		return -1;
	}
	else if (k == (n + m)) {
		return first.back() > second.back() ? first.back() : second.back();
	}

	int count = 0, current = 0;
	vector<int>::iterator itFirst = first.begin();
	vector<int>::iterator itSecond = second.begin();

	while (count < k) {
		if (*itFirst < *itSecond) {
			current = *itFirst;
			itFirst++;
		}
		else {
			current = *itSecond;
			itSecond++;
		}
		count++;
	}

	cout << current;
	return 0;
}