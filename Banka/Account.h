#pragma once

#include "Client.h"

class Account
{
private:
	int number;
	double interestRate;

	Client* owner;

protected:
	double balance;

public:
	Account(int n, Client* c);
	Account(int n, Client* c, double ir);

	int GetNumber();
	double GetBalance();
	double GetInterestRate();
	Client* GetOwner();
	bool CanWithdraw(double a);

	void Deposit(double a);
	bool Withdraw(double a);
	void AddInterest();
};

