#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsPerson.h"
#include "clsBankClient.h"

using namespace std;

class clsTransferScreen :protected clsScreen
{
private:

	static void _PrintClient(clsBankClient& Client)
	{
		cout << "Client Card\n";
		cout << "\n------------------------\n";
		cout << "\nFull Name: " << Client.FullName();
		cout << "\nAccount Number: " << Client.AccountNumber();
		cout << "\nBalance: " << Client.AccountBalance;
		cout << "\n------------------------\n";
	}

	static string _ReadAccountNumber(string Prompt)
	{
		string AccountNumber = "";
		cout << Prompt;
		cin >> AccountNumber;
		return AccountNumber;
	}

	static double _ReadAmount(clsBankClient& SourceClient)
	{
		cout << "\nEnter Transfer Amount: ";
		double Amount = clsInputValidate::ReadNumber<double>();

		while (Amount <= 0 || Amount > SourceClient.AccountBalance)
		{
			cout << "\nInvalid amount, please enter a valid amount: ";
			Amount = clsInputValidate::ReadNumber<double>();
		}
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{

		_DrawScreenHeader("\tTransfer Screen");

		string SourceAccountNumber = _ReadAccountNumber("\nPlease enter account number to transfer from : ");
		while (!clsBankClient::IsClientExist(SourceAccountNumber))
		{
			cout << "\nClient with [" << SourceAccountNumber << "] does not exist.\n";
			SourceAccountNumber = _ReadAccountNumber("\nPlease enter account number to transfer from : ");
		}
		clsBankClient SourceClient = clsBankClient::Find(SourceAccountNumber);
		_PrintClient(SourceClient);

		string DestinationAccountNumber = _ReadAccountNumber("\nPlease enter account number to transfer to : ");
		while (!clsBankClient::IsClientExist(DestinationAccountNumber))
		{
			cout << "\nClient with [" << DestinationAccountNumber << "] does not exist.\n";
			DestinationAccountNumber = _ReadAccountNumber("\nPlease enter account number to transfer to : ");
		}
		clsBankClient DestinationClient = clsBankClient::Find(DestinationAccountNumber);
		_PrintClient(DestinationClient);

		if (SourceClient.AccountNumber() == DestinationClient.AccountNumber())
		{
			cout << "\nYou cannot transfer to the same account.\n";
			system("pause>0");
			system("cls");
			ShowTransferScreen();
		}

		double Amount = _ReadAmount(SourceClient);

		char Answer = 'N';
		cout << "\nAre you sure you want to perform this operation? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully.\n";
			}
			else
			{
				cout << "\nTransfer failed. Please try again.\n";
			}
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};