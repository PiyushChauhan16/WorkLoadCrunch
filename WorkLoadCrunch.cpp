#include <iostream>
#include <string.h>
#include <fstream>
#include <ios>
#include <limits>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unordered_map>
#include <iomanip>
#include <conio.h>

using namespace std;

class Company_X;

float income_tax (Company_X); 

class Basic_Banking_function{

    protected:

    string name;
    char gender;
    string city;
    string address;
    long int account_number;
    static long int assign_account_number;
    long long unsigned int contact_number;
    int PIN;
    long int balance;

    public:

    virtual void new_customer () = 0;
    virtual void search_customer () = 0;
    virtual void display_customer () = 0;
    virtual void withdraw_money (int) = 0;
    virtual void deposit_money (int) = 0;
    virtual void check_balance () = 0;
};

long int Basic_Banking_function :: assign_account_number = 1;



class PaymentSlip_basic_functions {

    protected:


    string employee_name;
    int employee_id;
    string employee_city;
    string employee_address;
    int salary_per_month;
    string department;
    long long unsigned int employee_contact_number;
    char employee_gender;

    public : 

    static int assign_employee_id;
    virtual void new_employee () = 0;
    virtual void payment_slip () = 0;

};

int PaymentSlip_basic_functions :: assign_employee_id = 101;



class Axis_Bank : public Basic_Banking_function {

    
    public: 

    void new_customer ();
    void new_customer (Company_X);
    void search_customer ();
    void display_customer ();
    void withdraw_money (int);
    void deposit_money (int);
    void check_balance ();
};



class Company_X : public PaymentSlip_basic_functions {

    
    public :

    friend void Axis_Bank :: new_customer (Company_X); 
    friend float income_tax (Company_X);

    void new_employee ();
    void payment_slip ();
    void to_canteen (int);
    bool search_employee (int);

    
};


class Canteen {

    public :
    

    void interface (char);
    int bill_generator (char,int,int);
};




void Axis_Bank :: new_customer (Company_X details){

  system("cls");
        printf("================================================= AXIS_BANK ==============================================================\n");
		printf("=================================== Welcome To Customer Registration Page ================================================\n\n");

    ofstream fout ("BankDetails.dat", ios :: out | ios :: binary | ios :: app);

    cout << "LOADING DATA FROM YOUR REGISTERED SYSTEM......\n\n";
    name = details.employee_name;
    city = details.employee_city;
    address = details.employee_address;
    contact_number = details.employee_contact_number;
    gender = details.employee_gender;

    cout << "Generate account number (Format : 1XXXXX) : ";
    cin >> account_number;
   


    cin.ignore(numeric_limits<streamsize>::max(),'\n');
     
    cout << "Set 4 digit PIN : ";
    cin >> PIN;


    cout << "Deposit Rs. 1000 (or more) to open you account : ";
    cin >> balance;

    fout. write ((char*)this, sizeof (*this));
    fout. close();

    cout << "\n\n--- >>> NEW ACCOUNT CREATED <<< ---\n";    

}


void Axis_Bank :: new_customer (){

       system("cls");
        printf("================================================= AXIS_BANK ==============================================================\n");
		printf("=================================== Welcome To Customer Registration Page ================================================\n\n");

        ofstream fout ("BankDetails.dat", ios :: out | ios :: app);


		if(!fout)
		{	printf ("Sorry, Techincal fault, Try later!\n");
			return;	
		}

        cout << "-- > REGISTRATION FORM \n\n";


		cout << "Name : ";
        cin >> name;

        cin.ignore(numeric_limits<streamsize>::max(),'\n');

		printf("Enter your gender\n Press M for Male and F for Female : ");
		cin >> gender;
        
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        cout << "Enter contact number : ";
        cin >> contact_number;

        cin.ignore(numeric_limits<streamsize>::max(),'\n');

    
        cout << "Generate account number (Format : 1XXXXX) : ";
        cin >> account_number;
        

        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        
        cout << "Enter any 4 digit PIN : ";
        cin >> PIN;
       
        
        

        cin.ignore(numeric_limits<streamsize>::max(),'\n');

	    cout << "Enter City : ";
        getline (cin, city);


        cout << "Enter Address : ";
        getline (cin, address);
        

        do {

            cout << "Deposit Rs. 1000 or greater to open the account : ";
            cin >> balance;
        } while (balance < 1000);

		fout.write((char*) this, sizeof(*this));
		fout.close();

        cout << "\n\n--- >>> NEW ACCOUNT CREATED <<< ---\n";  


}


