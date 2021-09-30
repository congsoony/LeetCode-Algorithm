#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int check[1001];
	int key[1001];
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		memset(check, 0, sizeof(check));
		memset(key, 0, sizeof(key));
		key[0] = true;
		dfs(rooms);
		for (int i = 0; i < rooms.size(); i++)
			if (check[i] == false)return false;
		return true;
	}
	void dfs(vector<vector<int>>& rooms,int idx = 0) {
		check[idx] = true;
		for (int i = 0; i < rooms[idx].size(); i++) {
			key[rooms[idx][i]] = true;
		}
		for (int i = 0; i < rooms.size(); i++) {
			if (key[i] && check[i] == false) {
				dfs(rooms, i);
			}
		}
	}
};
