#include<iostream>
using namespace std;
#include<string>

class book {
    int num;
    string* titles;

    public:
    book(int n) {
        num = n;
        titles = new string[num];
    }

    void storeTitles() {
        cout << "store titles one by one\n";
        for (int i=0; i<num; i++) {
            getline(cin >> ws, titles[i]); 
        }
    }

    book(const book& obj1) {
        num = obj1.num;
        titles = new string[num];
        for (int i=0; i<num; i++) {
            titles[i] = obj1.titles[i];
        }
    }

    book& operator=(const book& obj) {
        num = obj.num;
        for (int i=0; i<num; i++) {
            titles[i] = obj.titles[i];
        }
        return *this;
    }

    void sort() {
        int gap=num/2;
        while(gap>0) {
            for (int i=gap; i<num; i++) {
                string temp = titles[i];
                int j = i-gap;
                while(j>=0 && titles[j] > temp) {
                    titles[j+gap] = titles[j];
                    j-=gap;
                }
                titles[j+gap]=temp;
            }
            gap = gap/2;
        }
    }

    void printTitles() {
        for (int i=0; i<num; i++) {
            cout << titles[i] << " ";
        }
    }

    ~book() {
        delete[] titles;
    }
};

int main() {
    int num;
    cin >> num;
    book B1(num);
    B1.storeTitles();
    B1.sort();
    B1.printTitles();
}