#include<bits/stdc++.h>
using namespace std;

struct Node{
	Node* links[26];
	bool flag = false;
	bool containsKey(char ch){
		return links[ch - 'a'];		
	}
	void putKey(char ch, Node* temp){
		links[ch - 'a'] = temp;
	}
	Node* getKey(char ch){
		return links[ch - 'a'];
	}
	void setEnd(){
		flag = true;
	}
	bool isEnd(){
		return flag;
	}
};

class Trie{
private:
	Node* root;
public:
	Trie(){
		root = new Node;
	}
	void insert(string word){
		Node* temp = root;
		for(int i = 0; i < word.length(); i++){
			if(!temp -> containsKey(word[i])){
				temp -> putKey(word[i], new Node);
			}
			temp = temp -> getKey(word[i]);
		}
		temp -> setEnd();
	}
	bool checkIfPrefixExist(string word){
		Node* temp = root;
		for(int i = 0; i < word.length(); i++){
			if(temp -> containsKey(word[i])){
				temp = temp -> getKey(word[i]);
				if(temp -> isEnd() == false){
					return false;
				}
			}
		}
		return true;
	}
};

string completeString(int n, vector<string> &a){
		Trie trie;
		for(auto &it : a){
			trie.insert(it);
		}
		string longest = "";
		for(auto &it : a){
			if(trie.checkIfPrefixExist(it)){
				if(it.length() > longest.length()){
					longest = it;
				}else if(it.length() == longest.length() && it < longest){
					longest = it;
				}
			}
		}
		if(longest == ""){
			return "None";
		}
		return longest;
	}

int main(){
	cout << "\nWELCOME TO TRIE PROGRAM";
	cout << "\nENTER THE NUMBER OF STRINGS : ";
	int n;
	cin >> n;
	vector<string> v(n);
	cout << "\nENTER THE STRING : \n";
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	string res = completeString(n, v);
	cout << "\nTHE LONGEST COMPLETE STRINGS IS : " << res;
	return 0;
}