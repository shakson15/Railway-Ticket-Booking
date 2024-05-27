#include<iostream>
#include<string>
#include<user.hpp>
#include<vector>
#include<fun.hpp>
#include<train.hpp>

using namespace std;

vector<Journey*>* temp2;
extern vector<Train*> train;


void add_money_to_wallet(User* ptr)
{
	cout<<"enter the amount add to the wallet:"<<endl;
	int money;
	cin>>money;
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
		cout<<setw(5)<<"3"<<setw(5)<<"-"<<setw(20)<<"Search particular user info"<<endl;
		cout<<setw(5)<<"4"<<setw(5)<<"-"<<setw(20)<<"Delete particular user info"<<endl;
		cout<<setw(5)<<"5"<<setw(5)<<"-"<<setw(20)<<"Seat availablity"<<endl;
		cout<<setw(5)<<"6"<<setw(5)<<"-"<<setw(20)<<"Ticket booking"<<endl;
		cout<<setw(5)<<"7"<<setw(5)<<"-"<<setw(20)<<"See ticket history"<<endl;
		cout<<setw(5)<<"8"<<setw(5)<<"-"<<setw(20)<<"EXIT"<<endl;
		cout<<endl;
		
		int choices;
		cin>>choices;
		switch(choices)
		{
			case 1:
				add_money_to_wallet(ptr);
				break;
			case 2:
				search(ptr);
				break;
			case 3:
				delete_particular(ptr->id);
				break;		
			case 5:
				seat_check();
				break;			
			case 6:
				ticket_booking(ptr);
				break;
			case 7:
				see_ticket_history(ptr);
				break;
			case 8:
				del_ticket(ptr);
			case 9:
				return;
		}
	}	


}

Journey* seat_check()
{
	Journey* temp3;
	cout<<"enter the day:";
	string day;
	cin>>day;
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
	for(Train * ptr : train)
	{
		map<int,struct station*>* map_station;
		temp2=get_jour(ptr);
		for(Journey * temp1:*temp2)
		{
			if(get_Day(temp1)==day)
			{
					map_station=ptr->get_station;
					for(auto it=map_station->begin();it!=map_station->end();++it)
					{
						if(it->second->station_name==onboard)
						{
							int i=it->second->dis_from_start;
							
						}
						else if(it->second->station_name==onboard)
						{
							int i=it->second->dis_from_start;
						}
					
					}
					if((j-i)<0)
					{
						cout<<"the source and destination are in opposite direction:"<<endl
						goto lable;
					
					}
				
				cout<<get_tran(ptr)<<endl;
							
			}
		}
	}
	cout<<"enter the train number: ";
	int num;
	cin>>num;
	for(Train * n_ptr:train)
	{
		if (get_tran(n_ptr)==num)
		{
			temp2=get_jour(n_ptr);
			for(Journey* temp3:*temp2)
			{
				if(get_Day(temp3)==day)
				{
					seat_availability(temp3);
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
	temp_obj=seat_check();
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
		cout<<"enter the coach:";
		cin>>coaches;
		if((temp=tick(temp_obj,coaches,count,destination,from,ptr))
		{
			
			ptr->ticket.push_back(temp);
		
		}

}

void del_ticket(User* ptr)
{
	see_ticket_history(ptr);
	cout<<"enter the ticket id:";
	int id;
	cin>>id;
	vector<vector<Ticket*>*> tk_detail=ptr->ticket;
	for(auto it:tk_detail)
	{
		for(auto temp:it)
		{
			if(temp->get_ticket_id==id)
			{
				for(Train* traverse:train)
				{
					if(temp->get_train_number==traverse->get_train_number())
					{
						vector<Journey*>* jour;
						jour=traverse->get_journey()
					}
					for(auto j:*jour)
					{
						if(j->get_journey_id()==temp->get_jouney_id())
						{
							j->delete_ticket(temp);
							return;
						}
					}
				}
			}
		}
	}
}

void see_ticket_history(User* ptr)
{
	vector<vector<Ticket*>*> temp=ptr->ticket;
	if(temp.empty())
	{
		cout<<"No Ticket booked:"<<endl;
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





