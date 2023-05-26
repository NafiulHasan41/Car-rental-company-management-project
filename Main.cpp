#include<iostream>
#include "rent.cpp"

using namespace std;
int main()
{
   string c;
   rent a;
   do
   {
      a.welcome();
   a.id();
   a.data();
   a.invoiceAmount();
   a.invoiceRecord();
    cout<<"\t\t\t\nDO YOU WANT TO CONTINUE ??????\n\t\t\tYES   OR   NO"<<endl;
    cin>>c;
   } while (c=="YES"); // to take multiple input
   a.thankyou();
   
  
}