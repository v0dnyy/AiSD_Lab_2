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
bool Is_Sorted(vector<int>& data) {
    int check = 0;
    for (size_t i = 0; i < data.size()-1; ++i) {
        if (data[i] <= data[i + 1]) ++check;
    }
   return check == (data.size() - 1) ? 1 : 0;
}
vector<int> Merge(vector<int>& leftpod, vector<int>& rightpod, stats& stat)
{
	vector<int> respod(leftpod.size() + rightpod.size());
	size_t i = 0;
	size_t j = 0;
	size_t k = 0;
	while (k != leftpod.size() + rightpod.size())
	{
		if (i == leftpod.size()){
			respod[k] = rightpod[j];
			j++;
			k++;
			stat.copy_count++;
			continue;
		}
		if (j == rightpod.size()){
			respod[k] = leftpod[i];
			i++;
			k++;
			stat.copy_count++;
			continue;
		}
		if (leftpod[i] < rightpod[j]){
			respod[k] = leftpod[i];
			i++;
		}
		else{
			respod[k] = rightpod[j];
			j++;

		}
		stat.copy_count++;
		stat.comparison_count++;
		k++;
	}
	return respod;
}

stats Two_Way_Merge_Sort(vector<int>& data, stats result)
{
    if (data.size() == 1) return result;
    if (Is_Sorted(data) == true) return result;
    stats stat;
    while (Is_Sorted(data) != true) {
        vector<int> res(data.size());
        int l = 0;
        int l_new = 0;
        int r = data.size() - 1;
        int r_new = data.size() - 1;
        bool count = true;
        while (l_new < r_new) {
            vector<int> leftpod;
            vector<int> rightpod;
            while (l < r && data[l] <= data[l + 1] && (l < data.size())) {
                leftpod.push_back(data[l]);
                ++l;
                stat.comparison_count++;
            }
            leftpod.push_back(data[l]);
            while (r > l && data[r] <= data[r - 1] && (r > 0)) {
                rightpod.push_back(data[r]);
                --r;
                stat.comparison_count++;
            }
            rightpod.push_back(data[r]);
            vector<int> respod = Merge(leftpod, rightpod, stat);
            if (count) {
                if (respod.size() < res.size()) {
                    for (int i = 0; i <= respod.size()-1; i++) {
                        res[l_new] = respod[i];
                        l_new++;
                        stat.copy_count++;
                    }
                }
                else {
                    for (int i = 0; i <= res.size()-1; i++) {
                        res[l_new] = respod[i];
                        l_new++;
                        stat.copy_count++;
                    }
                }
                count = false;
            }
            else {
                if (respod.size() < res.size()-1) {
                    for (int i = 0; i < respod.size()-1; ++i) {
                        res[r_new] = respod[i];
                        r_new--;
                        stat.copy_count++;
                    }
                }
                else {
                    for (int i = 0; i < res.size(); ++i) {
                        res[r_new] = respod[i];
                        r_new--;
                        stat.copy_count++;
                    }
                }
                count = true;
            }
            if(l<data.size()) l++;
            if(r>0) r--;
        }
        if (((data.size()-1)%2==0) && (r==l)) res[r] = data[data.size()-r];
        data = res;
        stat.copy_count += res.size();
    }
    return stat;
}
int main() {
    srand(time(NULL));
    stats result;
    vector <int> v3(10);
    for (auto i = v3.begin(); i != v3.end(); ++i) {
        *i = rand() % 10-5;
    }
    vector <int> v2(10);
    vector <int> v1(10);
    for (auto i = v3.begin(); i != v3.end(); ++i){
        *i = rand() % 10;
    }
    for (auto i = v2.begin(); i != v2.end(); ++i) {
        *i = rand() % 10;
    }
    for (auto i = v1.begin(); i != v1.end(); ++i) {
        *i = rand() % 10;
    }
    for (size_t i = 0; i < v1.size(); ++i) {
        cout << "[" << v1[i] << "] ";
    }
    cout << "\n";
    result = bubble_sort(v1);
    for (size_t i = 0; i < v1.size(); ++i) {
        cout << "[" << v1[i] << "] ";
    }
    cout << "\n";
    cout << "Comparison count: " << result.comparison_count << endl;
    cout << "Copy count: " << result.copy_count << endl;
    cout << "\n";

    for (size_t i = 0; i < v2.size(); ++i) {
        cout << "[" << v2[i] << "] ";
    }
    result=cocktail_sort(v2);
    cout << "\n";
    for (size_t i = 0; i < v2.size(); ++i) {
        cout << "[" << v2[i] << "] ";
    }
    cout << "\n";
    cout << "Comparison count: " << result.comparison_count << endl;
    cout << "Copy count: " << result.copy_count << endl;
    cout << "\n";

    for (size_t i = 0; i < v3.size(); ++i) {
        cout << "[" << v3[i] << "] ";
    }
    result = Two_Way_Merge_Sort(v3, result);
    cout << "\n";
    for (size_t i = 0; i < v3.size(); ++i) {
        cout << "[" << v3[i] << "] ";
    }
    cout << "\n";
    cout << "Comparison count: " << result.comparison_count << endl;
    cout << "Copy count: " << result.copy_count << endl;
    cout << "\n";
    return 0;
}