
#include<bits/stdc++.h>
using namespace std;

struct Node{
	Node* links[26];
	bool flag = false;
	bool containsKey(char ch){
		return links[ch - 'a'] != NULL;
	}
	void putKey(char ch, Node* node){
		links[ch - 'a'] = node;
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
		Node* node = root;
		for(int i = 0; i < word.length(); i++){
			if(!node -> containsKey(word[i])){
				node -> putKey(word[i], new Node());
			}
			node = node -> getKey(word[i]);
		}
		node -> setEnd();
	}
	bool search(string word){
		Node* node = root;
		for(int i = 0; i < word.length(); i++){
			if(!node -> containsKey(word[i])){
				return false;
			}
			node = node -> getKey(word[i]);
		}
		return node -> isEnd();
	}
	bool startsWith(string prefix){
		Node* node = root;
		for(int i = 0; i < prefix.length(); i++){
			if(!node -> containsKey(prefix[i]) || node -> isEnd()){
				return false;
			}
			node = node -> getKey(prefix[i]);
		}
		return true;
	}
};

int main(){
	cout << "WELCOME TO THE PROGRAM OF TRIE";
	Trie obj1;
	while(1){
		cout << "\n1.INPUT\n2.SEARCH\n3.PREFIX CHECK\n4.EXIT\nENTER YOUR CHOICE : ";
		int choice;
		cin >> choice;
		if(choice == 4){
			cout <<"\nTHANKS FOR USING THE PROGRAM!!!";
			break;
		}
		string input;
		cout << "\nENTER THE STRING : ";
		cin >> input;
		switch(choice){
			case 1:
			obj1.insert(input);
			break;
			case 2:
			if(obj1.search(input)){
				cout <<"\nMATCH FOUND!!!";
			}else{
				cout <<"\nMATCH NOT FOUND";
			}
			break;
			case 3:			
			if(obj1.startsWith(input)){
				cout <<"\nMATCH FOUND!!!";
			}else{
				cout <<"\nMATCH NOT FOUND";
			}
			break;
			default:
			cout <<"\nPLEASE ENTER A VALID NUMBER!";
			break;
		}
	}	
	return 0;
}

