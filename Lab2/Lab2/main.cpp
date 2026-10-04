#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
#include <sstream>
#include <numeric>
using namespace std;

static int nextIndex(const std::vector<int>& arr, int currentIndex, const bool reverse = false) {
    for (int j = currentIndex + 1; j < arr.size(); ++j) {
        if (reverse) {
            if (arr[j] > arr[currentIndex]) {
                currentIndex = j;
            }
        }
        else {
            if (arr[j] < arr[currentIndex]) {
                currentIndex = j;
            }
        }
    }
    return currentIndex;
}

vector<int> randomBag(const int min, const int max) {
    vector<int> bag(max - min + 1);
    iota(bag.begin(), bag.end(), min);

    static mt19937 gen(random_device{}());
    ranges::shuffle(bag.begin(), bag.end(), gen);

    return bag;
}

vector<string> randomNumbersBag(const int size) {
    vector<string> bag(size);
    static mt19937 gen(random_device{}());
    uniform_int_distribution dist(0, 9);
    for (int i = 0; i < size; ++i) {
        stringstream ss;
        ss << dist(gen) << dist(gen) << "-" << dist(gen) << dist(gen) << "-" << dist(gen) << dist(gen);
        bag[i] = ss.str();
    }
    return bag;
}

void selectionSort(std::vector<int>& arr, const bool reverse = false) {
    for (int i = 0; i < arr.size() - 1; ++i) {
        std::swap(arr[i], arr[nextIndex(arr, i, reverse)]);
    }
}

void numbersSelectionSort(vector<string>& arr, const bool reverse = false) {
    vector<int> bag(arr.size());
    for (int i = 0; i < arr.size(); ++i) {
        string s = arr[i];
        erase(s, '-');
        bag[i] = stoi(s);
    }
    selectionSort(bag, reverse);

    for (int i = 0; i < bag.size(); ++i) {
        stringstream ss;

        ss << setfill('0') << setw(6) << bag[i];

        string s = ss.str();
        s.insert(2, "-");
        s.insert(5, "-");

        arr[i] = s;
    }
}

int main() {
    /*
     * 1) Написать программу, сортирующую по возрастанию одномерный массив случайных целых чисел,
     * находящихся в интервале {2,103}. Использовать сортировку выбором.
     */
    vector<int> bag1 = randomBag(2, 103);
    // printVec(bag1);
    selectionSort(bag1);
    // printVec(bag1);

    /*
    * 2) Написать программу, сортирующую по убыванию одномерный массив случайных целых чисел,
    * находящихся в интервале {0,100}.
    */
    vector<int> bag2 = randomBag(2, 103);
    // printVec(bag1);
    selectionSort(bag2, true);
    // printVec(bag2);

    /*
    * 3) Написать программу, сортирующую список телефонов по возрастанию и использующую  сортировку выбором.
    * Телефон задан в виде строки. Например, 23-45-67.
    */
    vector<string> bag3 = randomNumbersBag(3);
    // printVec(bag3);
    numbersSelectionSort(bag3);
     //printVec(bag3);
    return 0;
}
