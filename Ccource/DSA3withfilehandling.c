//LIBRARIES NEEDED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//STRUCTURE TO CREATE A BANK ACCOUNT
typedef struct BankAccount {
    char accountNumberStr[10];  
    char accountHolderName[50];
    char pass[15];
    float balance;
} BankAccount;

BankAccount accounts[100];

int count = 0;

//THIS FUNCTION MAKES SURE ACCOUNT NUMBERS AREN'T REPEATED
int check_unique(const char *accountNumberStr) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(accounts[i].accountNumberStr, accountNumberStr) == 0) {
            return 1;
        }
    }
    return 0;
}

//MENU THAT WILL BE DISPLAYED AFTER LOGIN
void menu()
   {
   printf("\n--------------------------------------\n");
   printf("\nMAIN MENU\n1:account details\n2:deposit money\n3:withdraw money\n4:transfer money\n5:exit\n");
         
   }
   
//THIS FUNCTION PUSHES THE ARRAY OF STRUCTURE TO THE CSV FILE   
void saveAccountsToCSV(BankAccount accounts[], int count) {
    FILE *file = fopen("accounts.csv", "w");
    int i;
    if (file == NULL) {
        printf("Error opening the CSV file.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        fprintf(file, "%s,%s,%s,%.2f\n",
            accounts[i].accountNumberStr,
            accounts[i].accountHolderName,
            accounts[i].pass,
            accounts[i].balance
        );
    }

    fclose(file);
}

//THIS FUNCTION GETS ACCOUNTS FROM EXISTING CSV FILE AND PUTS IT INTO THE ARRAY   
void loadAccountsFromCSV(BankAccount accounts[], int *count) {
    FILE *file = fopen("accounts.csv", "r");
    if (file == NULL) {
        printf("CSV file not found. Starting with no accounts.\n");
        return;
    }

    *count = 0;
    while (*count < 100 && fscanf(file, "%9[^,],%49[^,],%14[^,],%f\n",
        accounts[*count].accountNumberStr,
        accounts[*count].accountHolderName,
        accounts[*count].pass,
        &accounts[*count].balance) != EOF) {
        (*count)++;
    }

    fclose(file);
}

//CREATING A NEW ACCOUNT
void createAccount() {
    if (count >= 100) {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return;
    }

    BankAccount newAccount;
    printf("Enter account holder name: ");
    scanf("%s", newAccount.accountHolderName);
    printf("Enter password [up to 15 characters]: ");
    scanf("%s", newAccount.pass);
    printf("Enter initial balance: $");
    scanf("%f", &newAccount.balance);

    // Generate a unique account number as a string
    do {
    
        sprintf(newAccount.accountNumberStr, "%d", (rand() % 90000) + 10000);
    } while (check_unique(newAccount.accountNumberStr));

    accounts[count] = newAccount;
    count++;

    // Save the updated account information to the CSV file
    saveAccountsToCSV(accounts, count);

    printf("\n--------------------------------------\n");
    printf("Account Number: %s\n", newAccount.accountNumberStr);
    printf("\nAccount created successfully.\n");
}

void displayMainMenu() {
    printf("\n--------------------------------------\n");
    printf("\nMAIN MENU\n1: Create Account\n2: Log In\n3: Exit\n");
}

int login() {
    char enteredAccountNumberStr[10];
    printf("Enter account number: ");
    scanf("%s", enteredAccountNumberStr);
    
    
    int accountIndex = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(accounts[i].accountNumberStr, enteredAccountNumberStr) == 0) {
            accountIndex = i;
            break;
        }
    }

    if (accountIndex != -1) {
        char enteredPassword[15];
        printf("Enter Your Password: ");
        scanf("%s", enteredPassword);
        if (strcmp(accounts[accountIndex].pass, enteredPassword) == 0) {
            printf("Login Successful\n");
        } else {
            printf("Login Failed\n");
            accountIndex = -1;
        }
    } else {
        printf("Account Not Found.\n");
    }

    return accountIndex;
}

void accountDetails(BankAccount tempAccount) {
    printf("Account Number: %s\n", tempAccount.accountNumberStr);
    printf("Name: %s\n", tempAccount.accountHolderName);
    printf("Current Balance: $%.2f\n", tempAccount.balance);
}

void afterLogin(int accountIndex) {
    int choice1, exit = 0;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice1);
        printf("--------------------------------------\n");

        switch (choice1) {
            case 1:
                accountDetails(accounts[accountIndex]);
                break;
            case 2:
                float dep_amt;
                printf("DEPOSITING THE MONEY\n");
                printf("Enter the amount: $");
                scanf("%f", &dep_amt);
                accounts[accountIndex].balance += dep_amt;
                printf("MONEY DEPOSITED\n");
                printf("Current balance: $%.2f.\n", accounts[accountIndex].balance);
                break;
            case 3:
                float with_amt;
                printf("WITHDRAW MONEY\n");
                printf("Enter the amount: $");
                scanf("%f", &with_amt);
                if (accounts[accountIndex].balance >= with_amt) {
                    accounts[accountIndex].balance -= with_amt;
                    printf("MONEY WITHDRAWN\n");
                    printf("Current balance: $%.2f.\n", accounts[accountIndex].balance);
                } else {
                    printf("\nWithdrawn amount cannot be greater than the current balance.\n");
                }
                break;
            case 4:
                BankAccount otherAccount;
                float trans_amt;
                printf("TRANSFERRING MONEY\n");
                printf("Enter the account number to which you want to transfer money: ");
                scanf("%s", otherAccount.accountNumberStr);

                int recipientIndex = -1;
                for (int i = 0; i < count; i++) {
                    if (strcmp(accounts[i].accountNumberStr, otherAccount.accountNumberStr) == 0) {
                        recipientIndex = i;
                        break;
                    }
                }

                if (recipientIndex != -1) {
                    printf("Enter the amount: ");
                    scanf("%f", &trans_amt);
                    if (accounts[accountIndex].balance >= trans_amt) {
                        accounts[accountIndex].balance -= trans_amt;
                        accounts[recipientIndex].balance += trans_amt;
                        printf("Money transferred\n");
                    } else {
                        printf("\nTransfer amount cannot be greater than the current balance.\n");
                    }
                } else {
                    printf("Recipient account not found.\n");
                }
                break;
            case 5:
                exit = 1;
                break;
            default:
                printf("INVALID CHOICE !!!\n");
                break;
        }
    } while (exit == 0);
}

int main() {
    int choice;
    printf("\nWelcome to the Bank Management System\n");

    // Load existing accounts from the CSV file
    loadAccountsFromCSV(accounts, &count);

    do {
        displayMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("--------------------------------------\n");

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2: {
                int loggedInAccount = login();
                if (loggedInAccount != -1) {
                    afterLogin(loggedInAccount);
                }
            }
            break;
            case 3:
                printf("Goodbye! Have a nice day.\n");
                break;
            default:
                printf("Invalid choice. Please choose a valid option.\n");
                break;
        }
    } while (choice != 3);

    // Save the account information to the CSV file before exiting
    saveAccountsToCSV(accounts, count);

    return 0;
}
