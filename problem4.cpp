#include "iostream"
#include "vector"
using namespace std;

void heapify(vector<int> &arr, int n, int i){
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr, int n){
    for (int i = n/2 - 1; i >=0; --i) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int diff(vector<int> &arr){
    int dif = INT_MAX;
    for (int i = 0; i < arr.size(); ++i){
        for (int j = 0; j < arr.size(); ++j) {
            if(j != i) dif = min(dif, abs(arr[i] - arr[j]));
        }
    }
    return dif;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    if(n == 1) cout << arr[0];
    else {
        heapSort(arr, n);

        int dif = diff(arr);

        vector<pair<int, int>> vec;
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i + 1] - arr[i] == dif && arr[i + 1] > arr[i]) vec.emplace_back(arr[i], arr[i + 1]);
        }

        cout << vec[0].first << " " << vec[0].second;
        for (int i = 1; i < vec.size(); ++i) {
            cout << "\n" << vec[i].first << " " << vec[i].second;
        }
    }
}