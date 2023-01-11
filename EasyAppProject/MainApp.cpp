
#include "db_functions.h"


int             qstate;
MYSQL		      conn;
MYSQL_ROW		   row;
MYSQL_RES		   res;

User currUser(1, (std::string)"default", (std::string)"1111");


void create_acc_menu();
void login_menu();
int main()
{
	
	
	if (MOJA_DB_CONNECT(&conn)) 
	{
		char i = 'm';
		while (i != '4')
		{
			
			std::cout << "1. Log in." << std::endl;
			std::cout << "2. Create Account." << std::endl;
			std::cout << "3. Show all users." << std::endl;
			std::cout << "4. Exit." << std::endl;
			std::cin >> i;
			switch (i)
			{
			case '1':
				system("cls");
				login_menu();
				break;
			
			case '2':
				system("cls");
				create_acc_menu();
				break;
			
			case '3':
				system("cls");
				DB_SELECT_ALL_USERS(&conn, qstate, &res, row);
				break;
			}


		}
	}
	else { puts("Connection to database failed !"); }
	

	std::cout << "Da vidim samo : " << currUser.get_username() << std::endl;
	
	//DB_CLOSE(&conn);
	
	return 0;
}
void create_acc_menu() 
{
	std::string username;
	std::string password;
	std::cout << "Enter username" << std::endl;
	std::cin >> username;
	std::cout << "Enter password" << std::endl;
	std::cin >> password;
	currUser.set_password(password); currUser.set_username(username);
	ADD_NEW_USER(currUser.get_username(), currUser.get_password(), &conn, qstate, &res, row);
}

void login_menu() 
{
	std::string username;
	std::string password;
	std::cout << "Enter username" << std::endl;
	std::cin >> username;
	std::cout << "Enter password" << std::endl;
	std::cin >> password;
	USER_EXISTS(username, password, &conn, qstate, &res, row);
	currUser.set_password(password); currUser.set_username(username);
	
}

