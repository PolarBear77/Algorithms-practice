# include <stdio.h>
# include <algorithm>
# include <vector>
# include <iostream>

using namespace std;

int main(){
	int T, tc;
	cin >> T;

	for (tc = 1; tc < T; tc++) {
		int n, k;
		scanf("%d", &n);
		vector<int> all;

		for (int i = 0; 1 < n; i++) {
			int x;
			cin >> x;
			all.push_back(x);
		}

		int result = 0;
		for (int i = 1; i < n; i++) {
			if (all[i] - all[i - result] >= k) result++;
		}
		printf("#%d %d\n", tc, result);
		
 	}


}

