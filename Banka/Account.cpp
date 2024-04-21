#include "Account.h"

Account::Account(int n, Client* c)
{
	Account(n, c, 0.05);
}

Account::Account(int n, Client* c, double ir)
{
	this->number = n;
	this->owner = c;
	this->interestRate = ir;
	this->balance = 0;
}

int Account::GetNumber()
{
	return this->number;
}

double Account::GetBalance()
{
	return this->balance;
}

double Account::GetInterestRate()
{
	return this->interestRate;
}

Client* Account::GetOwner()
{
	return this->owner;
}

bool Account::CanWithdraw(double a)
{
	return (this->balance >= a);
}

void Account::Deposit(double a)
{
	this->balance += a;
}

bool Account::Withdraw(double a)
{
	bool succes = false;
	if (this->CanWithdraw(a))
	{
		this->balance -= a;
		succes = true;
	}
	return succes;
}

void Account::AddInterest()
{
	this->balance += this->interestRate * this->balance;
}