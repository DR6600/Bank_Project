#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFaild = false;
		string Username, Password;
		short FailedLoginCounter = 0;

		do
		{
			if (LoginFaild)
			{
				FailedLoginCounter++;

				cout << "\nInvlaid Username/Password!\n\n";
				cout << "You have " << 3 - FailedLoginCounter << " attempts left.\n";
			}
			if (FailedLoginCounter >= 3)
			{
				cout << "You have exceeded the maximum number of attempts. Exiting...\n";
				return false;
			}
			cout << "Enter Username? ";
			cin >> Username;
			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFaild = CurrentUser.IsEmpty();
		}
		while (LoginFaild);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();

		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}
};