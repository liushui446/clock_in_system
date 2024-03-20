#ifndef AS_PADCORE_HPP
#define AS_PADCORE_HPP
#include "as/CommonCore.hpp"

namespace as
{
	class User;
}

namespace as
{
	enum class UserType
	{
		Student = 0, 
		Teacher
	};

	class AS_EXPORTS User
	{
	public:
		User();

		User& operator=(User& ref);

		string getUsername();
		void setUsername(string name);

		string getPassword();
		void setPassword(string pwd);

		UserType getUserType();
		void setUserType(UserType type);

	private:
		string username;
		string password;
		UserType userType;
	};

	class AS_EXPORTS UserManage
	{
	public:
		UserManage();

		map<string, map<string, User>>& GetuserDataRes();
		bool FindUserType(string type);
		bool FindUsername(string type, string name);
		map<string, User>& GetUserTypeParam(string type);
		User& GetUserParam(string type, string name);
		//void InsertUserTypeParam(string name, User param);
		void InsertUserParam(string type, string name, User param);
	private:
		map<string, map<string, User>> userDatabase;
	};
}

#endif