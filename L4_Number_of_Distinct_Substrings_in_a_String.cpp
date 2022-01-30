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
public:
	Node* root = new Node;
	int insert(string word){
		int count = 0;
		for(int i = 0; i < word.length(); i++){
    		Node* temp = root;
			for(int j = i; j < word.length(); j++){
				if(!temp -> containsKey(word[j])){
				    count++;
					temp -> putKey(word[j], new Node);
				}
				temp = temp -> getKey(word[j]);
			}
		}	
		return count + 1;
	}
};

int main(){
	cout << "WELCOME TO THE PROGRAM";
	while(1){		
		Trie t;
		cout <<"\n1.Insert\n2.Exit\nChoice : ";
		int choice;
		cin >> choice;
		if(choice == 2){
			cout << "\nThanks for choosing the program!";
			return 0;
		}
		string input;
		cout << "\nEnter the string : ";
		cin >> input;
		cout << "\nThe number of distinct substrings is : " << t.insert(input);
	}
	return 0;
}