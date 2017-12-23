

#ifndef TRANSACTION
#define TRANSACTION


class Transactions
{
	private:
		enum {open, withdraw, deposit }type;
		int amount;
	public:
		friend class Account;
	
 
};


#endif