void Axis_Bank :: search_customer (){


       system("cls");
        printf("================================================= AXIS_BANK ==============================================================\n");
		printf("============================================== SEARCH EMPLOYEE ===========================================================\n\n");

    
    int customer_account_number;
    bool flag = true;

    ifstream fin ("BankDetails.dat", ios :: in);

    if (!fin){
        printf ("Sorry, Techincal fault, Try later!\n");
    }

    else {

        
            cout << "Enter your account number : ";
            cin >> customer_account_number;
         

        while (fin.read ((char*) this, sizeof (*this))){

            if (this -> account_number == customer_account_number && flag){
                
                cout << "THIS ACCOUNT EXISTS !!\n";
                 
                flag = false;
            }
        }

        fin.close ();

       

        if (flag == 1){
            cout << "Sorry, No such account exist! \n\n PRESS 1 to create new account\n PRESS 0 to exit\n\n";
            cout << "Enter your choice:";
        
            int choice;

            cin >> choice;

            if (choice == 1){
                new_customer ();
            }
        }

        return;
    }
}


void Axis_Bank :: withdraw_money (int i = 0){

    system("cls");
        printf("================================================= AXIS_BANK ==============================================================\n");
		printf("=============================================== WITHDRAW MONEY ===========================================================\n\n");
	

    long int customer_account_number;
    int customer_PIN,amount,flag = true;

    fstream f ("BankDetails.dat", ios :: in | ios :: out | ios :: binary);


    if (i != 0){

        cout << "---->>>> PAY Rs. " << i << " <<<<----" <<endl << endl;

    }

    cout << "Enter your account number : ";
    cin >> customer_account_number;

    cout << "Enter your PIN : ";
    cin >> customer_PIN;

    while (f.read ((char*) this, sizeof (*this))){
       
       if (account_number == customer_account_number && PIN == customer_PIN){

           
           f.seekg (-104, ios :: cur);

           if (i == 0){
               cout << "Enter the amount : ";
               cin >> amount;
           }

           else {
               amount = i;
           }
           

           if ((balance - amount) < 0){
               cout << "Entered amount is INVALID\n\n";
               cout << "Your current balance : ";
               cin >> balance;
           }

           else{
               balance -= amount;
               flag = false;
               if (i == 0){
                   cout << "\n\n COLLECT YOUR CASH !!!\n\n";
                   cout << "\n\n MESSAGE: -\nRs. " << amount << " debited from your account with account No. " << account_number << endl << endl;
                   cout << "Your Current Balance : " << balance << endl;
               }

               else{
               cout << "\n\n MESSAGE: -\nRs. " << amount << " debited from your account with account No. " << account_number << endl << endl;
               cout << "Your Current Balance : " << balance << endl;}

               f.write ((char*) this, sizeof (*this));
               f.close ();
           }

       }
    }

    if (flag){

        char choice;
        cout << "NO such accont exist !!\n";
        cout << "Kindly check your details and TRY AGAIN!!\n\n";

        cout << "Do you want to create an account at Axis Bank";
        cout << "\nPress 'Y' to confirm OR Press 'N' to cancel : ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y'){
            new_customer ();
        }
        else{
            return;
        }
    }

}


void Axis_Bank :: deposit_money (int i = 0){

    if (i == 0){
        system("cls");
    }
    
        printf("================================================= AXIS_BANK ==============================================================\n");
		printf("=============================================== DEPOSIT MONEY ============================================================\n\n");
	

    long int customer_account_number;
    int customer_PIN,amount;
    bool flag = true;

    fstream f ("BankDetails.dat", ios :: in | ios :: out | ios :: binary);

    
        cout << "Enter your account number : ";
        cin >> customer_account_number;

    
    

    while (f.read ((char*) this, sizeof (*this))){
       
       if (account_number == customer_account_number){

           f.seekg (-104, ios :: cur);

           if (i == 0){
               cout << "Enter the amount : ";
               cin >> amount;
           }

           else {
               amount = i;
           }

           flag = false;

            balance += amount;
            cout << "\n\n YOUR MONEY HAS BEEN DEPOSITED !!!\n\n";
            cout << "\n\n MESSAGE: -\nRs. " << amount << " credited into your account with account No. " << account_number << endl << endl;
            cout << "Your Current Balance : " << balance << endl;


            f.write ((char*) this, sizeof (*this));
            f.close ();
           
       }
    }

    if (flag){

        char choice;
        cout << "NO such accont exist !!\n";
        cout << "Kindly check your details and TRY AGAIN!!\n\n";

        cout << "Do you want to create an account at Axis Bank";
        cout << "\nPress 'Y' to confirm OR Press 'N' to cancel : ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y'){
            new_customer ();
        }
        else{
            return;
        }
    }

}


 void Axis_Bank :: display_customer (){

        system("cls");
        printf("================================================= AXIS_BANK ==============================================================\n");
		printf("============================================== DISPLAY CUSTOMER ==========================================================\n\n");
	


    ifstream fin ("BankDetails.dat", ios :: in | ios :: binary  );

    if (fin.eof()){
        cout << "NO RECORDS TO DISPLAY!!";
    }

    while (fin.read ((char*) this, sizeof (*this))){
        cout << "account no:" << account_number << endl;
        cout << "name :" << name << endl;
        cout << "balance :" << balance << endl;
        cout << "city:" << city << endl;
        cout << "address :" << address << endl;
        cout << "contact_number :" << contact_number << endl;
    }

    fin.close ();
}


