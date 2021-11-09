#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &li, int idx, int n) {
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;
    int l_idx = idx;
    if(left < n && li[left] > li[l_idx])
        l_idx = left;
    if(right < n && li[right] > li[l_idx])
        l_idx = right;
    if(l_idx != idx) {
        int temp = li[idx];
        li[idx] = li[l_idx];
        li[l_idx] = temp;
        heapify(li, l_idx, n);
    }
    return;
}

void heapsort(vector<int> &li) {
    int n = li.size();
    for(int i = n/2 - 1; i > -1; i--) {
        heapify(li, i, n);
    }
    for(int i = n-1; i > 0; i--) {
        int temp = li[0];
        li[0] = li[i];
        li[i] = temp;
        heapify(li, 0, i);
    }
}

int main() {
    int cnt;
    cin >> cnt;

    for(int i = 0; i < cnt; i++) {
        int num;
        long long sum;
        cin >> num;
        vector<int> minh;
        vector<int> maxh;
        for (int j = 0; j < num; j++) {
            int arr_num;
            cin >> arr_num;
            int median;

            if(minh.size() == 0 && maxh.size() ==0) {
                maxh.push_back(arr_num);
                median = maxh[0];
            }
            else if(maxh.size() != 0) {
                if(arr_num > maxh[maxh.size() - 1]) {
                    minh.push_back(arr_num);
                    if(arr_num < minh[0])
                        heapsort(minh);
                }
                else {
                    maxh.push_back(arr_num);
                    if(arr_num < maxh[maxh.size() - 2])
                        heapsort(maxh);
                }

                if(minh.size() == maxh.size()) {
                    median = (maxh[maxh.size() - 1] + minh[0]) / 2;
                }
                else if(minh.size() + 1 == maxh.size()) {
                    median = maxh[maxh.size() - 1];
                }
                else if(minh.size() == maxh.size() + 1) {
                    median = minh[0];
                }
                else if(minh.size() == maxh.size() + 2) {
                    maxh.push_back(minh[0]);
                    if(arr_num < maxh[maxh.size() - 2])
                        heapsort(maxh);
                    // heapsort(maxh);
                    minh.erase(minh.begin());
                    median = (maxh[maxh.size() - 1] + minh[0]) / 2;
                }
                else if(minh.size() + 2 == maxh.size()) {
                    minh.push_back(maxh[maxh.size() - 1]);
                    if(arr_num < minh[0])
                        heapsort(minh);
                    // heapsort(minh);
                    maxh.erase(maxh.end() -1);
                    median = (maxh[maxh.size() - 1] + minh[0]) / 2;
                }
                
            }

            // for(int j = 0; j< minh.size(); j++) cout << minh[j] << " ";
            // cout << "minheap" << endl;
            // for(int j = 0; j< maxh.size(); j++) cout << maxh[j] << " ";
            // cout << "maxheap" << endl;
            // cout << median << " median"<< endl;
            // cout << "===========" << endl;
            sum += median;
        }
        cout << sum % 10 << endl;
    }
    return 0;
}