#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;
int getfromword(string word)  {
    int sum = 0;
    int n = word.size();

    for(int i = 0; i < n; i++) {
        sum += int(word[i]);
    }
    sum = sum % 100;
    return sum;
}
int main() {
    vector<string> words = {"zero","one","two", "three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen"};
    map<string, int> word2num;
    for(int i = 0; i < words.size(); i++)   
        word2num[words[i]] = i;
    int m;
    cin >> m;
    vector<int> input;
    for(int i = 0; i < m; i++){
        string tmp;
        string ori;
        cin >> tmp;
        ori = tmp;
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        auto it = find(words.begin(), words.end(), tmp);
        if (it != words.end()) {
            int asc = getfromword(ori);
            input.push_back(asc);
        }
    }
    sort(input.begin(), input.end());
    string result = "";
    for(int num : input) {
        ostringstream oss;
        oss << num;
        string str = oss.str();
        if(str.size() == 2)
            result = result + str;
        else
            result = result + "0" + str;
    }
    long long numres;
    istringstream(result) >> numres;
    ostringstream stringres;
    stringres << numres;
    result = stringres.str();
    cout << result << endl;
    return 0;   

}

