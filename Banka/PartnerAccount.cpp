#include "PartnerAccount.h"
#include "Account.h"

#include <iostream>

PartnerAccount::PartnerAccount(int n, Client* o, Client* p) : Account(n, o)
{
	this->partner = p;
	cout << "Kontruktor PAcc zavol�n" << endl;
}

PartnerAccount::PartnerAccount(int n, Client* o, Client* p, double ir) : Account(n, o, ir)
{
	this->partner = p;
	cout << "Kontruktor PAcc zavol�n" << endl;
}

PartnerAccount::~PartnerAccount()
{
	cout << "�Destruktor PAcc zavol�n" << endl;
}

Client* PartnerAccount::GetPartner()
{
	return this->partner;
}