#include "contacts.h"

// Konstrutkor
Contacts::Contacts(int _id, int _user_id, std::string _name, std::string _phone_number) :
					id(_id), user_id(_user_id), name(_name), phone_number(_phone_number) {}

void Contacts::set_id(int id) { this->id = id; }
void Contacts::set_user_id(int user_id) { this->user_id = user_id; }
void Contacts::set_name(std::string name) { this->name = name; }
void Contacts::set_phone_number(std::string phone_number) { this->phone_number = phone_number; }

int Contacts::get_id() { return this->id; }
int Contacts::get_user_id() { return this->user_id; }
std::string Contacts::get_name() { return this->name; }
std::string Contacts::get_phone_number() { return this->phone_number; }