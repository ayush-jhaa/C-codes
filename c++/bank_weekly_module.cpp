#include <iostream>
using namespace std;

class bank {
private:
    int accno;
    string name;
    float balance;

public:
    // Default constructor
    bank() {
        cout << "Enter account number: ";
        cin >> accno;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter balance: ";
        cin >> balance;
    }

    // Parameterized constructor for withdrawal
    bank(int withdrawalAmt,int bal) {

            balance=bal;
            balance -= withdrawalAmt;
    }

    void deposit(int amt) {
        balance += amt;
    }

    void balanceEnq() {
        cout << "Amount in your bank is: " << balance << endl;
    }

    void withdrawal() {
        cout << "Enter amount to withdraw: " << endl;
        int amt;
        cin >> amt;

        transaction(amt);  // Call the transaction method to perform withdrawal
    }

    void transaction(int amt) {
        bank newObj(amt,balance);  // Create a new bank object with the withdrawal amount
        balance = newObj.balance;  // Update the original object's balance
    }
};

int main() {
    bank obj1;  // Create a bank object

    obj1.deposit(1500);  // Deposit 1500
    obj1.withdrawal();  // Withdraw an amount

    cout << "Amount after withdrawal:" << endl;
    obj1.balanceEnq();  // Display the balance

    return 0;
}
