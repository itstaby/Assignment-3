#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include "Account.h"

using namespace std;
void header();
void color(int x);
void cursor(char CharacterEntered, int& selection, int limit);
void Account::setName()
		{
			cout<<"\nEnter Name: ";
			if((cin.peek())==10)
				cin.ignore();
			cin.getline(name, 20);
		}
		/*********************************************************************************************************/
		void Account::setIR()
		{
			cout<<"Enter interest rate: ";
			cin>>interestRate;
		}
		/*********************************************************************************************************/
		void Account::setAN()
		{
			cout<<"Enter the desired Account Number: ";
			cin>>accountNumber;
		}
		void Account::setP()
		{
			char p[10],d[10];
			do
			{
				cout<<"Enter deisred password: ";
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
				cout<<endl;

				cout<<"Confirm password: ";
				for(i=0; i<10; i++)
				{
					d[i]=getch();
					if(d[i]=='\r')
					{
						d[i]='\0';
						break;
					}
					cout<<"*";
				}
				cout<<endl;

				if(strcmp(p,d)!=0)
				{
					cout<<"\n\nThe passwords did not match, please re-enter password.\n";
				}

			}while(strcmp(p,d)!=0);
			strcpy(password,p);
			cout<<"\nThe password is: "<<password<<endl; 

			
		}
		/*********************************************************************************************************/
		void Account::withdrawM()
		{
			int m;
			system("cls");
			header();
			cout<<"Enter the amount of money to be withdrawn: ";
			cin>>m;

			if(m<=amount)
			{
				amount-=m;
				t[transactionNumber].amount=m;
				t[transactionNumber].type=Transactions::withdraw;
				cout<<"You have withdrawn an amount of Rs."<<m<<"/- from your account.\nYour remaining balance is Rs."<< amount<<"/-\n";
				getch();
				transactionNumber++;
				if(transactionNumber%20==0)
				realloc(t,20*sizeof(Transactions));
			}
			else
			{
				cout<<"You don't have enough money in your account to make this transaction!\nPress any key to return to the main menu.\n";
				getch();
			}

		}
		/*********************************************************************************************************/
		void Account::depositM()
		{
			system("cls");
			header();
			cout<<"Enter the amount to be deposited in your account: ";
			unsigned int m;
			cin>>m;
			amount=amount+m;
			t[transactionNumber].type=Transactions::deposit;
			t[transactionNumber].amount=m;
			transactionNumber++;
			if(transactionNumber%20==0)
				realloc(t,20*sizeof(Transactions));
			cout<<"\nYou have deposited an amount of Rs."<<m<<"/- in your account.\nYour updated balance is Rs."<<amount<<"/-\n";
			cout<<"\nPress any key to go back to the menu.";
			getch();
		}
		/*********************************************************************************************************/
		void Account::openM()
		{
			transactionNumber=0;
			t=new Transactions[20];			
			t[transactionNumber].type=Transactions::open;
			cout<<"Enter the first deposit: ";
			cin>>amount;
			t[transactionNumber].amount=amount;
			cout<<"\n\t\tPress any key to view the account details";
			transactionNumber++;
			getch();
			

		}
		/*********************************************************************************************************/
		void Account::printDetails()
		{
			cout<<"\n\nAccount Holder's Name: "<<name<<endl;
			cout<<"Account Number: "<<accountNumber<<endl;
			cout<<"Current Balance: "<<amount<<endl;
			cout<<"Interest Rate: "<<interestRate<<"%"<<endl;
			cout<<"Press any key to go back to the main menu.";
			getch();
		}
		/*********************************************************************************************************/
		void Account::printTransactionSummary()
		{
			header();
			for(int i=0; i<transactionNumber; i++)
			{
				if(t[i].type==Transactions::open)
				{
					cout<<"The first transaction made was when the account was opened.\n";
					cout<<"The ammount deposited was Rs."<<t[i].amount<<"/-\n";

				}
				else if(t[i].type==Transactions::deposit)
				{
					cout<<"\nTransaction Number "<<i<<" was a deposit.\nThe amount deposited was Rs."<<t[i].amount<<"/-\n";
				}
				else if(t[i].type==Transactions::withdraw)
				{
					cout<<"\nTransaction Number "<<i<<" was a withdrawl.\nThe amount withdrawn was Rs."<<t[i].amount<<"/-\n";
				}
			}

			cout<<"\n\n\nThe remaining account balance is:\n\t\t\tRs."<<amount<<"/-\n";

			cout<<"Press any key to return to the previous menu.\n\n";
			getch();
			
			cout<<3;
			Sleep(200);
			cout<<".";
			Sleep(200);
			cout<<".";
			Sleep(200);
			cout<<2;
			Sleep(200);
			cout<<".";
			Sleep(200);
			cout<<".";
			Sleep(200);
			cout<<1;
			Sleep(200);
			cout<<".";
			Sleep(200);
			cout<<".";
		}
		/*********************************************************************************************************/
		void Account::financialPlanning()
		{	
			header();
			char curr_date[9];
			_strdate(curr_date);

			struct date
			{
				int month;
				int day;
				int year;
			}current,retire;
			
			char day[2],month[2],year[2];
			day[0]=curr_date[0];
			day[1]=curr_date[1];
			month[0]=curr_date[3];
			month[1]=curr_date[4];
			year[0]=curr_date[6];
			year[1]=curr_date[7];

			current.day=atoi(day);
			current.month=atoi(month);
			current.year=2000+atoi(year);

			cout<<"The current date is: "<<current.day<<"/"<<current.month<<"/"<<current.year<<endl;

			

			cout<<"Please enter the retirement date:\n";
			fflush(stdin);
			int dc=0,mc=0,yc=0;
			do
			{
				if(yc==0)
				{
					cout<<"\nEnter the year: ";
					cin>>retire.year;
					if(retire.year<current.year)
					{
						cout<<"Unacceptable year entered, please re-enter the year:";
						continue;
					}
					else
						yc=1;

				}

				if(mc==0)
				{
					cout<<"\nEnter the month: ";
					cin>>retire.month;
					if(retire.month>12 || retire.month<1)
					{
						cout<<"Unacceptable month entered, please re-enter the month:";
						continue;
					}
					else
						mc=1;
				}

				if(dc==0)
				{
					cout<<"\nEnter the day: ";
					cin>>retire.day;
					if((retire.month==2 && retire.day>28)|| retire.day<1 || retire.day>31)
					{
						cout<<"Unacceptable day entered, please re-enter the day:";
						continue;
					}
					else
						dc=1;
				}

				if(dc==1 && mc==1 && yc==1)
					break;

				cout<<"Calculating.\n";
	
			
			
			}while(dc!=0 || mc!=0 || yc!=0);

			float paisa=amount;
			int saal=retire.year-current.year;
			int mahina=retire.month-current.month;
			int chakkar=12*saal+mahina;
			for(int i=0; i<chakkar; i++)
			{
				paisa+=paisa*(((float)interestRate)/100);
			}

			cout<<"Mr./Ms."<<name<<"!\nThe current balance in you account is:\n\n\t\t\tRs."<<amount<<"/-\n";
			cout<<"The amount you will recieve on retirement is:\n\n\t\t\tRs."<<paisa<<"/-\n";
			
			getch();
		}

		/*********************************************************************************************************/

		

		/*********************************************************************************************************/

		void Account::handleTransaction()
		{
			int selection=1;
			char input;
			while(input!=59)
			{
				do
				{
					header();
					cout<<"\n\n\n\t\t  Use ARROW KEYS to navigate through the options.\n\t\t  And press ENTER to select.\n\n\n";

					cout<<"\t\t\t  ";
					if(selection==1)
						{color(53);}
					cout<<"Withdraw money.\n";
					color(63);
					cout<<"\t\t\t  ";
					if(selection==2)
						{color(53);}
					cout<<"Deposit Money.\n";
					color(63);
					cout<<"\t\t\t  ";
					if(selection==3)
						{color(53);}
					cout<<"View Summary of all Transactions.\n";
					color(63);

					cout<<"\n\t\t  Press F1 to return to the main menu.";
					cout<<"\n\n\t\t  Press the ESC key to exit the program.";
					input=getch();

					cursor(input,selection,3);

				}while(input!=13 && input!=59);

				if(input==13)
				{
					switch(selection)
					{
						case 1:
							{
								this->withdrawM();
								break;
							}
						case 2:
							{
								this->depositM();
								break;
							}
						case 3:
							{
								this->printTransactionSummary();
							}
					}
				}
			}

			cout<<"\n\nYou will be redirected to the main menu in 3 seconds.\n";

			
			cout<<3;
			Sleep(200);
			cout<<".";
			Sleep(200);
			cout<<".";
			Sleep(200);
			cout<<2;
			Sleep(200);
			cout<<".";
			Sleep(200);
			cout<<".";
			Sleep(200);
			cout<<1;
			Sleep(200);
			cout<<".";
			Sleep(200);
			cout<<".";
			



		}
		/*********************************************************************************************************/
	
		/*********************************************************************************************************/

		Account::Account()
		{
			transactionNumber=0;
		}

		friend class Customer;