void Axis_Bank :: check_balance (){

    system("cls");
        printf("================================================= AXIS_BANK ==============================================================\n");
		printf("=============================================== CHECK BALANCE ============================================================\n\n");
	

    ifstream fin ("BankDetails.dat", ios :: in | ios :: binary);

    int customer_account_number;
    int customer_PIN;

    cout << "Enter your account number : ";
    cin >> customer_account_number;

    cout << "Enter your PIN : ";
    cin >> customer_PIN;

    while (fin.read ((char*)this, sizeof (*this))){

        if (PIN == customer_PIN && account_number == customer_account_number){

            cout << "\n\n YOUR BALANCE : " << balance << endl;
        }
    }
}





float income_tax (Company_X details){


    if (details. salary_per_month > 25000 && details.salary_per_month <= 50000){
        
        return 0.98;
    }

    else if (details.salary_per_month > 50000 && details.salary_per_month <= 75000){

        return 0.97;
    }

    else if (details.salary_per_month > 75000 && details.salary_per_month <= 100000){

       return 0.96;
    }

    else if (details.salary_per_month){

        return 0.95;
    }
}



template<typename T> void printElement(T t, const int& width){
    const char separator    = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}



void Company_X :: new_employee () {
    
    system("cls");
        printf("================================================= COMPANY_X ==============================================================\n");
		printf("========================================= WELCOME TO REGISTRATION FORM ====================================================\n\n");
	

     

    ofstream fout ("CompanyDetails.dat", ios :: out | ios :: binary | ios :: app);

    cout << "-- > NEW EMPLOYEE REGISTRATION FORM\n\n";

    cout << "Employee ID (Format : 1XX ) : ";
    cin >> employee_id;

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter employee name : ";
    cin >> employee_name;

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter your Gender: -\nM for Male && F for Female : ";
    cin >> employee_gender;

     cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter city : ";
    getline (cin,employee_city);


    cout << "Enter address : ";
    getline (cin,employee_address);


    cout << "Enter salary : ";
    cin >> salary_per_month;

     cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter department : ";
    cin >> department;

     cin.ignore(numeric_limits<streamsize>::max(),'\n');

    cout << "Enter contact number : ";
    cin >> employee_contact_number;

    

    fout.write ((char*) this, sizeof (*this));
    fout.close ();


    Axis_Bank ab;
    ab. new_customer (*this);

}



void Company_X :: to_canteen (int emp_code){

    fstream f ("CompanyDetails.dat", ios :: in | ios :: out | ios :: app | ios :: binary);

    while (f.read ((char*)this, sizeof (*this))){

        if (emp_code == employee_id){

            Canteen obj;
            obj.interface(employee_gender);
            
        }
    }

    f.close ();
}


bool Company_X :: search_employee (int emp_code){

    fstream f ("CompanyDetails.dat", ios :: in | ios :: out | ios :: app | ios :: binary);

    while (f.read ((char*)this, sizeof (*this))){

        if (emp_code == employee_id){

            return true;
            
        }
    }

    f.close ();
    return false;
}



