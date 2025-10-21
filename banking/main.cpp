#include <iostream>
#include <vector>

using namespace std;

struct Account
{
    string name;
    int balance;
    string currency;
};

class BankAccount
{
public:
    vector<Account> accounts;
    void listAccounts()
    {
        if (accounts.empty())
        {
            cout << "No accounts found.\n";
            return;
        }

        cout << "\n--- Account List ---\n";
        for (int i = 0; i < accounts.size(); i++)
        {
            cout << (i + 1) << ". Account Name: " << accounts[i].name
                 << ", Balance: " << accounts[i].balance
                 << " " << accounts[i].currency << "\n";
        }
        cout << "-------------------\n\n";
    }
    void createAccount(string accountname, string currency)
    {
        for (Account account : accounts)
        {
            if (account.name == accountname)
            {
                cout << "Account with this name already exists.\n";
                return; // Exit if account already exists
            }
        }
        Account newAccount;
        newAccount.name = accountname;
        newAccount.balance = 1000;
        newAccount.currency = currency;
        accounts.push_back(newAccount);
        cout << "Account '" << accountname << "' created successfully with initial balance: 1000 " << currency << "\n";
    }
    void withdraw(string accountname, int amount)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].name == accountname)
            {
                if (accounts[i].balance >= amount)
                {
                    accounts[i].balance -= amount;
                    cout << "Withdrawal successful. New balance: " << accounts[i].balance << " " << accounts[i].currency << "\n";
                }
                else
                {
                    cout << "Insufficient funds. Current balance: " << accounts[i].balance << " " << accounts[i].currency << "\n";
                }
                return;
            }
        }
        cout << "Account not found.\n";
    }

    void deposit(string accountname, int amount)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].name == accountname)
            {
                accounts[i].balance += amount;
                cout << "Deposit successful. New balance: " << accounts[i].balance << " " << accounts[i].currency << "\n";
                return;
            }
        }
        cout << "Account not found.\n";
    }

    void closeAccount(string accountname)
    {
        for (int i = 0; i < accounts.size(); i++)
        {
            if (accounts[i].name == accountname)
            {
                accounts.erase(accounts.begin() + i);
                cout << "Account '" << accountname << "' closed successfully.\n";
                return;
            }
        }
        cout << "Account not found.\n";
    }
};

int main()
{
    BankAccount bank;

    while (true)
    {
        cout << "\nWELCOME TO BANK\nWhat can we help you with?\n*********************************************\n";
        string options[5] = {
            "1. List Accounts",
            "2. Withdraw from account",
            "3. Deposit to account",
            "4. Close account",
            "5. Create new Account"};
        for (int i = 0; i < 5; i++)
        {
            cout << options[i] << "\n";
        }
        cout << "0. Exit\n";
        cout << "*********************************************\nEnter action: ";

        int action;
        cin >> action;

        switch (action)
        {
        case 0:
            cout << "Thank you for using our banking service!\n";
            return 0;
        case 1:
            bank.listAccounts();
            break;
        case 2:
        {
            string accountName;
            int amount;
            cout << "Enter account name: ";
            cin >> accountName;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            if (amount <= 0)
            {
                cout << "Invalid amount. Please enter a positive number.\n";
                break;
            }
            bank.withdraw(accountName, amount);
            break;
        }
        case 3:
        {
            string accountName;
            int amount;
            cout << "Enter account name: ";
            cin >> accountName;
            cout << "Enter deposit amount: ";
            cin >> amount;
            if (amount <= 0)
            {
                cout << "Invalid amount. Please enter a positive number.\n";
                break;
            }
            bank.deposit(accountName, amount);
            break;
        }
        case 4:
        {
            string accountName;
            cout << "Enter account name to close: ";
            cin >> accountName;
            bank.closeAccount(accountName);
            break;
        }
        case 5:
        {
            string accountName, currency;
            cout << "Enter account name: ";
            cin >> accountName;
            cout << "Enter currency (e.g., USD, EUR, GBP): ";
            cin >> currency;
            bank.createAccount(accountName, currency);
            break;
        }
        default:
            cout << "Invalid option selected.\n";
            break;
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}