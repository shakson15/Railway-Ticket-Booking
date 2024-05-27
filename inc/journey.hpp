#include <iostream>
#include <string>
#include<vector>
#include<map>
#include <iomanip>
#include<train.hpp>
#include<user.hpp>

int Journ_id=0;
using namespace std;
class Seat;
class Journey;
	int train_number;
	int journey_id;
	string train_name;
	string day;
	string destination;
	string from;
	map<int,struct station*>* jour_station=NULL;

		map<string, vector<Seat*>*> sitter_coaches;
    map<string, vector<Seat*>*> sleeper_coaches;
    map<string, vector<Seat*>*> Ac_sleeper_coaches;
    vector<Seat*>* seats;
    vector<Ticcket*> train_ticket;
    Train* train
    
	public:
		Journey(string name,int number,string day,Train* obj)
		{
			this->train_number=number;
			this->train_name=name;
			this->day=day;
			this->train=obj;
			this->destination=train->get_destination();
			this->from=train->get_from();
			this->jour_station=train->get_station
			journ_id++;
			this->journey_id=journ_id;
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
    
	
	void check(string from,string destination,map<string, vector<SeaTicket*>*>* coaches)
	{
		int from_station_id,i;
		int des_station_id;
		map<int,struct station*>* map_station;
		map_station=this->get_station;
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
		for(auto it=coaches.begin();it!=coaches.end();++it)
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
						
						bool check=it->seat_ticket_check(from_station_id,int des_station_id);
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
			int i=0;
			
			check(from,destination,&sitter_coaches)
			
			cout<<endl;
			cout<<"Sleeper coaches:"<<endl;
			cout<<setw(10)<<"Coaches"<<setw(20)<<"Seats Availability"<<endl;
			
			check(from,destination,&sleeper_coaches);
			
			cout<<endl;
			cout<<"AC Sleeper coaches:"<<endl;
			cout<<setw(10)<<"Coaches"<<setw(20)<<"Seats Availability"<<endl;
			
			check(from,destination,&sleeper_coaches);
		
	}
	
	bool seat_count(map<string, vector<Seat*>*>* coaches, int count,int source_id,int destination_id)
	{
		
		int i =0;
		for(auto it=coaches->begin();it!=coaches->end();++it)
		{
			vector<Seat*>* seats=it->second;
			
			
			for(auto it=seats->begin();it!=seats->end();++it)		
			{
				if(*it==NULL) i++;
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
	
	bool add_st_tk(Seat* seat_it )
	{
		if(*seat_it==NULL) 
		{	
			st=new Seat(ticket_num,from_station_id,des_station_id,obj->ticket_id);
			int num=i;
			string coach=coach_it->first;
								
			obj->set_coach(coach);
			obj->set_seat(num);
			*seat_it=st;
								
			return true;
		}
		else 
		{
						
			bool check=seat_it->seat_ticket_check(from_station_id,des_station_id);
			if(!check)
			{
				int num=i;
				string coach=coach_it->first;
									
				obj->set_coach(coach);
				obj->set_seat(num);
				seat_it->set_ticket_id(obj->ticket_id);
				seat->add_inter_station(from_station_id,des_station_id)							
				return true;
			}
		}
		return false;
	}	
	
	void ticket_obj_map(string coaches,Ticket* obj, string preference,int from_station_id,int des_station_id )
	{
		
		if(coaches=="2S")
		{
			
			if(preference=="Window")
			{
			
				for(auto coach_it=sitter_coaches.begin();coach_it!=sitter_coaches.end();++coach_it)
				{
					vector<Seat*>* seats=coach_it->second;
					int i =0;

				
					for(auto seat_it=seats->begin();seat_it!=seats->end();++seat_it)
					{
						i++;
						if(i%6==1 or i%6==0)
						{
							if(add_st_tk(*seat_it5))
								return;
						}
					}	
				}	
			}	
			
			for(auto coach_it=sitter_coaches.begin();coach_it!=sitter_coaches.end();++coach_it)
			{
				vector<Seat*>* seats=coach_it->second;
				int i =0;	
				for(auto seat_it=seats->begin();seat_it!=seats->end();++seat_it)
				{
					i++;
					if(add_st_tk(*seat_it4))
						return;
				}	
			}
		}	
		if(coaches=="Sleeper")
		{
			map<string,vector<Seat*>*>* coaches=&sleeper_coaches
			
		}
		else if(coaches=="Ac_sleeper")
		{
			map<string,vector<Seat*>*>* coaches=&Ac_sleeper_coaches
		}
			
		if(preference=="Lower")	
		{
				
			for(auto coach_it=coaches->begin();coach_it!=coaches->end();++coach_it)
			{
				vector<Seat*>* seats=coach_it->second;
				int i =0;

					
				for(auto seat_it=seats->begin();seat_it!=seats->end();++seat_it)
				{
					i++;
					if(i%8==1 or i%8==4 or i%8==7)
					{	
						if(add_st_tk(*seat_it))
								return;
					}
				}	
				
			}
		}
			
		else if (preference=="Middle") 
		{
			for(auto coach_it=coaches->begin();coach_it!=coaches->end();++coach_it)
			{
				vector<Seat*>* seats=coach_it->second;
				int i =0;

				
				for(auto seat_it=seats->begin();seat_it!=seats->end();++seat_it)
				{
					i++;
					if(i%8==2 or i%8==5)
					{
						if(add_st_tk(*seat_it))
							return;
					}	
			
				}
		
			}

		}
		else if (preference=="Upper") 
		{
			for(auto coach_it=coaches->begin();coach_it!=coaches->end();++coach_it)
			{
				vector<Seat*>* seats=coach_it->second;
				int i =0;

				
				for(auto seat_it=seats->begin();seat_it!=seats->end();++seat_it)
				{
					i++;
					if(i%8==3 or i%8==6 or i%8==0)
					{
						if(add_st_tk(*seat_it))
								return;
					}	
			
				}
		
			}

		}
		for(auto coach_it=coaches->begin();coach_it!=coaches->end();++coach_it)
		{
			vector<Seat*>* seats=coach_it->second;
			int i =0;			
			for(auto seat_it=seats->begin();seat_it!=seats->end();++seat_it)
			{
				i++;				
				if(add_st_tk(*seat_it))
					return;	
			}
		}
	}
	
	vector<Ticket*>* booking(string coaches,int count,string destination, string from,User* obj)
	{
		vector<Tiket*> ret_tick;
		bool a=false;
		
		map<int,struct station*>* map_station;
		map_station=this->get_station;
		for(auto it=map_station->begin();it!=map_station->end();++it)
		{
			if(it->second->station_name==onboard)
			{
				int i=it->second->dis_from_start;
				int from_station_id=it->first;
								
			}
			else if(it->second->station_name==destination)
			{
				int j=it->second->dis_from_start;
				int des_station_id=it->first;
			}
					
		}
		if(coaches=="2S") a= seat_count(&this->sitter_coaches,count,from_station_id,des_station_id);
		else if(coaches=="Sleeper") a=seat_count(&this->sleeper_coaches,count,from_station_id,des_station_id);
		else if(coaches=="Ac_sleeper") a=seat_count(&this->Ac_sleeper_coaches,count,from_station_id,des_station_id);
		
		if(a)
		{
			int i=1;
			while(i<=count)
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
				cout<<"enter the seat preference:"
				string preference;
				cin>>preference;
				
				
				int distance=j-i;
				if(coaches=="2S") int cost=distance*0.5*count; 
				else if(coaches=="Sleeper") int cost=distance*1*count;
				else if(coaches=="Ac_sleeper") int cost=distance*2*count;
				int balance;
				balance=obj->get_balance;
				if(balance<cost)
				{
					cout"insufficient balance:"<<endl;
					return NULL;
				}
				obj->debit_amount(cost);
				
				Ticket* tick_ptr
				tr=new Ticket(name,age,gender,destination,from,distance,cost,from_station_id,des_station_id,journ_id,train_number,coaches);
				Seat* st;
				ticket_obj_map(coaches,tick_ptr,,from_station_id,des_station_id,st);
				ret_tick.push_back(tick_ptr);
				i++;
				
			}
			return &ret_tick;		
		}
		
		return NULL;
	}
	
	void create_coaches(int num_coaches, int seats_per_coach);
	void delete_ticket(Ticket* ticket); 
	
};

