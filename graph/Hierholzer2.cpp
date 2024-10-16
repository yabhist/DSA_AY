#include <bits/stdc++.h>
using namespace std;

void printCircuit(vector<int> adj[], int n){
	if (n == 0)
		return; 

	vector<int> curr_path;
	curr_path.push_back(0);

	vector<int> circuit;

	while (curr_path.size() > 0) {
		int curr_v = curr_path[curr_path.size() - 1];

		if (adj[curr_v].size() > 0) {
			int next_v = adj[curr_v].back();
			adj[curr_v].pop_back();

			curr_path.push_back(next_v);
		}

		else {
			circuit.push_back(curr_path.back());
			curr_path.pop_back();
		}
	}

	for (int i = circuit.size() - 1; i >= 0; i--) {
		cout << circuit[i];
		if (i)
			cout << " -> ";
	}
}

int main()
{
	int n1 = 3;
	vector<int> adj1[n1];

	adj1[0].push_back(1);
	adj1[1].push_back(2);
	adj1[2].push_back(0);
	printCircuit(adj1, n1);
	cout << endl;

	
	int n2 = 7;
	vector<int> adj2[n2];

	adj2[0].push_back(1);
	adj2[0].push_back(6);
	adj2[1].push_back(2);
	adj2[2].push_back(0);
	adj2[2].push_back(3);
	adj2[3].push_back(4);
	adj2[4].push_back(2);
	adj2[4].push_back(5);
	adj2[5].push_back(0);
	adj2[6].push_back(4);
	printCircuit(adj2, n2);
	cout << endl;
	return 0;
}

