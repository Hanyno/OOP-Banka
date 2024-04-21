#include "Client.h"
#include "Account.h"
#include "Bank.h"

using namespace std;

int main()
{
	int maxClients = 10;
	int maxAccounts = 10;

	string names[10] = { "Pepa", "Franta", "Honza", "Karel", "Jakub", "Karolina", "Adela", "Vendula", "Jana", "Zaneta" };

	Bank* myBank = new Bank(maxClients, maxAccounts);

	for (int i = 0; i < maxClients; i++)
	{
		myBank->CreateClient(i + 1, names[i]);
	}

	myBank->CreateAccount(1, myBank->GetClient(1));
	myBank->CreateAccount(2, myBank->GetClient(2), 0.07);
	myBank->CreateAccount(3, myBank->GetClient(3), myBank->GetClient(1));
	myBank->CreateAccount(4, myBank->GetClient(4), myBank->GetClient(2), 0.10);

	for (int i = 5; i <= 10; i++)
	{
		myBank->CreateAccount(i, myBank->GetClient(i));
	}

	myBank->Print();

	for (int i = 1; i <= myBank->GetAccountsCount(); i++)
	{
		myBank->GetAccount(i)->Deposit(10000);
	}

	myBank->GetAccount(10)->Withdraw(5000);

	myBank->Print();

	myBank->AddInterest();

	myBank->Print();

	return 0;
}