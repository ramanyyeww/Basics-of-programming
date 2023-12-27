#include <iostream>
#include <set>
#include <string>
using namespace std;

class MedianFinder {
    multiset<int> numbers; 

public:
    void addNum(int num) {
        numbers.insert(num); 
    }

    double findMedian() {
        int n = numbers.size();
        auto mid = next(numbers.begin(), n / 2); 

        if (n % 2 == 0) {
            auto midPrev = prev(mid); 
            return (*mid + *midPrev) / 2.0; 
        }
        else {
            return *mid; 
        }
    }
};

int main() {
    string choice;
    do {
        MedianFinder mf; 
        int arr[] = { 1, 2, 3, 4, 5 }; 
        int n = sizeof(arr) / sizeof(arr[0]); 

        for (int i = 0; i < n; i++) {
            mf.addNum(arr[i]); 
        }

        cout << "Median is: " << mf.findMedian() << endl; 
        cout << "Run again? (y/n): ";
        cin >> choice;
    } while (choice == "y" || choice == "Y");
    return 0;
}
