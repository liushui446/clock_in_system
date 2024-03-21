#include "as/UserImpl.hpp"
#include <as/sqlite3.hpp>

namespace as
{
	UserImpl::UserImpl()
	{
	}

	void UserImpl::GetItem()
	{
		char* cErrMsg = NULL, ** dbResult = nullptr;
		string sql_1;
		string sql_2;
		string sql_3;
		int nRow = 0, nColumn = 0;

		sql_1 = fmt::format("select * from UserPassword");
		try
		{
			int res = sqlite3_get_table(as::UserDBUtils::Getinstance().getsqlite(), sql_1.c_str(), &dbResult, &nRow, &nColumn, &cErrMsg);
			if (res != SQLITE_OK)
			{
				std::cout << "UserPassword select fail" << (cErrMsg ? cErrMsg : "0 count") << endl;
				as::UserDBUtils::Getinstance().free();
			}
		}
		catch (...)
		{
			throw nullptr;
		}

		int index = nColumn-1;
		ASContext* level = &ASContext::GetInstance();
		for (int row = 0; row < nRow; row++)
		{
			User tmp_user;
			if (dbResult[index] == "Teacher")
			{
				tmp_user.setUserType(UserType::Teacher);
				tmp_user.setUsername(dbResult[index - 1]);
				tmp_user.setPassword(dbResult[index + 1]);
				level->GetUserManagedata()->InsertUserParam(tmp_user.getUserType(), dbResult[index - 1], tmp_user);
			}
			else if (dbResult[index] == "Student")
			{
				tmp_user.setUserType(UserType::Student);
				tmp_user.setUsername(dbResult[index - 1]);
				tmp_user.setPassword(dbResult[index + 1]);
				level->GetUserManagedata()->InsertUserParam(tmp_user.getUserType(), dbResult[index - 1], tmp_user);
			}
		}
		sqlite3_free_table(dbResult);
	}

	
	bool UserImpl::UpdateItem()
	{
		ASContext* level = &ASContext::GetInstance();
		auto data = level->GetUserManagedata()->GetuserDataRes();
		string type;
		char* cErrMsg = NULL;
		string sql;
		int res = SQLITE_OK;
		try
		{
			for (auto it = data.find(UserType::Teacher)->second.begin(); it != data.find(UserType::Teacher)->second.end(); it++)
			{
				type = "Teacher";
				sql = fmt::format("update UserPassword set USER_TYPE ='{1}', USER_PASSWORD = '{2}' where USER_Name = '{0}';", \
					it->second.getUsername(), type, it->second.getPassword());
				
				res = sqlite3_exec(UserDBUtils::Getinstance().getsqlite(), sql.c_str(), 0, 0, &cErrMsg);
				if (res != SQLITE_OK)
				{
					std::cout << it->second.getUsername() << "--" << "User Update Fail" << (cErrMsg ? cErrMsg : "0 count") << endl;
					as::UserDBUtils::Getinstance().free();
					return false;
				}
			}
			for (auto it = data.find(UserType::Student)->second.begin(); it != data.find(UserType::Student)->second.end(); it++)
			{
				type = "Student";
				sql = fmt::format("update UserPassword set USER_TYPE ='{1}', USER_PASSWORD = '{2}' where USER_Name = '{0}';", \
					it->second.getUsername(), type, it->second.getPassword());
				
				res = sqlite3_exec(UserDBUtils::Getinstance().getsqlite(), sql.c_str(), 0, 0, &cErrMsg);
				if (res != SQLITE_OK)
				{
					std::cout << it->second.getUsername() << "--" << "User Update Fail" << (cErrMsg ? cErrMsg : "0 count") << endl;
					as::UserDBUtils::Getinstance().free();
					return false;
				}
			}
		}
		catch (...)
		{
			return false;
		}
		
		as::UserDBUtils::Getinstance().free();
		return true;
	}

	void UserImpl::DeleteItem()
	{

	}

	void UserImpl::AddItem()
	{

	}

}