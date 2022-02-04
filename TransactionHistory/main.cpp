//
//  main.cpp
//  TransactionHistory
//  I pledge this program is of my own hand, created for CSCI275.
//  Created by Nicholas Herrick on 1/31/22.
//

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <array>
#include "Customer.h"

using namespace std;


// This program reads customer information from a text file, and prints the information in a formatted table.

int main(int argc, const char * argv[]) {
    Customer customers [50]; // Array of customers
    ifstream fin; // Input for file
    string idNum, info, date,  custName; // Customer ID number, Transaction info, Transaction date, Customer name
    char transactionType  ; // Deposit (D) or Withdrawal(W)
    double custBal, transactionAmnt; // Customer beginning balance, Transaction amount

    
    fin.open("customers.txt");
    
    if (fin.fail()){ // Check if file open fails, report if so.
        cout << "File failed to open!" << endl;
        return 1;
    }
    
    fin >> idNum;
    while (!fin.fail()){
        int i = 0; // Counter
        string s; // Helper string to consume newline
        getline(fin, s); // consume newline
        getline(fin, custName); // read line for Customer Name
        fin >> custBal; // read balance
        customers[i].setCustID(idNum);
        customers[i].setName(custName);
        customers[i].setBalance(custBal);

        cout << "\nCustomer: " << customers[i].getName() << "\nIdentification: " << "XXX"
        << customers[i].getCustID().substr(3) << "\nBalance: "
                                    << fixed << setprecision(2) << customers[i].getBalance() << endl;

        cout << "\nDate" << right << setw(20) << "Transaction" << setw(12)
                                                << "Amount" << setw(12) << "Balance" << endl;
        
        getline(fin, s);
        getline(fin, info);
        cout << "------------------------------------------------" << endl;

        // Begin printout of transactions if xxx is not found.
        while (info.substr(0, 3) != "xxx") {
            istringstream inString{info}; // String stream for info (date,type,amount,balance).
            inString >> date >> transactionType >> transactionAmnt; // Parse string for transaction history
            string transaction = (transactionType == 'W') ? "Withdrawal" : "Deposit"; // Determine transaction type

            if (transactionType == 'W') {   // Checks transaction type and calculates balance
                customers[i].withdrawal(transactionAmnt);
            } else {
                customers[i].deposit(transactionAmnt);
            }

            cout << date << setw(15) << transaction << fixed << setprecision(2) << setw(13) <<
              transactionAmnt << setw(12) << customers[i].getBalance() << endl;
            getline(fin, info);
        }

        i++;
        fin >> idNum;
    }
    fin.close();

    return 0;
}
