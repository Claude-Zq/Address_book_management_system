#include<iostream>
#include<string>
#define MAX 1000 //通讯录最大人数
using namespace std;

//联系人结构体
struct contact
{
	string name;
	int sex; //性别：1男 2女
	int age;
	string phoneNum;
	string address;
};

//通讯录结构体
struct AddressBooks
{
	contact conArray[MAX];
	int numOfCon; //记录通讯录中人员个数
};


int IsExist(AddressBooks* pabs, string name);
void AddContacts(AddressBooks *pabs);
void ShowContacts(AddressBooks* pabs);
void DeleteContacts(AddressBooks* pabs);
void SearchContacts(AddressBooks* pabs);
void ChangeContacts(AddressBooks* pabs);
void EmptyContacts(AddressBooks* pabs);
void ShowMenu();

int main()
{
	AddressBooks abs;
	/*初始化通讯录人数为零*/
	abs.numOfCon = 0;

	int select;
	/*菜单的调用*/
	while (true)
	{
		ShowMenu();
		cin >> select;

		switch (select)
		{
			case 1: //1.添加联系人
				AddContacts(&abs);
				break;
			case 2://2.显示联系人
				ShowContacts(&abs);
				break;
			case 3://3.删除联系人
				DeleteContacts(&abs);
				break;
			case 4:// 4.查找联系人
				SearchContacts(&abs);
				break;
			case 5://5.修改联系人
				ChangeContacts(&abs);
				break;
			case 6://6.清空联系人
				EmptyContacts(&abs);
				break;
			case 0:// 0.退出通讯录 /*程序唯一出口*/
				cout << "欢迎下次使用" << endl;
				system("pause");  
				return 0;
			default: 
				cout << "无该选项" << endl;
				/*清屏*/
				system("pause");
				system("cls");
				break;

		}
	}
	
}


//函数功能：展示菜单
void ShowMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.添加联系人 *****" << endl;
	cout << "***** 2.显示联系人 *****" << endl;
	cout << "***** 3.删除联系人 *****" << endl;
	cout << "***** 4.查找联系人 *****" << endl;
	cout << "***** 5.修改联系人 *****" << endl;
	cout << "***** 6.清空联系人 *****" << endl;
	cout << "***** 0.退出通讯录 *****" << endl;
	cout << "************************" << endl;

}

//函数功能：添加联系人
void AddContacts(AddressBooks* pabs)
{
	/*判断通讯录是否有空间*/
	if(pabs->numOfCon < MAX)
	{
		//姓名
		cout << "请输入姓名：" << endl;
		cin >> pabs->conArray[pabs->numOfCon].name;

		//性别
		int sex = 0;
		/*输入合法性检测*/
		while (true)
		{
			cout << "请输入性别（1.男 2.女）：" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) break;
			cout << "输入错误，请重新输入！" << endl;
			/*清空输入缓冲区*/
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
		pabs->conArray[pabs->numOfCon].sex = sex;

		//年龄
		int age = 0;

		while (true)
		{
			cout << "请输入年龄：" << endl;
			cin >> age;
			if (age > 0 && age < 120) break;
			cout << "输入错误，请重新输入！"<<endl;
			/*清空输入缓冲区*/
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
		}
		pabs->conArray[pabs->numOfCon].age = age;
		
		//电话
		cout << "请输入电话号码：" << endl;
		/*清空输入缓冲区*/
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cin >> pabs->conArray[pabs->numOfCon].phoneNum;

		//住址
		cout << "请输入家庭住址：" << endl;
		/*清空输入缓冲区*/
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
		getline(cin,pabs->conArray[pabs->numOfCon].address);
		/*更新通讯录人数*/
		pabs->numOfCon++;

		cout << "添加成功！" << endl;
		
		/*清屏*/
		system("pause");
		system("cls");

	}
	else
	{
		cout << "通讯录已满！" << endl;
		return ;
	}

	return;

}

//函数功能：检测联系人是否存在于通讯录
// 函数参数：通讯录地址，联系人的名字
//函数返回值：联系人存在：返回其在数组中的下标 
//			  联系人不存在：返回-1

int IsExist(AddressBooks* pabs, string name)
{
	for (int i = 0; i < pabs->numOfCon; i++)
	{
		if (pabs->conArray[i].name == name)
		{
			return i;
		}
	}

	return -1;
}


