/*******************
 * ��Ŀ��
 *		��������ʶ��
 * ĳ��A������������֮һ������Ϊ���������ŷ����ߣ�
	��A���Ͷ��ŵĽ������У�û�з������Ÿ�A������ > L��
	��A���͵Ķ����� - A���յĶ����� > M��
	���������X��A���͸�X�Ķ�����-A���յ�X�Ķ����� > N��
	�����У�
	L = 20
	M = 50
	N = 10 
* ���룺
*		��ѯ�Ƿ��������ŷ����ߣ�һ�У���������ߣ��Կո����
	���Ӷ��ŷ��ͼ�¼�����У�ÿ��һ�η��ͼ�¼��2���Ǹ���������ʽ�������� �����ߣ��Կո����
* �����
*		��Բ�ѯ�ߣ����������ŷ����߷���1�����򷵻�0��!!�������ŷ������޷��ͼ�¼�����!!���������ǲ�ѯ2λ��90909090 20
		����90909090���������ŷ����ߣ�20���ǣ������1 0
		��һ���ո������
***************************/
#include<iostream>
#include<map>
#include<string>
#include<sstream>
using namespace std;

struct client {
	map<int,int> recivers; // ID,counts
	int sends;
	int revs;
};
const int L = 20;
const int M = 50;
const int N = 10;

int main() {
	string str;
	getline(cin,str); //inquire id
	int send,rev;
	map<int,client> table; // Id,Object
	while (cin >> send >> rev) {
		client* ct = &table[send];
		ct->recivers[rev]++;
		ct->sends++;
		ct = &table[rev];
		ct->revs++;
	}
	stringstream ss;
	ss << str;
	int id;
	stringstream sout;
	while (ss >> id) {
		client* ct = &table[id];
		if(ct->sends ==0 && ct->revs ==0) {
			sout << '0' << ' ';//��ʽ��Ҫע��
			continue;
		}
		if((ct->sends - ct->revs) > M) {
			sout << '1' << ' ';
			continue;
		}
		//��������1��3
		bool b1 = false, b3 = false;
		int count1 = 0;
		map<int,int>::iterator it = ct->recivers.begin();
		for(; it != ct->recivers.end(); it++) {
			client* ct2 = &table[it->first];
			if((it->second - ct2->recivers[id]) > N) {
				b3 = true;
				break;
			}
			if(ct2->recivers[id] == 0) {
				count1++;
			}
		}
		if(count1 > L)
			b1 = true;
		if(b1 || b3) {
			sout << '1' << ' ';
			continue;
		}
		sout << '0' << ' ';
	}
	string strout;
	getline(sout,strout);
	strout[strout.length()-1] = '\0';
	cout << strout;
	return 0;

}
