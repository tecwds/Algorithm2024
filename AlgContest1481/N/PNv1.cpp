#include <iostream>
#include <vector>
using namespace std;

vector<int> arr(1);
vector<int> tmp(1);

// 计算逆序对的数量
long long merge(
    int left,
    int mid,
    int right
) {
    long long count = 0;

    int i = left;
    int j = mid;
    int k = left;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else {
            tmp[k++] = arr[j++];
            count += mid - i;
        }
    }

    while (i <= mid - 1) tmp[k++] = arr[i++];
    while (j <= right) tmp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = tmp[i];

    return count;
}

long long merge_sort(int left, int right) {
    long long count = 0;
    if (right > left) {
        int mid = (left + right) / 2;
        count = merge_sort(left, mid);
        count += merge_sort(mid + 1, right);
        count += merge(left, mid + 1, right);
    }
    return count;
}

int main() {
    int n;

    while (1) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long tmp;

        cout << merge_sort(0, arr.size() - 1) << endl;

        arr.clear();
    }   

    return 0;
}