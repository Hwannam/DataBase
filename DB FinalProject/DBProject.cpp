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
	cout << "가격 = ~이상 ~이하 >>>";
	cin >> a >> b;
	cout << "무게 = ~이상 ~이하 >>>" ;
	cin >> c >> d;
	cout << endl;
	const char* sql = "Select * from roadbike order by price desc";
	sqlite3_exec(db, sql, print1, 0, &err);
}

void insert(sqlite3* db)
{
	string name, price,weight,frame,fork,gs,wheel,br, com,conum;
	cout << endl << "추가하고 싶은 자전거의 정보를 입력하세요." << endl;
	cout << "이름: ";
	cin >> name;
	cout << "가격: ";
	cin >> price;
	cout << "무게: ";
	cin >> weight;
	cout << "프레임: ";
	cin >> frame;
	cout << "포크: ";
	cin >> fork;
	cout << "그룹셋: ";
	cin >> gs;
	cout << "휠: ";
	cin >> wheel;
	cout << "브레이크: ";
	cin >> br;
	cout << "제조사: ";
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
	cout << "추가가 완료되었습니다!" << endl << endl;
}

void recommand(sqlite3* db)
{
	count1 = 1;
	int num;
	cout << endl <<"원하는 추천 기준은?" << endl << "1.가격   2. 레벨 >>> ";
	cin >> num;
	if (num == 1)
	{
		cout <<endl<< "최대 예산이 얼마인가요?(100만 500만 1000만이상): ";
		cin >> budget;
		cout << endl;

		if (budget == "1000만이상")
		{
			const char* sql = "select r.* from roadbike r, belong b where r.bike_name = b.bike_name and b.reno = 1 order by r.price desc";
			sqlite3_exec(db, sql, print2, 0, &err);
			count1 = 1;
			cout << "------------------이 중에서 가장 추천하는 자전거는-----------------" << endl;
			sql = "select r.* from roadbike r, recommend c where r.bike_name = c.bestbike and c.reno = 1";
			sqlite3_exec(db, sql, print2, 0, &err);
		}
		else if (budget == "500만")
		{
			const char* sql = "select r.* from roadbike r, belong b where r.bike_name = b.bike_name and b.reno = 2 order by r.price desc";
			sqlite3_exec(db, sql, print2, 0, &err);
			count1 = 1;
			cout << "------------------이 중에서 가장 추천하는 자전거는-----------------" << endl;
			sql = "select r.* from roadbike r, recommend c where r.bike_name = c.bestbike and c.reno = 2";
			sqlite3_exec(db, sql, print2, 0, &err);
		}
		else if (budget == "100만")
		{
			const char* sql = "select r.* from roadbike r, belong b where r.bike_name = b.bike_name and b.reno = 3 order by r.price desc";
			sqlite3_exec(db, sql, print2, 0, &err);
			count1 = 1;
			cout << "------------------이 중에서 가장 추천하는 자전거는-----------------" << endl;
			sql = "select r.* from roadbike r, recommend c where r.bike_name = c.bestbike and c.reno = 3";
			sqlite3_exec(db, sql, print2, 0, &err);
		}
	}
	else if (num == 2)
	{
		cout <<endl<< "난이도를 입력해주세요(상급 중급 입문): ";
		cin >> level;
		cout << endl;

		if (level == "상급")
		{
			const char* sql = "select r.* from roadbike r, belong b where r.bike_name = b.bike_name and b.reno = 1 order by r.price desc";
			sqlite3_exec(db, sql, print2, 0, &err);
			count1 = 1;
			cout << "------------------이 중에서 가장 추천하는 자전거는-----------------" << endl;
			sql = "select r.* from roadbike r, recommend c where r.bike_name = c.bestbike and c.reno = 1";
			sqlite3_exec(db, sql, print2, 0, &err);
		}
		else if (level == "중급")
		{
			const char* sql = "select r.* from roadbike r, belong b where r.bike_name = b.bike_name and b.reno = 2 order by r.price desc";
			sqlite3_exec(db, sql, print2, 0, &err);
			count1 = 1;
			cout << "------------------이 중에서 가장 추천하는 자전거는-----------------" << endl;
			sql = "select r.* from roadbike r, recommend c where r.bike_name = c.bestbike and c.reno = 2";
			sqlite3_exec(db, sql, print2, 0, &err);
		}
		else if (level == "입문")
		{
			const char* sql = "select r.* from roadbike r, belong b where r.bike_name = b.bike_name and b.reno = 3 order by r.price desc";
			sqlite3_exec(db, sql, print2, 0, &err);
			count1 = 1;
			cout << "------------------이 중에서 가장 추천하는 자전거는-----------------" << endl;
			sql = "select r.* from roadbike r, recommend c where r.bike_name = c.bestbike and c.reno = 3";
			sqlite3_exec(db, sql, print2, 0, &err);
		}
	}
}

