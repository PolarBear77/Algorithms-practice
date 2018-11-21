# include <iostream>
# include <algorithm>
# include <vector>
# include <sstream>

using namespace std;

int main() {
	int T, testcase;
	cin >> T;

	for (testcase = 1; testcase <= T; testcase++) {
		string text;
		cin >> text;
		stringstream ss;
		ss << text;
		string str = ss.str();
		int len = str.length()-1;
		bool flag = false;

		for (int i = 0; i < len; i++) {
			if (str[i] != str[len - i]) {
				printf("Not palindrome\n");
				flag = true;
				break;
			}
		}
		if (flag) {
			continue;
		}
		cout << str << "is plaindrome" << '\n';



	}
}
