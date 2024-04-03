#include "iostream"
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

int main(){
    int n;
    cin >> n;
    int o = (n%2 > 0) ? n/2 + 1 : n/2, e = 0;
    int Odd[o], Even[n/2];
    o = 0;
    for (int i = 0; i < n; ++i) {
        if(i%2 < 1){
            cin >> Odd[o];
            o++;
        }
        else{
            cin >> Even[e];
            e++;
        }
    }
    heapSort(Odd, o);
    heapSort(Even, e);

    e = 0;
    for (int i = 0; i < n; ++i) {
        if(i%2 < 1){
            o--;
            cout << Odd[o] << " ";
        }
        else{
            cout << Even[e] << " ";
            e++;
        }
    }

}