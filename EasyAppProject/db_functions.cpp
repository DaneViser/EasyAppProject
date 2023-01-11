#pragma once
#include "db_functions.h"
#include <sstream>
#define HOST "127.0.0.1"
#define USER "root"
#define PASS "password"
#define DATABASE "contact_db"
#define PORT 3306


// Returns true:false if connected to database
bool MOJA_DB_CONNECT(MYSQL* connection)
{
	*connection = *mysql_init(0);
	*connection = *(mysql_real_connect(connection, HOST, USER, PASS, DATABASE, PORT, NULL, 0));
	if (connection) {
		puts("Successful connection to database!");
		return true;

	}
	else {
		puts("Connection to database has failed!");
		return false;
	}

}
// Close connection when no longer using resource 
void DB_CLOSE(MYSQL* connection)
{
	puts("Connection to database closed.");
	mysql_close(connection);
}
// Creates a query
void DB_SELECT_ALL_USERS(MYSQL* conn, int qstate, MYSQL_RES* res, MYSQL_ROW row)
{
		
	std::string query = "SELECT * FROM users";
	const char* q = query.c_str();
	qstate = mysql_query(conn, q);
	
	if (!qstate)
	{
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			printf("ID: %s, Name: %s, Value: %s\n", row[0], row[1], row[2]);
		}
	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
	}
	return;
}
void ADD_NEW_USER(std::string username, std::string password, MYSQL* conn, int qstate, MYSQL_RES* res, MYSQL_ROW row)
{
	std::stringstream stmt;
	stmt.str("");
	stmt << "INSERT INTO users (username, pass) VALUES('" << username << "','" << password << "');";
	std::string query = stmt.str();
	const char *q = query.c_str();
	mysql_query(conn, q);
	res = mysql_store_result(conn);
	
	if ((&res))
		std::cout << std::endl << std::endl << "New user created successfully" << std::endl << std::endl << std::endl;
	else
		std::cout << std::endl << std::endl << "Entry ERROR !" << std::endl << "Contact Technical Team " << std::endl << std::endl << std::endl;
	
}

void USER_EXISTS(std::string username, std::string password, MYSQL* conn, int qstate, MYSQL_RES* res, MYSQL_ROW row) 
{
	std::stringstream stmt;
	stmt.str("");
	stmt << "SELECT * FROM users WHERE username = '" << username << "' and pass = '" << password << "';";
	std::string query = stmt.str();
	const char* q = query.c_str();
	mysql_query(conn, q);

	if (!qstate)
	{
		res = mysql_store_result(conn);
		row = mysql_fetch_row(res);
		if (row == NULL)
			std::cout << "NO USER FOUND !" << std::endl;
		else 
			printf("ID: %s, Name: %s, Value: %s\n", row[0], row[1], row[2]);

		while (row = mysql_fetch_row(res))
		{
			printf("ID: %s, Name: %s, Value: %s\n", row[0], row[1], row[2]);
		}
	}
	else
	{
		std::cout << "Query failed: " << mysql_error(conn) << std::endl;
	}
	
}

