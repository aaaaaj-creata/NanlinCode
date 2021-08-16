#include <iostream>
#include <vector>
using namespace std;
//找到数组第K大的数
//1.对数组进行排序
//2.遍历k-1个数，然后下标指向的数即为第K大的
int getStard(vector<int> arr) {
    int key = arr[0];
    int low = 0;
    int high = arr.size() - 1;
    while (low < high) {
        while (low < high&& arr[high] > key) {
            high--;
        }
        if (low < high) {
            arr[low] = arr[high];
        }
        while (low < high && key <= arr[low]) {
            low++;
        }
        if (low < high) {
            arr[high] = arr[low];
        }
    }
    key = arr[low];
    return key;
}

void sort(vector<int>& arr, int low, int high) { //快排
    int key = arr[0];
    //找到基准key
    key = getStard(arr);
    //递归排序
    sort(arr, low, key - 1);
    sort(arr, key + 1, high);
}

int findK(vector<int> arr, int K) {
    int len = arr.size();
    //排序
    sort(arr, 0, len - 1);
    //遍历到第K个
    return arr[len - K];
}

int main() {
    vector<int> arr = { 2,5,7,3,1 };
    int K = 2; //期望输出5
    int res = findK(arr, K);
    cout << res << endl;
    return 0;
}