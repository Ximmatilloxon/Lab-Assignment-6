#include "iostream"
#include "vector"
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if(l < n && arr[l] > arr[largest]) largest = l;
    if(r < n && arr[r] > arr[largest]) largest = r;
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    for (int i = n/2 - 1; i >=0; --i) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int minDiff(int arr[], int n){
    int dif = INT_MAX;
    for (int i = 0; i < n - 1; ++i) dif = min(dif, abs(arr[i] - arr[i + 1]));
    return dif;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    heapSort(arr, n);
    int dif = minDiff(arr, n);
    vector<vector<int>> vec;
    for (int i = 0; i < n - 1; ++i) {
        vector<int> temp;
        if(abs(arr[i] - arr[i+1]) == dif){
            temp.push_back(min(arr[i], arr[i+1]));
            temp.push_back(max(arr[i], arr[i+1]));
            vec.push_back(temp);
        }
    }
    for(auto i:vec) cout << i[0] << " " << i[1] << endl;
}