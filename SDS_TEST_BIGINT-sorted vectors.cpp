# include <stdio.h>
# include <iostream>
# include <vector>
# include <algorithm>
# include <functional>

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

using namespace std;

vector<int> posNumbers, negNumbers;



int main() {

	int tc = 0;
	cin >> tc;

	for (int t = 0; t < tc; t++) {
		int plus = 0;
		int minus = 0;
		MAX = -9876543210;
		int zeroCount = 0;

		// input test case params
		cin >> N >> plus >> minus;

		/* 
		get N numbers
	    push back according to positive | negative
		ignore zero, as +|- zero does not make difference
		*/
		for (int i = 0; i < N; i++) {
			int input;
			cin >> input;

			if (input == 0) { // if zero skip
				zeroCount += 1;
				continue;
			}
			if (input > 0) { // positive
				posNumbers.push_back(input);
			} else { // negative
				negNumbers.push_back(input);
			}
		}

		sort(posNumbers.begin(), posNumbers.end());
		sort(negNumbers.begin(), negNumbers.end());


		/* 
		SOLVING PART
		*/

		vector<int>::iterator pos = posNumbers.begin();
		vector<int>::iterator neg = negNumbers.begin();

		// compare postive&negative numbers, add | subtract according to number size
		while (plus + minus != 0) {

			/* 1. Corner case: When vector depletes
			   no positive numbers & negative numbers left */
			if (pos == posNumbers.end() && neg != negNumbers.end()) {
				for(int i = 0; i < minus; i++) { // use -
					MAX -= *neg;
					neg++;
				}
				for (int i = 0; i < plus; i++) { // use +
					MAX += *neg;
					neg++;
				}
				break; // break While loop
			}

			// no negative numbers & positive numbers left
			if (neg == negNumbers.end() && pos != posNumbers.end()) { 	
				for (int i = 0; i < plus; i++) { // use +
					MAX += *pos;
					pos++;
				}
				for (int i = 0; i < minus; i++) { // use -
					MAX -= *pos;
					pos++;
				}
				break; // break While loop
			}

			/* FROM HERE
			- cant think of cases where same
			- we need recursion of some sort
			- runtime 5seconds daunting :O!
			*/

			// if positive 
			if (*pos > abs(*neg)) {

			}


		} // while loop

		


		cout << "#" << t + 1 << " " << MAX;
	}
}