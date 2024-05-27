#ifndef TRAIN_CPP
#define TRAIN_CPP

#include<iostream>
#include<fstream>
#include <sstream>
#include <string>
#include "journey.hpp"
#include "train.hpp"
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
		  	vector<Seat*>* seats=new vector<Seat*>(seats_per_coach,nullptr);
	      	sitter_coaches[coach_name] = seats;
	    }
	    else if(i<=5)
		{
	    	vector<Seat*>* seats=new vector<Seat*>(seats_per_coach,nullptr);
		    sleeper_coaches[coach_name] = seats;
		}
		else
		{
			vector<Seat*>* seats=new vector<Seat*>(seats_per_coach,nullptr);
		    Ac_sleeper_coaches[coach_name] = seats;
		}	      
	}
}
	
void Journey :: delete_ticket(Ticket* ticket)
{
	string coach=ticket->get_coach();
	int seat=ticket->get_seat();
	string type=ticket->get_coach_type();
	map<string,vector<Seat*>*>* coaches;
	if(type=="2S")
	{
		coaches=&sitter_coaches;		
	}
	else if(type=="Sleeper")
	{
		coaches=&sleeper_coaches;
	}
	else if(type=="Ac_sleeper")
	{
		coaches=&Ac_sleeper_coaches;
	}
	
	for(auto it : *coaches)
	{
		if(it.first == coach)
		{
			for(Seat*& i:*(it.second))
			{
				if(i!=NULL && i->get_seat_num() == seat)
				{
					if(i->free_seat(ticket->get_des_station_id(),ticket->get_from_station_id(),ticket->get_ticket_id())) i=NULL;
					return;
				}
			}
		}
	}	
}

int create_train()
{
		ifstream file("/home/azhagarasan/Downloads/azhagarasan/train_reservation/train.txt");
    if(!file.is_open())
    {
        cout << "File open error" << endl;
        return 1;
    }
    string line;
    while (getline(file, line))
    {
        map<int , struct station*>* all_stations = new map<int, struct station*>;
        stringstream ss(line);
        string name;
        int number, coaches, seats,kilometer;
		string from, destination, sta;
        getline(ss, name, ',');        
        ss >> number; ss.ignore();
        ss >> coaches; ss.ignore();
        ss >> seats; ss.ignore();
        getline(ss,from,',');
        getline(ss,destination,',');
        int i=0;
        while((getline(ss,sta,',')) and (ss >> kilometer))
        {
			i++;
			station* temp_station=new station{sta,kilometer};		
        	(*all_stations)[i]=temp_station;
			ss.ignore();
        }
        Train* ptr = new Train(name, number,coaches,seats,all_stations,destination,from);
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

void seat_availability(Journey* ptr,string onboard,string destination)
{
	ptr->seats_available(onboard,destination);
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
#endif
