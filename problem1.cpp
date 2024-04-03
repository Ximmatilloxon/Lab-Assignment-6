#include "iostream"
using namespace std;

void Sort(int arr[], int s){
    bool flag = true;
    while(flag){
        flag = false;
        for(int i = 0; i < s - 1; i++){
            if(arr[i] > arr[i + 1]){
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                flag = true;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    int o = (n % 2 > 0) ? n / 2 + 1 : n / 2, e = -1, t = -1;
    int Odd[o], Even[n / 2];
    for (int i = 1; i <= n; ++i) {
        if(i % 2 > 0){
            t++;
            cin >> Odd[t];
        }
        else{
            e++;
            cin >> Even[e];
        }
    }

    Sort(Odd, o);
    Sort(Even, e);
    o = 0;
    for (int i = 1; i < n + 1; ++i) {
        if(i % 2 > 0){
            cout << Odd[o] << " ";
            o++;
        }
        else{
            cout << Even[e] << " ";
            e--;
        }
    }

}