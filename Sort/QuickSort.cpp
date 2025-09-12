#include <cstdio>
#include <cstdlib>

const int maxn = 1e5 + 9;

int num[maxn], a[maxn], b[maxn], c[maxn];

int randNumInit(int, int);
void quickSort(int, int);

int main(int argc, const char *argv[]) {
    int n;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
    }

    quickSort(1, n);

    for (int i = 1; i <= n; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}

int randNumInit(int l, int r) {
    return rand() % (r - l + 1) + l;
}

void quickSort(int l, int r) {
    if (l >= r) {
        return;
    }

    int randNum = randNumInit(l, r);
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;

    for (int i = l; i <= r; i++) {
        if (num[i] < num[randNum]) {
            a[cnt1] = num[i];
            cnt1++;
        } else if (num[i] == num[randNum]) {
            b[cnt2] = num[i];
            cnt2++;
        } else {
            c[cnt3] = num[i];
            cnt3++;
        }
    }

    for (int i = 0; i < cnt1; i++) {
        num[l + i] = a[i];
    }

    for (int i = 0; i < cnt2; i++) {
        num[l + i + cnt1] = b[i];
    }

    for (int i = 0; i < cnt3; i++) {
        num[l + i + cnt1 + cnt2] = c[i];
    }

    quickSort(l, l + cnt1 - 1);
    quickSort(l + cnt1 + cnt2, r);
}