#include<iostream>
#include <fstream>		//file
#include <unistd.h>   //sleep
#include <iomanip>  //setting width
#include <ctime>	//time
#include "Login.cpp"
using namespace std;

// make a class to take input and calculate and show invoice
class rent:public login{
    protected:
    string cutomer_name;
    int rent_fee;
    int nuber_of_days;
    bool flag;
    public:
        rent();
		void welcome();
        void check(); //check if id and password is valid or not
        void id();
		void data();
		void invoiceAmount();	//Computes 
		void invoiceRecord();  //Prints the invoice 
		void thankyou();
		void creation();
};
rent::rent()
{
    rent_fee=0;
    nuber_of_days=0;
    flag=0;
   
    
}
void rent::welcome()
{
	system("clear");
    ifstream inputfile("welcome.txt"); //displaying welcome ASCII image text on output screen fn1353
	if(!inputfile) {
		cout << "Cannot open input file.\n";
	}
	char str[1000];
	while(inputfile) {
		inputfile.getline(str, 1000);  // get the ascii code line by line
		if(inputfile) 
			cout << str << endl;
  	}
  	inputfile.close();
	sleep(1);
	cout<<"\nStarting the program please wait....."<<endl;
	sleep(1);
	cout<<"\nloading up files....."<<endl;
	sleep(1); //function which waits for (n) seconds
	system("clear");     //cleares screen
}
void rent::check()
{
 
   int c; string d;
            cout<<"\t\tWELL COME TO LOGIN PAGE "<<endl;

            cout<<"\tID       : "; cin>>c;
            cout<<"\tPASSWORD : "; cin>>d;
            if(checkid_and_password(c,d))
            {
                flag=1;
            }
            else
            {
                cout<<"\t\tTHE ID AND PASSWORD IS INVALLID"<<endl;
                // LOOP FOR ID AND PASSWORD UNTIL CORRECT ID IS NOT FOUND
                while(flag!=1)
				{
					int a;
					cout<<"\t\tDO YOU WANT TO LOGIN(press 1) OR SIGN UP(press 2)"<<endl;
					cin>>a;
                   if(a==1)
				   {
                      check();
				   }
				   else
				   {
					id();
				   }
                    
				}
               
            }
}

