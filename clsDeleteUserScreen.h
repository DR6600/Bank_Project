#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteUserScreen :protected clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";
	}

	static string _GetDeletableUserName()
	{
		string UserName = clsInputValidate::ReadString();

		if (UserName == "Admin")
		{
			cout << "\nYou cannot Delete This User, choose another one: ";
			_GetDeletableUserName();
		}

		if (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is not found, choose another one: ";
			_GetDeletableUserName();
		}
		return UserName;
	}

public:

	static void ShowDeleteUserScreen()
	{
		char Answer = 'n';

		_DrawScreenHeader("\tDelete User Screen");

		cout << "\nPlease Enter UserName: ";
		string UserName = _GetDeletableUserName();

		clsUser User1 = clsUser::Find(UserName);
		_PrintUser(User1);

		cout << "\nAre you sure you want to delete this User y/n? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (User1.Delete())
			{
				cout << "\nUser Deleted Successfully :-)\n";
				_PrintUser(User1);
			}
			else
			{
				cout << "\nError User Was not Deleted\n";
			}
		}
	}
};