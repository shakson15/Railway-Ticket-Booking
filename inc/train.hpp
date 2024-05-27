#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>
#include <string>
#include<vector>
#include<map>
#include <iomanip>
#include <struct.hpp>

using namespace std;
class Journey;

class Train
{
	private:
		string train_name;
		int train_num;
		int coaches;
		int seats;
		string destination;
		string from;
		map<int,struct station*>* station;
		vector<Journey*> journey;
		
	public:
		Train(string name,int number,int coaches, int seats,map<int,struct station*>* station,string destination,string from)
		{
			this->train_num=number;
			this->train_name=name;
			this->coaches=coaches;
			this->seats=seats;
			this->destination=destination;
			this->from=from;
			this->station=station;		
		}
		int get_train_number()
		{
			return this->train_num;
		}
		
		string get_train_name()
		{
			return this->train_name;
		}
		int get_coaches()
		{
			return this->coaches;
		}
		int get_seats()
		{
			return this->seats;
		}
		
		void add_journey(Journey* temp)
		{
			journey.push_back(temp);
		}
		vector<Journey*>* get_journey()
		{
				return &journey;
		}
		string get_destination()
		{
			return this->destination;
		}
		string get_from()
		{
			return this->from;
		}
		map<int,struct station *>* get_station()
		{
			return station;
		}
};
#endif
