#include<iostream>
#define MAX 1000
using namespace std;

typedef struct _NODE_
{
  int data;
  struct _NODE_ *lChild;
  struct _NODE_ *rChild;
}Node,*pNode,*pTree;
void FindPath(pTree pT,int stack[],int exceptedNum,int curNum,int p)
{
  curNum += pT->data;//·���ͼ��ϵ�ǰ���ֵ
  stack[p++] = pT->data;//�ѵ�ǰ�������stack��
  bool isLeaf = (pT->lChild == NULL) && (pT->rChild == NULL);//�Ƿ�ΪҶ�ӽ��
  if((curNum == exceptedNum) && isLeaf)//��ǰΪҶ�ӽڵ����·����ǡΪ�ڴ�ֵ
  {
    for(int i = 0; i < p-1; i++)//��ӡ·��
    {
      cout<< stack[i] << ',';
    }
    cout << stack[p-1];
  }
  
  if(pT->lChild)//���������,��ô�ݹ����������
  {
    FindPath(pT->lChild,stack,exceptedNum,curNum,p);
  }
  if(pT->rChild)//������Һ���
  {
    FindPath(pT->rChild,stack,exceptedNum,curNum,p);
  }
  p--;//���ظ��ڵ�ǰҪ��ջ����,pop����ǰջ��Ԫ��
}
void FindPath(pTree pT,int exceptedNum)
{
  int stack[1000];//ʹ������ģ��һ��ջ
  if(pT == NULL)
  {
    return;
  }
  int curNum = 0;//��ǰ·����
  int p = 0;//ջ��ָ��
  FindPath(pT,stack,exceptedNum,curNum,p);
}	
void create(pTree *ppTree)
{
  int data;
  cin >> data;
  if(data == -1)
  {
    return;
  }
  *ppTree = new _NODE_;
  if(*ppTree == NULL)
  {
    return;
  }
  (*ppTree)->data = data;
  (*ppTree)->lChild = NULL;
  (*ppTree)->rChild = NULL;
  create(&(*ppTree)->lChild);
  create(&(*ppTree)->rChild);
}
int main()
{
  pTree pT = NULL;
  int n;
  cin >> n; 
  create(&pT);	
  FindPath(pT,n);
  return 0;
}