void Company_X :: payment_slip (){

    system ("cls");
       printf("================================================= COMPANY_X ==============================================================\n");
 		printf("=========================================== PAYMENT SLIP GENERATOR =======================================================\n\n");
	

    int emp_code;

    cout << "Enter the Employee ID : ";
    cin >> emp_code;

    cout << "\n\n------------------------------------------------------------------------------------------\n\n";

    cout << setw (50) << "Company_X\n" << setw (55) << "EMPLOYEE PAYMENT SLIP";
    cout << "\n\n------------------------------------------------------------------------------------------\n\n";

    printElement("ID", 15);
    printElement("NAME", 15);
    printElement("GENDER", 15);
    printElement("SALARY", 15);
    printElement("DEPARTMENT", 15);
    printElement("CONTACT NUMBER", 15);
    cout << "\n\n------------------------------------------------------------------------------------------\n\n";
    
    ifstream fin ("CompanyDetails.dat", ios :: in);

    while (fin.read ((char*)this, sizeof(*this))){        
        if (emp_code == employee_id){

            salary_per_month =  (salary_per_month) * income_tax (*this);


            printElement (employee_id,15);
            printElement (employee_name,15);
            printElement (employee_gender,15);
            printElement (salary_per_month,15);
            printElement (department,15);
            printElement (employee_contact_number,15);

            cout << "\n\n------------------------------------------------------------------------------------------\n\n";

             Axis_Bank obj;
             obj. deposit_money (salary_per_month);
            break;
        }
    }

}


int Canteen :: bill_generator (char category, int choice, int quantity){

    switch (category){
        
        case 'B' : switch (choice){
            case 1: return 20 * quantity;
            break;
            case 2: return 25 * quantity;
            break;
            case 3: return 30 * quantity;
        }

        break;

        case 'S' :switch (choice){
            case 1: return 25 * quantity;
            break;
            case 2: return 40 * quantity;
            break;
            case 3: return 45 * quantity;
        }
    }
}


void Canteen :: interface (char gender){
    
    system("cls");
        printf("================================================= COMPANY_X ==============================================================\n");
		printf("============================================= WELCOME TO CANTEEN =========================================================\n\n");
	

    int choice, bill = 0, quantity;
    char confirm;
    
    cout << "Good Morning ";
    if (gender == 'F' || gender == 'f'){

        cout <<"Mam !!\n\n";
    }

    else{

        cout <<"Sir !!\n\n";
    }

    cout << "\n\n================TODAY's HOT MENU===================\n\n";

    cout << "<<<<< BEVERAGES >>>>>\n\n";

    cout << "1. COFFEE : Rs. 20\n";
    cout << "2. TEA : Rs. 25\n";
    cout << "3. SMOOTHIE : Rs. 30\n";


    cout << "\n<<<<< SNACKS >>>>>\n\n";

    cout << "1. VEG SANDWICH : Rs. 25\n";
    cout << "2. PIZZA SANDWICH : Rs. 40\n";
    cout << "3. MAGGI : Rs. 45\n\n";




    cout << "What would you like to have in \"BEVERAGES\" today ?\n";
    cout << "Press 'Y' to confirm OR Press 'N' to cancel : ";
    cin >> confirm;
    
    
    while (confirm == 'Y' || confirm == 'y'){

        cout << "\n\nEnter the number against the item you would like to order : ";
        cin >> choice;

        cout << "Enter the quantity of the ordered item : ";
        cin >> quantity;


        cout << "\nYou want Item Number : - " << choice << " with quantity : - " << quantity << endl << endl;
        cout << "Press 'Y' to confirm OR Press 'N' to cancel : -";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y'){

            bill += bill_generator ('B',choice,quantity);
            cout << "\n --------->>>>> ORDER  TAKEN !!! <<<<<----------\n\n";
        }

        
        
        cout << "\n\nWould you like to order more \"BEVERAGES\" ?\n";
        cout << "Press 'Y' to order OR Press 'N' to cancel : -";
        cin >> confirm;
        
    } 




    cout << "\n\nWhat would you like to have in \"SNACKS\" today ?\n";
    cout << "Press 'Y' to confirm OR Press 'N' to cancel : ";
    cin >> confirm;
    
    while (confirm == 'Y' || confirm == 'y'){

        cout << "\n\nEnter the number against the item you would like to order : ";
        cin >> choice;

        cout << "Enter the quantity of the ordered item : ";
        cin >> quantity;

        cout << "\nYou want Item Number : - " << choice << " with quantity : - " << quantity << endl << endl;
        cout << "Press 'Y' to confirm OR Press 'N' to cancel : -";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y'){

            bill += bill_generator ('S',choice,quantity);
            cout << "\n --------->>>>> ORDER  TAKEN !!! <<<<<----------\n\n";
        }

        
        
        cout << "\n\nWould you like to order more \"SNACKS\" ?\n";
        cout << "Press 'Y' to order OR Press 'N' to cancel : -";
        cin >> confirm;
        
    } 


    cout << "\n\nYOUR TOTAL BILL : " << bill;

    Axis_Bank pay_bill;
    pay_bill.withdraw_money (bill);
     
    
    
}


 


