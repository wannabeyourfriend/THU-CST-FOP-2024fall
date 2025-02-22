#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;
string password(map<string, int> &word2num, vector<string> input){
    vector<int> res;
    for (const auto& element : input) {
        int num = word2num[element];
        res.push_back(num * num % 100);
    }
    sort(res.begin(), res.end());
    string result = "";
    for(const auto& num : res){
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
    return result;       
}
int main(){
    vector<string> words = {"zero","one","two", "three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen"};
    map<string, int> word2num;
    for(int i = 0; i < words.size(); i++)   
        word2num[words[i]] = i;
    int m;
    cin >> m;
    vector<string> input;
    for(int i = 0; i < m; i++){
        string tmp;
        cin >> tmp;
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        auto it = find(words.begin(), words.end(), tmp);
        if (it != words.end())
            input.push_back(tmp);
    }
    string result = password(word2num, input);
    cout << result << endl;
    return 0;
}


   
    