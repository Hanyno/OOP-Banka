#include "Account.h"

Account::Account(int n, Client* c)
{
	Account(n, c, nullptr, 0.05);
}

Account::Account(int n, Client* c, double ir)
{
	Account(n, c, nullptr, ir);
}

Account::Account(int n, Client* c, Client* p)
{
	Account(n, c, p, 0.05);
}

Account::Account(int n, Client* c, Client* p, double ir)
{
	this->number = n;
	this->owner = c;
	this->partner = p;
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

Client* Account::GetPartner()
{
	return this->partner;
}

bool Account::CanWithdraw(double a)
{
	if (a <= this->balance)
		return true;

	return false;
}

void Account::Deposit(double a)
{
	this->balance += a;
}

void Account::Withdraw(double a)
{
	if (CanWithdraw(a))
		this->balance -= a;
}

void Account::AddInterest()
{
	this->balance += this->interestRate * this->balance;
}