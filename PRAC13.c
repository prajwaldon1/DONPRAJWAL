#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Structure to hold account information
typedef struct {
    int accountNumber;
    char accountHolderName[100];
    double balance;
} Account;

// Array to store accounts
Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

// Function prototypes
void createAccount();
void depositMoney();
void withdrawMoney();
void displayAccount();
void displayAllAccounts();
void menu();

int main() {
    while (1) {
        menu();
    }
    return 0;
}

// Menu function to display options
void menu() {
    int choice;
    printf("Banking System Menu\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Display Account\n");
    printf("5. Display All Accounts\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            createAccount();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            withdrawMoney();
            break;
        case 4:
            displayAccount();
            break;
        case 5:
            displayAllAccounts();
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
    }
}

// Function to create a new account
void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached!\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    printf("Enter account holder's name: ");
    getchar(); // to consume the newline character from previous input
    fgets(newAccount.accountHolderName, 100, stdin);
    newAccount.accountHolderName[strcspn(newAccount.accountHolderName, "\n")] = 0; // Remove newline character
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("Account created successfully!\n");
}

// Function to deposit money into an account
void depositMoney() {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Amount deposited successfully!\n");
}

// Function to withdraw money from an account
void withdrawMoney() {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }

    if (accounts[accountNumber - 1].balance < amount) {
        printf("Insufficient balance!\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Amount withdrawn successfully!\n");
}

// Function to display account information
void displayAccount() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    Account account = accounts[accountNumber - 1];
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Holder: %s\n", account.accountHolderName);
    printf("Balance: %.2lf\n", account.balance);
}

// Function to display all accounts
void displayAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Account Holder: %s\n", accounts[i].accountHolderName);
        printf("Balance: %.2lf\n", accounts[i].balance);
        printf("-------------------------------\n");
    }
}

// Additional functions to expand the code further
void deleteAccount() {
    int accountNumber;

    printf("Enter account number to delete: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    for (int i = accountNumber - 1; i < accountCount - 1; i++) {
        accounts[i] = accounts[i + 1];
    }
    accountCount--;

    printf("Account deleted successfully!\n");
}

void updateAccount() {
    int accountNumber;
    char newName[100];

    printf("Enter account number to update: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter new account holder's name: ");
    getchar(); // to consume the newline character from previous input
    fgets(newName, 100, stdin);
    newName[strcspn(newName, "\n")] = 0; // Remove newline character

    strcpy(accounts[accountNumber - 1].accountHolderName, newName);
    printf("Account updated successfully!\n");
}

void calculateInterest() {
    double interestRate;
    printf("Enter annual interest rate (in %%): ");
    scanf("%lf", &interestRate);

    for (int i = 0; i < accountCount; i++) {
        double interest = accounts[i].balance * (interestRate / 100);
        accounts[i].balance += interest;
    }

    printf("Interest calculated and added to all accounts successfully!\n");
}

void menuExpanded() {
    int choice;
    printf("Banking System Menu\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Display Account\n");
    printf("5. Display All Accounts\n");
    printf("6. Delete Account\n");
    printf("7. Update Account\n");
    printf("8. Calculate Interest\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            createAccount();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            withdrawMoney();
            break;
        case 4:
            displayAccount();
            break;
        case 5:
            displayAllAccounts();
            break;
        case 6:
            deleteAccount();
            break;
        case 7:
            updateAccount();
            break;
        case 8:
            calculateInterest();
            break;
        case 9:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
    }
}

int mainExpanded() {
    while (1) {
        menuExpanded();
    }
    return 0;
}

int main() {
    // Choose main function to run
    mainExpanded();
    // Or use basic main
    // main();
    return 0;
}
