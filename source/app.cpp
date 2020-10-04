/**
 * @author: Karandeep Singh (19BCB0055) Kashyap Bastola (19BCE2529) Ayushma Joshi (19BCB0143)
 * @desc: Entry Point of Application
 */

#include<iostream>
#include"./../includes/login/login.h"
#include"./../includes/Homescreen/Homescreen.h"

using namespace std;

int main(){
	Login loginHandler;
	loginHandler.renderLoginScreen();
	
	return 0;
}
