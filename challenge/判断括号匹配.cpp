/***************************************************
 * ��Ŀ��
 *		�ж��ַ����е������Ƿ�ƥ��
 * ������
 *		һ���ַ����а���()��[]��{}�������͵����ţ���дһ�������ж������ַ����е������Ƿ���ԡ�
 * ���룺
 *		һ���ַ���
 * �����
 *		true��false
 *******************************************************/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string str;
	stack<char> st;

	getline(cin,str);
	int len = str.length();
	for(int i = 0; i < len; i++) {
		switch(str[i]) {
			case '(':
				st.push('(');
				break;
			case '[':
				st.push('[');
				break;
			case '{':
				st.push('{');
				break;
			case ')':
				if(st.empty()) {
					cout << "false";
					return 0;
				}
				if(st.top() == '(') {
					st.pop();
				} else {
					cout << "false";
					return 0;
				}
				break;
			case ']':
				if(st.empty()) {
					cout << "false";
					return 0;
				}
				if(st.top() == '[') {
					st.pop();
				} else {
					cout << "false";
					return 0;
				}
				break;
			case '}':
				if(st.empty()) {
					cout << "false";
					return 0;
				}
				if(st.top() == '{') {
					st.pop();
				} else {
					cout << "false";
					return 0;
				}
				break;
			}
	}
	if(st.empty())
		cout << "true";
	else
		cout << "false";

	return 0;
}

