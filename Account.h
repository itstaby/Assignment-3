#ifndef	ACCOUNT
#define ACCOUNT
#include "Transaction.h"
class Account
{
	private:
		char name[20];
		int accountNumber;
		int interestRate;
		char password[10];
		Transactions *t;
		int transactionNumber;
		int amount;
	public:
		/*********************************************************************************************************/
		void setName();
		/*********************************************************************************************************/
		void setIR();
		/*********************************************************************************************************/
		void setAN();
		void setP();
		/*********************************************************************************************************/
		void withdrawM();
		/*********************************************************************************************************/
		void depositM();
		/*********************************************************************************************************/
		void openM();
		/*********************************************************************************************************/
		void printDetails();
		/*********************************************************************************************************/
		void printTransactionSummary();
		/*********************************************************************************************************/
		void financialPlanning();

		/*********************************************************************************************************/

		friend int searchAccount(Account *a, int& accountCount, int s);

		/*********************************************************************************************************/

		void handleTransaction();
		/*********************************************************************************************************/
		friend void addAccount(Account*a,int& accountCount);
		/*********************************************************************************************************/

		Account();

		friend class Customer;
		friend bool checkRepeat(Account*a,int n, int count);
};

#endif