#pragma once

#include "Bank.h"
#include "Account.h"
#include "Client.h"
#include "PartnerAccount.h"
#include "CreditAccount.h"

class Bank
{
private:
	Client** clients;
	int clientsCount;
	int maxClients;

	Account** accounts;
	int accountsCount;
	int maxAccounts;

public:
	Bank(int c, int a);
	~Bank();

	Client* GetClient(int c);
	Account* GetAccount(int n);

	Client* CreateClient(int c, string n);
	Account* CreateAccount(int n, Client* c);
	Account* CreateAccount(int n, Client* c, double ir);
	PartnerAccount* CreateAccount(int n, Client* c, Client* p);
	PartnerAccount* CreateAccount(int n, Client* c, Client* p, double ir);

	void AddInterest();
	void Print();

	int GetAccountsCount();
};

