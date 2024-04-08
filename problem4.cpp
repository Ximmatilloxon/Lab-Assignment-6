#include "iostream"
#include "vector"
#include "cstdint"
using namespace std;

void heapify(vector<int64_t> &arr, int64_t n, int64_t i){
    int64_t largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int64_t > &arr, int64_t n){
    for (int64_t i = n/2 - 1; i >=0; --i) {
        heapify(arr, n, i);
    }
    for (int64_t i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    int64_t n;
    cin >> n;
    vector<int64_t> arr;
    for (int64_t i = 0; i < n; ++i) {
        int t;
        cin >> t;
        arr.push_back(t);
    }
    heapSort(arr, arr.size());
    int64_t dif = INT_MAX;
    for (int64_t i = 0; i < arr.size() - 1; ++i) dif = min(dif, arr[i + 1] - arr[i]);
    vector<vector<int64_t >> vec;
    for (int64_t i = 0; i < arr.size() - 1; ++i) {
        if(arr[i + 1] - arr[i] == dif) vec.push_back({arr[i], arr[i+1]});
    }
    cout << vec[0][0] << " " << vec[0][1];
    for (int64_t i = 1; i < vec.size(); ++i) {
        cout << "\n" << vec[i][0] << " " << vec[i][1];
    }
}