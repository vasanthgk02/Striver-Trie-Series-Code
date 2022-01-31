
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

int main(){
	cout << "WELCOME TO MY PROGRAM\n";
	int ans = 0, input;
	vector<int> v1, v2;
	Trie t1;
	while(1){
	    cout <<"\n1.Insert elements into array1\n2.Insert elements into array2\n3.Compute Max X-OR\n4.Exit\n";
	    int option;
	    cin >> option;
	    if(option == 4){
	        cout << "\nThank you!";
	        break;
	    }
	    switch(option){
	        case 1:
	        cout << "\nEnter the elements of array1 (NOTE: Enter -1 to exit) : ";
	        while(1){
	            int t;
	            cin >> t;
	            if(t == -1){
	                break;
	            }
	            v1.push_back(t);
	            t1.insert(t);
	        }
	        break;
	        case 2:
	        cout << "\nEnter the elements of array2 (NOTE: Enter -1 to exit) : ";
	        while(1){
	            int t;
	            cin >> t;
	            if(t == -1){
	                break;
	            }
	            v2.push_back(t);
        		int temp_max = t1.getXor(t);
        		ans = max(ans, temp_max);
	        }
	        break;
	        case 3:
        	cout << "The max X-OR of two given elements is : " << ans;
        	break;
	        default:
	        break;
	    }
	}	return 0;
}

