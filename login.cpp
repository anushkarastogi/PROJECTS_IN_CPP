#include<iostream>
#include<fstream>
#include<string.h>
using namespace  std;

void login();
void registration();
void forgotpassword();

int main()
{
	int c;
	cout<<"\t\t\t________________________________________\n\n\n";
	cout<<"\t\t\t         Welcome To Login Page           \n\n\n";
	cout<<"\t\t\t__________________MENU___________________\n\n\n";
	cout<<"                                                  \n\n";
	cout<<"\t| Press 1 to LOGIN                  |"<<endl;
	cout<<"\t| Press 2 to REGISTER               |"<<endl;
	cout<<"\t| Press 3 if FORGOT YOUR PASSWORD   |"<<endl;
	cout<<"\t| Press 4 to EXIT                   |"<<endl;
	cout<<"\n\t\t\t Enter your choice: ";
	cin>>c;
	cout<<endl;
	
	
	switch(c)
	{
		case 1:
			login();
			break;
			
		case 2:
			registration();
			break;
			
		case 3:
			forgotpassword();
			break;
					
		case 4:
			cout<<"\t\t\t Thank You!  \n\n";
			
		default:
			system("cls"); //
			cout<<"Please select the correct key to enter! \n\n";
	}	
		
}
void login(){
	int count;
	string userId, password, id, pass;
	system("cls");
	cout<<"\t\t\t Enter the username and password: "<<endl;
	cout<<"\t\t USERNAME   "<<endl;
	cin>>userId;
	cout<<"\t\t\t PASSWORD  "<<endl;
	cin>>password;
	
	ifstream input("records.txt");
	while(input>>id>>pass)
	{
		if(id==userId && pass==password)
		{
			count=1;
			system("cls");
		}
	}
	input.close();
	
	if(count==1)
	{
		cout<<userId<<"Your LOGIN is successful.\n Thanks for logging in! \n ";
		main();
	}
	else{
		cout<<"LOGIN ERROR. Please check your username and password \n";
		main();
	}
}
void registration(){
	string ruserId, rpassword, rId, rpass;
	cout<<"\t\t\tt Enter the username:  ";
	cin>>ruserId;
	cout<<"\t\t\t Enter the password:  ";
	cin>>rpassword;
	
	ofstream f1("records.txt", ios::app);
	f1<<ruserId<<' '<<rpassword<<endl;
	system("cls");
	cout<<"\n\t\t\t  Registration is successful!\n ";
	main();
	
	
}
void forgotpassword(){
	int option;
	system("cls");
	cout<<"\t\t\t Forgot the password? Don't worry!\n ";
	cout<<"Press 1 to search your Id by username "<<endl;
	cout<<"Press 2 to go back to main menu "<<endl;
	cout<<"\t\t\t Enter your choice: ";
	cin>>option;
	switch(option){
		case 1:
			{
				int count=0;
				int suserid, sid, spass;
			    cout<<"\n\t\t\t\tEnter the username you remembered: \n";
			    cin>>suserid;
			    
			    ifstream f2("records.txt");
			    while(f2>>sid>>spass)
			    {
			    	if(sid==suserid)
			    	{
			    		count=1;
					}
				}
				f2.close();
				if(count==1)
				{
					cout<<"\n\n Your account is found!  \n";
					cout<<"\n\n  Your password is:  \n";
					main();
				}
				else{
					cout<<"\n\t Sorry! Your account is not found! \n ";
					main();
				}
				break;
				
			}
		case 2:
			{
				main();
			}
			default:
				cout<<"\n\t\t\t Please try again!  "<<endl;
				forgotpassword();
	}
}
