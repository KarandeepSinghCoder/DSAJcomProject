#ifndef DB
#define DB
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//structure to store prisoner data
struct convict_data
{
    string str, name, BloodGroup, crime, medical, dob, adrs, sex, duration, age, hist, Ability, breakp;
};

class db
{
private:
public:
    vector<convict_data> data; //vector to store structures
    static int  getPK();
    static void AddPrisonerData();
    static void DeletePrisonerData();
    static void DisplayPrisonerData();
    static void SecuritySettings();
};
#endif