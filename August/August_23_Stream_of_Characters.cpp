#include <bits/stdc++.h>
using namespace std;
struct Node {
   Node* child[26];
   bool isEnd;
   Node(){
      isEnd = false;
      for (int i = 0; i < 26; i++)
      child[i] = NULL;
   }
};

class StreamChecker {
   public:
   Node* head;
   vector<Node*> waitList;
   void insertNode(Node* head, string& s){
      Node* curr = head;
      for (int i = 0; i < s.size(); i++) {
         char x = s[i];
         if (!curr->child[x - 'a']) {
            curr->child[x - 'a'] = new Node();
         }
         curr = curr->child[x - 'a'];
      }
      curr->isEnd = true;
   }
   
   StreamChecker(vector<string>& words){
      head = new Node();
      for (int i = 0; i < words.size(); i++) {
         insertNode(head, words[i]);
      }
      Node* curr = head;
   }
   
   bool query(char x){
      vector<Node*> temp;
      if (head->child[x - 'a']) {
         waitList.push_back(head);
      }
      bool ret = false;
      for (int i = 0; i < waitList.size(); i++) {
         Node* curr = waitList[i];
         if (curr->child[x - 'a']) {
            curr = curr->child[x - 'a'];
            temp.push_back(curr);
            ret |= curr->isEnd;
         }
      }
      swap(temp, waitList);
      return ret;
   }
};
