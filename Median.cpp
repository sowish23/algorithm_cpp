#include <iostream>
#include <vector>
using namespace std;

int max_pop(vector<int> &heap) {
	int result = heap[1];

    int temp = heap[1];
    heap[1] = heap[heap.size() - 1];
    heap[heap.size() - 1] = temp;
    heap.erase(heap.end() - 1);

	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= heap.size() - 1) {
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}

	while (child <= heap.size() - 1 && heap[parent] < heap[child]) {
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;

		parent = child;
		child = child * 2;
		if (child + 1 <= heap.size() - 1) {
			child = (heap[child] > heap[child + 1]) ? child : child + 1;
		}
	}

	return result;
}

int min_pop(vector<int> &heap) {
	int result = heap[1];

    int temp = heap[1];
    heap[1] = heap[heap.size() - 1];
    heap[heap.size() - 1] = temp;
    heap.erase(heap.end() - 1);

	int parent = 1;
	int child = parent * 2;

	if (child + 1 <= heap.size() - 1) {
		child = (heap[child] < heap[child + 1]) ? child : child + 1;
	}

	while (child <= heap.size() - 1 && heap[parent] > heap[child]) {
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;

		parent = child;
		child = child * 2;
		if (child + 1 <= heap.size() - 1) {
			child = (heap[child] < heap[child + 1]) ? child : child + 1;
		}
	}

	return result;
}
void max_push(vector<int> &heap, int data) {
	heap.push_back(data);

	int child = heap.size() - 1;
	int parent = child / 2;
    while (child > 1 && heap[parent] < heap[child]) {
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        child = parent;
        parent = child / 2;
    }
}

void min_push(vector<int> &heap, int data) {
	heap.push_back(data);

	int child = heap.size() - 1;
	int parent = child / 2;
    while (child > 1 && heap[parent] > heap[child]) {
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        child = parent;
        parent = child / 2;
    }
}
int main() {
    int cnt;
    cin >> cnt;

    for(int i = 0; i < cnt; i++) {
        int num;
        long long sum = 0;
        cin >> num;
        vector<int> minh;
        vector<int> maxh;
        minh.push_back(0);
        maxh.push_back(0);
        for (int j = 0; j < num; j++) {
            int arr_num;
            cin >> arr_num;
            int median;

            if(minh.size() == 1 && maxh.size() ==1) {
                max_push(maxh, arr_num);
                median = maxh[1];
            }
            else if(maxh.size() != 1) {
                if(arr_num > maxh[1]) {
                    min_push(minh, arr_num);
                }
                else {
                    max_push(maxh, arr_num);
                }

                if(minh.size() == maxh.size()) {
                    median = (maxh[1] + minh[1]) / 2;
                }
                else if(minh.size() + 1 == maxh.size()) {
                    median = maxh[1];
                }
                else if(minh.size() == maxh.size() + 1) {
                    median = minh[1];
                }
                else if(minh.size() == maxh.size() + 2) {
                    int m = min_pop(minh);
                    max_push(maxh, m);
                    int max = maxh[1];
                    int min = minh[1];
                    median = (max + min) / 2;
                }
                else if(minh.size() + 2 == maxh.size()) {
                    int m = max_pop(maxh);
                    min_push(minh, m);
                    int max = maxh[1];
                    int min = minh[1];
                    median = (max + min) / 2;
                }
                
            }

            // for(int j = 1; j< minh.size(); j++) cout << minh[j] << " ";
            // cout << "minheap" << endl;
            // for(int j = 1; j< maxh.size(); j++) cout << maxh[j] << " ";
            // cout << "maxheap" << endl;
            // cout << median << " median"<< endl;
            // cout << "===========" << endl;
            sum += median;
        }
        cout << sum % 10 << endl;
    }
    return 0;
}