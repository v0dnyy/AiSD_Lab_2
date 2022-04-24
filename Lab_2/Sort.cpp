#include<iostream>
#include<vector>
using namespace std;
struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
};
stats bubble_sort(std::vector<int>& data) {
    stats result;
    for (size_t i = 0; i < data.size() - 1; ++i) {
        for (size_t j = 0; j < data.size() - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                result.comparison_count++;
                int value = data[j + 1];
                data[j + 1] = data[j];
                data[j] = value;
                result.copy_count++;
            }
        }
        result.copy_count++;
    }
    return result;
};
