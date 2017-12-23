#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "Account.h"
#include "Customer.h"

using namespace std;


/**************************************************************************************************************************************/

void header();
void cursor(char CharacterEntered, int& selection, int limit);
void printDetails(Account*,int);

void color(int x)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle,x);
}
bool checkRepeat(Account*a,int n, int count)
{
	for(int i=0; i<count; i++)
	{
		if(a[i].accountNumber==n)
			return true;
	}
	return false;
}
void addAccount(Account*a,int& accountCount)
{
	header();

	a[accountCount].setName();
	int check=0;
	while(check==0)
	{	
		a[accountCount].setAN();
		if(checkRepeat(a,a[accountCount].accountNumber,accountCount))
		{
			cout<<"The Account Number is already taken, please choose another number.\n";
		}
		else check=1;

	}
	a[accountCount].setIR();
	//a[accountCount].setP();
	a[accountCount].openM();

}


/*************************************************************************************************************************************/
int searchAccount(Account *a, int& accountCount, int s)
{
	if(accountCount!=0)
	{
		int n,c=0;
		header();
		cout<<"Enter the Account Number: ";
		cin>>n;
		for (int i=0; i<accountCount; i++)
		{
			if(n==a[i].accountNumber)
			{
				/*char p[10];
				cout<<"\nThe password is: "<<a[i].password<<endl; 
				cout<<"Enter password: ";

				for(int i=0; i<10; i++)
				{
					p[i]=getch();
					if(p[i]=='\r')
					{
						p[i]='\0';
						break;
					}
					cout<<"*";
				}

				cout<<"Password entered is: "<<p<<endl;

				for(int j=0; a[i].password[j]!='\0' && p[j]!='\0' ; j++)
				{
					cout<<(int)a[j].password<<endl<<(int)p[j]<<endl;
					if((int)a[i].password[j]!=(int)p[j])
					{
						cout<<"Characters did not match!";
						getch();
						return 0;
					}
				}*/
				header();
				cout<<"The following customer is now being handled:\n";
				a[i].printDetails();
				c=1;
				if(s==1)
					a[i].handleTransaction();
				else if(s==2)
					a[i].financialPlanning();

			}

		}
		if(c!=1)
		{
			cout<<"\nNo result found for the given account number!\nPress any key to return to the main menu.";
			getch();
		}
	}
	else
	{
		cout<<"\nThere is no Account in the database of the bank.\nPress any key to return to the main menu.\n";
		getch();
	}

	return 0;
}
/**************************************************************************************************************************************/




void printCustomer(Customer* c, int count)
{

	header();
	
	if(count==0)
	{
		cout<<"\n\nThere are no users currently registered to the database of the bank!\n";
	}
	else
	{
		cout<<"We have the following customers of our bank:\n";
		
		for(int i=0; i<count; i++)
		{
			cout<<"Customer "<<i+1<<":\n";
			cout<<"\n\nAccount Holder's Name: "<<c[i].name<<endl;
			cout<<"Account Number: "<<c[i].accountNumber<<endl;
			cout<<"Current Balance: "<<c[i].amount<<endl;
			cout<<"Interest Rate: "<<c[i].interestRate<<"%"<<endl<<endl;
		}
	}
	cout<<"Press any key to go back to the main menu.";
	getch();

}


/*************************************************************************************************************************************/





void header()
{
	system("cls");
	for(int i=0;i<80;i++)
		cout<<"*";
	cout<<"* * * * * * * * * * * * * * * * * THE BEST BANK * * * * * * * * * * * * * * * *\n * * * * * * * * * * * * * * * *  BANKING SYSTEM   * * * * * * * * * * * * * * *";

	for(i=0;i<80;i++)
		cout<<"*";
	time_t curr_time=time(0);
	cout<<"\n\n\t\t\t\t\t\t\t"<<ctime(&curr_time);

	cout<<"\n\n";
}

/*************************************************************************************************************************************/




void menu()
{	
	system("mod 80,39");
	color(63);
	int accountCount=0;
	int selection=1;
	Account *a= new Account[20];
	Customer *c=new Customer[20];
	char stroke;

	while(1)
	{
		do
		{
			header();
			cout<<"\n\n\n\t\t  Use ARROW KEYS to navigate through the options.\n\t\t  And press ENTER to select.\n\n\n";

			cout<<"\t\t\t  ";
			if(selection==1)
			{color(53);}
			cout<<" Add New Account\n";
			color(63);
			cout<<"\t\t\t  ";
			if(selection==2)
			{color(53);}
			cout<<" Handle Transactions\n";
			color(63);
			cout<<"\t\t\t  ";
			if(selection==3) 
			{color(53);}
			cout<<" Financial Planning\n";
			color(63);
			cout<<"\t\t\t  ";
			if(selection==4) 
			{color(53);}
			cout<<" Customer Details\n";
			color(63);

			cout<<"\n\n\t\t  Press the ESC key to exit the program.";
			stroke=getch();

			cursor(stroke,selection,4);

		}
		while(stroke!=13);

		switch(selection)
		{
			case 1:
				{
					addAccount(a,accountCount);
					a[accountCount].printDetails();
					c[accountCount].setValues(a[accountCount]);
					accountCount++;
					if(accountCount%20==0)
					{
						realloc(a, 20* sizeof(class Account));
						realloc(c, 20*sizeof(class Customer));
					}
					break;
				}
			case 2:
				{
					searchAccount(a,accountCount,1);
					break;
				}
			case 3:
				{
					searchAccount(a,accountCount,2);
					break;
				}
			case 4:
				{
					printCustomer(c,accountCount);
					break;
				}
		}
	}

//	delete [] c;
	delete [] a;

}


void main()
{	
	menu();
}

void cursor(char CharacterEntered, int& selection, int limit)
{
		if (CharacterEntered == 0 || -32)
		{
				switch (CharacterEntered)
				{
				
				case 80:
					{
						selection++;
						if(selection>limit)
						selection=1;
						break;
					}

				case 72:
					{
					selection--;
					if (selection<1)
						selection=limit;
					break;
					}

				case 27:
					{
						header();
						cout<<"\n\nYou have chosen to exit!\nThank you for using the program!\nHave a nice day!\n";
						exit(0);
					}
				}
			}
}