void rent :: id()
{
    cout<<"\t\t\tLogIn Or Sign Up\t\t\t"<<endl;
    cout<<"\t\tPress 1 for Sing up or Press 2 for login "<<endl;
    int choice;
    cin>>choice;
    switch (choice)
    {
        case 1:
        //sing up if id and password is not set
           { system("clear");
            int a;
            string b;
            cout<<"\t\tWELL COME TO SING UP PAGE "<<endl;
            cout<<"\tDISCLAIMER\n\t\t\t CAN NOT USE SPACE IN PASSWORD!!!!!!!!!! "<<endl;
            cout<<"\tID       : ";cin>>a;
            cout<<"\tPASSWORD : ";cin>>b;
            setid_and_password(a,b);
            system("clear");

            id();
            break;
           }
        case 2:
        {
            check();
        }
      
    }    
}
void rent:: data()
{
    if(flag)
    {
		system("clear");
		cout<<"\t\t\nWELCOME!!! YOU ARE LOGGED IN "<<endl;
        cout << "\n\n\nPlease Enter your Name: "; 	//taking data from the user
  	cin >> cutomer_name;
	cout<<endl;
    int car_model;
	do{
		//giving user a choice to select among three different models
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
	    cout << "\t\t\t\tChoose a Car from the options below. \n ";
	    cout <<	"\t\t\t\tChoose a number corresponding to the car you want to Select." << endl; 
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
		cout << "\t\t\t\t1. Toyota 2021.\t\tRent is 1500 TK per day"<<endl;
	    cout << "\t\t\t\t2. Hyundai 2019.\t\tRent is 1600 TK per day"<<endl;
	    cout << "\t\t\t\t3. Ford 2020.\t\tRent is 1800 TK per day"<<endl;
        cout << "\t\t\t\t4. Mustang 2021.\t\tRent is 2500 TK per day"<<endl;
	    cout << "\t\t\t\t5. Lexus 2019.\t\tRent is 1700 TK per day"<<endl;
	    cout << "\t\t\t\t6. Range Rover 2020.\t\tRent is 2200 TK per day"<<endl;
	    cout << endl;
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
	    cout << "\n\t\t\t\tChoose: ";
       
	    cin >> car_model;
	    cout << endl;
		 cout<<"Number of days you wish to rent the car : ";
	    cin >> nuber_of_days;
        		
	 	switch(car_model){
	 		case 1:
	 			system("clear");
	 			cout<<"You have choosed Toyota model 2021"<<endl;
                rent_fee=(nuber_of_days*1500);

				sleep(2);
				break;
			case 2:
				system("clear");
	  			cout<<"You have choosed Hyundai model 2019"<<endl;
                 rent_fee=(nuber_of_days*1600);
		     	sleep(2);
				break;	
			case 3:
		     	system("clear");
		     	cout<<"You have choosed Ford model 2020"<<endl;
			     rent_fee=(nuber_of_days*1800);
		     	sleep(2);
		   		break;  
            case 4:
                 system("clear");
		     	cout<<"You have choosed Mustang model 2021"<<endl;
			     rent_fee=(nuber_of_days*2500);
		     	sleep(2);
		   		break;  
            case 5:
                 system("clear");
		     	cout<<"You have choosed Lexus model 2019"<<endl;
			     rent_fee=(nuber_of_days*1700);
		     	sleep(2);
		   		break;  

            case 6:
                 system("clear");
		     	cout<<"You have choosed Range Rover model 2020"<<endl;
			     rent_fee=(nuber_of_days*2200);
		     	sleep(2);
		   		break;  

			default:
		     	cout<<"Invaild Car Model. Please try again!"<<endl;
		}
	}while(car_model < 1 && car_model > 6);
    cout<<endl;

    }
    
}
void rent::invoiceAmount(){
	sleep(1);
	system ("clear");
	cout<<"Calculating rent. Please wait......"<<endl;
	sleep(2);
}
void rent::invoiceRecord(){
	time_t now  = time(0);		//getting local time 
	char *date = ctime(&now); 	//Converting toa string 
	cout << setw(80) << date << endl;
	cout << "\n\t\t                       CAR RENTAL - CUSTOMER INVOICE                  "<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	| Invoice No.  "<<"					|"<< setw(10) <<"#1001"<<" |"<<endl;  //can be automatically generated
	cout << "\t\t	| Customer Name "<<"				|"<< setw(10) <<cutomer_name<<" |"<<endl;
	cout << "\t\t	| Number of days  "<<"				|"<< setw(10) <<nuber_of_days<<" |"<<endl;
	cout << "\t\t	| Rental Amount  "<<"				|"<< setw(10) <<rent_fee<<" |"<<endl;
	cout << "\t\t	| Caution Money  "<<"				|"<< setw(10) <<"0"<<" |"<<endl;      //Can be calculated 
	cout << "\t\t	| Advanced  "<<"					|"<< setw(10) <<"0"<<" |"<<endl;		//Can be calculated 
	cout << "\t\t	|___________________________________________________________|"<<endl;
	cout << "\t\t	| Total Rental Amount    "<<"			|"<<setw(6)<<"R " << rent_fee<<" |"<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	 NOTE: This is a computer generated invoce. "<<endl;
	cout << "\t\t	       It does not require an authorised signture."<<endl;
	cout << "\t\t	***********************************************************" << endl;
	cout << "\t\t	You are advised to pay up the amount before due date."<<endl;
	cout << "\t\t	Otherwise penelty fee will be applied"<<endl;
	cout << "\t\t	***********************************************************" << endl;

      string c;
      cout<<"\t\t\t\n\nDO YOU WANT TO CONTINUE ??????\n\t\t\tYES   OR   NO\n"<<endl;
      cin>>c;
	  if(c=="YES" || c=="yes")
	  {
		system("clear");
		id();
        data();
        invoiceAmount();
        invoiceRecord(); 
	  }
	  else
	  {
		thankyou();
	  }




	
}
void rent::thankyou() // To show the last part of the project
{
    	system("PAUSE");
	system ("clear");
        ifstream inputfile("thanku.txt"); //displaying welcome ASCII image text on output screen fn1353
	if(!inputfile) {
		cout << "Cannot open input file.\n";
	}
	char str[1000];
	while(inputfile) {
		inputfile.getline(str, 1000);  // get the ascii code line by line
		if(inputfile) 
			cout << str << endl;
  	}
  	inputfile.close();
}
void rent::creation()
{
	
     welcome();
    id();
    data();
    invoiceAmount();
    invoiceRecord();

}



