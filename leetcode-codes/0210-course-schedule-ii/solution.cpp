class Solution {
public:
	vector<int> v[100001];
	vector<int> indegree;
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		indegree = vector<int>(numCourses);
		vector<int> res;
		queue<int> q;
		for (vector<int> t : prerequisites) {
			v[t[1]].push_back(t[0]);
			indegree[t[0]]++;
		}
		for (int i = 0; i < numCourses; i++)
			if (indegree[i] == 0)q.push(i);
		
		while (!q.empty()) {
			int qsize = q.size();
			while (qsize--) {
				int cur = q.front();
				res.push_back(cur);
				q.pop();
				for (int next : v[cur]) {
					indegree[next]--;
					if (indegree[next] == 0)
						q.push(next);
				}
			}
		}
		for (int i = 0; i < numCourses; i++)
			if (indegree[i])return { };
		return res;
	}

};
