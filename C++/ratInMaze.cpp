#include<bits/stdc++.h>
using namespace std;

bool ratInMaze(vector<vector<int>> &arr, int n, int x, int y, vector<vector<int>> &vis) {

	if (x >= n || y >= n || x < 0 || y < 0 || vis[x][y] == 1 || arr[x][y] == 0)
		return false;
	if (x == (n - 1) && y == (n - 1)) {
		return true;
	}
	vis[x][y] = 1;
	if (ratInMaze(arr, n, x + 1, y, vis))
		return true;
	if (ratInMaze(arr, n, x, y + 1, vis))
		return true;
	vis[x][y] = 0;
	return false;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 5;
	vector<vector<int>> arr;
	arr = {
		{1, 0, 1, 0, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 0, 1, 0},
		{1, 0, 0, 1, 1},
		{1, 1, 1, 0, 1}
	};
	vector<vector<int>> vis( n , vector<int> (n, 0));

	if (ratInMaze(arr, n, 0, 0, vis))
		cout << "Possible";
	else
		cout << "Not Possible";

	return 0;
}