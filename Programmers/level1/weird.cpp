#include <string>
#include <vector>
using namespace std;

string solution(string s) {
    int si = s.size(), j = 0;
    for(int i=0;i<si;i++){
        if(s[i]==' '){
            j=0;
            continue;
        }
        if(j%2==0 && 'a'<=s[i]&&s[i]<='z'){
            s[i] = s[i]-'a'+'A';
        }
        if(j%2==1 && 'A'<=s[i]&&s[i]<='Z'){
            s[i] = s[i] - 'A'+'a';
        }
        j++;
    }
    return s;
}