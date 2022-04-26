#include<iostream>
#include<vector>
using namespace std;
struct stats {
    size_t comparison_count = 0;
    size_t copy_count = 0;
};
stats bubble_sort(std::vector<int>& data)
{
    stats stat;
    for (size_t i = 0; i < data.size() - 1; i++){
        for (size_t j = 0; j < data.size() - i - 1; j++){
            stat.comparison_count++;
            if (data[j + 1] < data[j]){
                int temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
                stat.copy_count++;
            }
        }
    }
    return stat;
}
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
    stats result;
    for (size_t i = 0; i < v1.size(); ++i) {
        cin >> v1[i];
    }
    for (size_t i = 0; i < v1.size(); ++i) {
        cout << "[" << v1[i] << "] ";
    }
    cout << "\n";
    //result=bubble_sort(v1);
    //result = cocktail_sort(v1);
    //cout << "Comparison count: "<<result.comparison_count<<endl;
    //cout << "Copy count: " << result.copy_count << endl;
    for (size_t i = 0; i < v1.size(); ++i) {
        cout << "[" << v1[i] << "] ";
    }
    cout << "\n";
    return 0;
}