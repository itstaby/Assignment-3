#ifndef CUSTOMER
#define CUSTOMER

#include "Transaction.h"


class Customer
{	
	private:
		char name[20];
		int accountNumber;
		int interestRate;
		int amount;
	public:
		//void setValues(char *name, int accountNumber, int interestRate, int amount);
		void setValues(Account);
		friend void printCustomer(Customer *c,int count);
	
};

#endif