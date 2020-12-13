#pragma comment(lib,"sqlite3.lib")
#include "sqlite3.h"
#include <iostream>
#include <string>
using namespace std;
char* err = 0;
string GID;
string GPW;
string level;
string budget;
bool ck = true;
int a,b,c,d;
int count1;

int check(void* NotUsed, int argc, char** argv, char** azColName)
{
	NotUsed = 0;
	if (argv[0] == GID && argv[1] == GPW)
		ck = true;
	else
		ck = false;

	return 0;
}

int print1(void* NotUsed, int argc, char** argv, char**azColName)
{
	NotUsed = 0;

	if (stoi(argv[1]) >= a && stoi(argv[1]) <= b && stoi(argv[2]) >= c && stoi(argv[2]) <= d)
	{
		cout << "<" << count1 << ">" << endl;
		for (int i = 0; i < argc; i++)
		{
			cout <<azColName[i] << " = " << argv[i] << endl;
		}
		cout << endl;
		count1++;
	}
	return 0;
}

int print2(void* NotUsed, int argc, char** argv, char** azColName)
{
	NotUsed = 0;
	cout << "<" << count1 << ">" << endl;
	for (int i = 0; i < argc; i++)
	{
		cout << azColName[i] << " = " << argv[i] << endl;
	}
	cout << endl;
	count1++;
	return 0;
}

void want(sqlite3* db)
{
	count1 = 1;
	cout << "���� = ~�̻� ~���� >>>";
	cin >> a >> b;
	cout << "���� = ~�̻� ~���� >>>" ;
	cin >> c >> d;
	cout << endl;
	const char* sql = "Select * from roadbike order by price desc";
	sqlite3_exec(db, sql, print1, 0, &err);
}

void insert(sqlite3* db)
{
	string name, price,weight,frame,fork,gs,wheel,br, com,conum;
	cout << endl << "�߰��ϰ� ���� �������� ������ �Է��ϼ���." << endl;
	cout << "�̸�: ";
	cin >> name;
	cout << "����: ";
	cin >> price;
	cout << "����: ";
	cin >> weight;
	cout << "������: ";
	cin >> frame;
	cout << "��ũ: ";
	cin >> fork;
	cout << "�׷��: ";
	cin >> gs;
	cout << "��: ";
	cin >> wheel;
	cout << "�극��ũ: ";
	cin >> br;
	cout << "������: ";
	cin >> com;
	if (com == "Trek")
		conum = '1';
	else if (com == "Merida")
		conum = '2';
	else if (com == "Cello")
		conum = '3';

	string sq = "Insert into roadbike values('";
	sq = sq + name + "', " + " " +price + ", " + " " + weight + ", " + "'" + frame + "', " + "'" + fork + "', " + "'" + gs + "', " + "'" + wheel + "', " + "'" + br + "' ,"+ conum +");";
	const char* sql = sq.c_str();
	sqlite3_exec(db, sql, 0, 0, &err);
	cout << "�߰��� �Ϸ�Ǿ����ϴ�!" << endl << endl;
}

void recommand(sqlite3* db)
{
	count1 = 1;
	int num;
	cout << endl <<"���ϴ� ��õ ������?" << endl << "1.����   2. ���� >>> ";
	cin >> num;
	if (num == 1)
	{
		cout <<endl<< "�ִ� ������ ���ΰ���?(100�� 500�� 1000���̻�): ";
		cin >> budget;
		cout << endl;

		if (budget == "1000���̻�")
		{
			const char* sql = "select r.* from roadbike r, belong b where r.bike_name = b.bike_name and b.reno = 1 order by r.price desc";
			sqlite3_exec(db, sql, print2, 0, &err);
			count1 = 1;
			cout << "------------------�� �߿��� ���� ��õ�ϴ� �����Ŵ�-----------------" << endl;
			sql = "select r.* from roadbike r, recommend c where r.bike_name = c.bestbike and c.reno = 1";
			sqlite3_exec(db, sql, print2, 0, &err);
		}
		else if (budget == "500��")
		{
			const char* sql = "select r.* from roadbike r, belong b where r.bike_name = b.bike_name and b.reno = 2 order by r.price desc";
			sqlite3_exec(db, sql, print2, 0, &err);
			count1 = 1;
			cout << "------------------�� �߿��� ���� ��õ�ϴ� �����Ŵ�-----------------" << endl;
			sql = "select r.* from roadbike r, recommend c where r.bike_name = c.bestbike and c.reno = 2";
			sqlite3_exec(db, sql, print2, 0, &err);
		}
		else if (budget == "100��")
		{
			const char* sql = "select r.* from roadbike r, belong b where r.bike_name = b.bike_name and b.reno = 3 order by r.price desc";
			sqlite3_exec(db, sql, print2, 0, &err);
			count1 = 1;
			cout << "------------------�� �߿��� ���� ��õ�ϴ� �����Ŵ�-----------------" << endl;
			sql = "select r.* from roadbike r, recommend c where r.bike_name = c.bestbike and c.reno = 3";
			sqlite3_exec(db, sql, print2, 0, &err);
		}
	}
	else if (num == 2)
	{
		cout <<endl<< "���̵��� �Է����ּ���(��� �߱� �Թ�): ";
		cin >> level;
		cout << endl;

		if (level == "���")
		{
			const char* sql = "select r.* from roadbike r, belong b where r.bike_name = b.bike_name and b.reno = 1 order by r.price desc";
			sqlite3_exec(db, sql, print2, 0, &err);
			count1 = 1;
			cout << "------------------�� �߿��� ���� ��õ�ϴ� �����Ŵ�-----------------" << endl;
			sql = "select r.* from roadbike r, recommend c where r.bike_name = c.bestbike and c.reno = 1";
			sqlite3_exec(db, sql, print2, 0, &err);
		}
		else if (level == "�߱�")
		{
			const char* sql = "select r.* from roadbike r, belong b where r.bike_name = b.bike_name and b.reno = 2 order by r.price desc";
			sqlite3_exec(db, sql, print2, 0, &err);
			count1 = 1;
			cout << "------------------�� �߿��� ���� ��õ�ϴ� �����Ŵ�-----------------" << endl;
			sql = "select r.* from roadbike r, recommend c where r.bike_name = c.bestbike and c.reno = 2";
			sqlite3_exec(db, sql, print2, 0, &err);
		}
		else if (level == "�Թ�")
		{
			const char* sql = "select r.* from roadbike r, belong b where r.bike_name = b.bike_name and b.reno = 3 order by r.price desc";
			sqlite3_exec(db, sql, print2, 0, &err);
			count1 = 1;
			cout << "------------------�� �߿��� ���� ��õ�ϴ� �����Ŵ�-----------------" << endl;
			sql = "select r.* from roadbike r, recommend c where r.bike_name = c.bestbike and c.reno = 3";
			sqlite3_exec(db, sql, print2, 0, &err);
		}
	}
}

