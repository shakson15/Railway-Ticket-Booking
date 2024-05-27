#ifndef TICKET1_H
#define TICKET1_H

#include <iostream>
#include <train.hpp>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Seat
{
    int seat_num;
    string seat_availability;
    vector<int> station_num;
    vector<int> ticket_id;

public:
    Seat(int Seat_num, int dest_station_id, int from_station_id, int id)
    {
        this->seat_num = Seat_num;
        for (int i = from_station_id; i < dest_station_id; i++)
        {
            station_num.push_back(i);
        }
        ticket_id.push_back(id);
    }

    bool seat_ticket_check(int source, int destination)
    {
        int j = 0;
        for (int i = source; i < destination; i++)
        {
            auto temp1 = find(station_num.begin(), station_num.end(), i);
            if (temp1 != station_num.end())
                j++;
        }
        if(j != 0) return true;
        else return false;
    }

    void set_ticket_id(int id)
    {
        ticket_id.push_back(id);
    }

    void add_inter_station(int source, int destination)
    {
        for (int i = source; i < destination; i++)
        {
            station_num.push_back(i);
        }
    }

    int get_seat_num()
    {
        return this->seat_num;
    }
	
	bool free_seat(int destination, int source, int id) 
	{
		for (auto i = ticket_id.begin(); i != ticket_id.end(); )
    		{
        		if (*i == id)
        		{
            			i = ticket_id.erase(i); 
        		}
        		else
        		{
            			++i;
        		}
    		}

		for (int j = source; j <= destination; ++j)
    		{
        		for (auto it = station_num.begin(); it != station_num.end(); )
        		{
            			if (*it == j)
            			{
                			it = station_num.erase(it);  
            			}
            			else
            			{
                			++it;
            			}
        		}
    		}
  		if(station_num.empty())
  		{
  			return true;
  		}
  		else return false;
	}

};

#endif

