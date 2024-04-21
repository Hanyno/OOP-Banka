#include "CreditAccount.h"

CreditAccount::CreditAccount(int n, Client* o, double c) : Account(n, o)
{
	this->credit = c;
}

CreditAccount::CreditAccount(int n, Client* o, double ir, double c) : Account(n, o, ir)
{
	this->credit = c;
}

bool CreditAccount::CanWithdraw(double a)
{
	return(this->GetBalance() + this->credit >= a);
}

bool CreditAccount::Withdraw(double a)
{
	bool success = false;
	if (this->CanWithdraw(a))
	{
		this->balance -= a;
		success = true;
	}
	return success;
}