//函数功能：显示通讯录中已有的联系人信息
void ShowContacts(AddressBooks* pabs)
{
	if (pabs->numOfCon == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < pabs->numOfCon; i++)
		{
			cout << "姓名：" << pabs->conArray[i].name
				<< "\t性别：" << (pabs->conArray[i].sex == 1? "男":"女")
				<< "\t年龄：" << pabs->conArray[i].age
				<< "\t电话号码：" << pabs->conArray[i].phoneNum
				<< "\t住址：" << pabs->conArray[i].address << endl;
		}
	}

	/*清屏*/
	system("pause");
	system("cls");

}

//函数功能：按姓名进行删除指定联系人
void DeleteContacts(AddressBooks* pabs)
{
	string name;
	cout << "请输入您要删除的联系人" << endl;
	cin >> name;

	int pos = IsExist(pabs,name);

	if (pos == -1)
	{
		cout << "通讯录中无该联系人" << endl;
	}
	else
	{
		for (int i = pos; i <= pabs->numOfCon - 1; i++)
		{
			/*数据前移动*/
			pabs->conArray[i] = pabs->conArray[i+1];
			
		}
		pabs->numOfCon--; //更新通讯录中人员数
		cout << "删除成功" << endl;
	}
	/*清屏*/
	system("pause");
	system("cls");

}

//函数功能：按姓名查看指定联系人信息
void SearchContacts(AddressBooks* pabs)
{
	string name;
	cout << "请输入待查联系人的姓名" << endl;
	cin >> name;

	int pos = IsExist(pabs, name);
	if (pos == -1)
	{
		cout << "通讯录中无该联系人" << endl;
	}
	else
	{
		cout << "姓名：" << pabs->conArray[pos].name << endl;
		cout << "性别：" << (pabs->conArray[pos].sex == 1? "男":"女") << endl;
		cout << "年龄：" << pabs->conArray[pos].age << endl;
		cout << "电话：" << pabs->conArray[pos].phoneNum << endl;
		cout << "住址：" << pabs->conArray[pos].address << endl;
	}
	/*按任意键后清屏*/
	system("pause");
	system("cls");

}

//函数功能：按名字重新修改指定联系人
void ChangeContacts(AddressBooks* pabs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;

	int pos = IsExist(pabs,name);
	
	/*未找到指定联系人*/
	if (pos == -1)
	{
		cout << "通讯录中无该人" << endl;
	}
	else
	{
		//姓名
		cout << "请输入姓名：" << endl;
		cin >> pabs->conArray[pos].name;

		//性别
		int sex = 0;
		/*输入合法性检测*/
		while (true)
		{
			cout << "请输入性别（1.男 2.女）：" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) break;
			cout << "输入错误，请重新输入！" << endl;
			/*清空输入缓冲区*/
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
		pabs->conArray[pos].sex = sex;

		//年龄
		int age = 0;

		while (true)
		{
			cout << "请输入年龄：" << endl;
			cin >> age;
			if (age > 0 && age < 120) break;
			cout << "输入错误，请重新输入！" << endl;
			/*清空输入缓冲区*/
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
		pabs->conArray[pos].age = age;

		//电话
		cout << "请输入电话号码：" << endl;
		cin >> pabs->conArray[pos].phoneNum;

		//住址
		cout << "请输入家庭住址：" << endl;
		/*清空输入缓冲区*/
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, pabs->conArray[pos].address);

		cout << "修改成功！" << endl;
	}
	/*清屏*/
	system("pause");
	system("cls");
}

//函数功能：清空通讯录中所有信息
void EmptyContacts(AddressBooks* pabs)
{
	cout << "当前通讯录有" << pabs->numOfCon << "人，请确认是否清空："<<endl;
	cout << "1.清空！"<<endl;
	cout << "2.取消" << endl;
	int selection;
	cin >> selection;

	if (selection == 1)
	{
		/*置通讯录的人数为零，完成逻辑上的清空*/
		pabs->numOfCon = 0;
		cout << "通讯录已清空" << endl;
	}
	else if(selection == 2)
	{
		cout << "已取消" << endl;
	}
	else
	{
		cout << "无该选项，默认取消" << endl;
	}
	  
	/*清空输入缓冲区*/
	cin.clear();
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	/*按任意键后清屏*/
	system("pause");
	system("cls");
}