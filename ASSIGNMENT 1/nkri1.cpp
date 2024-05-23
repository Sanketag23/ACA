#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iomanip>
#include <fstream>
#define ll long long
using namespace std;
int main() {
    ll n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << m << endl;
        return 0;
    }
    if (m == 0) {
        cout << 0 << endl;
      return 0;
    }
    ll lw = 1, hgh = m;
     ll rslt = -1;
    while (lw <= hgh) {
        ll m_p = 1;
        ll md = lw + (hgh - lw) / 2;
        int  flag = 0;
        for (int i = 0; i < n; i++) {
            if (m_p > m / md) {
                flag = 1;
                break;
            }
            m_p *= md;
        }
        if (flag==0 && m_p==m) {
           rslt = md;
            break;
        } else if (flag==1 || m_p > m) {
            hgh = md - 1;
        } else {
            lw = md + 1;
        }
    }
    cout <<rslt << endl;
   
}
