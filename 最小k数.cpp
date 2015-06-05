/*********************************************************
��Ŀ:
	����n�����������������С��k��
����:	 
	����˵�� 
	1 ������������ 
	2 ����һ����������
���:	 
	���һ����������
*****************************************************************/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	int n,k;
	vector<int> a;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a.push_back(t);
	}
	
	priority_queue<int> minI;
	for(int i = 0; i < k; i++) {
		minI.push(a[i]);
	}
	
	for(int i = k; i < n; i++) {
		minI.push(a[i]);
		minI.pop();
	}

	vector<int> b;
	for(int i = 0; i < k; i++) {
		b.push_back(minI.top());
		minI.pop();
	}

	for(int i = k-1; i > 0; i--) {
		cout << b[i] << ' ';
	}
	cout << b[0];
	return 0;

}
