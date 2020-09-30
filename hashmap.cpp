// 1.) Given an array find the count of even and odd count of numbers
// 	    Eg:- [1, 2, 5, 2, 1] even_count = 2 odd_count = 1

// 2.) Given two strings return true/false if there is any common char between two
// 		Eg:- s1 = Hello s2 = World  will return true as 'o' is present in both string 
// 		Eg:- s1 = Hello s2 = tab

// 3.) Given an array remove all the duplicates. return a vector 
//  eg:- [1, 2, 3, 2, 1] vector<int> removeDuplicate(int *arr) {}

#include <bits/stdc++.h>
using namespace std;

bool check(string s1, string s2) {
	map<char, bool> ourmap;
	for(int i = 0; i < s1.size(); i++) {
		if(ourmap[s1[i]] == 0) {
			ourmap[s1[i]] = true;
		} 
	}

	for(int i = 0; i < s2.size(); i++) {
		if(ourmap[s2[i]]) {
			return true;
		}
	}

	return false;
}

vector<int> removeDuplicate(int *arr, int n) {
	map<int, bool> ourmap;
	vector<int> ans;
	for(int i = 0; i < n; i++) {
		if(ourmap[arr[i]] == 0) {
			ourmap[arr[i]] = 1;
			ans.push_back(arr[i]);
		}
	}
	return ans;
}

int main() {

	// Question 1

	// int arr[] = {1, 2, 5, 1, 1};
	// int even_count = 0, odd_count = 0;
	// map<int, int> ourmap;
	// for(int i = 0; i < 5; i++) {
	// 	if(ourmap[arr[i]] == 0) {
	// 		ourmap[arr[i]] = 1;
	// 		continue;
	// 	}
	// 	ourmap[arr[i]]++;
	// }

	// map<int, int>::iterator it = ourmap.begin();
	// while(it != ourmap.end()) {
	// 	if(it->second % 2 == 0) {
	// 		even_count++;
	// 	} else {
	// 		odd_count++;
	// 	}
	// 	it++;
	// }
	// cout << "Even Count: " << even_count << endl;
	// cout << "Odd Count: " << odd_count << endl;


	// Question 2

	// string s1 = "Hello";
	// string s2 = "what";
	// bool ans = check(s1, s2);
	// if(ans) {
	// 	cout << "Common Word Found" << endl;
	// } else {
	// 	cout << "Common Word Not Found" << endl;
	// }

	// Question 3

	int arr[] = {1, 2, 3, 2, 1};
	vector<int> v = removeDuplicate(arr, 5);
	for(int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
}

/*
[1: 2,
 2: 2,
 5: 1]

*/
