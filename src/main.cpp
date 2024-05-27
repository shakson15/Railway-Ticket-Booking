#ifndef MAIN_CPP
#define MAIN_CPP

#include <iostream>
#include<vector>
#include<string>
#include "user.hpp"
#include "struct.hpp"
#include "fun.hpp"
#include <limits>
using namespace std;
int id = 0;
class Train;

extern vector<Train*> train;
string user_id;

void binary_tree(User* temp)
{
	if(temp->gender=="male")
	{
		user_id=to_string(1);
		auto ptr=tree_user.ptr_left; 
		if(temp->age>=59)
		{
			user_id=user_id+to_string(1);
			auto temp_age=ptr->ptr_left;
			if (temp->name[0]<='m'||temp->name[0]<='M')
			{
				user_id=user_id+to_string(1);
				user_id=user_id+to_string(temp->id);
				auto temp_name=temp_age->left;
				(temp_name->store_obj).push_back(temp);
				temp->set_userid(user_id);
				cout << "User ID : " << user_id << endl;
			}
			else
			{
				user_id=user_id+to_string(2);
				user_id=user_id+to_string(temp->id);
				auto temp_name=temp_age->right;
				(temp_name->store_obj).push_back(temp);
				temp->set_userid(user_id);
				cout << "User ID : " << user_id << endl;
			}
		}
		else
		{
			user_id=user_id+to_string(2);
			
			auto temp_age=ptr->ptr_right;
			if (temp->name[0]<='m'||temp->name[0]<='M')
			{
				
				user_id=user_id+to_string(1);
				auto temp_name=temp_age->left;
				user_id=user_id+to_string(temp->id);
				(temp_name->store_obj).push_back(temp);
				temp->set_userid(user_id);
				cout << "User ID : " << user_id << endl;
			}
			else
			{
				user_id=user_id+to_string(2);
				auto temp_name=temp_age->right;
				user_id=user_id+to_string(temp->id);
				(temp_name->store_obj).push_back(temp);
				temp->set_userid(user_id);	
				cout << "User ID : " << user_id << endl;
			}
			
		}
			
	}
	else
	{
		user_id=to_string(2);
		auto ptr=tree_user.ptr_right; //user root gender female 
		if(temp->age>=59)
		{
			user_id=user_id+to_string(1);
			auto temp_age=ptr->ptr_left;
			if (temp->name[0]<='m'||temp->name[0]<='M')
			{
				user_id=user_id+to_string(1);
				user_id=user_id+to_string(temp->id);
				auto temp_name=temp_age->left;
				(temp_name->store_obj).push_back(temp);
				temp->set_userid(user_id);
				cout << "User ID : " << user_id << endl;
			}
			else
			{
				user_id=user_id+to_string(2);
				user_id=user_id+to_string(temp->id);
				auto temp_name=temp_age->right;
				(temp_name->store_obj).push_back(temp);
				temp->set_userid(user_id);	
				cout << "User ID : " << user_id << endl;
			}
		}
		else
		{
			user_id=user_id+to_string(2);
			auto temp_age=ptr->ptr_right;
			if (temp->name[0]<='m'||temp->name[0]<='M')
			{
				user_id=user_id+to_string(1);
				auto temp_name=temp_age->left;
				user_id=user_id+to_string(temp->id);
				(temp_name->store_obj).push_back(temp);
				temp->set_userid(user_id);
				cout << "User ID : " << user_id << endl;
			}
			else
			{
				user_id=user_id+to_string(2);
				user_id=user_id+to_string(temp->id);
				
				auto temp_name=temp_age->right;
				(temp_name->store_obj).push_back(temp);
				temp->set_userid(user_id);	
				cout << "User ID : " << user_id << endl;
			}
			
		}
	}
}

void create_user()
{
	id++;
	cout<<"enter the user name:";
	string name;
	cin>>name;
	lable:
	cout<<"enter the age:";
	int age;
	cin>>age;
	if (age>120 || age<0) goto lable;
	string address;
	cout<<"enter the address:";
	cin>>address;
	string gender;
	cout<<"enter the gender:";
	cin>>gender;
	
	User* ptr=new User(id,name,age,address,gender,0);
	binary_tree(ptr);
}

void print_fun(struct name * ptr)
{
	if(ptr==NULL)
	{
		cout<<"group is empty:"<<endl;
	}
	for(User* vec_ptr:ptr->store_obj)
	{
			vec_ptr->getinfo();
	}

}

vector<User*>* search_user(string user_id)
{
	vector<User*>* temp=NULL;
	if(user_id[0]=='1')
	{
		if(user_id[1]=='1')
		{
			if(user_id[2]=='1')
			{
				temp=&tree_user.ptr_left->ptr_left->left->store_obj;
				return temp;
			}
			else if(user_id[2]=='2')
			{
				temp=&tree_user.ptr_left->ptr_left->right->store_obj;
				return temp;
			}
		else return temp;
		}
		else if(user_id[1]=='2')
		{
			if(user_id[2]=='1')
			{
				temp=&tree_user.ptr_left->ptr_right->left->store_obj;
				return temp;
			}
			else if(user_id[2]=='2')
			{
				temp=&tree_user.ptr_left->ptr_right->right->store_obj;
				return temp;
			}
		else return temp;
			
		}
	else return temp;
	}
	else if(user_id[0]=='2')
	{
		if(user_id[1]=='1')
		{
			if(user_id[2]=='1')
			{
				temp=&tree_user.ptr_right->ptr_left->left->store_obj;
				return temp;
			}
			else if(user_id[2]=='2')
			{
				temp=&tree_user.ptr_right->ptr_left->right->store_obj;
				return temp;
			}
			else return temp;
		}
		else if(user_id[1]=='2')
		{
			if(user_id[2]=='1')
			{
				temp=&tree_user.ptr_right->ptr_right->left->store_obj;	
				return temp;
			}
			else if(user_id[2]=='2')
			{
				temp=&tree_user.ptr_right->ptr_right->right->store_obj;
				return temp;
			}
			else return temp;
			
		}
		else return temp;
	}
	
	else return temp;


}

