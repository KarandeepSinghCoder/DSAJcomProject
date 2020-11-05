#include <iostream>
#include <string>
#include "db.h"
#include <cstdio>
#include <stdio.h>
#include <vector>
#include <conio.h>
#include <fstream>
#include "./../filehandling/filehandling.h"
#include "./../login/login.h"
#include "./../rainbow/rainbow.h"

using namespace std;

void db::AddPrisonerData()
{

	fstream ob;
	string line;
	ob.open("PK.txt", ios::in | ios::out);
	getline(ob, line);
	int pk=stoi(line);
   pk+=1;
   //cout<<pk<<endl;
   ob.close();
   db p2;
   convict_data p1;
   fflush(stdin);  
   cout<<"Prisoner number is :  "<<pk<<endl;
   string str= to_string(pk);
   p1.str=str;
   fflush(stdin);
   cout <<endl<<"Enter name:  ";
   getline(cin, p1.name);
   cout << "Enter Blood Group:  ";
   cin >> p1.BloodGroup;
   fflush(stdin);
   cout << "Enter crime committed:  ";
   getline(cin, p1.crime);
   fflush(stdin);
   cout << "Enter Medical History:  ";
   getline(cin, p1.medical);
   fflush(stdin);
   cout << "Enter dob:  ";
   cin >> p1.dob;
   fflush(stdin);
   cout << "Enter Address:  ";
   getline(cin, p1.adrs);
   fflush(stdin);
   cout << "Enter sex:  ";
   cin >> p1.sex;
   fflush(stdin);
   cout << "Enter Sentence Duration:  ";
   getline(cin, p1.duration);
   fflush(stdin);
   cout << "Enter Convict's Age:  ";
   getline(cin, p1.age);
   fflush(stdin);
   cout << "Enter Convict's Crime History:  ";
   getline(cin, p1.hist);
   fflush(stdin);
   cout << "Enter Convict's Special Ability:  ";
   getline(cin, p1.Ability);
   fflush(stdin);
   cout << "Enter Convict's Atempts to break the prison: ";
   getline(cin, p1.breakp);
   fflush(stdin);
   p2.data.push_back(p1);
//



//Creating a file in write mode

   fstream Database;
   Database.open("Data.txt", ios::out | ios::app);
   for (vector<convict_data>::iterator i = p2.data.begin(); i != p2.data.end(); ++i)
   {
      // int s = (11 - i->primarykey);
      int s = (10 - i->str.length());
      int a = (20 - i->name.length());
      int b = (15 - i->BloodGroup.length());
      int c = (21 - i->crime.length());
      int d = (25 - i->medical.length());
      int e = (17 - i->dob.length());
      int f = (37 - i->adrs.length());
      int g = (12 - i->sex.length());
      int h = (12 - i->duration.length());
      int j = (11 - i->age.length());
      int k = (36 - i->hist.length());
      int l = (36 - i->Ability.length());
      int m = (36 - i->breakp.length());
      Database << "|" << i->str << string(s, ' ') << "|" << i->name << string(a, ' ') << "|" << i->BloodGroup << string(b, ' ') << "|" << i->crime << string(c, ' ') << "|" << i->medical << string(d, ' ') << "|" << i->dob << string(e, ' ') << "|" << i->adrs << string(f, ' ') << "|" << i->sex << string(g, ' ') << "|" << i->duration << string(h, ' ') << "|" << i->age << string(j, ' ') << "|" << i->hist << string(k, ' ') << "|" << i->Ability << string(l, ' ')<< "|" << i->breakp << string(m, ' ') << "|" << endl;
   }
   Database.close();
      //string line;
   //string line;
         fstream obj;
         obj.open("PK.txt", ios::in | ios::out | ios::trunc);
         obj << str ;
         obj.close();
}

void db::DisplayPrisonerData()
{
   string line;
   ifstream infile;
   infile.open("Data.txt");
   while (getline(infile, line))
   {
      cout << line << endl;
   }
   infile.close();
}
void db::DeletePrisonerData()
{
   string str;
   cout << "Enter the number to be Deleted" << endl;
   cin >> str;
   string line;
   fstream offile;
   fstream newfile;
   offile.open("Data.txt", ios::out | ios::in);
   newfile.open("temp.txt", ios::out | ios::app);
   while (getline(offile, line))
   {
      size_t found = line.find(str);
      if (found != string::npos)
      {
         line.erase(line.begin(), line.end());
      }
      else
      {
         newfile << line << "\n";
      }
   }
   offile.close();
   newfile.close();
   remove("C:\\cygwin64\\home\\ASUS\\jail-management-system\\Data.txt");
   char oldname[] = "temp.txt";
   char newname[] = "Data.txt";
   rename(oldname, newname);
}

void db::SecuritySettings()
{
   fstream ob1;
   string line;
   password = "";
   ob1.open("Password.txt", ios::in | ios::out);
   getline(ob1, line);
   string OldPassword, NewPassword, ConfirmNewPassword;
   cout << "Enter Current password" << endl;
   ;
   Login::PassKeyEncoder();
   OldPassword = password;
   if (OldPassword == line)
   {
      ob1.close();
      getchar();
      cout << "Enter New Password" << endl;
      password = "";
      Login::PassKeyEncoder();
      NewPassword = password;
      cout << "confirm New Password" << endl;
      password = "";
      Login::PassKeyEncoder();
      ConfirmNewPassword = password;
      if (NewPassword == ConfirmNewPassword)
      {
         ob1.open("Password.txt", ios::in | ios::out | ios::trunc);
         ob1 << NewPassword;
         cout << "\n " << rainbow::safe("Password Changed Successfully") << endl;
         ob1.close();
      }
      else
      {
         cout << "\n " << rainbow::warn("Passwords Do Not Match!") << endl;
      }
   }
   else
   {
      cout << "\n " << rainbow::warn("Passwords Do Not Match!") << endl;
   }
}
