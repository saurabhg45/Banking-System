////Develop a C++ program to simulate a basic banking system.
//Implement essential banking functionalities such as creating accounts, depositing, withdrawing, and checking balances.
//Ensure account validation, minimum balance requirements, and error handling.
//Attributes:
//name (string): Name of the account holder.
//gender (char): Gender of the account holder (e.g., 'M' for male, 'F' for female).
//amount (double): Current balance in the account.
//accountNumber (int): Unique, auto-generated account number.
//Methods:
//createAccount(): Generates a unique account number and initializes other attributes.
//deposit(double amount): Adds the specified amount to the account balance, ensuring it's non-negative.
//withdraw(double amount): Subtracts the specified amount from the account balance, ensuring it doesn't fall below the minimum balance.
//checkBalance(): Returns the current account balance.
//The minimum balance required to open an account is 5000.
//Withdrawals cannot reduce the balance below the minimum balance.
//Implement appropriate error handling for invalid inputs, insufficient funds, and other potential issues.


#include<iostream>
using namespace std;
class Account{
	private:
		string name,gender;
		
		double amount;
		int acc_no;
		static int account_number_generator;
		
		
	public:
		void create_acc(string n,string g,double amt){
			acc_no=++account_number_generator;
			name=n;
			gender=g;
			amount=amt;
			cout<<"\nHello, "<<name<<" your account is created and account number is : "<<acc_no;
			
		}
		void deposit(double amt)
    	{
        	if(amt<0)
            	cout<<"\n Entered negative amount : "<<amt;
        	else
        		{
            		amount=amount+amt;
            		checkBalance();
        	}
    	}
		void withdraw(double amt){
			if(amount-amt<5000){
				cout<<"\nInsufficient balance, please try again..";
			}
			else{
				amount-=amt;
				checkBalance();
			}
		}
		

		
		void checkBalance(){
			cout<<"\nHi "<<name<<" ,Your account number : "<<acc_no<<" and balance : "<<amount<<endl;
		}
		
		int check_acc(){
			return acc_no;
		}
		
};
int Account::account_number_generator=202400;
main(){
	Account bank[100];
	int accounts=0;
	int acc_no;
	double amount;
	int flag;
	int ch;
	Account a;
	string n,g;
	int dest_acc;
	double amt;
	
	do{	
		cout<<"\n---------------------------";
		cout<<"\n....WELL COME TO OUR BANK....";
		cout<<"\n---------------------------";
		cout<<"\n1. Create Account";
		cout<<"\n2. Diposite Money";
		cout<<"\n3. Withdraw Money";
		cout<<"\n4. Check Balance";
		cout<<"\n5. Transfer Money";
		cout<<"\n0 Exit";
		
		cout<<"\n---------------------------";
		cout<<"\nEnter choice: ";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"\nEnter name:";
            	cin>>n;
            	cout<<"\nEnter gender:";
            	cin>>g;
            	while(1)
            	{
                cout<<"\nEnter amount>=5000 to open account:";
                cin>>amt;
                if(amt>=5000)
                {
               
                    a.create_acc(n,g,amt);
                    break;
                }
                cout<<"\nMinimum Amount to open account is 5000";    
            	}
            	bank[accounts++]=a;//account added to bank array
            	break;
			
			case 2:
				cout<<"\nEnter account number : ";
				cin>>acc_no;				
				for(int i=0;i<accounts;i++)
                {
                    if(bank[i].check_acc()==acc_no)
                    {
                        cout<<"\nAccount found:";
                        bank[i].checkBalance();
                        cout<<"\nEnter amount to deposit:";
                        cin>>amount;
                        bank[i].deposit(amount);
                        flag=1;//found
                        break;
                    }
                }
                if(flag==0)
                    cout<<"\nAccount "<<acc_no<<" not found";
                break;
            case 3:
                cout<<"\nEnter Account number:";
                cin>>acc_no;
                flag=0;
                for(int i=0;i<accounts;i++)
                {
                    if(bank[i].check_acc()==acc_no)
                    {
                        cout<<"\nAccount found:";
                        bank[i].checkBalance();
                        cout<<"\nEnter amount to withdraw:";
                        cin>>amount;
                        bank[i].withdraw(amount);
                        cout<<"\nYour amount "<<amount<<" withdraw sucessfully...";
                        flag=1;//found
                        break;
                    }
                }
                if(flag==0)
                    cout<<"\nAccount "<<acc_no<<" not found";
                break;
               
            case 4:
                cout<<"\nEnter Account number:";
                cin>>acc_no;
                flag=0;
                for(int i=0;i<accounts;i++)
                {
                    if(bank[i].check_acc()==acc_no)
                    {
                        cout<<"\nAccount found:";
                        bank[i].checkBalance();
                        flag=1;//found
                        break;
                    }
                }
                if(flag==0)
                    cout<<"\nAccount "<<acc_no<<" not found";
                break;
                
            case 5:
            	double amount1;
                int dest_acc;
            	
            	cout<<"\nEnter account number:";
                cin>>acc_no;
                cout<<"\nEnter destination account number: ";
                cin>>dest_acc;
                flag=0;
                for(int i=0;i<accounts;i++)
                
                {	if(bank[i].check_acc()==acc_no ){
				
						for(int j=1;j<accounts;j++){
                	
				
                    		if(bank[j].check_acc()==dest_acc)
                    	{
                        cout<<"\nAccount found successfully\n";
                        bank[i].checkBalance();
                        bank[j].checkBalance();
                        cout<<"\nEnter amount to withdraw: ";
                        cin>>amount1;
                        cout<<amount1<<" is transfered successfully on "<<dest_acc<<" account number.";
                        bank[i].withdraw(amount1);
                        
                        bank[j].deposit(amount1);
                        
                        
                        flag=1;//found
                        break;
                    }}
                }}
                if(flag==0)
                    cout<<"\nAccount "<<acc_no<<" not found";

                break;
            	
            case 0:
                    cout<<"Thanks for banking with us.....";
                    break;
            default:
                    cout<<"Wrong option selected";
                    break;
                }
				
				
		}while(ch!=0);
	
}
