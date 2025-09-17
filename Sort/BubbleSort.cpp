#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
    const int maxn = 10005;

    int n;
    int num[maxn];
    bool flag;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    flag = true;
    while (flag) {
        flag = false;
        for (int i = 1; i < n; i++) {
            if (num[i] > num[i + 1]) {
                flag = true;
                swap(num[i], num[i + 1]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}