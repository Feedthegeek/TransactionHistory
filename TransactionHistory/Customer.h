//
//  Customers.h
//  TransactionHistory
//
//  Created by Nicholas Herrick on 1/31/22.
//
#pragma once
#include <string>
using namespace std;

class Customer {
    
private:
    string custID;
    string name;
    double balance;
public:
    Customer() // Default
    {
        custID = "";
        name = "";
        balance = 0.0;
    }
    Customer(string ID, string n, double bal) // Parameterized
    {
        custID = ID;
        name = n;
        balance = bal;
    }
    
    void deposit(double d)
        {
        balance += d;
        }
    void withdrawal(double d)
        {
        balance -= d;
        }
    string getCustID() const
        {
        return custID;
        }
    string getName() const
        {
        return name;
        }
    double getBalance() const
        {
        return balance;
        }
    void setCustID(string idNum)
    {
        custID = idNum;
    }
    void setName(string s)
        {
        name = s;
        }
    void setBalance(double b)
        {
        balance = b;
        }
    
};
