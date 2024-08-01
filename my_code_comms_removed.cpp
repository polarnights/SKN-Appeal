#include <iostream>
#include <vector>
#include <string>
#include <ios>

using namespace std;

double total = 0; // <-- 3
int n, a;

int main() {
    cin >> n;
    cin >> a;
    
    vector<double> results(n + 1, 0); // <-- 1
    results[n] = 1; // <-- 2
    for (int i = n; i >= 0; i--) {
        for (int j = 1; j <= a; j++) {
            if (i - j >= 0) {
                results[i - j] += results[i];
            }
        }
    }
    cout << fixed << results[0] << "\n";
}