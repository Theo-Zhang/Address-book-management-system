#include<iostream>
using namespace std;
#include<string>

#define Max 1000




//- 封装函数显示该界面 如void showMenu()
//- 在main函数中调用封装好的函数

//菜单界面
void showMenu() 
{	
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

//1、添加联系人
/*
功能描述：
实现添加联系人功能，联系人上限为1000人，联系人信息包括（姓名、性别、年龄、联系电话、家庭住址）

添加联系人实现步骤：
1、设计联系人结构体
2、设计通讯录结构体
3、main函数中创建通讯录
4、封装添加联系人函数
5、测试添加联系人功能

*/

//设计联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别
	int m_Sex;
	//年龄
	int  m_Age;
	//电话
	string m_Phone;
	//住址
	string m_Addr;
};


//设计通讯录结构体
struct Addressbooks {

	//通讯录中保存的联系人数组
	struct Person personArray[Max];

	//通讯录中当前记录联系人个数
	int m_Size;
};

void addPerson(Addressbooks* abs) {
	
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->m_Size == Max)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人

				//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别： " << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true) 
		{
			//如果输入的是1 或者2 可以退出循环，因为输入的是正确值
			//如果输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;

		system("pause"); //请按任意键继续
		system("cls"); //清屏操作
	}
}


//2、显示所有联系人
/*
功能描述：显示通讯录中已有的联系人信息

显示联系人实现步骤：
1、封装显示联系人函数
2、测试显示联系人功能
*/
void showPerson(Addressbooks *abs) 
{
	//判断通讯录中人数是否为0，如果为0，提升记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0) {
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "/t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "/t";
			cout << "年龄：" << abs->personArray[i].m_Age << "/t";
			cout << "电话：" << abs->personArray[i].m_Phone << "/t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}

	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}


//3、删除指定联系人
/*
功能描述：按照姓名删除联系人

删除联系人实现步骤：
1、封装检测联系人是否存在
2、封装删除联系人函数
3、测试删除联系人功能

*/

int isExist(Addressbooks* abs, string name); //调用函数在函数体后面，要事先声明。

void deletePerson(Addressbooks* abs) {

	cout << "请输入您要删除的联系人" << endl;

	string name;
	cin >> name;

	//ret == -1 未查到
	//ret != -1 查到了
	int ret = isExist(abs, name);

	if (ret != -1) {
		//找到此人，要进行删除操作
		for (int i = ret; i < abs->m_Size; i++) {
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新通讯录中的人员数
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}

//4、查找指定联系人信息
/*
功能描述：按照姓名查看指定联系人信息
查找联系人实现步骤
1、封装查找联系人函数
2、测试查找指定联系人
*/
void findPerson(Addressbooks* abs) {

	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	//判断指定的联系人是否存在通讯录中
	int ret = isExist(abs, name);

	if (ret != -1) //找到联系人
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "/t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "/t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "/t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "/t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else //未找到联系人
	{
		cout << "查无此人" << endl;
	}
	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}

//5、修改联系人信息
/*
功能描述：按照姓名重新修改指定联系人
修改联系人实现步骤
1、封装修改联系人函数
2、测试修改联系人功能
*/
void modifyPerson(Addressbooks* abs) {

	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	
	int ret = isExist(abs, name);
	
	if (ret != -1) //找到指定联系人
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别
		cout << "请输入性别： " << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			//如果输入的是1 或者2 可以退出循环，因为输入的是正确值
			//如果输入有误，重新输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		string phone;
		cout << "请输入联系电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
	}
	else //未找到联系人
	{
		cout << "查无此人" << endl;
	}
	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}

//6、清空所有联系人
/*
功能描述：清空通讯录中所有信息
清空联系人实现步骤
1、封装清空联系人函数
2、测试清空联系人
*/
void cleanPerson(Addressbooks* abs){

	abs->m_Size = 0; //将当前通讯录记录联系人数置为0，做逻辑清空操作即可

	cout << "通讯录已清空" << endl;
	system("pause"); //请按任意键继续
	system("cls"); //清屏操作
}


//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1 通讯录 参数2 对比姓名
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++) {
		
		//找到用户输入的姓名了
		if (abs->personArray[i].m_Name == name) {
			return i; //找到了，返回这个人在数组中的下标编号
		}
	}
	return -1; //如果遍历结束都没有找到，返回-1
}

int main() {
	
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;



	//根据用户不同的选择，进入不同的功能，可以选择switch分支机构，将整个架构进行搭建
	//当用户选择0的时候，执行退出，选择其他先不操作，也不会退出程序

	int select = 0; //创建用户选择输入的变量

	while (true) {

		showMenu(); //菜单调用

		cin >> select;

		switch (select) {
		case 1: //1、添加联系人
			addPerson(&abs);// 利用地址传递，可以修饰实参
			break;

		case 2: //2、显示联系人
			showPerson(&abs);
			break;

		case 3: //3、删除联系人
		//{
		//	cout << "请输入删除联系人姓名：" << endl;
		//	string name;
		//	cin >> name;
		//	if (isExist(&abs, name) == -1) {
		//		cout << "查无此人" << endl;
		//	}
		//	else {
		//		cout << "找到此人" << endl;
		//	}
		//}
			deletePerson(&abs);
			break;
		case 4: //4、查找联系人
			findPerson(&abs);
			break;
		case 5: // 5、修改联系人
			modifyPerson(&abs);
			break;
		case 6: // 6、清空联系人
			cleanPerson(&abs);
			break;
		case 0: // 0、退出通讯录
			cout << "欢迎下次使用" << endl;
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