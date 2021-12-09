#include <stdio.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
  
struct Customer_details
	{
		char name[30];
		char gender;
		char city[10];
		int id;
        long long contact_no;
		float balance;
	}Customer;

    void insert()
	{	
		system("cls");
		printf("===============================Welcome To Customer Registration Page==============================================\n");
		ofstream fout;	
		fout.open("details.dat",ios::out|ios::binary|ios::app);
        char c[30];
		printf("Enter your First Name: ");
		scanf("%s",&Customer.name);
        
		printf("Enter your last name: ");
		scanf("%s",c);
		strcat(Customer.name,c);

		printf("Enter your gender\n Press M for Male and F for Female: ");
		scanf(" %c",&Customer.gender);
        //gets(Customer.gender);
		printf("Enter your Customer ID: ");
		scanf("%d",&Customer.id);

		printf("Enter your Contact Number: ");
		scanf("%lld",&Customer.contact_no);

		printf("Add 100 rupees (minimum) to open an account: ");
		scanf("%f",&Customer.balance);

		printf("Enter your State: ");
		scanf(" %s",Customer.city);
		 
		fout.write((char*)&Customer,sizeof(Customer));
		fout.close();

	}

	void balance()
	{   
		system("cls");
		int flag=0;
		fstream fin;
		int tid;
		float bal;
		int pos;
		fin.open("details.dat",ios::in|ios::out|ios::binary|ios::ate);
		printf("Enter the customer id in which you want to update balance:");
		scanf("%d",&tid);
		fin.seekg(ios::beg);
		while(fin.read((char*)&Customer,sizeof(Customer)))
		{
			
		if(Customer.id==tid)
		{   
			fin.seekp(-64,ios::cur);
			flag=1;
			pos=fin.tellg();
			printf("Enter the amount you want to enter:");
			scanf("%f",&bal);
		    Customer.balance+=bal;
			printf("Your new balance is:%f",Customer.balance);
			fin.write((char*)&Customer,sizeof(Customer));
			fin.close();
		}
		}
		if(flag==0)
		{
			printf("================================!!! ERROR !!!==========================================\n");
			printf("NO such account exist!! Visit main menu to create an account.");
		}
		
		return;
	}

    void withdraw()
	{   
		system("cls");
		int flag=0;
		fstream fin;
		int tid;
		float bal;
		int pos;
		fin.open("details.dat",ios::in|ios::out|ios::binary|ios::ate);
		printf("Enter the customer id: ");
		scanf("%d",&tid);
		fin.seekg(ios::beg);
		while(fin.read((char*)&Customer,sizeof(Customer)))
		{
			
		if(Customer.id==tid)
		{   
			fin.seekp(-64,ios::cur);
			flag=1;
			pos=fin.tellg();
			printf("Enter the amount you want to withdraw:");
			scanf("%f",&bal);
		     if(bal<Customer.balance)
			 {
				  Customer.balance-=bal;
				  printf("Your new balance is:%f",Customer.balance);
			 }
			
			 else
			 {
				printf("================================!!! ERROR !!!==========================================\n");
				printf("ypur current balance: %d",Customer.balance);
                printf("Not enough amount in your account");
			 }
			 
			fin.write((char*)&Customer,sizeof(Customer));
			fin.close();
		}
		}
		if(flag==0)
		{
			printf("================================!!! ERROR !!!==========================================\n");
			printf("NO such account exist!! Visit main menu to create an account.");
		}
		
		return;
	}


    void search()
{		
            system("cls");
			int tid;
			ifstream fin;
            fin.open("details.dat",ios::in|ios::binary|ios::app );
			int flag=0;
		    printf("Enter the customer id you are looking for:-");
        	scanf("%d",&tid);
            
            while(fin.read((char*)&Customer,sizeof(Customer)))
            {	
				if(Customer.id==tid)
				{
				printf("==================================Customer DETAILS=========================================\n"); 
                flag=1;
			    printf("Customer Name:%s",Customer.name);
				printf("\nContact Number:%lld",Customer.contact_no);
				printf("\nCity Name:%s",Customer.city);
				printf("\n");
                break;
				}
            	
            }

			fin.close();
			if(flag==0)
				{	printf("================================!!! ERROR !!!==========================================\n");
					printf("NO such account exist!! Visit main menu to create an account. \n");
				}                    
  		return;                  

}

void display()
{	
	system("cls");
	printf("==================================Customer DETAILS=========================================\n");	
	ifstream fin;
	fin.open("details.dat",ios::in|ios::binary|ios::app);
     
	while(fin.read((char*)&Customer,sizeof(Customer)))
		{
			printf("Customer Name:%s",Customer.name);
		    printf("\nCustomer ID:%d",Customer.id);
			printf("\nContact Number:%lld",Customer.contact_no);
		    printf("\nCity Name:%s",Customer.city);
		    printf("\nBalance:%f",Customer.balance);
			printf("\n---------------------------------------------------------------------------------------\n");
			printf("\n");

		}
	fin.close();
	printf("\n");
	return;
}

int main()
{
	int ch;
	do
	{	
		printf("\n---------------------------------- WELCOME TO BANK MANAGEMENT SYSTEM--------------------------------------");
		printf("\n\n");
		printf("Press 1 for New Customer registration.\n");
		printf("Press 2 to Display All Records of Customers.\n");
		printf("Press 3 to Search for your account.\n"); 
		printf("Press 4 to add balance to your account.\n");
		printf("Press 5 to withdraw money from your account.\n");
		printf("Press 6 to exit.\n ");
		printf("Enter your choice.\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
			insert();	
			break;
			case 2:				
			display();
			break;
			case 3:
			search();
			break;
			case 4:
			balance();
			break;
			case 5:
			withdraw();
			break;
			default:
			break;

		}
	}while(ch<6);
}
