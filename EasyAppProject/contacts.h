#pragma once
#include <string>
class Contacts
{
	public:
		Contacts(int, int, std::string, std::string);

		void set_id(int id);
		void set_user_id(int user_id);
		void set_name(std::string name);
		void set_phone_number(std::string phone_number);
		int get_id();
		int get_user_id();
		std::string get_name();
		std::string get_phone_number();

	private:
		int id;
		int user_id;
		std::string name;
		std::string phone_number;


};