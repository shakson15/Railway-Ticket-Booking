#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct name
{
	vector<User*>store_obj;	
};
struct age
{
	struct name* left;
	struct name* right;
	
};
struct gender
{
	struct age* ptr_left;
	struct age* ptr_right;
};

struct user
{
	struct gender* ptr_left;
	struct gender* ptr_right;
};

struct station
{
	
	string station_name;
	int dis_from_start;
};

struct name a_to_m_male59;

struct name a_to_m_female59;

struct name a_to_m_male0;

struct name a_to_m_female0;

struct name n_to_z_male59;

struct name n_to_z_female59;
	
struct name n_to_z_male0;
	
struct name n_to_z_female0;
	
struct age male_above59;

struct age male_below59;
	
struct age female_above59;

struct age female_below59;
	
struct gender male;
	
struct gender female;
	
struct user tree_user;

void init()
{
	male_above59.left=&a_to_m_male59;
	male_above59.right=&n_to_z_male59;
	
	male_below59.left=&a_to_m_male0;
	male_below59.right=&n_to_z_male0;
	
	female_above59.left=&a_to_m_female59;
	female_above59.right=&n_to_z_female59;
	
	
	female_below59.left=&a_to_m_female0;
	female_below59.right=&n_to_z_female0;
	
	male.ptr_left=&male_above59;
	male.ptr_right=&male_below59;
	
	female.ptr_left=&female_above59;
	female.ptr_right=&female_below59;
	
	tree_user.ptr_left=&male;
	tree_user.ptr_right=&female;


}
