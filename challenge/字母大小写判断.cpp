/***************************************
 * ��Ŀ��
 *		��ĸ��Сд�ж�
 * ������
 *		�ж�һ���ַ����Ƿ�������ĸ��д�ҷ�����ĸСд��
 * ����:	 
 *		һ�������ַ��������Ȳ�����128���ַ�
 * �����
 *		��������ַ������ַ�Ϊ��д��ĸ�������ַ��Ǵ�д��ĸ������true
 *		������������ַ��������ַ�����ĸ������ĸΪСд������ĸ��д�������ַ�����ĸ�ȣ�������false
 ****************************************************/
#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	getline(cin,str);
	if(str[0] < 'A' || str[0] > 'Z' || str.length() == 1){
		cout << "false";
		return 0;
	}
	bool lower = 0;//have lower?
	bool upper = 0;//have upper?
	for(int i = 1; i < str.length(); i++) {
		if(str[i]>= 'a' && str[i] <= 'z')
			lower = 1;
		if(str[i]>= 'A' && str[i] <= 'Z')
			upper = 1;
	}
	if(lower && !upper)
		cout << "true";//���֮ǰд����ture 
	else 
		cout << "false";

	return 0;
}
