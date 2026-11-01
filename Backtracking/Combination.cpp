#include <iostream>
using namespace std;

class Combination {
    int arr[5] = {1, 2, 3, 4, 5};
    int sums[3] = {0};
    int N = 3;
    int S = 9;

    void sumFunc(int index, int sum, int i) {   // i stores index of sums array                                            
        if(i == N) {                           // index shows the index of arr[5]
            if(sum == S) {
                for(int j = 0; j < N; j++) {
                    cout << sums[j] << " ";
                }
                cout << endl;
            }
            return;
        }

        for(int x = index; x < 5; x++) {

            if(sum + arr[x] > S)
                break;

            sums[i] = arr[x];

            sumFunc(x + 1, sum + arr[x], i + 1);

            sums[i] = 0;
        }
    }

public:
    void generate() {
        sumFunc(0, 0, 0);
    }
};

int main() {
    Combination c;
    c.generate();

    return 0;
}