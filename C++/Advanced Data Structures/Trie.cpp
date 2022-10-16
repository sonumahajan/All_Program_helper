#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return 0; }();

struct TrieNode {
	TrieNode *child[26] = {nullptr};
	bool isWord = false;
};
TrieNode *root = nullptr;
void insert(string word) {
	TrieNode *curr = root;
	for(int i = 0; i < word.length(); i++) {
		char ch = word[i] - 'a';
		if(!curr->child[ch])
			curr->child[ch] = new TrieNode();
		curr = curr->child[ch];
	}
	curr->isWord = true;
}
bool search(string word) {
	TrieNode *curr = root;
	for(int i = 0; i < word.length(); i++) {
		char ch = word[i] - 'a';
		if(curr->child[ch])
			curr = curr->child[ch];
		else return false;
	}
	return curr->isWord;
}

int main() {
	root = new TrieNode();

	// For Testing Purpose.
	insert("banana");
	insert("banaaana");

	cout<< search("banaana")<< endl;
	cout<< search("bana")<< endl;
	cout<< search("banana")<< endl;

	return 0;
}