#include<iostream>
#include<string>
#define MAX 1000 //ͨѶ¼�������
using namespace std;

//��ϵ�˽ṹ��
struct contact
{
	string name;
	int sex; //�Ա�1�� 2Ů
	int age;
	string phoneNum;
	string address;
};

//ͨѶ¼�ṹ��
struct AddressBooks
{
	contact conArray[MAX];
	int numOfCon; //��¼ͨѶ¼����Ա����
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
	/*��ʼ��ͨѶ¼����Ϊ��*/
	abs.numOfCon = 0;

	int select;
	/*�˵��ĵ���*/
	while (true)
	{
		ShowMenu();
		cin >> select;

		switch (select)
		{
			case 1: //1.�����ϵ��
				AddContacts(&abs);
				break;
			case 2://2.��ʾ��ϵ��
				ShowContacts(&abs);
				break;
			case 3://3.ɾ����ϵ��
				DeleteContacts(&abs);
				break;
			case 4:// 4.������ϵ��
				SearchContacts(&abs);
				break;
			case 5://5.�޸���ϵ��
				ChangeContacts(&abs);
				break;
			case 6://6.�����ϵ��
				EmptyContacts(&abs);
				break;
			case 0:// 0.�˳�ͨѶ¼ /*����Ψһ����*/
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");  
				return 0;
			default: 
				cout << "�޸�ѡ��" << endl;
				/*����*/
				system("pause");
				system("cls");
				break;

		}
	}
	
}


//�������ܣ�չʾ�˵�
void ShowMenu()
{
	cout << "************************" << endl;
	cout << "***** 1.�����ϵ�� *****" << endl;
	cout << "***** 2.��ʾ��ϵ�� *****" << endl;
	cout << "***** 3.ɾ����ϵ�� *****" << endl;
	cout << "***** 4.������ϵ�� *****" << endl;
	cout << "***** 5.�޸���ϵ�� *****" << endl;
	cout << "***** 6.�����ϵ�� *****" << endl;
	cout << "***** 0.�˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl;

}

//�������ܣ������ϵ��
void AddContacts(AddressBooks* pabs)
{
	/*�ж�ͨѶ¼�Ƿ��пռ�*/
	if(pabs->numOfCon < MAX)
	{
		//����
		cout << "������������" << endl;
		cin >> pabs->conArray[pabs->numOfCon].name;

		//�Ա�
		int sex = 0;
		/*����Ϸ��Լ��*/
		while (true)
		{
			cout << "�������Ա�1.�� 2.Ů����" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) break;
			cout << "����������������룡" << endl;
			/*������뻺����*/
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
		pabs->conArray[pabs->numOfCon].sex = sex;

		//����
		int age = 0;

		while (true)
		{
			cout << "���������䣺" << endl;
			cin >> age;
			if (age > 0 && age < 120) break;
			cout << "����������������룡"<<endl;
			/*������뻺����*/
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
		}
		pabs->conArray[pabs->numOfCon].age = age;
		
		//�绰
		cout << "������绰���룺" << endl;
		/*������뻺����*/
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cin >> pabs->conArray[pabs->numOfCon].phoneNum;

		//סַ
		cout << "�������ͥסַ��" << endl;
		/*������뻺����*/
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
		getline(cin,pabs->conArray[pabs->numOfCon].address);
		/*����ͨѶ¼����*/
		pabs->numOfCon++;

		cout << "��ӳɹ���" << endl;
		
		/*����*/
		system("pause");
		system("cls");

	}
	else
	{
		cout << "ͨѶ¼������" << endl;
		return ;
	}

	return;

}

//�������ܣ������ϵ���Ƿ������ͨѶ¼
// ����������ͨѶ¼��ַ����ϵ�˵�����
//��������ֵ����ϵ�˴��ڣ��������������е��±� 
//			  ��ϵ�˲����ڣ�����-1

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


//�������ܣ���ʾͨѶ¼�����е���ϵ����Ϣ
void ShowContacts(AddressBooks* pabs)
{
	if (pabs->numOfCon == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < pabs->numOfCon; i++)
		{
			cout << "������" << pabs->conArray[i].name
				<< "\t�Ա�" << (pabs->conArray[i].sex == 1? "��":"Ů")
				<< "\t���䣺" << pabs->conArray[i].age
				<< "\t�绰���룺" << pabs->conArray[i].phoneNum
				<< "\tסַ��" << pabs->conArray[i].address << endl;
		}
	}

	/*����*/
	system("pause");
	system("cls");

}

