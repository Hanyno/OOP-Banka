#pragma once

#include "Client.h"

class Account
{
private:
	static int objectCount;
	int number;
	double interestRate;

	Client* owner;

protected:
	double balance;

public:
	Account(int n, Client* c);
	Account(int n, Client* c, double ir);
	~Account();

	int GetNumber();
	double GetBalance();
	double GetInterestRate();
	Client* GetOwner();
	bool CanWithdraw(double a);
	void SetInterestRate(double ir);

	void Deposit(double a);
	bool Withdraw(double a);
	void AddInterest();

	int GetNumOfObj();
};

