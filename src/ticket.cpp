#include<iostream>
#include<train.hpp>
#include<fstream>
#include "fun.hpp"
#include "journey.hpp"

class Seat
{
	int seat_num;
	string seat_availability;
	vector<string> station_num;
	vector<int> ticket_id;
	
	
	public:
		Seat(int seat_num,int dest_station_id,int from_station_id)
		{
			this->seat_num=seat_num;
			for(int i=from_station_id;i<dest_station_id;i++)
			{
					station_num.push_back(i);
					
			}
		}
	
	bool seat_ticket_check(int source,int destination)
	{
			
			for(int i=source;i<destination;i++)
			{
				auto temp1=find(station_num.begin(),station_num.end(),i)
				if (temp!=station_num.end());
				return true;
			}
			return false
}
	void set_ticket_id(int id)
	{
		ticket_id.push_back(id);
	}
	void remove_ticket(int id)
	{
		
	}
	void add_inter_station(int source,int destination)
	{
		for(int i=source;i<destination;i++)
		{
			station_num.push_back(i);			
		}
	}
	
	int get_seat_num()
	{
		return seat_num;
	}
	void free_seat(int destination,int source,int id)
	{
		for(int i=ticket_id.begin();i!=ticket_id.end();++i)
		{
			if (i==id)
			{
				ticket_id.earse(i);
			}
		}
		for(int j=source;j<=destination;j++)
		{
			for(auto it:station_num)
			{
				if(j==it)
				{
					station_num.earse(it);
					break;
				}
			}
		}
	}
};
void ticket
