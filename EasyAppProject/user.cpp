#include "user.h"
// Konstruktor
User::User(int _id, std::string _username, std::string _passoword) :
	id(_id), username(_username), password(_passoword) {}

void User::set_id(int id) { this->id = id; }
void User::set_username(std::string username) { this->username = username; }
void User::set_password(std::string password) { this->password = password; }

int User::get_id() { return this->id; }
std::string User::get_username() { return this->username; }
std::string User::get_password() { return this->password; }