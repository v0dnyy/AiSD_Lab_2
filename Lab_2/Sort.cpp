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
stats Two_Way_Merge_Sort(std::vector<int>& data)
{
    stats stat;
    std::vector<int> res(data.size());
    int l = 0;
    int r = data.size() - 1;
    int count = 0;
    while (l != r) {
        ++count;
        while (l < r && data[l] < data[l + 1]) ++l;
        vector<int> leftpod(l + 1);
        while (r > l && data[r] < data[r - 1]) --r;
        vector<int> rightpod(data.size() - r);
        for (int i = 0; i <= l; ++i) {
            leftpod[i] = data[i];
        }
        for (int i = 0; i < data.size() - r; ++i) {
            rightpod[i] = data[data.size() - 1 - i];
        }
        vector<int> respod(leftpod.size() + rightpod.size());
        int j = 0;
        int k = 0;
        int c = 0;
        /*for (int i = 0; i < leftpod.size() + rightpod.size(); i++) {
            if (k < leftpod.size() && j < rightpod.size()) {
                if (leftpod[j] > rightpod[k]) {
                    respod[i]=rightpod[k];
                    k++;
                }
                else {
                    respod[i]=leftpod[j];
                    j++;
                }
            }
        }*/
        for (int i = 0; i <= respod.size() - 1; i++) {
            if (j <= leftpod.size() - 1 && leftpod[j] < rightpod[k]) {
                respod[i] = leftpod[j];
                ++j;
            }
            else {
                respod[i] = rightpod[k];
                if (k < rightpod.size() - 1) ++k;
            }
        }

        /*else {
            for (int i = j + k; i < leftpod.size(); i++) {
                if (leftpod[j] <= rightpod[k]) {
                    res[j + k] = leftpod[j];
                    ++j;
                }
                else {
                    res[j + k] = rightpod[k];
                    ++k;
                }
            }
            for (int i = leftpod.size(); i < respod.size(); i++) {
                respod[respod.size() - i] = rightpod[i];
            }
        }
    }*/
        if (count % 2 != 0) {
            for (int i = 0; i < respod.size(); ++i) {
                res[i] = respod[i];
            }
        }
        else {
            for (int i = res.size() - 1; i >= res.size() - respod.size(); --i) {
                res[i] = respod[res.size()-i];
            }
        }
        data = res;
    }
    return stat;
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
    result = Two_Way_Merge_Sort(v1);
    //cout << "Comparison count: "<<result.comparison_count<<endl;
    //cout << "Copy count: " << result.copy_count << endl;
    for (size_t i = 0; i < v1.size(); ++i) {
        cout << "[" << v1[i] << "] ";
    }
    cout << "\n";
    return 0;
}