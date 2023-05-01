// https://www.acmicpc.net/problem/2615
#include <bits/stdc++.h>

using namespace std;

int arr[21][21];
bool check[21][21];

int dir[3][2] = { {1,0},{0,1},{1,1} };

bool DFS(int y, int x, int depth, int k) {
	check[y][x] = true;

	int tempY = y + dir[k][0];
	int tempX = x + dir[k][1];

	if (tempY <= 19 && tempX <= 19) {
		if (!check[tempY][tempX] && arr[tempY][tempX] == arr[y][x]) {
			return DFS(tempY, tempX, depth + 1, k);
		}
		else if (arr[tempY][tempX] != arr[y][x] && depth == 4) {
			return true;
		}
	}
	return false;
}

int main(void) {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (!check[i][j] && arr[i][j] != 0) {
				if (DFS(i, j, 0, 0)) {
					cout << arr[i][j] << '\n';
					cout << i + 1 << ' ' << j + 1;
					return 0;
				}
				else if (DFS(i, j, 0, 1)) {
					cout << arr[i][j] << '\n';
					cout << i + 1 << ' ' << j + 1;
					return 0;
				}
				else if (DFS(i, j, 0, 2)) {
					cout << arr[i][j] << '\n';
					cout << i + 1 << ' ' << j + 1;
					return 0;
				}
			}
		}
	}

	cout << 0;

	return 0;
}