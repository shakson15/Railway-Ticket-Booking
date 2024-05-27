#ifndef FUNCTION_H
#define FUNCTION_H

#include<vector>
#include<map>
using namespace std;

class Train;
class Journey;
class User;
class Ticket;

int get_tran(Train* obj);
vector<Journey*>* get_jour(Train* obj);
string get_Day(Journey* obj);
vector<Ticket*>* tick(Journey* obj,string coaches,int count);
int create_train();
void create_journey(int num);
void seat_availability(Journey* ptr, string onboard, string destination);
void ticket_booking(User* ptr);
void see_ticket_history(User* ptr,bool& exitF);
void del_ticket(User* ptr);
vector<Ticket*>* tick(Journey* obj,string coaches,int count,string destination, string from,User* ptr);
Journey* seat_check(string onboard, string destination);
void sign_in();
void show_wallet(User* ptr);
vector<User*>* search_user(string user_id);
User* obj_return(vector<User*>* temp,string user_id);
void search(User* ptr);
void delete_particular(string id);
int get_tran(Train* obj);
vector<Journey*>* get_jour(Train* obj);
string get_Day(Journey* obj);

#endif
