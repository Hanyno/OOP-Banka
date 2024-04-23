#include "Bank.h"
#include "Account.h"
#include "Client.h"
#include "PartnerAccount.h"
#include "CreditAccount.h"

#include <iostream>

double Bank::ir = 0.05;

Bank::Bank(int c, int a)
{
	this->maxClients = c;
	this->maxAccounts = a;
	this->clientsCount = 0;
	this->accountsCount = 0;
	this->clients = new Client * [c];
	this->accounts = new Account * [a];
}

Bank::~Bank()
{
	for (int i = 0; i < this->clientsCount; i++)
	{
		delete this->clients[i];
	}

	for (int i = 0; i < this->accountsCount; i++)
	{
		delete this->accounts[i];
	}

	delete[] this->clients;
	delete[] this->accounts;

}

Client* Bank::GetClient(int c)
{
	for (int i = 0; i < this->clientsCount; i++)
	{
		if (this->clients[i]->GetCode() == c)
			return this->clients[i];
	}
	return nullptr;
}

Account* Bank::GetAccount(int n)
{
	for (int i = 0; i < this->accountsCount; i++)
	{
		if (this->accounts[i]->GetNumber() == n)
			return this->accounts[i];
	}
	return nullptr;
}

Client* Bank::CreateClient(int c, string n)
{
	if (this->clientsCount > this->maxClients)
		return nullptr;

	Client* newClient = new Client(c, n);

	this->clients[this->clientsCount] = newClient;
	this->clientsCount++;
	return newClient;
}

Account* Bank::CreateAccount(int n, Client* c)
{
	return CreateAccount(n, c, nullptr, 0.05);
}

Account* Bank::CreateAccount(int n, Client* c, double ir)
{
	return CreateAccount(n, c, nullptr, ir);
}

PartnerAccount* Bank::CreateAccount(int n, Client* c, Client* p)
{
	return CreateAccount(n, c, p, 0.05);
}

PartnerAccount* Bank::CreateAccount(int n, Client* c, Client* p, double ir)
{
	if (this->accountsCount > this->maxAccounts)
		return nullptr;

	PartnerAccount* newAccount = new PartnerAccount(n, c, p, ir);

	this->accounts[this->accountsCount] = newAccount;
	this->accountsCount++;
	return newAccount;
}

void Bank::AddInterest()
{
	for (int i = 0; i < this->accountsCount; i++)
	{
		this->accounts[i]->AddInterest();
	}
}

void Bank::Print()
{
	cout << "Clients:" << endl;
	for (int i = 0; i < this->clientsCount; i++)
	{
		cout << "Code: " << this->clients[i]->GetCode() << "\t" << "Name: " << this->clients[i]->GetName() << endl;
	}

	cout << endl;

	cout << "Accounts:" << endl;
	for (int i = 0; i < this->accountsCount; i++)
	{
		cout << "Number: " << this->accounts[i]->GetNumber() << endl;
		cout << "Balance: " << this->accounts[i]->GetBalance() << endl;
		cout << "Interest rate: " << this->accounts[i]->GetInterestRate() << endl;
		cout << "Owner: " << this->accounts[i]->GetOwner()->GetName() << endl;
		cout << endl;
	}
}


int Bank::GetAccountsCount()
{
	return this->accountsCount;
}

void Bank::ModifyIr(int new_ir)
{
	for (int i = 0; i < this->GetAccountsCount(); i++)
	{
		if (this->GetAccount(i)->GetInterestRate() == this->ir)
		{
			this->GetAccount(i)->SetInterestRate(new_ir);
		}
	}
	this->ir = new_ir;
}