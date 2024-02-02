#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;

        for (int currentSize = trunc(log10(low)) + 1; currentSize <= trunc(log10(high)) + 1; ++currentSize) {
            for (int firstDigit = 1; firstDigit <= 10 - currentSize; ++firstDigit) {
                int number = firstDigit;
                for (int digit = firstDigit + 1; digit < currentSize + firstDigit; ++digit) {
                    number *= 10;
                    number += digit;
                }
                if (number > high) {
                    break;
                }
                if (number >= low) {
                    res.push_back(number);
                }
            }
        }

        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    auto res1 = solution->sequentialDigits(100, 300);
    for (int i: res1)
        cout << i << ' ';

    cout << endl;

        auto res2 = solution->sequentialDigits(1000, 13000);
    for (int i: res2)
        cout << i << ' ';

    return 0;
}