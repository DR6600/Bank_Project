#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;

class clsLoginRegisterScreen :protected clsScreen
{
private:

	static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << left << setw(40) << LoginRegisterRecord.DateTime;
		cout << "| " << left << setw(20) << LoginRegisterRecord.UserName;
		cout << "| " << left << setw(20)<< LoginRegisterRecord.Permissions;
	}

public:

	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;// this will exit the function and it will not continue
		}
		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		_DrawScreenHeader("\tLogin Register List Screen", "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).");

		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(40) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Permissions";
		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n" << endl;

		if (vLoginRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";

		else
			for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
			{
				PrintLoginRegisterRecordLine(Record);
				cout << endl;
			}
		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n" << endl;
	}
};

