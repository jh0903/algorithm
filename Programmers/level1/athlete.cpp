#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer="";
    map<string, int> m;
	int c_si = completion.size();
	for (int i = 0; i < c_si; i++) {
		if (m.find(completion[i]) != m.end())
			m[completion[i]]++;
		else m.insert({ completion[i], 1 });
	}
	int p_si = participant.size();
	for (int i = 0; i < p_si; i++) {
		if (m.find(participant[i]) != m.end()) {
			if (m[participant[i]]) m[participant[i]]--;
			else {
				answer = participant[i];
				break;
			}
		}
		else {
			answer = participant[i];
			break;
		}
	}
    return answer;
}