#include<string>
#include<iostream>
#include "sqlite_operation.h"
#include"Email_operation.h"
#include"mail.h"
#include"Email.h"
/*
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
		Email_write1(address, password);
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
		cout << ">>>  ���أ�B " << endl;
		cout << ">>>  ";
		cin >> input;
		if (input == 'B') {
			break;
		}
	}
}

void Email_write1(string address, string password) {
	string receiver;
	string content;
	string title;
	string path = " ";
	char input;
	int check = 0;
	while (check == 0) {
		cout << ">>>  ���أ�B" << endl;
		cout << ">>>  �ռ��ˣ�";
		cin >> receiver;
		if (receiver == "B") {
			Email_Home(address, password);
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
			cin >> input;
			if (input == 'Y')
			{
				cout << "�����븽��·����";
				cin >> path;
			}
			cout << "ȷ�Ϸ��ͣ�[Y/N]" << endl;
			cin >> input;
			if (input == 'N') {
				continue;
			}
			Email_Send(address, receiver, title, content, path);
			Email_Home(address, password);
		}
	}
}
*/