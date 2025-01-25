#include <iostream>
#include <vector>
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int n;
  vector<int> nums;

  cin >> n;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    nums.push_back(temp);
  }

  int x;
  cin >> x;

  int left = 0;
  int right = n - 1;

  while (left < right) {
    const int mid = (left + right) / 2;
    if (nums[mid] < x) {
      right = mid;
    } else {
      left = mid;
    }
    if (nums[mid] == x) {
      cout << "YES" << endl;
      return 0;
    }
  }
  
  cout << "NO" << endl;
  return 0;
}