void employee_login (){

    system("cls");
        printf("================================================= COMPANY_X ==============================================================\n");
		printf("=============================================== EMPLOYEE SPACE ===========================================================\n\n");
	


    string username;
    int password,choice;
    char confirm;
    Company_X X_obj;
    Axis_Bank Axis_obj;
    
    do{
        cout << "Enter Username : ";
        cin >> username;
    
        cout << "password : ";
        cin >> password;

        if (username != "employee" || !X_obj.search_employee (password)){
            cout << "\n\n--->>> WRONG ID OR PASSWORD. TRY AGAIN <<<---\n\n";
        }


     } while (username != "employee" || !X_obj.search_employee (password));

    do {

    cout << "\n\n-- > MAIN MENU \n\n";

    cout << "1. Open new account at Axis Bank\n";
    cout << "2. Withdraw Money\n";
    cout << "3. Deposit Money\n";
    cout << "4. Check Balance\n";
    cout << "5. Visit X_Canteen\n\n";

    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice){
        
        case 1 : Axis_obj.new_customer ();
        break;

        case 2 : Axis_obj.withdraw_money ();
        break;

        case 3 : Axis_obj.deposit_money ();
        break;

        case 4 : Axis_obj.check_balance ();
        break;

        case 5 : X_obj.to_canteen (password);
        break;
    }
    cout << "\n\nDo you want to continue ?\n";
    cout << "Press 'Y' to continue OR Press 'N' to cancel : ";
    cin >> confirm;

    } while (confirm == 'Y' || confirm == 'y'); 

}


void manager_login (){

    system ("cls");
        printf("================================================= COMPANY_X ==============================================================\n");
		printf("=============================================== MANAGER SPACE ============================================================\n\n");
	
    string username;
    int password, choice;
    char confirm;

    Axis_Bank Axis_obj;
    

    do{

        cout << "Enter Username : ";
        cin >> username;

        cout << "Password : ";
        cin >> password;

        if (username != "manager" || password != 1223334444){
            cout << "\n\n--->>> WRONG ID OR PASSWORD. TRY AGAIN <<<---\n\n";
        }

    }while (username != "manager" || password != 1223334444);

    do {

    cout << "\n\n-- > MAIN MENU \n\n";

    cout << "1. Register new employee\n";
    cout << "2. Open new account at Axis Bank\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Deposit Money\n";
    cout << "5. Check Balance\n";
    cout << "6. Search an employee Axis Bank account\n";
    cout << "7. Generate payment slip of an employees\n\n";

    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice){
        
        case 1 :{Company_X X_obj;
                X_obj.new_employee ();}
        break;

        case 2 : Axis_obj.new_customer ();
        break;

        case 3 : Axis_obj.withdraw_money ();
        break;

        case 4 : Axis_obj.deposit_money ();
        break;

        case 5 : Axis_obj.check_balance ();
        break;

        case 6 : Axis_obj.search_customer();
        break;

        case 7 : {Company_X X_obj;
        X_obj.payment_slip();}
        break;
    } 
    
    cout << "\n\nDo you want to continue ?\n";
    cout << "Press 'Y' to continue OR Press 'N' to cancel : ";
    cin >> confirm;

    } while (confirm == 'Y' || confirm == 'y'); 

}
 








int main (){

    /// For an "EMPLOYEE", username = "employee" and password = < employee id >
   ///  For a "MANAGER", username = "manager" and password = 122334444



    int choice;
      system ("cls");

    printf("================================================= COMPANY_X ==============================================================\n");
	printf("======================================= A PLACE WHERE INNOVATION HAPPENS =================================================\n\n");
	


    do {

        cout << "1. Manager Login\n";
        cout << "2. Employee Login\n\n";
        
        cout << "Enter your choice : ";
        cin >> choice;
    } while (choice > 2);

    switch (choice){

        case 1 : manager_login ();
        break;

        case 2 : employee_login ();
        break;
    }
     
}