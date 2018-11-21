#include <iostream>
#include <algorithm>
#define N 1001

using namespace std;

string inpt[N];

int getSum(string a) {
	int sum = 0;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] - '0' >= 0 && a[i] - '0' <= 9) {
			sum += a[i] - '0';
		}
	}

	return sum;
}


bool compareStrings(string a, string b) {
	//int lenA, lenB;
	//lenA = a.length();
	//lenB = b.length();
	
	if (a.length() != b.length()) {
		return false;
	}
	else if (a.length() < b.length()) {
		return true;
	} 
	else if (a.length() == b.length()) { // ���ٸ� ��ȣ�� �� ��

		if (getSum(a) != getSum(b)) { // sum�� �ٸ� ���� ���ڿ��� ������ -> �Ѵ� 0 �̹Ƿ� sum�� ������
			return getSum(a) < getSum(b);
		}
		else {
			return a > b; // ������ ��
		}
 	}	
}

int main() {

	int n = 0;
	cin >> n;
	if (n > 1000) {
		return -1;
	}

	for (int i = 0; i < n; i++) {
		cin >> inpt[i];
	}

	sort(inpt, inpt + n, compareStrings);
		
	for (int i = 0; i < n; i++) {
		cout << inpt[i] << '\n';
	}

	return 1;
}
