#include "Customer.h"
#include "Account.h"
#include <cstring>

void Customer::setValues(Account a)
{
			strcpy(name,a.name);
			accountNumber=a.accountNumber;
			interestRate=a.interestRate;
			amount=a.amount;
}