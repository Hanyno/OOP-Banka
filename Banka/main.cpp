#include "Client.h"
#include "Account.h"
#include "Bank.h"
#include "PartnerAccount.h"
#include "CreditAccount.h"

#include <iostream>

using namespace std;

int main()
{
	Account* a;
	PartnerAccount* pa;

	Bank* b = new Bank(100, 1000);
	Client* o = b->CreateClient(0, "Smith");
	Client* p = b->CreateClient(1, "Jones");
	a = b->CreateAccount(0, o);
	pa = b->CreateAccount(1, o, p);

	cout << a->GetOwner()->GetName() << endl;
	cout << pa->GetPartner()->GetName() << endl;

	cout << b->GetClient(1)->GetName() << endl;

	b->Print();

	/*
	Client* o = new Client(0, "Smith");
	CreditAccount* ca = new CreditAccount(1, o, 1000);

	cout << ca->CanWithdraw(1000) << endl;

	Account* a = ca;

	cout << a->CanWithdraw(1000) << endl;
	cout << ca->CanWithdraw(1000) << endl;

	a = nullptr;
	delete ca;
	*/

	return 0;
}