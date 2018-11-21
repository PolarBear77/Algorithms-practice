#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class InterestingParty{
	public:
		pair<string, int> bestInvitation(vector<int> first, vector<int> second) {
			map<string, int> temp;

			for (auto t : first) {
				temp[t]++;
			}

			map<string, int>::iterator it;
			pair<string, int> topic;

			for (it = temp.begin(); it != temp.end(); it++) {
				topic = (*it).second > topic.second ? make_pair((*it).first, (*it).second) : topic;

			}

			return topic;
		}
}

int main() {
	InterestingParty temp = InterestingParty();
	
	cout << temp.bestInvitation({ "v", "d", "l", "c" }, { "t", "s", "d", "m" });

	return 1;
}