//�������ܣ�����������ɾ��ָ����ϵ��
void DeleteContacts(AddressBooks* pabs)
{
	string name;
	cout << "��������Ҫɾ������ϵ��" << endl;
	cin >> name;

	int pos = IsExist(pabs,name);

	if (pos == -1)
	{
		cout << "ͨѶ¼���޸���ϵ��" << endl;
	}
	else
	{
		for (int i = pos; i <= pabs->numOfCon - 1; i++)
		{
			/*����ǰ�ƶ�*/
			pabs->conArray[i] = pabs->conArray[i+1];
			
		}
		pabs->numOfCon--; //����ͨѶ¼����Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	/*����*/
	system("pause");
	system("cls");

}

//�������ܣ��������鿴ָ����ϵ����Ϣ
void SearchContacts(AddressBooks* pabs)
{
	string name;
	cout << "�����������ϵ�˵�����" << endl;
	cin >> name;

	int pos = IsExist(pabs, name);
	if (pos == -1)
	{
		cout << "ͨѶ¼���޸���ϵ��" << endl;
	}
	else
	{
		cout << "������" << pabs->conArray[pos].name << endl;
		cout << "�Ա�" << (pabs->conArray[pos].sex == 1? "��":"Ů") << endl;
		cout << "���䣺" << pabs->conArray[pos].age << endl;
		cout << "�绰��" << pabs->conArray[pos].phoneNum << endl;
		cout << "סַ��" << pabs->conArray[pos].address << endl;
	}
	/*�������������*/
	system("pause");
	system("cls");

}

//�������ܣ������������޸�ָ����ϵ��
void ChangeContacts(AddressBooks* pabs)
{
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;

	int pos = IsExist(pabs,name);
	
	/*δ�ҵ�ָ����ϵ��*/
	if (pos == -1)
	{
		cout << "ͨѶ¼���޸���" << endl;
	}
	else
	{
		//����
		cout << "������������" << endl;
		cin >> pabs->conArray[pos].name;

		//�Ա�
		int sex = 0;
		/*����Ϸ��Լ��*/
		while (true)
		{
			cout << "�������Ա�1.�� 2.Ů����" << endl;
			cin >> sex;
			if (sex == 1 || sex == 2) break;
			cout << "����������������룡" << endl;
			/*������뻺����*/
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
		pabs->conArray[pos].sex = sex;

		//����
		int age = 0;

		while (true)
		{
			cout << "���������䣺" << endl;
			cin >> age;
			if (age > 0 && age < 120) break;
			cout << "����������������룡" << endl;
			/*������뻺����*/
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
		pabs->conArray[pos].age = age;

		//�绰
		cout << "������绰���룺" << endl;
		cin >> pabs->conArray[pos].phoneNum;

		//סַ
		cout << "�������ͥסַ��" << endl;
		/*������뻺����*/
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, pabs->conArray[pos].address);

		cout << "�޸ĳɹ���" << endl;
	}
	/*����*/
	system("pause");
	system("cls");
}

//�������ܣ����ͨѶ¼��������Ϣ
void EmptyContacts(AddressBooks* pabs)
{
	cout << "��ǰͨѶ¼��" << pabs->numOfCon << "�ˣ���ȷ���Ƿ���գ�"<<endl;
	cout << "1.��գ�"<<endl;
	cout << "2.ȡ��" << endl;
	int selection;
	cin >> selection;

	if (selection == 1)
	{
		/*��ͨѶ¼������Ϊ�㣬����߼��ϵ����*/
		pabs->numOfCon = 0;
		cout << "ͨѶ¼�����" << endl;
	}
	else if(selection == 2)
	{
		cout << "��ȡ��" << endl;
	}
	else
	{
		cout << "�޸�ѡ�Ĭ��ȡ��" << endl;
	}
	  
	/*������뻺����*/
	cin.clear();
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	/*�������������*/
	system("pause");
	system("cls");
}