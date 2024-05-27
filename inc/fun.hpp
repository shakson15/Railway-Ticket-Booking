#ifndef FUNCTION_H
#define FUNCTION_H

#include<vector>
#include<map>

class Train;
class Journey;
class User;
int get_tran(Train* obj);
vector<Journey*>* get_jour(Train* obj);
string get_Day(Journey* obj);
vector<Ticket*>* tick(Journey* obj,string coaches,int count);
int create_train();
void create_journey(int num);
void seat_availability(Journey* ptr);
void ticket_booking(User* ptr);
void see_ticket_history(User* ptrf);
Journey* seat_check();
void sign_in();
vector<User*>* search_user(string user_id);
User* obj_return(vector<User*>* temp,string user_id);
void search(User* ptr);
void delete_particular();



#endif
