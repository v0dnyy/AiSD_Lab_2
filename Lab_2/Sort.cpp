#include<iostream>
#include<vector>
using namespace std;
struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
};
stats bubble_sort(vector<int>& data) {
    stats result;
    for (size_t i = 0; i < data.size()-1; ++i) {
        for (size_t j = 0; j < data.size() - i - 1; ++j) {
            result.comparison_count++;
            if (data[j] > data[j + 1]) {
                int value = data[j + 1];
                data[j+1] = data[j];
                data[j] = value;
                result.copy_count++;
            }
        }
        result.copy_count++;
    }
    return result;
};
stats cocktail_sort(vector<int>& data){
    stats result;
    bool swapped = true;
    int start = 0;
    int end = data.size() - 1;

    while (swapped)
    {
        swapped = false;
        for (int i = start; i < end; ++i)
        {
            result.comparison_count++;
            if (data[i] > data[i + 1]) {
                int tmp=data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
                ++result.copy_count;
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i)
        {
            result.comparison_count++;
            if (data[i] > data[i + 1]) {
                int tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
                ++result.copy_count;;
                swapped = true;
            }
        }
        ++start;
    }
    return result;
}
int main() {
    vector<int> v1(5);
    for (size_t i = 0; i < v1.size(); ++i) {
        cin >> v1[i];
    }
    for (size_t i = 0; i < v1.size(); ++i) {
        cout << "[" << v1[i] << "] ";
    }
    cout << "\n";
    bubble_sort(v1);
    cocktail_sort(v1);
    for (size_t i = 0; i < v1.size(); ++i) {
        cout << "[" << v1[i] << "] ";
    }
    cout << "\n";
    return 0;
}