#include <bits/stdc++.h>

using namespace std;

int solveProblem (map<int, list<int> > & graph, int & user) {
	queue<int> myq;
	set<int> visited;
	myq.push(user);
	while (!myq.empty()) {
		int annen = myq.front(); myq.pop();
		if (visited.find(annen) != visited.end()) continue;
		visited.insert(annen);
		for (auto const & i : graph[annen]) {
			myq.push(i);
		}
	}
	int size = visited.size();
	visited.clear();
	
	return size;
}



int main (void) {


	ios_base::sync_with_stdio (false);
	cin.tie (NULL);
	
	map<int, list<int> > graph;
	int numUsers;
	int numGroups;
	int subUsers;
	int id;
	vector <int> ids;

	cin >> numUsers >> numGroups;

	for (int i = 0;i < numGroups; i++) {
		cin >> subUsers;
		for (int k = 0; k < subUsers; k++) {
			cin >> id;
			ids.push_back(id);
		}

		for (int k = 0; k < subUsers; k++) {
			for (int z = 0; z < subUsers; z++) {
				if ( k == z ) continue;
				graph[ids[k]].push_back(ids[z]);
			}
		}
		ids.clear();
	}

	int pass;
	for (int i = 0; i < numUsers; i++) {
		pass = i+1;
		cout << solveProblem (graph, pass);
		if (i != numUsers-1) cout << " ";
	}
	cout << endl;

	return 0;
}
