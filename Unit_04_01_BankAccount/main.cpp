#include "BankAccount.h"
#include <print>

int main()
{

    std::println("\nCreating accounts...\n");
    BankAccount account1("Willy", 500.00);
    BankAccount account2("Amarilys", 300.00);
    BankAccount account3; // Default account

    std::println("Initial Account Information:\n");
    account1.printAccountInfo();
    account2.printAccountInfo();
    account3.printAccountInfo();

    std::println("Total Accounts: {}", BankAccount::getTotalAccounts());

    std::println("Depositing $200 to {} account...", account1.getAccountHolder());
    if (account1.deposit(200.0))
        std::println("New balance is ${:.2f}\n", account1.getAccountBalance());
    else
        std::println("Deposit unsuccesful\n");

    std::println("Withdrawing $1000 from {} account...", account2.getAccountHolder());
    if (account2.withdraw(1000.0))
    {
        std::println("-Withdrawal successful, {}'s balance is now: ${:.2f}\n", account1.getAccountHolder(), account1.getAccountBalance());
    }
    else
        std::println("-Withrawal Unsuccessful, Insufficient funds.\n");

    std::println("Attempting to deposit negative balance to Unknown Account");
    if (!account3.deposit(-50))
        std::println("Deposit of -$50 to Unknown account unsucessful\n");

    std::println("Transferring $150 from {} to {}", account1.getAccountHolder(), account2.getAccountHolder());
    if (account1.transfer(account2, 150))
    {
        std::print("Balance transfer of $150 to {} successful, ", account2.getAccountHolder());
        std::println("{}'s Balance is now: {:.2f}", account2.getAccountHolder(), account2.getAccountBalance());
        std::println("{}'s balance is ${:.2f}\n", account1.getAccountHolder(), account1.getAccountBalance());
    }
    else
        std::println("Balance transfer of $150 to {} unsuccessful\n", account2.getAccountHolder());

    std::println("Exiting program\n");
}