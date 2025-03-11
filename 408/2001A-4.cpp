#include <bits/stdc++.h>

using namespace std;

struct Node{
	int val;
	Node* next; 
	Node(){
	}
	Node(int val) {
		this->val = val;
		this->next = nullptr; 
	}
};
int main()
{
	Node* head = new Node();
	Node* pre = head;
	Node* cur;
	for (int i = 1; i < 31; i++) {
		cur = new Node(i);
		pre->next = cur;
		pre = cur;
	}
	pre->next = head->next;  // 成环
	
	int cnt = 1;
	pre = head;
	cur = head->next;
	int num = 0;
	while (num < 30) {
		if (cnt % 3 == 0) {
			cout << cur->val << ' ';
			pre->next = cur->next;
			cur = cur->next;
			num++;
		} else {
			pre = cur;
			cur = cur->next;
		} cnt++;
	} 
}