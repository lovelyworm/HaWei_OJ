#include<iostream>
#include<cstring>
#include<string>
#include<map>
using namespace std;
int map_g[100][100];    
int m_find[20];
map<int ,int> my;
int check(int m,int n){   
	int flag=0; int out_deg=0;//���� 
	int r_deg=0;//���    
	int out_t=0;    
	int in_t=0; 
	int m_index=my[m_find[m]];//�ҵ�ӳ��    
	for(int i=1;i<=n;i++){
		if(map_g[m_index][i]>0){
			out_deg++;
			out_t+=map_g[m_index][i];
		}
		if((map_g[m_index][i]-map_g[i][m_index])>10){
			//���һ������
			flag=1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(map_g[i][m_index]){
			r_deg++;
			in_t+=map_g[i][m_index];
		}
	}   int l=(out_deg-r_deg);//û�и�A���͵Ķ������� //���ȼ�ȥ���
	int s=out_t-in_t;//������
	if(l>20||s>50)
		flag=1; return flag;
}

int main(){
	memset(map_g,0,sizeof(map_g));  //string ��ʾ����id��,int ��ʾ������ͼ�ľ����е��±�  //c����û��map�����ýṹ����ʵ�֣�����Ҫ����Ԫ�صĲ��ң��Լ�ȥ�صȵȡ�      
	map<int ,int >::iterator ptr;
	int s_id,r_id;
	int num=0;
	char c;
	scanf("%d",&m_find[num++]);
	c=getchar();
	while(c!='\n'){
		scanf("%d",&m_find[num++]);
		c=getchar();
	}
	int count=0;
	int real_id,real_id2;
	while(cin>>s_id>>r_id){
		//test      //my[s_id]++;       //my[r_id]++;       if(my[s_id]==0) my[s_id]=++count;       //my[s_id]�Ƿ��ʾ������
		if(my[r_id]==0) my[r_id]=++count;       //==0��ʾ���Ԫ�ز�����
		real_id=my[s_id];
		real_id2=my[r_id];
		map_g[real_id][real_id2]++;//���͵Ķ�����Ŀ��
	}
	int m_size=my.size();
	for(int i=0;i<num;i++){
		if(check(i,count))
			cout<<1<<" ";
		else
			cout<<0<<" ";
	}
	return 0;
}  
