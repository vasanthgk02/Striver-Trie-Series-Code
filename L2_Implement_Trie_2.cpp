
#include<bits/stdc++.h>
using namespace std;

struct Node{
	Node* links[26];
	bool flag = false;
	int cntPrefix = 0;
	int cntEndWith = 0;
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
	void increaseEnd(){
		cntEndWith++;
	}
	void increasePrefix(){
		cntPrefix++;
	}
	void deleteEnd(){
		cntEndWith--;
	}
	void deletePrefix(){
		cntPrefix--;
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
			temp -> increasePrefix();
		}
		temp -> increaseEnd();
	}
	void erase(string word){
		Node* temp = root, *prev = root;
		for(int i = 0; i < word.length(); i++){
			if(temp -> containsKey(word[i])){
				temp = temp -> getKey(word[i]);
			}else{
				return;
			}
		}
		temp -> deleteEnd();
	}
	
	int countWordEqualTo(string word){
		Node* temp = root;
		for(int i = 0; i < word.length(); i++){
			if(!temp -> containsKey(word[i])){
				return 0;
			}
			temp = temp -> getKey(word[i]);
		}
		return temp -> cntEndWith;
	}
	
	int countWordStartWith(string word){
		Node* temp = root;
		for(int i = 0; i < word.length(); i++){
			if(temp -> containsKey(word[i])){
				temp = temp -> getKey(word[i]);
			}else{
				return 0;
			}
		}
		return temp -> cntPrefix;		
	}
};

int main(){
	cout << "\nWELCOME TO THE PROGRAM OF TRIE";
	Trie obj1;
	while(1){
		int choice;
		cout << "\n1.INSERT\n2.ERASE\n3.COUNT WORDS START WITH\n4.COUNT WORDS EQUAL TO\n5.EXIT";
		cout << "\nENTER YOUR CHOICE : ";
		cin >> choice;
		if(choice == 5){
			cout << "\n5THANKS FOR USING THE PROGRAM!!!";
		}
		cout << "\nENTER THE STRING : ";
		string input;
		cin >> input;
		int count;
		switch(choice){
			case 1:
			obj1.insert(input);
			cout << "\nWORD HAS SUCCESSFULLY INSERTED";
			break;
			case 2:
			obj1.erase(input);
			cout << "\nWORD HAS SUCCESSFULLY DELETED";
			break;
			case 3:
			count = obj1.countWordStartWith(input);
			cout << "\nWORD OCCURRENCE : " << count;
			break;
			case 4:
			count = obj1.countWordEqualTo(input);
			cout << "\nWORD OCCURRENCE : " << count;
			break;
			default:
			cout << "\nENTER A VALID NUMBER!!!";
			break;
		}
	}
	return 0;
}