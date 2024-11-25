#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n;
  cin >> n;
  int numInc = 1;
  int numDec = 0;
  int prevNum = 1;
  int decPtrBegin;
  int decPtrEnd = -1;
  bool isIncreasing = true;

  vector<int> num;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    num.push_back(temp);
    if (i == 0) {
      prevNum = temp;
      continue;
    }
    if ((isIncreasing && prevNum <= temp) ||
        (!isIncreasing && prevNum >= temp)) {
      cout << isIncreasing << " && " << prevNum << " <= " << temp << endl;

      prevNum = temp;

      continue;
    } else if (isIncreasing && prevNum > temp) {
      // cout << prevNum << " n" << temp << endl;
      prevNum = temp;
      decPtrBegin = i - 1;
      isIncreasing = false;

      numDec++;
      cout << numDec << endl;
      if (numDec > 1) {
        cout << "impossible";
        break;
      }
    } else {
      prevNum = temp;

      decPtrEnd = i - 1;
      isIncreasing = true;
    }
  }

  // cout << num[decPtrBegin - 1] << " " << num[decPtrBegin] << endl;
  if (decPtrBegin > 0)
    while (num[decPtrBegin - 1] == num[decPtrBegin]) decPtrBegin--;
  cout << numDec << " " << decPtrEnd << endl;

  if (numDec == 0)
    cout << "0  0" << endl;
  else {
    if (decPtrBegin == decPtrEnd) {
      cout << "impossible";
    } else if (decPtrBegin == 0 && num[decPtrBegin] <= num[decPtrEnd + 1]) {
      cout << decPtrBegin + 1 << " " << decPtrEnd + 1 << endl;
    } else if ((decPtrEnd == -1) && num[decPtrEnd] >= num[decPtrBegin - 1]) {
      cout << decPtrBegin + 1 << " " << decPtrEnd + 1 << endl;
    } else if (num[decPtrBegin] <= num[decPtrEnd + 1] &&
               num[decPtrEnd] >= num[decPtrBegin - 1])
      cout << decPtrBegin + 1 << " " << decPtrEnd + 1 << endl;
    else
      cout << "impossible";
  }
}

int main() {
  solution();
  return 0;
}