#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

int count =0,login=0;
// Structure to represent a bank account
typedef struct BankAccount {
    int accountNumber;
    char accountHolderName[50];
    char pass[15];
    float balance;
}BankAccount;

BankAccount accounts[100];

int check_unique(int account_number)
{
    int i;
    for(i=0;i<count;i++)
    {
        if (accounts[i].accountNumber==account_number)
        {
            return 1;
        }
        
    }
    return 0;
}

void createAccount(BankAccount accounts[]) {    
       
        
        printf("Enter account holder name: ");
        scanf("%s", accounts[count].accountHolderName);
        printf("Enter password[upto 15 char]: ");
        scanf("%s", &accounts[count].pass); 

        printf("Enter initial balance: $");
        scanf("%f", &accounts[count].balance);

        accounts[count].accountNumber=(rand()%90000)+10000; 
        while((check_unique(accounts[count].accountNumber))==1)
        {
            accounts[count].accountNumber=(rand()%90000)+10000; 
        }

        printf("\n--------------------------------------\n");           
        printf("Account Number: %d\n",accounts[count].accountNumber);
        printf("\nAccount created successfully.\n");
    	count++;
        
}

void menu()
   {
   printf("\n--------------------------------------\n");
   printf("\nMAIN MENU\n1:account details\n2:deposit money\n3:withdraw money\n4:transfer money\n5:exit\n");
   
      
   }
void account_details(BankAccount tempAccount)
{


printf("Account Number: %d\n",tempAccount.accountNumber);
printf("Name: %s\n",tempAccount.accountHolderName);
printf("Current Balance: $%.2f\n",tempAccount.balance);
}

void afterlogin(BankAccount tempAccount)
{
int choice1,exit = 0;
		
	do
	{
	menu();
	printf("enter your choice: ");
    
	scanf("%d",&choice1);
	printf("--------------------------------------\n");
	switch (choice1)
	{
		case 1:
            account_details(tempAccount);
            break;
        case 2:
			float dep_amt;
   	        printf("DEPOSITING THE MONEY\n");
   	        printf("enter the amount : $");
   	        scanf("%f",&dep_amt);        
   	        tempAccount.balance+= dep_amt;
   	        printf("MONEY DEPOSITED\n");
            printf("current balance : $%.2f.\n",tempAccount.balance);
			break;
	    case 3:
	    	float with_amt;
            printf("WITHDRAW MONEY \n");
            printf("Enter the amount: $");
            scanf("%f",&with_amt);
            if(tempAccount.balance>=with_amt)
            {
                tempAccount.balance -= with_amt;
                printf("MONEY WITHDRAW\n");
                printf("current balance: $%.2f.\n",tempAccount.balance);
            }
            else
            {
               printf("\nWithdrawn amount cannot be greater than current balance.\n"); 
            }
		    break;
        case 4:
		    BankAccount otheraccount;
            float trans_amt;
            
            printf("TRANSFERRING MONEY\n");
		    
		    printf("enter the account no in which you want to transfer money: ");
		    scanf("%d",&otheraccount.accountNumber);
            if(check_unique(otheraccount.accountNumber)==1)
            {
                
                        printf("enter the amount:");
		                scanf("%f",&trans_amt);
                        if(tempAccount.balance>=trans_amt)
                        {
                            tempAccount.balance-=trans_amt;
                            otheraccount.balance+=trans_amt;
                            printf("money transferred\n");

                            
                        }
                        else
                        {
                            printf("\nTransfer amount cannot be greater than current balance.");
                            
                        }
                        
                    
               
            }
            else
            printf("Account Not Found.\n");
	        
	        break;
	    case 5: 
            exit = 1;
            break;
		
		default:
		printf("INVALID CHOICE !!!\n");
		break;   
	} 
    }while(exit == 0);
}


void loggingin(BankAccount accounts[])
{
	BankAccount tempAccount;
	int i=0;
	printf("Enter account number: ");
    scanf("%d", &tempAccount.accountNumber);
    
    
    if(check_unique(tempAccount.accountNumber))  
    { 
        printf("Enter Your Password: ");
        scanf("%s", &tempAccount.pass); 
        if(strcmp(tempAccount.pass,accounts[i].pass)==0)
        {
            printf("Login Successful\n");
            afterlogin(accounts[i]);
        }
        else
        {
            printf("Login Failed\n");
        } 
	    

    }
    
    
    else
    printf("Account Not Found.\n");
    //return i;	
}


int main() {
        
    
    int choice,exit;
	exit=0;
    printf("\nWelcome to the Bank Management System\n");
    do
	{
       
        printf("--------------------------------------\n");
        printf("1. Create an Account\n");
        printf("2. Logging in\n");      
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts);
                break;
            
            case 2:
            	loggingin(accounts);
            	break;
            case 3:
                printf("Goodbye! Have a nice day.\n");
                printf("--------------------------------------\n");
                exit = 1;
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
                break;
        }
    }while(exit == 0);

    return 0;
}

