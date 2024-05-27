#ifndef Journey_H
#define JOurney_H

#include <iostream>
#include <string>
#include<vector>
#include<map>
#include <iomanip>
#include "user.hpp"
#include "ticket1.hpp"
#include "ticket.hpp"
#include "struct.hpp"
#include "train.hpp"
extern int Journ_id;
using namespace std;

class Journey
{
	int train_number;
	int journey_id;
	string train_name;
	string day;
	string destination;
	string from;
	int si = 0;

	public:
	map<int,struct station*>* jour_station;
	map<string, vector<Seat*>*> sitter_coaches;
    map<string, vector<Seat*>*> sleeper_coaches;
    map<string, vector<Seat*>*> Ac_sleeper_coaches;
    vector<Seat*>* seats;
    vector<Ticket*> train_ticket;
    Train* train;  
	Journey(string name,int number,string day,Train* obj)
	{
		this->train_number=number;
		this->train_name=name;
		this->day=day;
		this->train=obj;
		this->destination= destination;
		this->from=from;
		this->jour_station=obj->get_station();
		Journ_id++;
		this->journey_id=Journ_id;
	}

	int get_train_number()
	{
		return this->train_number;
	}

	string get_day()
	{
		return this->day;
	}

	int get_Journey_id()
	{
		return journey_id;
	}
  
	void check(string from,string destination,map<string, vector<Seat*>*>* coaches)
	{
		int from_station_id,i;
		int des_station_id;
		map<int,struct station*>* map_station;
		map_station=this->jour_station;
		for(auto it=map_station->begin();it!=map_station->end();++it)
		{
			if(it->second->station_name==from)
			{
				from_station_id=it->first;
								
			}
			else if(it->second->station_name==destination)
			{
				des_station_id=it->first;
			}			
		}
		for(auto it=coaches->begin();it!=coaches->end();++it)
			{
				vector<Seat*>* seats=it->second;
				i=0;
				for(auto it=seats->begin();it!=seats->end();++it)
				{
					if(*it==NULL) 
					{
						i++;	
					}
					else 
					{		
						bool check=(*it)->seat_ticket_check(from_station_id,des_station_id);
						if(!check)
						{
							i++;
						}
					}
				}
				cout<<setw(10)<<it->first<<setw(20)<<i<<endl;	
			}	
	}

	void seats_available(string from,string destination)
	{
		cout<<"sitter coaches:"<<endl;
		cout<<setw(10)<<"Coaches"<<setw(20)<<"Seats Availability"<<endl;		
		check(from,destination,&sitter_coaches);
	
		cout<<endl;
		cout<<"Sleeper coaches:"<<endl;
		cout<<setw(10)<<"Coaches"<<setw(20)<<"Seats Availability"<<endl;		
		check(from,destination,&sleeper_coaches);
		
		cout<<endl;
		cout<<"AC Sleeper coaches:"<<endl;
		cout<<setw(10)<<"Coaches"<<setw(20)<<"Seats Availability"<<endl;		
		check(from,destination,&Ac_sleeper_coaches);
	}
	
	bool seat_count(map<string, vector<Seat*>*>* coaches, int count,int source_id,int destination_id)
	{
		int i =0;
		for(auto& it : *coaches)
		{
			vector<Seat*>& seats = *it.second;			
			for(auto& it : seats)		
			{
				if(it==NULL)
				{
				 	i++;
				}
				else 
				{	
					bool check=it->seat_ticket_check(source_id,destination_id);
					if(!check)
					{
						i++;
					}
				}
				if(i>=count)
				{
					return true;
				}
			}	
		}
		return false;
	}
	
	bool add_st_tk(Seat*& seat_it,int ticket_num, int from_station_id,int des_station_id,Ticket* obj, string coach_it)
	{
		if(seat_it == NULL) 
		{	
			Seat* st = new Seat(ticket_num,des_station_id,from_station_id,obj->get_ticket_id());
			seat_it = st;							
			obj->set_coach(coach_it);
			obj->set_seat(ticket_num);								
			return true;
		}
		else 
		{			
			bool check=seat_it->seat_ticket_check(from_station_id,des_station_id);
			if(!check)
			{
				int num=seat_it->get_seat_num();
				string coach=coach_it;	
				obj->set_coach(coach);
				obj->set_seat(num);
				seat_it->set_ticket_id(obj->get_ticket_id());
				seat_it->add_inter_station(from_station_id,des_station_id);							
				return true;
			}
		}
		return false;
	}	
	
