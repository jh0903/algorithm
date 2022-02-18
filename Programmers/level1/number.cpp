#include <string>
#include <vector>

using namespace std;

vector<string> v = { "zero", "one", "two", "three", "four", "five","six","seven","eight","nine" };

int solution(string s) {
    string st = s;
    for (int i = 0; i < 10; i++) {
        if (st.find(v[i]) != string::npos) {
            while(st.find(v[i])!=string::npos)
                st.replace(st.find(v[i]), v[i].size(), to_string(i));
        }
    }
    int answer = stoi(st);
    return answer;
}