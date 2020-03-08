#include<iostream>
using namespace std;
#include<string>

#define Max 1000




//- ��װ������ʾ�ý��� ��void showMenu()
//- ��main�����е��÷�װ�õĺ���

//�˵�����
void showMenu() 
{	
	cout << "*************************" << endl;
	cout << "***** 1�������ϵ�� *****" << endl;
	cout << "***** 2����ʾ��ϵ�� *****" << endl;
	cout << "***** 3��ɾ����ϵ�� *****" << endl;
	cout << "***** 4��������ϵ�� *****" << endl;
	cout << "***** 5���޸���ϵ�� *****" << endl;
	cout << "***** 6�������ϵ�� *****" << endl;
	cout << "***** 0���˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

//1�������ϵ��
/*
����������
ʵ�������ϵ�˹��ܣ���ϵ������Ϊ1000�ˣ���ϵ����Ϣ�������������Ա����䡢��ϵ�绰����ͥסַ��

�����ϵ��ʵ�ֲ��裺
1�������ϵ�˽ṹ��
2�����ͨѶ¼�ṹ��
3��main�����д���ͨѶ¼
4����װ�����ϵ�˺���
5�����������ϵ�˹���

*/

//�����ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա�
	int m_Sex;
	//����
	int  m_Age;
	//�绰
	string m_Phone;
	//סַ
	string m_Addr;
};


//���ͨѶ¼�ṹ��
struct Addressbooks {

	//ͨѶ¼�б������ϵ������
	struct Person personArray[Max];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};

void addPerson(Addressbooks* abs) {
	
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_Size == Max)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��

				//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		cout << "�������Ա� " << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true) 
		{
			//����������1 ����2 �����˳�ѭ������Ϊ���������ȷֵ
			//�������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;

		system("pause"); //�밴���������
		system("cls"); //��������
	}
}


//2����ʾ������ϵ��
/*
������������ʾͨѶ¼�����е���ϵ����Ϣ

��ʾ��ϵ��ʵ�ֲ��裺
1����װ��ʾ��ϵ�˺���
2��������ʾ��ϵ�˹���
*/
void showPerson(Addressbooks *abs) 
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0��������¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0) {
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "/t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "/t";
			cout << "���䣺" << abs->personArray[i].m_Age << "/t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "/t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause"); //�밴���������
	system("cls"); //��������
}


//3��ɾ��ָ����ϵ��
/*
������������������ɾ����ϵ��

ɾ����ϵ��ʵ�ֲ��裺
1����װ�����ϵ���Ƿ����
2����װɾ����ϵ�˺���
3������ɾ����ϵ�˹���

*/

int isExist(Addressbooks* abs, string name); //���ú����ں�������棬Ҫ����������

void deletePerson(Addressbooks* abs) {

	cout << "��������Ҫɾ������ϵ��" << endl;

	string name;
	cin >> name;

	//ret == -1 δ�鵽
	//ret != -1 �鵽��
	int ret = isExist(abs, name);

	if (ret != -1) {
		//�ҵ����ˣ�Ҫ����ɾ������
		for (int i = ret; i < abs->m_Size; i++) {
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause"); //�밴���������
	system("cls"); //��������
}

//4������ָ����ϵ����Ϣ
/*
�������������������鿴ָ����ϵ����Ϣ
������ϵ��ʵ�ֲ���
1����װ������ϵ�˺���
2�����Բ���ָ����ϵ��
*/
void findPerson(Addressbooks* abs) {

	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	//�ж�ָ������ϵ���Ƿ����ͨѶ¼��
	int ret = isExist(abs, name);

	if (ret != -1) //�ҵ���ϵ��
	{
		cout << "������" << abs->personArray[ret].m_Name << "/t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "/t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "/t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "/t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else //δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}
	system("pause"); //�밴���������
	system("cls"); //��������
}

//5���޸���ϵ����Ϣ
/*
�����������������������޸�ָ����ϵ��
�޸���ϵ��ʵ�ֲ���
1����װ�޸���ϵ�˺���
2�������޸���ϵ�˹���
*/
void modifyPerson(Addressbooks* abs) {

	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	
	int ret = isExist(abs, name);
	
	if (ret != -1) //�ҵ�ָ����ϵ��
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�Ա�
		cout << "�������Ա� " << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true)
		{
			//����������1 ����2 �����˳�ѭ������Ϊ���������ȷֵ
			//�������������������
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		string phone;
		cout << "��������ϵ�绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
	}
	else //δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}
	system("pause"); //�밴���������
	system("cls"); //��������
}

//6�����������ϵ��
/*
�������������ͨѶ¼��������Ϣ
�����ϵ��ʵ�ֲ���
1����װ�����ϵ�˺���
2�����������ϵ��
*/
void cleanPerson(Addressbooks* abs){

	abs->m_Size = 0; //����ǰͨѶ¼��¼��ϵ������Ϊ0�����߼���ղ�������

	cout << "ͨѶ¼�����" << endl;
	system("pause"); //�밴���������
	system("cls"); //��������
}


//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
//����1 ͨѶ¼ ����2 �Ա�����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++) {
		
		//�ҵ��û������������
		if (abs->personArray[i].m_Name == name) {
			return i; //�ҵ��ˣ�����������������е��±���
		}
	}
	return -1; //�������������û���ҵ�������-1
}

int main() {
	
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;



	//�����û���ͬ��ѡ�񣬽��벻ͬ�Ĺ��ܣ�����ѡ��switch��֧�������������ܹ����д
	//���û�ѡ��0��ʱ��ִ���˳���ѡ�������Ȳ�������Ҳ�����˳�����

	int select = 0; //�����û�ѡ������ı���

	while (true) {

		showMenu(); //�˵�����

		cin >> select;

		switch (select) {
		case 1: //1�������ϵ��
			addPerson(&abs);// ���õ�ַ���ݣ���������ʵ��
			break;

		case 2: //2����ʾ��ϵ��
			showPerson(&abs);
			break;

		case 3: //3��ɾ����ϵ��
		//{
		//	cout << "������ɾ����ϵ��������" << endl;
		//	string name;
		//	cin >> name;
		//	if (isExist(&abs, name) == -1) {
		//		cout << "���޴���" << endl;
		//	}
		//	else {
		//		cout << "�ҵ�����" << endl;
		//	}
		//}
			deletePerson(&abs);
			break;
		case 4: //4��������ϵ��
			findPerson(&abs);
			break;
		case 5: // 5���޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: // 6�������ϵ��
			cleanPerson(&abs);
			break;
		case 0: // 0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}


	system("pause");
	return 0;
}