void erase(sqlite3* db)
{
	string name;
	cout << endl << "제거하고 싶은 자전거 이름은?: ";
	cin >> name;
	string sq = "Delete from roadbike where bike_name = '";
	sq = sq + name +"'" ;
	const char* sql = sq.c_str();
	sqlite3_exec(db, sql, 0, 0, &err);
	cout << "제거가 완료되었습니다!" << endl << endl;
}

void update(sqlite3* db)
{
	string name, item,after;
	cout << endl << "수정하고 싶은 자전거 이름은?: ";
	cin >> name;
	cout << "수정하고 싶은 항목은?(이름,가격,무게,프레임,포크,그룹셋,휠,브레이크): ";
	cin >> item;
	cout << "어떤 값으로 바꾸고 싶은가요?: ";
	cin >> after;
	string sq;
	if (item == "이름")
	{
		sq= "Update roadbike set bike_name =";
		sq = sq + "'" + after + "' where bike_name = '" + name + "';";
	}
	else if (item == "가격")
	{
		sq = "Update roadbike set price =";
		sq = sq  + after + " where bike_name = '" + name + "';";
	}
	else if (item == "무게")
	{
		sq = "Update roadbike set weight =";
		sq = sq + after + " where bike_name = '" + name + "';";
	}
	else if (item == "프레임")
	{
		sq = "Update roadbike set frame =";
		sq = sq + "'" + after + "' where bike_name = '" + name + "';";
	}
	else if (item == "포크")
	{
		sq = "Update roadbike set fork =";
		sq = sq + "'" + after + "' where bike_name = '" + name + "';";
	}
	else if (item == "그룹셋")
	{
		sq = "Update roadbike set groupset =";
		sq = sq + "'" + after + "' where bike_name = '" + name + "';";
	}
	else if (item == "휠")
	{
		sq = "Update roadbike set wheel =";
		sq = sq + "'" + after + "' where bike_name = '" + name + "';";
	}
	else if (item == "브레이크")
	{
		sq = "Update roadbike set break =";
		sq = sq + "'" + after + "' where bike_name = '" + name + "';";
	}

	const char* sql = sq.c_str();
	sqlite3_exec(db, sql, 0, 0, &err);
	cout << "수정이 완료되었습니다!" << endl << endl;
}

int main()
{
	sqlite3* db;
	sqlite3_open("roadbike.db", &db);
	
	cout << "Road Bicycle DB에 접속하였습니다." << endl;

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
			cout << "로그인에 성공하였습니다!" << endl;
			break;
		}
		else
			cout << "로그인에 실패하였습니다. 다시 입력해주세요." << endl;
	}

	bool more = true;
	while (more)
	{
		int menu;
		cout << endl << "원하는 메뉴를 선택해주세요." << endl;
		cout << "1. 조건에 맞는 자전거 보기   2. 구매 추천 리스트 보기   3. 자전거 추가   4. 자전거 삭제   5. 정보 수정   6. 종료" << endl;
		cout << "입력 > ";
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
