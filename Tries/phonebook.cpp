/*
 * Author: Ashwin Goel
 */

// Phone Directory using Trie

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

  /* Returns a pointer to the Trienode representing the last letter of the word.
   */

  vector<string> autosuggest(string prefix) {
    // First use search to iterate to the final node of prefix
    // Then use DFS to build all the other strings
    // Use DFS to display all the
    vector<string> result;
    Trienode *root = search(prefix);
    if (root != nullptr) {
      autosuggestDFS(prefix, root, result);
    }
    return result;
  }

private:
  Trienode *search(string word) {
    Trienode *itr = root;
    int ind;
    for (int i = 0; i < word.length(); i++) {
      ind = word[i] - 'a';
      if (itr->node[ind] == nullptr) {
        return nullptr;
      }
      itr = itr->node[ind];
    }
    return itr;
  }

  void autosuggestDFS(string pre, Trienode *root, vector<string> &result) {

    if (root->isWord) {
      result.push_back(pre);
    }
    for (int i = 0; i < 26; i++) {

      string s;
      if (root->node[i] != nullptr) {
        s = (char)97 + i;
        autosuggestDFS(pre + s, root->node[i], result);
      }
    }
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

  vector<string> suggestion;
  suggestion = T.autosuggest("as");

  if (suggestion.size() != 0) {

    for (auto str : suggestion) {
      cout << str << endl;
    }
  } else {
    cout << "No strings found!!";
  }

  return 0;
}