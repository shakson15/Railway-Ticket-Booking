#include<iostream>
#include<train.hpp>
#include<fstream>
#include "fun.hpp"
#include "journey.hpp"
#include "struct.hpp"

using namespace std;

vector<Train*>train;

vector<Seat*> ret_tick;
void Journey :: create_coaches(int num_coaches, int seats_per_coach) 
{
		  
		for (int i = 0; i < num_coaches; ++i) 
		{
			string coach_name = 'C' + to_string(i + 1);
		      
		  if(i<=3)
		  {
		  	cout<<"enter"<<endl;
		  	vector<Seat*>* seats=new vector<Seat*>();
		      	seats->resize(seats_per_coach,nullptr);
		      	cout<<seats<<endl;
		      	sitter_coaches[coach_name] = seats;
		      }
		      else if(i<=5)
		      {
				    vector<Seat*>* seats=new vector<Seat*>();
		      	seats->resize(seats_per_coach/2,nullptr);
				    
				    
				    sleeper_coaches[coach_name] = seats;
		      
		      }
		      else
		      {
		      	vector<Seat*>* seats=new vector<Seat*>();
		      	seats->resize(seats_per_coach/2,nullptr);
		      	Ac_sleeper_coaches[coach_name] = seats;
		      }

		      
		  }
   
	}
	
void Journey :: delete_ticket(Ticket* ticket)
{
	string coach=ticket->get_coach();
	string seat=ticket->get_seat();
	string type=ticket->get_coach_type();
	if(type=="2S")
	{
		map<string,vector<Seat*>*>* coaches=&sitter_coaches
			
	}
	else if(type=="Sleeper")
	{
		map<string,vector<Seat*>*>* coaches=&sleeper_coaches
			
	}
	else if(type=="Ac_sleeper")
	{
		map<string,vector<Seat*>*>* coaches=&Ac_sleeper_coaches
	}
	
	for(auto it : *coaches)
	{
		if(it->first==coach)
		{
			for(auto i:it->second)
			{
				if(i->get_seat_num())
				{
					i->free_seat(ticket->get_des_station_id(),ticket->det_from_station_id(),ticket->get_ticket_id());
				}
			}
		}
	}
	
}

int create_train()
{
		ifstream file("/home/arun/train_reservation/txt/train.txt");
    if(!file.is_open())
    {
        cout << "File open error" << endl;
        return 1;
    }
    string line;
    while (getline(file, line))
    {
        map<int , struct station*> all_stations;
        stringstream ss(line);
        string name;
        int number, coaches, seats,kilometer;
				string from, destination, station;
        getline(ss, name, ',');
        
        ss >> number; ss.ignore();
        ss >> coaches; ss.ignore();
        ss >> seats; ss.ignore();
        getline(ss,from,",");
        getline(ss,destination,",");
        int i=0;
        while((getline(ss,station,",")) and (ss >> kilometer; ss.ignore()))
        {
						i++;
						station * temp_station=new{station,kilometer};
        		
        	all_station[i]=temp_station;
        }
        
        Train* ptr = new Train(name, number,coaches,seats,&all_station,destination,from);
				train.push_back(ptr);
				
    }
    
    return 0;

}


void create_journey(int num)
{
	for(Train * ptr:train)
	{
		
		if(ptr->get_train_number()==num)
		{
			int num=ptr->get_train_number();
			string name=ptr->get_train_name();
			int seats=ptr->get_seats();
			int coaches=ptr->get_coaches();
			string day;
			cout<<"enter the day:";
			cin>>day;
			Journey* temp=new Journey(name,num,day,ptr);
			temp->create_coaches(coaches, seats);
			ptr->add_journey(temp); 
			
		
		}
	}

}


void seat_availability(Journey* ptr)
{
			ptr->seats_available();
		

}
int get_tran(Train* obj)
{
	return obj->get_train_number();
}

vector<Journey*>* get_jour(Train* obj)
{
	return obj->get_journey();
}

string get_Day(Journey* obj)
{
	return obj->get_day();
}

vector<Ticket*>* tick(Journey* obj,string coaches,int count,string destination, string from,User* ptr)
{
	return obj->booking(coaches,count, destination, from,ptr);

}