	void ticket_obj_map(string coaches,Ticket* obj, string preference,int from_station_id,int des_station_id )
	{
		si = 0;
		if(coaches=="2S")
		{		
			if(preference=="Window")
			{	
				for(auto& coach_it : sitter_coaches)
				{
					vector<Seat*>& seats = *coach_it.second;			
					for(auto& seat_it : seats)
					{
						si++;
						if(si%6==1 or si%6==0)
						{
							if(add_st_tk(seat_it,si,from_station_id,des_station_id,obj,coach_it.first))
							{							
								return;
							}
						}
					}	
				}	
			}			
			for(auto& coach_it : sitter_coaches)
			{
				vector<Seat*>& seats = *coach_it.second;	
				for(auto& seat_it : seats)
				{
					si++;
					if(add_st_tk(seat_it,si,from_station_id,des_station_id,obj,coach_it.first))
						return;
				}	
			}
		}	
		map<string,vector<Seat*>*>* coaches_a;
		if(coaches=="Sleeper")
		{
			coaches_a=&sleeper_coaches;		
		}
		else if(coaches=="Ac_sleeper")
		{
			coaches_a=&Ac_sleeper_coaches;
		}
		if(preference=="Lower")	
		{
			for(auto it=coaches_a->begin();it!=coaches_a->end();++it)
			{
				vector<Seat*>* seats= it->second;
				
				for(auto seat_it=seats->begin();seat_it!=seats->end();++seat_it)
				{
					si++;
					if(si%8==1 or si%8==4 or si%8==7)
					{	
						if(add_st_tk(*seat_it,si,from_station_id,des_station_id,obj,it->first))
								return;
					}
				}		
			}
		}	
		else if (preference=="Middle") 
		{
			for(auto it=coaches_a->begin();it!=coaches_a->end();++it)
			{
				vector<Seat*>* seats= it->second;	
				for(auto seat_it=seats->begin();seat_it!=seats->end();++seat_it)
				{
					si++;
					if(si%8==2 or si%8==5)
					{
						if(add_st_tk(*seat_it,si,from_station_id,des_station_id,obj,it->first))
							return;
					}	
				}
			}

		}
		else if (preference=="Upper") 
		{
			for(auto it=coaches_a->begin();it!=coaches_a->end();++it)
			{
				vector<Seat*>* seats= it->second;			
				for(auto seat_it=seats->begin();seat_it!=seats->end();++seat_it)
				{
					si++;
					if(si%8==3 or si%8==6 or si%8==0)
					{
						if(add_st_tk(*seat_it,si,from_station_id,des_station_id,obj,it->first))
								return;
					}	

				}
			}

		}
		for(auto& it : *coaches_a)
		{
			vector<Seat*>& seats= *it.second;
			for(auto& seat_it : seats)
			{
				si++;				
				if(add_st_tk(seat_it,si,from_station_id,des_station_id,obj,it.first))
					return;	
			}
		}
	}
	
	vector<Ticket*>* booking(string coaches,int count,string destination, string from,User* obj)
	{
		vector<Ticket*>* ret_tick = new vector<Ticket*>();
		bool a=false;
		map<int,struct station*>* map_station;
		map_station=this->jour_station;
		int from_station_id,i,j;
		int des_station_id;
		for(auto it=map_station->begin();it!=map_station->end();++it)
		{
			if(it->second->station_name==from)
			{
				i =it->second->dis_from_start;
				from_station_id=it->first;
								
			}
			else if(it->second->station_name==destination)
			{
				j=it->second->dis_from_start;
				des_station_id=it->first;
			}
					
		}
		cout << "source : " << from_station_id << "dest : " << des_station_id << endl;
		if(coaches=="2S") a= seat_count(&this->sitter_coaches,count,from_station_id,des_station_id);
		else if(coaches=="Sleeper") a=seat_count(&this->sleeper_coaches,count,from_station_id,des_station_id);
		else if(coaches=="Ac_sleeper") a=seat_count(&this->Ac_sleeper_coaches,count,from_station_id,des_station_id);
		
		if(a)
		{
			int b=1;
			while(b<=count)
			{
				cout<<"enter the passenger name:";
				string name;
				cin>>name;
				cout<<"enter the passenger age:";
				int age;
				cin>>age;
				cout<<"enter the passenger gender:";
				string gender;
				cin>>gender;
				cout<<"enter the seat preference:";
				string preference;
				cin>>preference;
				int distance=j-i;
				int cost;
				if(coaches=="2S") cost=distance*0.5*count; 
				else if(coaches=="Sleeper") cost=distance*1*count;
				else if(coaches=="Ac_sleeper") cost=distance*2*count;
				int balance;
				balance=obj->get_balance();
				if(balance<cost)
				{
					cout << "insufficient balance:"<<endl;
					return NULL;
				}
				obj->debit_amount(cost);
				
				Ticket* tick_ptr;
				tick_ptr=new Ticket(name,age,gender,destination,from,distance,cost,des_station_id,from_station_id,journey_id,train_number,coaches);
				ticket_obj_map(coaches,tick_ptr,preference,from_station_id,des_station_id);
				ret_tick->push_back(tick_ptr);
				b++;			
			}
			return ret_tick;		
		}
		return NULL;
	}
	
	void create_coaches(int num_coaches, int seats_per_coach);
	void delete_ticket(Ticket* ticket); 
};
#endif
