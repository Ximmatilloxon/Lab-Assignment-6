#include "iostream"
#include "map"
using namespace std;

int main(){
    int n;
    map<int, int> m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        m[t]++;
    }
    int answer, Max = 0;
    for (auto i:m) {
        if (i.second > Max){
            answer = i.first;
            Max = i.second;
        }
    }
    cout << answer;
}