/****************************************
 *	 ��Ŀ��
 *		���������
 *	˵��:
 *		�������������߱����˺�ǰ���Ĺ��ܣ�ʵ�ֲ鿴��һ����ҳ����ǰһ����ҳ�Ĺ��ܣ�������ܿ���ͨ��ά������ջ�����������ʷ��¼��ʵ
	�֣������У�����Ҫʵ�ֹ���֧���������
	BACK:�ѵ�ǰҳ������ǰ�����ջ�Ķ������Ӻ������ջ�Ķ�������ҳ�棬ʹ֮��Ϊ�µĵ�ǰҳ�森����������ջΪ�գ���������ԣ�
	FORWARD:�ѵ�ǰҳ�����ں������ջ�Ķ�������ǰ�����ջ�Ķ�������ҳ�棬��ʹ֮��Ϊ��ǰҳ�森���ǰ�����ջΪ�գ���������ԣ�
	VISIT :�ѵ�ǰҳ�����ں������ջ�Ķ�����ʹָ����URL��Ϊ�µĵ�ǰҳ�森!!!!ǰ�����ջ�ÿ�!!!!��
	QUIT:�˳������
	�ٶ�������ĳ�ʼҳ���URLΪ�� http://www.acm.org/
	 
*	����:
	������һϵ���������ؼ��ְ����� BACK, FORWARD, VISIT�Լ� QUIT.URL�����ո��ҳ��Ȳ�����70���ַ�������Լٶ�ʵ��������ÿһ��ջ�е�Ԫ����Զ���ᳬ��100������Ľ�����QUIT�����ʶ��
*	���:
	����QUIT�������⣬���ÿһ�����������Ҫ��ӡ��ִ�и��������Ҫ���ʵ�URL,����Ϊ��������������ԣ������Ignored�������ÿһ������������Ӧ�ô�ӡ�ڵ���һ���ϣ����QUIT�����Ҫ���
*********************************************************/

#include<iostream>
#include<stack>
#include<string>
using namespace std;
enum Operator{
	BACK,FORWARD,VISIT,QUIT
} op; //ö�ٲ���
void opSt(stack<string>& webL, stack<string>& webR, Operator op, string str =" ");
int main() {

	stack<string> webL;//back Stack 
	stack<string> webR;
	string input;
	
	webL.push("http://www.acm.org/");
	getline(cin,input);
	while(input != "QUIT") {
		char cop;
		cop = input[0];
		switch(cop) {
			case 'B':
				opSt(webL,webR,BACK);
				break;
			case 'F':
				opSt(webL,webR,FORWARD);
				break;
			case 'V':
				string str;
				str = input.substr(5,input.length()-5);
				opSt(webL,webR,VISIT,str);
		}
		getline(cin,input);
	}
	return 0;
	

}

void opSt(stack<string>& webL, stack<string>& webR, Operator op, string str) {
	switch(op){
		case BACK:
			if(webL.size() == 1) {
				cout << "Ignored" << endl;
			} else {
				webR.push(webL.top());
				webL.pop();
				cout << webL.top() << endl;
			}
			break;
		case FORWARD:
			if(webR.size()==0) {
				cout << "Ignored" << endl;
			} else {
				webL.push(webR.top());
				webR.pop();
				cout << webL.top() << endl;
			}
			break;
		case VISIT:
			webL.push(str);
			cout << str << endl;
			while(!webR.empty())
				webR.pop();
	}
}
