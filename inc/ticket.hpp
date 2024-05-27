#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>
#include<vector>
#include<map>
#include <iomanip>

using namespace std;
extern int i;

class Ticket
{
	int seat_num;
	string coaches;
	string coach_type;
	string passenger_name;
	int age;
	string gender;
	string destination;
	string from;
	int des_station_id;
	int from_station_id;
	int ticket_id;
	int journ_id;
	int distance;
	int cost;
	int train_number;
	public:
	Ticket(string passenger_name, int age,string gender, string destination, string from,int distance,int cost,int des_id,int from_id,int j_id,int train_number,string coach_type)
	{	
		this->passenger_name=passenger_name;
		this->age=age;
		this->gender=gender;
		this->destination=destination;
		this->des_station_id=des_id;
		this->from=from;
		this->from_station_id=from_id;
		this->distance=distance;
		this->cost=cost;
		i++;
		this->ticket_id=i;
		this->journ_id=j_id;
		this->train_number=train_number;
		this->coach_type=coach_type;
	}
	void set_coach(string coach)
	{
		this->coaches=coach;
	}
	void set_seat(int num)
	{
		this->seat_num=num;
	}
	int get_ticket_id()
	{
		return ticket_id;
	}
	int get_jouney_id()
	{
		return journ_id;
	}
	int get_train_number()
	{
		return train_number;
	}
	string get_coach()
	{
		return coaches;
	}
	int get_seat()
	{
		return seat_num;
	}
	string get_coach_type()
	{
		return coach_type;
	}
	int get_des_station_id()
	{
		return des_station_id;
	}
	int get_from_station_id()
	{
		return from_station_id;
	}
	
	void ticket_info()
	{
		cout<<left;
		cout<<setw(20)<<ticket_id<<setw(20)<<train_number<<setw(20)<<passenger_name<<setw(10)<<age<<setw(20)<<coaches<<setw(20)<<seat_num<<endl;
		cout<<endl;
			
	}
};
#endif
