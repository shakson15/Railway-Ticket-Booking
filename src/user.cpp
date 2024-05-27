#ifndef USER_cpp
#define USER_cpp

#include<iostream>
#include<string>
#include<user.hpp>
#include<vector>
#include<fun.hpp>
#include<train.hpp>
#include <journey.hpp>
#include <ticket.hpp>
#include <struct.hpp>
#include <limits>
#include <algorithm>
using namespace std;

vector<Journey*>* temp2;
extern vector<Train*> train;

void show_wallet(User* ptr)
{
	cout << "Money In Wallet : " << ptr->get_balance() << endl << endl;
}
void add_money_to_wallet(User* ptr)
{
	int money;
	while(true)
	{
		cout<<"enter the amount add to the wallet:"<<endl;
		cin>>money;
		if(cin.fail())
		{
			cout << "Please enter an integer value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (cin.peek() != '\n') 
        {
            cout << "Please enter an integer value." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
	}
	ptr->add_money(money);
}

void sign_in()
{
	vector<User*>* temp;
	get_userid:
		cout<<"enter the user id for search:";
		string id;
		cin>>id;
		
		temp=search_user(id);
		User* ptr;
		if (!temp)
		{
			cout<<"user id invalid:"<<endl;
			return ;
		}
		else
		{
			
			ptr=obj_return(temp,id);
			if (ptr==NULL) 
			{
				cout<<"enter the vaild user id"<<endl;
				goto get_userid;
			}
		}
	while(1)
	{
		cout<<left;
		cout<<setw(5)<<"1"<<setw(5)<<"-"<<setw(20)<<"add money"<<endl;
		cout<<setw(5)<<"2"<<setw(5)<<"-"<<setw(20)<<"Show all details"<<endl;
		cout<<setw(5)<<"3"<<setw(5)<<"-"<<setw(20)<<"Delete account"<<endl;
		cout<<setw(5)<<"4"<<setw(5)<<"-"<<setw(20)<<"Seat availablity"<<endl;
		cout<<setw(5)<<"5"<<setw(5)<<"-"<<setw(20)<<"Ticket booking"<<endl;
		cout<<setw(5)<<"6"<<setw(5)<<"-"<<setw(20)<<"See ticket history"<<endl;
		cout<<setw(5)<<"7"<<setw(5)<<"-"<<setw(20)<<"Cancel Ticket"<<endl;
		cout<<setw(5)<<"8"<<setw(5)<<"-"<<setw(20)<<"Check Wallet"<<endl;
		cout<<setw(5)<<"9"<<setw(5)<<"-"<<setw(20)<<"EXIT"<<endl;
		cout<<endl;
		
		int choices;
		cin>>choices;
		if (cin.fail())
        {   
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
		switch(choices)
		{
			case 1:
				add_money_to_wallet(ptr);
				break;
			case 2:
				search(ptr);
				break;
			case 3:
				delete_particular(id);
				return;
				break;		
			case 4:
			{
				lable:
    			cout<<"enter the onboard station:";
    			string onboard;
    			cin>>onboard;
    			cout<<"enter the destination:";
    			string destination;
    			cin>>destination;
    			if(destination==onboard)
    			{
        			cout<<"onboard and destination not be the same station"<<endl;
        			goto lable;
    			}
				seat_check(onboard,destination);
			}
				break;			
			case 5:
				ticket_booking(ptr);
				break;
			case 6:
			{
				bool exitF = false;
				see_ticket_history(ptr,exitF);
			}
				break;
			case 7:
				del_ticket(ptr);
				break;
			case 8:
				show_wallet(ptr);
				break;
			case 9:
				return;
		}
	}	
}

Journey* seat_check(string onboard, string destination)
{
	Journey* temp3;
	cout<<"enter the day:";
	string day;
	cin>>day;
	vector<int>train_av;
	for(Train * ptr : train)
	{
		map<int,struct station*>* map_station;
		vector<Journey*>* temp2= ptr->get_journey();
		for(Journey * temp1:*temp2)
		{
			if(get_Day(temp1)==day)
			{
				map_station=temp1->jour_station;
				int i=0,j=0;
				for(auto it=map_station->begin();it!=map_station->end();++it)
				{
					if(it->second->station_name==onboard)
					{
						i=it->second->dis_from_start;
					}
					else if(it->second->station_name==destination)
					{
						j=it->second->dis_from_start;
					}
				}
				if((j-i)>0 && i != 0)
				{
					train_av.push_back(get_tran(ptr));
				}							
			}
		}
	}
	if(train_av.empty())
	{
		cout<<"No train route"<<endl;
		return NULL;	
	}
	for(auto it : train_av)
	{
		cout<<it<<endl;
	}
	
	lable_t:
	cout<<"enter the train number : ";
	int num;
	cin>>num;
	auto i=find(train_av.begin(),train_av.end(),num);
	if(i==train_av.end())
	{
		goto lable_t;
	
	}
	for(Train * n_ptr:train)
	{
		if (get_tran(n_ptr)==num)
		{
			temp2=get_jour(n_ptr);
			for(Journey* temp3:*temp2)
			{
				if(get_Day(temp3)==day)
				{
					seat_availability(temp3,onboard,destination);
					return temp3;
				}
			}
		}
	}
	temp3=NULL;
	return temp3;
}

void ticket_booking(User* ptr)
{
	Journey* temp_obj;
	lable:
    cout<<"enter the onboard station:";
    string onboard;
    cin>>onboard;
    cout<<"enter the destination:";
    string destination;
    cin>>destination;
    if(destination==onboard)
    {
        cout<<"onboard and destination not be the same station"<<endl;
        goto lable;
    }
	temp_obj=seat_check(onboard,destination);
	if(temp_obj==NULL)
	{
		cout<<"error:"<<endl;
		return;
	}
	else
	{
		vector<Ticket*>* temp;
		int count;
		cout<<"enter the passenger count:";
		cin>>count;
		string coaches;
		cout<<"enter the coach (2S,Sleeper,Ac_sleeper):";
		cin>>coaches;
		if((temp = tick(temp_obj,coaches,count,destination,onboard,ptr)))
		{	
			ptr->ticket.push_back(temp);
		}
	}
}

void del_ticket(User* ptr)
{
	bool exitF = false;
    see_ticket_history(ptr,exitF);
	if(exitF)
	{
		return;
	}
    cout << "Enter the Ticket id: ";
    int id;
    cin >> id;
    vector<vector<Ticket*>*>* tk_detail = &ptr->ticket;
    for (auto it = tk_detail->begin(); it != tk_detail->end(); )
    {
        bool found = false;
        for (auto temp = (*it)->begin(); temp != (*it)->end(); )
        {
            if ((*temp)->get_ticket_id() == id)
            {
                for (Train* traverse : train)
                {
                    if ((*temp)->get_train_number() == traverse->get_train_number())
                    {
                        vector<Journey*>* jour = traverse->get_journey();
                        for (auto j : *jour)
                        {
                            if (j->get_Journey_id() == (*temp)->get_jouney_id())
                            {
                                j->delete_ticket(*temp);
                                (*it)->erase(temp);
                                found = true;
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                ++temp;
            }
        }
        if ((*it)->empty())
        {
           	tk_detail->erase(it);
        }
        else
        {
            ++it;
        }

        if (found)
        {
            break;
        }
    }
}

void see_ticket_history(User* ptr, bool& exitF)
{
	vector<vector<Ticket*>*> temp=ptr->ticket;
	if(temp.empty())
	{
		exitF = true;
		cout<<"No Ticket booked"<< endl << endl;
	}
	else
	{
		cout<<setw(20)<<"Ticket id"<<setw(20)<<"Train number"<<setw(20)<<"Passenger Name"<<setw(10)<<"Age"<<setw(20)<<"Coach"<<setw(20)<<"Seat_NO"<<endl;
		for(vector<Ticket*>* ins_vec_temp:temp)
		{
			for(Ticket* obj:*ins_vec_temp)
			{
				obj->ticket_info();
			}
		}
	}
}
#endif
