#include<bits/stdc++.h>
using namespace std;
# define ll long long 
# define hashmap unordered_map<char,node*> 
class node{
public:
	char data;
	hashmap h;
	bool is_terminal;
	node(char d){
		data=d;
		is_terminal=false;
	}
};
class TRIE{
	node *root;
public:
	TRIE(){
		root=new node('\0');
	}
	void add_word(string word){
		node *temp=root;
		for(ll i=0;i<word.size();i++){
			if(temp->h.count(word[i])==0){
				node *child=new node(word[i]);
				temp->h[word[i]]=child;
				temp=child;
			}
			else{
				temp=temp->h[word[i]];
			}
		}
		temp->is_terminal=true;
	}
	bool search(string word){
		node *temp=root;
		for(ll i=0;i<word.size();i++){
			if(temp->h[word[i]]){
				temp=temp->h[word[i]];
			}
			else{
				return false;
			}
		}
		return true;
	}

};
int main(){
	TRIE t;
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		string s;
		cin>>s;
		t.add_word(s);
	}
	string p;
	cin>>p;
	if(t.search(p))
		cout<<"found"<<endl;
	else
		cout<<"not found"<<endl;
}
