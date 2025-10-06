#pragma once
#include <string>

class BankAccount{
   private:
   std::string accountHolder;
   int accountNumber;
   double balance;
   static int totalAccounts;
   static int nextAccountNumber;

   public:

   BankAccount();

   BankAccount(std::string holder, double initialBalance);
  
   std::string getAccountHolder() const;

   int getAccountNumber() const;

   double getAccountBalance() const;

   bool deposit( double amount);

   bool withdraw(double amount);

   void printAccountInfo() const;

   bool transfer(BankAccount& toAccount, double amount);

   static int getTotalAccounts();

    ~BankAccount();
};