void erase(sqlite3* db)
{
	string name;
	cout << endl << "�����ϰ� ���� ������ �̸���?: ";
	cin >> name;
	string sq = "Delete from roadbike where bike_name = '";
	sq = sq + name +"'" ;
	const char* sql = sq.c_str();
	sqlite3_exec(db, sql, 0, 0, &err);
	cout << "���Ű� �Ϸ�Ǿ����ϴ�!" << endl << endl;
}

void update(sqlite3* db)
{
	string name, item,after;
	cout << endl << "�����ϰ� ���� ������ �̸���?: ";
	cin >> name;
	cout << "�����ϰ� ���� �׸���?(�̸�,����,����,������,��ũ,�׷��,��,�극��ũ): ";
	cin >> item;
	cout << "� ������ �ٲٰ� ��������?: ";
	cin >> after;
	string sq;
	if (item == "�̸�")
	{
		sq= "Update roadbike set bike_name =";
		sq = sq + "'" + after + "' where bike_name = '" + name + "';";
	}
	else if (item == "����")
	{
		sq = "Update roadbike set price =";
		sq = sq  + after + " where bike_name = '" + name + "';";
	}
	else if (item == "����")
	{
		sq = "Update roadbike set weight =";
		sq = sq + after + " where bike_name = '" + name + "';";
	}
	else if (item == "������")
	{
		sq = "Update roadbike set frame =";
		sq = sq + "'" + after + "' where bike_name = '" + name + "';";
	}
	else if (item == "��ũ")
	{
		sq = "Update roadbike set fork =";
		sq = sq + "'" + after + "' where bike_name = '" + name + "';";
	}
	else if (item == "�׷��")
	{
		sq = "Update roadbike set groupset =";
		sq = sq + "'" + after + "' where bike_name = '" + name + "';";
	}
	else if (item == "��")
	{
		sq = "Update roadbike set wheel =";
		sq = sq + "'" + after + "' where bike_name = '" + name + "';";
	}
	else if (item == "�극��ũ")
	{
		sq = "Update roadbike set break =";
		sq = sq + "'" + after + "' where bike_name = '" + name + "';";
	}

	const char* sql = sq.c_str();
	sqlite3_exec(db, sql, 0, 0, &err);
	cout << "������ �Ϸ�Ǿ����ϴ�!" << endl << endl;
}

int main()
{
	sqlite3* db;
	sqlite3_open("roadbike.db", &db);
	
	cout << "Road Bicycle DB�� �����Ͽ����ϴ�." << endl;

	while (1)
	{
		string id, pw;
		cout << "ID: ";
		cin >> id;
		cout << "PW: ";
		cin >> pw;
		GID = id;
		GPW = pw;

		const char* sql = "Select * from ad";
		sqlite3_exec(db, sql, check, 0, &err);

		if (ck == true)
		{
			cout << "�α��ο� �����Ͽ����ϴ�!" << endl;
			break;
		}
		else
			cout << "�α��ο� �����Ͽ����ϴ�. �ٽ� �Է����ּ���." << endl;
	}

	bool more = true;
	while (more)
	{
		int menu;
		cout << endl << "���ϴ� �޴��� �������ּ���." << endl;
		cout << "1. ���ǿ� �´� ������ ����   2. ���� ��õ ����Ʈ ����   3. ������ �߰�   4. ������ ����   5. ���� ����   6. ����" << endl;
		cout << "�Է� > ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			want(db);
			break;
		case 2:
			recommand(db);
			break;
		case 3: 
			insert(db);
			break;
		case 4:
			erase(db);
			break;
		case 5:
			update(db);
			break;
		case 6:
			more = false;
			break;
		}
	}

	sqlite3_close(db);
	return 0;
}
