#pragma once
#include <string>
class User 
{
	public:
		// Konstrutkor
		User(int id, std::string, std::string);
		void set_id(int id);
		void set_username(std::string username);
		void set_password(std::string password);
		int get_id();
		std::string get_username();
		std::string get_password();
	private:	
		int				  id;
		std::string username;
		std::string password;
};