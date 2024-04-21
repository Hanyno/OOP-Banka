#pragma once
#include "Account.h"

class PartnerAccount :
    public Account
{
private:
	Client* partner;

public:
	PartnerAccount(int n, Client* o, Client* p);
	PartnerAccount(int n, Client* o, Client* p, double ir);

	Client* GetPartner();
};