#include <iostream>
#include <vector>
#include <string>
#include <ios>

using namespace std;

// N единиц
// 1 ... A
// Дп ???
// удаляем набор из (1...A) <- for единиц начиная с позиции j (наращивая j), если можем
// смотрим, что будет дальше, потом возвращаем
// возможно, подсчитаем часть способов 2 раза
// каждая операция описывается index_start + length

double total = 0;
int n, a;

// нужно как-то грамотно сохранять те позиции, по которым мы уже проходились
// иначе мы будем считать один и тот же checker(current_pos) много много раз
// bfs (?)

vector<int> visited(n + 1, 0); 

// !!!
// long double подумать

/*
void checker (int current_pos) {
    // current_pos включительно
    // расстояние до конца [1 .... n]
    for (int j = 1; j <= min(a, n - current_pos); j++) { // возможно n - current_pos + 1
    // пример [1] , cur_pos = 0, n = 1.n-cur_pos= 1, значит ок вроде
        if (visited[current_pos + j] == 0) {
            checker(current_pos + j)
        }
    }
    
}
*/

int main() {
    cin >> n;
    cin >> a;
    // vector<int> ops = {};
    
    vector<double> results(n + 1, 0);
    results[n] = 1;
    for (int i = n; i >= 0; i--) {
        for (int j = 1; j <= a; j++) {
            if (i - j >= 0) {
                results[i - j] += results[i];
                // cout << results[i - j] << "\n";
            }
        }
    }
    // long double final_r = 0;
    cout << fixed << results[0] << "\n";
    // cout << static_cast<string>(results[0]) << "\n";
    /*
    for (int i = 0; i < a; i++) {
        final_r += results[i];
    }
    cout << final_r << "\n";
    */

    /*
    vector<vector<long double>> results_two;
    results_two.resize(n + 1);
    for (auto& elem: results_two) {
        elem.resize(n + 1, 0);
    }
    results[n + 1]
    */
}
// 2 2
// 1 1
// 2


// 4 2 

// 1 1 1 1
//   1 1 1
//     1 1