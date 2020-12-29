#include <iostream>
#include "sqlite3.h"
#include <string>
#include<cstdlib>
#include "sqlite_operation.h"
#pragma comment(lib, "sqlite3.lib")
using namespace std;

void begin();
void Email_Home(string address,string password);
void Email_inbox(string address, string password); \
void Email_Read(string ID);
void Email_write(string address, string password);

class Email{
	char* address;
	char* password;
public:
	Email() {};
	Email(char* Address, char* Password) {
		address = Address; password = Password;
	}
	~Email() {};
	void Register();
		/*�������ݿ� ����*/
		/*���ӳɹ�Homeshow*/
	void Login();
};


void Email::Register() {
	string address;
	string password;
	string s,input;
	char *sql;
	int check;
	while (true) {
		cout << "�������û�������@oop.com��׺��" ;
		cin >> address;
		/*��ѯ�Ϸ���*/
		/*�������ݿ��ѯ�û���*/
		/*�������ֵΪ ������password,����*/
		check = Check_Account(address);
		if (check==1) {
			cout << "�����Ѵ��ڣ������ע����!" << endl;
		}
		else {
			cout << "���������룺";
			cin >> password;
			cout << "�Ƿ�ȷ��ע�᣿[ȷ�ϣ�Y / �˳���N]" << endl;
			cout << ">>>  " ;
			cin >> input;
			if (input == "Y") {
				s = "INSERT INTO EmailAccount (ADDRESS,PASSWORD) VALUES ('" + address + "','" + password + "');";
				sql = (char*)s.data();
				check=Insert_Record(sql);
				if (check == 1) {
					cout << "ע��ɹ�" << endl;
					break;
				}
				else {
					cout << "ע��ʧ��" << endl;
					break;
				}
			}
			else {
				break;
			}
		}
	}
}

void Email::Login() {
	int check=0;
	string address, password;
	char input;
	while (check == 0) {
		cout << ">>>  ���أ�B / ������¼��C" << endl;
		cout << ">>>  " ;
		cin >> input;
		if (input == 'C') {
			cout << "�����������ַ��";
			cin >> address;
			cout << "���������룺";
			cin >> password;
			check=Login_Check_Account(address, password);
			if (check == 0) {
				cout << ">>>  �û������������" << endl;
			}
		}
		else if(input=='B') {
			check = 1;
		}
		else {
			check == 0;
		}
	}
	if (check == 1) {
		Email_Home(address,password);
	}
}

int main() {

	begin();

	system("pause");
}

void begin() {
	Email E;
	string option;
	string address, password;

	while (true) {
		cout << ">>>>>> Welcome to the EmailSystem.<<<<<<" << endl;
		cout << "  ѡ��			����	" << endl;
		cout << "  ���������¼		L1		" << endl;
		cout << "  �����������¼	L2		" << endl;
		cout << "  ע��			R		" << endl;
		cout << "  �˳�			Q		" << endl;
		cout << ">>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "��ѡ�������";
		cin >> option;
		if (option.compare("L1") == 0) {
			cout << ">>> Login with local email." << endl;
			E.Login();
			break;
		}
		else if (option.compare("L2") == 0) {
			cout << "Login with other email..." << endl;
			break;
		}
		else if (option.compare("R") == 0) {
			E.Register();
		}
		else if (option.compare("Q") == 0) {
			cout << "Quit..." << endl;
			break;
		}
		else {
			cout << "����ָ�����룡" << endl;
		}
	}
}

void Email_Home(string address, string password) {
	cout << "----------------------------------------------------" << endl;
	cout << ">>>		Welcome," << address << "		<<<" << endl;
	cout << ">>>  �˳���¼��T" << endl;
	cout << ">>>  д�ţ�W | �ռ��䣺Q " << endl;
	cout << "----------------------------------------------------" << endl;
	char input;
	cout << ">>>  ";
	cin >> input;
	if (input == 'T') {
		begin();
	}
	else if (input == 'Q') {
		cout << "----------------------------------------------------" << endl;
		cout << ">>> >>> >>> >>>	InBox	<<< <<< <<< <<<" << endl;
		cout << "----------------------------------------------------" << endl;
		Email_inbox(address, password);
	}
	else if (input == 'W') {
		cout << "----------------------------------------------------" << endl;
		cout << ">>> >>> >>> >>>	Write Email	<<< <<< <<< <<<" << endl;
		cout << "----------------------------------------------------" << endl;
		Email_write(address, password);
	}
}

void Email_inbox(string address, string password) {
	string input;
	Email_list(address);
	while (true) {
		cout << ">>>  ���أ�B / ����ID�Ķ�" << endl;
		cout << ">>>  ";
		cin >> input;
		if (input == "B") {
			Email_Home(address, password);
			break;
		}
		else {
			Email_Read(input);
		}
	}
}

void Email_Read(string ID) {
	char input;
	Show_Email(ID);
	while (true) {
		cout << ">>>  ���أ�B  \  ɾ����D \ ��Ϊ�Ѷ���F" << endl;
		cout << ">>>  ";
		cin >> input;
		if (input == 'B') {
			break;
		}
		else if (input == 'D') {
			Email_Delete(ID);
		}
		else if (input == 'F') {
			Email_Sign(ID);
		}
	}
}

void Email_write(string address, string password) {
	string receiver;
	string content;
	string title;
	string path;
	char input1,input2;
	int check=0;
	while (check == 0) {
		cout << ">>>  ���أ�B" << endl;
		cout << ">>>  �ռ��ˣ�";
		cin >> receiver;
		if (receiver == "B") {
			Email_Home(address,password);
			break;
		}
		check = Check_Account(receiver);
		if (check == 0) {
			cout << "�ռ��˵�ַ�����ڣ�" << endl;
		}
		else {
			cout << ">>>  ���⣺";
			cin >> title;
			cout << ">>>  ���ģ�" << endl;
			cin >> content;
			cout << "�Ƿ���Ӹ�����[Y/N]" << endl;
			cin >> input1;
			if (input1=='Y')
			{
				cout << "�����븽��·����";
				cin >> path;
			}
			cout << "ȷ�Ϸ��ͣ�[Y/N]" << endl;
			cin >> input2;
			if (input2 == 'N') {
				Email_Home(address, password);
				break;
			}
			Email_Send(address, receiver, title, content,path);
			Email_Home(address, password);
			break;
		}
	}
}