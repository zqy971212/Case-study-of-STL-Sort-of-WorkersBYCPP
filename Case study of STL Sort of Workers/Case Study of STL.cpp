#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <time.h>

/*��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
Ա����Ϣ��: ���� ������ɣ����ŷ�Ϊ���߻����������з�
�����10��Ա�����䲿�ź͹���
ͨ��multimap������Ϣ�Ĳ��� key(���ű��) value(Ա��)
�ֲ�����ʾԱ����Ϣ*/

#define CHEHUA 0
#define MEISHU 1
#define YANFA 2

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

void createWorker(vector<Worker>& v)
{
	string NameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker w1;
		w1.m_Name = "Ա��";
		w1.m_Name += NameSeed[i];

		w1.m_Salary = rand() % 10000 + 10000;//10000~19999

		v.push_back(w1);
	}
}

//Ա������
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����������ű��
		int depId = rand() % 3;  //0~3

		//��Ա�����뵽������
		//key ���ű�ţ�value����Ա��
		m.insert(make_pair(depId, *it));
	}
}

void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "�߻�����" << endl;

	multimap<int, Worker>::iterator pos = m.find(CHEHUA);  //�ҵ�keyֵ
	int count = m.count(CHEHUA);  //ͳ�ƾ�������
	int index = 0;
	for (; pos != m.end() &&index< count; pos++,index++)
	{
		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << endl;
	}

	cout << "---------------------"<<endl;
	cout << "��������" << endl;
	pos = m.find(MEISHU);  //�ҵ�keyֵ
	count = m.count(MEISHU);  //ͳ�ƾ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << endl;
	}

	cout << "---------------------" << endl;
	cout << "�з�����" << endl;
	pos = m.find(YANFA);  //�ҵ�keyֵ
	count = m.count(YANFA);  //ͳ�ƾ�������
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << endl;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	//1������Ա��
	vector<Worker>v1;

	createWorker(v1);
	//����
	//for (vector<Worker>::iterator it = v1.begin(); it != v1.end(); it++)
	//{
	//	cout << "������" << it->m_Name << " нˮ��" << it->m_Salary << endl;
	//}

	//2��Ա������
	multimap<int, Worker>m1;
	setGroup(v1, m1);

	//3��������ʾԱ��
	showWorkerByGroup(m1);

	system("pause");
	return 0;
}