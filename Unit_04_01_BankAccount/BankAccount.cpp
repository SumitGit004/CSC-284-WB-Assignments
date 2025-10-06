#include "BankAccount.h"
#include <print>

int BankAccount::totalAccounts = 0;
int BankAccount::nextAccountNumber = 1001;

BankAccount::BankAccount() : BankAccount("Unknown", 0.0){
}


BankAccount::BankAccount(std::string holder,double initialBalance) : accountHolder(holder){
    
    balance = initialBalance >= 0 ? initialBalance : 0.0;
    accountNumber = nextAccountNumber++;
    totalAccounts++;
}

std::string BankAccount::getAccountHolder() const{
    return accountHolder;
}

int BankAccount::getAccountNumber() const{
    return accountNumber;
}

double BankAccount::getAccountBalance() const{
    return balance;
}
//returns true for succesfful deposit, otherwise false
bool BankAccount::deposit(double amount){
    if(amount > 0){
        balance += amount;
        return true;
     }
    else
    return false;
}
//returns true for succesfful deposit, otherwise false
bool BankAccount::withdraw(double amount){
    if(balance >= amount && amount > 0){
      balance -= amount;
        return true;
    }
    else
    return false;
   
}

void BankAccount::printAccountInfo() const{
    std::print("Account Holder: {}\n", accountHolder);
    std::print("Account Number: {}\n", accountNumber);
    std::print("Balance: ${:.2f}\n\n", balance);//prints balance with 2 digits after decimal point.
}

//returns true for succesfull balance transfer, otherwise false
bool BankAccount::transfer(BankAccount& toAccount, double amount){
   
    if(withdraw(amount)){
        toAccount.deposit(amount);
        return true;
    }
    else
        return false;
    
}

//no need to include static keyword in definition
int BankAccount:: getTotalAccounts(){
    return totalAccounts;
}



BankAccount::~BankAccount() {

    totalAccounts--;
    std::println("Account {} has been closed, Total active accounts now: {}\n", accountNumber, totalAccounts);
    
}
