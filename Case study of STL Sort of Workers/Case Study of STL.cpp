#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <time.h>

/*公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
员工信息有: 姓名 工资组成；部门分为：策划、美术、研发
随机给10名员工分配部门和工资
通过multimap进行信息的插入 key(部门编号) value(员工)
分部门显示员工信息*/

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
		w1.m_Name = "员工";
		w1.m_Name += NameSeed[i];

		w1.m_Salary = rand() % 10000 + 10000;//10000~19999

		v.push_back(w1);
	}
}

//员工分组
void setGroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//产生随机部门编号
		int depId = rand() % 3;  //0~3

		//将员工插入到分组中
		//key 部门编号，value具体员工
		m.insert(make_pair(depId, *it));
	}
}

void showWorkerByGroup(multimap<int, Worker>& m)
{
	cout << "策划部门" << endl;

	multimap<int, Worker>::iterator pos = m.find(CHEHUA);  //找到key值
	int count = m.count(CHEHUA);  //统计具体人数
	int index = 0;
	for (; pos != m.end() &&index< count; pos++,index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}

	cout << "---------------------"<<endl;
	cout << "美术部门" << endl;
	pos = m.find(MEISHU);  //找到key值
	count = m.count(MEISHU);  //统计具体人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}

	cout << "---------------------" << endl;
	cout << "研发部门" << endl;
	pos = m.find(YANFA);  //找到key值
	count = m.count(YANFA);  //统计具体人数
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	//1、创建员工
	vector<Worker>v1;

	createWorker(v1);
	//测试
	//for (vector<Worker>::iterator it = v1.begin(); it != v1.end(); it++)
	//{
	//	cout << "姓名：" << it->m_Name << " 薪水：" << it->m_Salary << endl;
	//}

	//2、员工分组
	multimap<int, Worker>m1;
	setGroup(v1, m1);

	//3、分组显示员工
	showWorkerByGroup(m1);

	system("pause");
	return 0;
}