User* obj_return(vector<User*>* temp,string user_id)
{
	int i=0;
	for(User* ptr:*temp)
	{
		if(ptr->user_id==user_id)
		{
			return ptr;
		}
		
	}
	if(i==1)
	{
		User* ret_temp;
		ret_temp=NULL;
		return ret_temp;
	}
	return NULL;
}

void search(User* ptr)
{
	if(ptr!=NULL)		
		ptr->getinfo();		
	else
		cout<<"Invalid userid"<<endl;
	

}

void delete_element(vector<User*>* temp,string user_id) {
    auto it = temp->begin();
    while (it != temp->end()) {
        if ((*it)->user_id == user_id) {
            delete *it;  
            it = temp->erase(it);
        } else {
            ++it;
        }
    }
}

void print_particular()
{
	vector<User*>* temp;
	lable:
	cout<<"enter the user id for search:";
	string id;
	cin>>id;
	if(id.size()<4)
	{
		cout<<"user id must have more than 4 character"<<endl;
		goto lable;
	}
	
	
	temp=search_user(id);

	if (!temp)
	{
		cout<<"user id invalid:"<<endl;
	}
	else
	{
		User* ptr;
		ptr=obj_return(temp,id);
		search(ptr);
	}
}
void delete_particular(string id)
{
	vector<User*>* temp;
	temp=search_user(id);
	if (!temp)
	{
		cout<<"user id invalid:"<<endl;
	}
	else delete_element(temp,id);
	
}

void show_userinfo()
{
		print_fun(tree_user.ptr_left->ptr_left->left);
		print_fun(tree_user.ptr_left->ptr_left->right);
		print_fun(tree_user.ptr_left->ptr_right->left);
		print_fun(tree_user.ptr_left->ptr_right->right);
		print_fun(tree_user.ptr_right->ptr_left->left);
		print_fun(tree_user.ptr_right->ptr_left->right);
		print_fun(tree_user.ptr_right->ptr_right->left);
		print_fun(tree_user.ptr_right->ptr_right->right);
		

}

void admin()
{
	while(1)
	{
		cout<<left;
		cout<<setw(10)<<"1"<<setw(10)<<"-"<<setw(20)<<"Show all the user info"<<endl;
		cout<<setw(10)<<"2"<<setw(10)<<"-"<<setw(20)<<"Show particular user info"<<endl;
		cout<<setw(10)<<"3"<<setw(10)<<"-"<<setw(20)<<"Delete particular user info"<<endl;
		cout<<setw(10)<<"4"<<setw(10)<<"-"<<setw(20)<<"add train"<<endl;
		cout<<setw(10)<<"5"<<setw(10)<<"-"<<setw(20)<<"add journey"<<endl;
		cout<<setw(10)<<"6"<<setw(10)<<"-"<<setw(20)<<"EXIT"<<endl;
		
		int choices;
		cin>>choices;
		if (cin.fail()) 
		{
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
      		cout << "Invalid input. Please enter a number." << endl;
        	continue;
       	}
		string id;
		switch(choices)
		{
			case 1:
				show_userinfo();
				break;
			case 2:
				print_particular();
				break;
			case 3:
				cout<<"enter the user id for delete:";
				cin>>id;
				delete_particular(id);
				return;
			case 4:
				create_train();
				break;	
			case 5:
				for(Train * ptr : train)
				{
					cout<<get_tran(ptr)<<endl;
				}
				cout<<"enter the train number: ";
				int num;
				cin>>num;
				create_journey(num);
				break;
			case 6:
				return;
		}	
	}
}

void user()
{
	while(1)
	{
			cout<<left;
			cout<<setw(10)<<"1"<<setw(10)<<"-"<<setw(20)<<"LOGIN"<<endl;
			cout<<setw(10)<<"2"<<setw(10)<<"-"<<setw(20)<<"SIGNUP"<<endl;
			cout<<setw(10)<<"3"<<setw(10)<<"-"<<setw(20)<<"EXIT"<<endl;
			int choices;
			cin>>choices;
			
			if (cin.fail()) 
			{
            			cin.clear();
            	                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            			cout << "Invalid input. Please enter a number." << endl;
            			continue;
        		}
			
			switch(choices)
			{
				case 1:
					sign_in();
					break;
				case 2:
					create_user();
					
					break;
				case 3:
					return;
			
			}
	}
}

int main()
{
	init();
	
	while(1)
	{
		cout<<left;
		cout<<setw(10)<<"1"<<setw(10)<<"-"<<setw(20)<<"ADMIN"<<endl;
		cout<<setw(10)<<"2"<<setw(10)<<"-"<<setw(20)<<"USER"<<endl;
		cout<<setw(10)<<"3"<<setw(10)<<"-"<<setw(20)<<"EXIT"<<endl;
		int choices;
		cin>>choices;
		if (cin.fail()) 
			{
            			cin.clear();
            	                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            			cout << "Invalid input. Please enter a number." << endl;
            			continue;
        		}
		switch(choices)
		{
			case 1:
				admin();
				break;
			case 2:
				user();
				break;
			case 3:
				exit(1);
		}	
	}
	
}
#endif
