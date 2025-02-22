/*
程设某年题 AC代码
2430
素数间距
g++ -o main2430 2430.cpp
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct Pair {
    int C1, C2;
    Pair(int x, int y) : C1(x), C2(y) {}
};
vector<int> Eratosthenes(int n) {
    const int N = n; 
    bool is_prime[N];
    vector<int> primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i) 
        is_prime[i] = true;
    // i * i <= n 说明 i <= sqrt(n)
    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i) 
                is_prime[j] = false;
    }
    for (int i = 2; i <= n; ++i)
        if (is_prime[i]) 
            primes.push_back(i);
    return primes; 
}
bool compare1(struct Pair a, struct Pair b) {
    if((a.C2 - a.C1) == (b.C2 - b.C1))
        return (a.C1 + a.C2) < (b.C1 + b.C2);
    return (a.C2 - a.C1) < (b.C2 - b.C1);
} 
bool compare2(struct Pair a, struct Pair b) {
    if((a.C2 - a.C1) == (b.C2 - b.C1))
        return (a.C1 + a.C2) < (b.C1 + b.C2);
    return (a.C2 - a.C1) > (b.C2 - b.C1);
}
//把 sqrt(n) 区间内的质数存下来后，用这些质数直接筛 [L,U] 之间的数字即可
int main() {
    int L, R;
    cin >> L >> R;
    vector<int> primes = Eratosthenes(sqrt(R));
    int rg = R - L;
    vector<int> is_prime(rg + 1, true);
    for(int prime : primes) {
        int left = L / prime;
        int right = R / prime;
        for(int i = left; i <= right + 1; i++){
            int x = i * prime;
            if(x <= R && x >= L && x != prime) {
                is_prime[x - L] = false; 
            }
        }
    }
    if(L == 0) {
        is_prime[0] = false;
        is_prime[1] = false;
    }
    if(L == 1) {
        is_prime[0] = false;
    }
    vector<Pair> pairs;
    for(int i = L; i < R; i++) {
        if(is_prime[i - L]){
            for(int j = i + 1; j <= R; j++){
                if(is_prime[j - L]) {
                    Pair pair(i, j);
                    pairs.push_back(pair);
                    break;
                }
            }
        }
    }
    if(pairs.size() == 0){
        cout << "-1" << endl;
        return 0;
    }
    sort(pairs.begin(), pairs.end(), compare1);
    cout << pairs[0].C1 << " " << pairs[0].C2 << endl;
    sort(pairs.begin(), pairs.end(), compare2);
    cout << pairs[0].C1 << " " << pairs[0].C2 << endl;
    return 0;
}
