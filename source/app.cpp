/*
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