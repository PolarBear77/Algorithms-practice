# include "stdafx.h"
#include<iostream>
#include<string>
#include<string.h>
#include <windows.h>
using namespace std;

string n;
int k, ans;
int D[1000000];

void go(string m, int cnt){
	int ret = stoi(m);

	if (D[cnt] > ret){
		return;
	}

	if (cnt == k) {

		if (ret > ans) {
			ans = stoi(m);
		}
		return;
	}

	D[cnt] = ret;


	for (int i = 0; i < m.size(); i++) {
		for (int j = i + 1; j < m.size(); j++) {
			string tmp = m;
			swap(tmp[i], tmp[j]);
			go(tmp, cnt + 1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		memset(D, -1, sizeof(D));
		n = "";
		k = 0, ans = 0;
		cin >> n >> k;

		go(n, 0);



		cout << "#" << t << " " << ans << "\n";
	}
	Sleep(50000);

	return 0;
}