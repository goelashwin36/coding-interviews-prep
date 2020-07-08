/*
 * Author: Ashwin Goel
 */

// Tries
// https://leetcode.com/problems/implement-trie-prefix-tree

#include <bits/stdc++.h>
using namespace std;

struct Trienode {
  Trienode *node[26] = {nullptr};
  bool isWord;
  Trienode() { isWord = false; }
};

class Trie {
  Trienode *root;

public:
  /** Initialize your data structure here. */
  Trie() { root = new Trienode(); }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Trienode *itr = root;
    int ind;
    for (int i = 0; i < word.length(); i++) {
      ind = word[i] - 'a';
      if (itr->node[ind] == nullptr) {
        itr->node[ind] = new Trienode();
        ;
      }
      itr = itr->node[ind];
    }
    itr->isWord = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Trienode *itr = root;
    int ind;
    for (int i = 0; i < word.length(); i++) {
      ind = word[i] - 'a';
      if (itr->node[ind] == nullptr) {
        return false;
      }
      itr = itr->node[ind];
    }
    return itr->isWord;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    Trienode *itr = root;
    int ind;
    for (int i = 0; i < prefix.length(); i++) {
      ind = prefix[i] - 'a';
      if (itr->node[ind] == nullptr) {
        return false;
      }
      itr = itr->node[ind];
    }
    return true;
  }

  bool isEmpty() {
    for (int i = 0; i < 26; i++) {
      if (root->node[i] != nullptr) {
        return false;
      }
    }
    return true;
  }
};
int main() {

  Trie T;
  T.insert("ashwin");
  T.insert("ash");
  T.insert("amitesh");
  T.insert("ashima");
  T.insert("akansha");
  T.insert("tanya");
  T.insert("aniket");
  T.insert("debprotim");
  T.insert("shaswat");
  T.insert("sheena");

  cout<<T.search("ashw");
return 0;
}