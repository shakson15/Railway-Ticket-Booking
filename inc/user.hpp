#ifndef User_H
#define User_H

#include <iostream>
#include <string>
#include <iomanip>
#include<vector>
using namespace std;
class Ticket;
class User
{
	public:
		int id;
		string name;
		int age;
		string address;
		string gender;
		string user_id;
		int wallet_money;
		vector<vector<Ticket*>*> ticket;

		User(int id,string name,int age, string address, string gender,int money)
		{
			this->id=id;
			this->name=name;
			this->age=age;
			this->address=address;
			this->gender=gender;
			this->wallet_money=money;
		}
		
		void getinfo()
		{
			cout<<left;
			cout<<setw(10)<<"ID"<<setw(20)<<id<<endl;
			cout<<setw(10)<<"Name"<<setw(20)<<name<<endl;
			cout<<setw(10)<<"Age"<<setw(20)<<age<<endl;
			cout<<setw(10)<<"Gender"<<setw(20)<<gender<<endl;
			cout<<setw(10)<<"user_id"<<setw(20)<<user_id<<endl;
			cout<<setw(10)<<"Wallet_money"<<setw(20)<<wallet_money<<endl;				
		}
		void set_userid(string id)
		{
			this->user_id=id;
			cout<<"your account is created!"<<endl;		
		}
		
		void add_money(int money)
		{
			this->wallet_money=this->wallet_money+money;
			cout<<"money added"<<endl;
		}
		void add_ticket(vector<Ticket*>* temp)
		{
			ticket.push_back(temp);
		}
		
		int get_balance()
		{
			return wallet_money;
		}
		void debit_amount(int cost)
		{
			this->wallet_money=this->wallet_money-cost;
		}
				
};



#endif
