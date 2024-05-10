#include "Client.h"
#include "Account.h"
#include "Bank.h"
#include "PartnerAccount.h"
#include "CreditAccount.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	// main pro tema 4,5 a 7
	
	Account* a;
	PartnerAccount* pa;
	CreditAccount* ca;

	Bank* b = new Bank(100, 1000);
	Client* o = b->CreateClient(0, "Smith");
	Client* p = b->CreateClient(1, "Jones");
	a = b->CreateAccount(0, o);
	pa = b->CreateAccount(1, o, p);
	ca = b->CreateAccount(2, p, 0.05, 1000);


	b->Print();

	b->ModifyIr(0.07);

	b->Print();

	//main pro tema 6
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