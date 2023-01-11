#pragma once
#include <mysql.h>
#include <iostream>
#include "user.h"
#include "contacts.h"

bool MOJA_DB_CONNECT(MYSQL*);
void DB_CLOSE(MYSQL*);
void DB_SELECT_ALL_USERS(MYSQL*, int, MYSQL_RES*, MYSQL_ROW);
void ADD_NEW_USER(std::string, std::string, MYSQL*, int, MYSQL_RES*, MYSQL_ROW);
void USER_EXISTS(std::string, std::string, MYSQL*, int, MYSQL_RES*, MYSQL_ROW);
