#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsManageBankClientsScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsTransferLogScreen.h"
#include "Global.h"

using namespace std;

class clsMainScreen :protected clsScreen
{
private:

	enum enMainMenueOptions {eTransactionsMenue = 1, eBankClientsMenue = 2, eManageUsers = 3, eLoginRegister = 4, eTransferLog = 5, eExit = 6};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		return clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter Number between 1 to 6? ");
	}

	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}

	static void _ShowTransactionsMenue()
	{
		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowBankClientsMenue()
	{
		clsManageBankClientsScreen::ShowBankClientsMenue();
	}

	static void _ShowManageUsersMenue()
	{
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	static void ShowLoginRegisterMenue()
	{
		system("cls");
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void ShowTransferLogMenue()
	{
		system("cls");
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}


	static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOptions::eTransactionsMenue:
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eBankClientsMenue:
			system("cls");
			_ShowBankClientsMenue();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eManageUsers:
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eLoginRegister:
			system("cls");
			ShowLoginRegisterMenue();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eTransferLog:
			system("cls");
			ShowTransferLogMenue();
			_GoBackToMainMenue();
			break;

		case enMainMenueOptions::eExit:
			system("cls");
			_Logout();
			break;
		}
	}
public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Transactions Menue.\n";
		cout << setw(37) << left << "" << "\t[2] Bank Clients Menue.\n";
		cout << setw(37) << left << "" << "\t[3] Manage Users Menue.\n";
		cout << setw(37) << left << "" << "\t[4] Login Register Menue.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log Menue.\n";
		cout << setw(37) << left << "" << "\t[6] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
	}
};