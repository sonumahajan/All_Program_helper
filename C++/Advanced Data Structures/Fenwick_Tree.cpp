#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Zero Indexed Binary Indexed Tree/Fenwick Tree Implementation.

static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

class FWT {
	vector<int> tree, BIT;
	int size = 0;
public: 
	FWT(vector<int> &arr) {
		size = arr.size(); tree = arr;
		BIT.resize(size + 1);
		for(int i = 0; i < size; i++)
			update(i, arr[i]);
	}
	void update(int idx, int val) {
		idx += 1;
		while(idx <= size) {
			BIT[idx] += val;
			idx += (idx & (-idx));
		}
	}
	void newValue(int idx, int val) {
		update(idx, val - tree[idx]);
		tree[idx] = val;
	}
	int sum(int idx) {
		idx += 1;
		int total = 0;
		while(idx > 0) {
			total += BIT[idx];
			idx -= (idx & (-idx));
		}
		return total;
	}
	int rangeSum(int low, int high) {
		return sum(high) - sum(low - 1);
	}
};

int main() {
	// vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> arr{1, 3, 5};
	
	FWT fwt(arr);

	// cout<< fwt.sum(6)<< endl;
	// cout<< fwt.rangeSum(3, 6)<< endl;

	cout<< fwt.rangeSum(0, 2)<< endl;
	fwt.newValue(1, 2);
	cout<< fwt.rangeSum(0, 2)<< endl;

	return 0;
}