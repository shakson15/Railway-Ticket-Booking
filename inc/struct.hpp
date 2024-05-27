#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct User;

struct name {
    vector<User*> store_obj;
};

struct age {
    struct name* left;
    struct name* right;
};

struct gender {
    struct age* ptr_left;
    struct age* ptr_right;
};

struct user {
    struct gender* ptr_left;
    struct gender* ptr_right;
};

struct station {
    string station_name;
    int dis_from_start;
};

extern struct name a_to_m_male59;
extern struct name a_to_m_female59;
extern struct name a_to_m_male0;
extern struct name a_to_m_female0;
extern struct name n_to_z_male59;
extern struct name n_to_z_female59;
extern struct name n_to_z_male0;
extern struct name n_to_z_female0;
extern struct age male_above59;
extern struct age male_below59;
extern struct age female_above59;
extern struct age female_below59;
extern struct gender male;
extern struct gender female;
extern struct user tree_user;

void init();

#endif // STRUCTS_HPP

