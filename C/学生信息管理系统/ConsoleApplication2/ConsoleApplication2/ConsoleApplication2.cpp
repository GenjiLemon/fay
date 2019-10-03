// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "xml/tinyxml.h"
#include <vector>
#include <string>
using namespace std;
struct student
{
	string name;
	string code;
	int age;
	bool sex;
	int score;
};

enum Manger
{
	INTRODUCE,
	CREATE_DATEBASE,
	OPEN_DATEBASE,
	ED_windows ,
	EXIT
};


class CSt
{
public:

	void runStudent()
	{

		while (true)
		{
			system("cls");
			switch (m_man)
			{
			case INTRODUCE:
				xinjianshujuku();

				break;
			case CREATE_DATEBASE:
				OnEditor1();
				break;
			case OPEN_DATEBASE:
				dakaiwenjian();
				
				break;
			case ED_windows:
				OnEditor2();
				break;
			case EXIT:
				exit(0);
				
			default:
				break;
			}
			cin.clear();//清空缓冲
			cin.sync();//
		}
	}
	//目录根  ok
	void xinjianshujuku()
	{
				cout << "欢迎使用傻瓜1.1学生信息管理系统" << endl;
				cout << "按1创建傻瓜， 按2读取傻瓜 ，按3退出傻瓜 " << endl;
				int a = 0;
				cin >> a;
				if (1 == a)
				{
					m_man = Manger::CREATE_DATEBASE;
				}
				else if (2 == a)
				{
					m_man = Manger::OPEN_DATEBASE;
				}
				else if (3 == a)
				{
				
					m_man = Manger::EXIT;
									
				}


	}
	//打开文件夹  ok
	void dakaiwenjian()
	{
		cout << "输入打开文件名" << endl;
		string wenben;
		cin >> wenben;
		TiXmlDocument doc(wenben.c_str());
		if (!doc.LoadFile())
		{
			cout << wenben << "打开失败" << endl;
			_sleep(1000);
			return;
		}
		auto root = doc.FirstChildElement("student");
		auto abc = root->FirstChildElement("Elements");
		for (; abc != nullptr; abc = abc->NextSiblingElement())
		{
			student stu;
			stu.name = abc->Attribute("name");
			stu.code = abc->Attribute("code");
			stu.age = atoi(abc->Attribute("age"));
			stu.sex = atoi(abc->Attribute("sex"));
			abc->Attribute("score",&stu.score);
				arr.push_back(stu);
		}
		cout<<"一共有"<<arr.size()<<"学员"<<endl;
		_sleep(1000);
		m_man = Manger::ED_windows;
	}
	//新文件操作 ok
	void OnEditor1()
	{
		cout << "1新建学员2保存3返回" << endl;
		int a = 0; cin >> a;
		if (1 == a)
		{
			addnew();
			cout << "添加成功" << endl;
			_sleep(1000);
		}

		else if (2 == a)
		{
			save(); _sleep(1000);
		}
		else if (3 == a)
		{
			cout << "是否保存Y/N" << endl;
			char a;
			cin >> a;
			if ('Y' == a)
			{
				save();
				_sleep(1000);
				m_man = Manger::INTRODUCE;
			}
			if ('N' == a)
			{
				m_man = Manger::INTRODUCE;
			}
			arr.clear();
			

		}
		else
		{
			cout << "输入错误" << endl;
			_sleep(1000);
		}
	}
	//读取文件后操作
	void OnEditor2()
	{
		cout << "1添加学员2查找学员3查询所有学员4保存5返回" << endl;
		int a = 0; cin >> a;
		if (1 == a)
		{
			addnew();
			cout << "添加成功" << endl;
			_sleep(1000);
		}
		else if (2 == a)
		{
			Find(); _sleep(1000);
		}
		else if (3 == a)
		{
			shouAllStudent(); _sleep(1000);
		}
		else if (4 == a)
		{
			save();
			_sleep(1000);
		}
		else if (5 == a)
		{
			
			cout << "是否保存Y/N" << endl;
			char a;
			cin >> a;
			if ('Y' == a)
			{
				save();
				_sleep(1000);
				m_man = Manger::INTRODUCE;
			}
			if ('N' == a)
			{
				m_man = Manger::INTRODUCE;
			}
			arr.clear();
		}
		else
		{			
			cout << "输入错误" << endl;
			_sleep(1000);
			
		}

	}
	//查找学员
	void Find()
	{
	
			cout << "开始查找" << endl;
			cout << "1姓名 2学号" << endl;
			int a = 0; cin >> a;
			//姓名查找
			if (1 == a)
			{
				cout << "输入学生名字" << endl;
				string name;
				cin >> name;
				int i = find1(name);
				if (-1 == i)
				{
					cout << "没有此人" << endl;
					return;
				}
				cout << "学员数据" << endl;
				shouby(i);
				cout << "1修改学员 2删除学员 3 返回" << endl;		
				int b = 0; cin >> b;				
				if (1 == b)
				{
					cout << "1姓名  2学号  3年龄  4性别  5成绩 6返回 " << endl;
					int c = 0; cin >> c;

					if (1 == c)
					{
						cout << "修改姓名" << endl;
						string name;
						cin >> name;
						arr[i].name = name;
					}
					if (2 == c)
					{
						cout << "修改学号" << endl;
						string code;
						cin >> code;
						arr[i].code = code;
					}
					if (3 == c)
					{
						cout << "修改年龄" << endl;
						int age;
						cin >> age;
						arr[i].age = age;
					}
					if (4 == c)
					{
						cout << "修改性别" << endl;
						cin >> arr[i].sex;
					}
					if (5 == c)
					{
						cout << "修改成绩" << endl;
						cin >> arr[i].score;
					}
					if (6 == c)
					{
						cout << "返回中ing" << endl;
					}

				}
				if (2 == b)
				{
					auto iter = arr.erase(std::begin(arr));
					
				}
				if (3 == b)
				{
					cout << "返回中ing" << endl;
					
				}
			}
			//学号查找
			if (2 == a)
			{
				cout << "输入学生学号" << endl;
				string code;
				cin >> code;
				int i = find2(code);
				if (-1 == i)
				{
					cout << "没有此人" << endl;
					return;
				}
				cout << "学员数据" << endl;
				shouby(i);
				cout << "1修改学员 2删除学员 3 返回" << endl;

				int b = 0; cin >> b;
				if (1 == b)
				{
					cout << "1姓名  2学号  3年龄  4性别  5成绩 6返回 " << endl;
					int c = 0; cin >> c;

					if (1 == c)
					{
						cout << "修改姓名" << endl;
						string name;
						cin >> name;
						arr[i].name = name;
					}
					if (2 == c)
					{
						cout << "修改学号" << endl;
						string code;
						cin >> code;
						arr[i].code = code;
					}
					if (3 == c)
					{
						cout << "修改年龄" << endl;
						int age;
						cin >> age;
						arr[i].age = age;
					}
					if (4 == c)
					{
						cout << "修改性别" << endl;
						cin >> arr[i].sex;
					}
					if (5 == c)
					{
						cout << "修改成绩" << endl;
						cin >> arr[i].score;
					}
				}
				if (2 == b)
				{
					auto iter = arr.erase(std::begin(arr));

				}
				if (3 == b)
				{
					cout << "返回中ing" << endl;

				}
			}

		

	}
	//找到这个名字的学生位置
	int find1(string _name)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i].name == _name)
			{
				return i;
			}
		}
		return -1;
	}
	//找到这个学号的学生位置
	int find2(string _code)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i].code == _code)
			{
				return i;
			}
		}
		return -1;
	}
	//保存当前学员数据
	void save()
	{
		cout << "开始进行学员档案" << endl;
		cout << "输入保存的文件名" << endl;
		string savename;
		cin >> savename;
		TiXmlDocument doc;
		TiXmlElement *root = new TiXmlElement("student");
		for (int i = 0; i < arr.size(); i++)
		{
			TiXmlElement *child = new TiXmlElement("Elements");
			child->SetAttribute("name", arr[i].name.c_str());
			child->SetAttribute("code", arr[i].code.c_str());
			child->SetAttribute("age", arr[i].age);
			child->SetAttribute("sex", arr[i].sex);
			child->SetAttribute("score", arr[i].score);
			root->LinkEndChild(child);
		}
		doc.LinkEndChild(root);
		doc.SaveFile(savename.c_str());
		doc.Clear();
		cout << "保存成功" << endl;
	} 
	//新建一个学员
	void addnew()
	{
		string _name;
		string _code;
		int _age;
		bool _sex;
		int _score;
		cout << "输入名字" << endl;
		cin >> _name;
		cout << "输入学号" << endl;
		cin >> _code;
		cout << "输入年龄" << endl;
		cin >> _age;
		cout << "输入性别" << endl;
		cin >> _sex;
		cout << "输入成绩" << endl;
		cin >> _score;
		student zhangsan = { _name,_code,_age,_sex,_score };
		arr.push_back(zhangsan);
		
	}
	//查询后的数据
	void shouAllStudent()
	{
		for (int i = 0; i < arr.size(); i++)
		{
			cout << "姓名" << arr[i].name<< " ";
			cout << "学号" << arr[i].code << " ";
			cout << "年龄" << arr[i].age << " ";
			if (arr[i].sex)
			{
				cout << "性别" <<"男" << " ";
			}
			else
			{
				cout << "性别" << "女" << " ";
			}
			cout << "成绩" << arr[i].score << ""<<endl;
		}
	}
	//找学生后的学生数据
	void shouby(int i) 
	{
		
			cout << "姓名" << arr[i].name << " ";
			cout << "学号" << arr[i].code << " ";
			cout << "年龄" << arr[i].age << " ";
			if (arr[i].sex)
			{
				cout << "性别" << "男" << " ";
			}
			else
			{
				cout << "性别" << "女" << " ";
			}
			cout << "成绩" << arr[i].score << "" << endl;
		
	}
	Manger m_man = Manger::INTRODUCE;
	vector<student>arr;
};
int main()
{

	CSt cst;
	cst.runStudent();


}