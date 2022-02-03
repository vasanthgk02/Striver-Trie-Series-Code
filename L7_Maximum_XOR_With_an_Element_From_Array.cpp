#include<bits/stdc++.h>
using namespace std;

struct Node{
	Node* links[2];
	bool flag = false;
	bool containsKey(int b){
		return links[b];
	}
	void putKey(int b, Node* temp){
		links[b] = temp;
	}
	Node* getKey(int b){
		return links[b];
	}
	void setEnd(){
		flag = true;
	}
};

class Trie{
	private:
	Node* root;
	public:
	Trie(){
		root = new Node;
	}
	void insert(int n){
		Node* temp = root;
		for(int i = 31; i >= 0; i--){
			int mask = (n >> i) & 1;
			if(!temp -> links[mask]){
				temp -> putKey(mask, new Node);
			}
			temp = temp -> getKey(mask);
		}
		temp -> setEnd();
	}
	
	int getXor(int n){
		int ans = 0;
		Node* temp = root;
		for(int i = 31; i >= 0; i--){
			int mask = (n >> i) & 1;
			if(temp -> containsKey(1 - mask)){
				temp = temp -> getKey(1 - mask);
				ans = ans | (1 << i);
			}else{
				temp = temp -> getKey(mask);
			}
		}
		return ans;
	}
	
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	sort(arr.begin(), arr.end());
	vector<pair<int, pair<int, int>>> oQ;
	int q = queries.size();
	for(int i = 0; i < q; i++){
		oQ.push_back(make_pair(queries[i][1], make_pair(queries[i][0], i)));
	}
	sort(oQ.begin(), oQ.end());
	vector<int> res(q, 0);
	int n = arr.size();
	Trie trie;
	int ind = 0;
	for(int i = 0; i < q; i++){
		int xi = oQ[i].second.first;
		int ai = oQ[i].first;
		int qInd = oQ[i].second.second;
		while(ind < n && arr[ind] <= ai){
			trie.insert(arr[ind]);
			ind++;
		}
		if(ind == 0){
			res[qInd] = -1;
		}else{
			res[qInd] = trie.getXor(xi);
		}
	}
	return res;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		vector<int> arr(n, 0);
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		vector<vector<int>> queries;
		for(int i = 0; i < m; i++){
			int x, a;
			cin >> x >> a;
			vector<int> temp;
			temp.push_back(x);
			temp.push_back(a);
			queries.push_back(temp);
		}
		vector<int> res = maxXorQueries(arr, queries);
		for(int i = 0; i < res.size(); i++){
			cout << res[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}

