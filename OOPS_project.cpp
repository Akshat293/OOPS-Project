#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack> 
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>
using namespace std;

class Address
{
    string block, houseName, city, zip;

public:
    Address(string block, string houseName, string city, string zip)
    {
        this->block = block;
        this->houseName = houseName;
        this->city = city;
        this->zip = zip;
    }

    void setFullAddress()
    {
        cout << "ENTER YOUR BLOCK NO.     :";
        cin >> this->block;
        cin.ignore();
        cout << "ENTER YOUR HOUSE NAME    :";
        getline(cin, this->houseName);
        cout << "ENTER YOUR CITY NAME     :";
        getline(cin, this->city);
        cout << "ENTER YOUR POST CODE     :";
        cin >> this->zip;
    }

    string getFullAddress()
    {
        return block + ", " + houseName + ", " + city + ", " + zip;
    }
};

class Payment
{
    double payNetAmount;
    string cardNumber, digit, ibankingUserID, ibankingUserPassword;
    int pinNumber, payment;

public:
    Payment(double payNetAmount, string cardNumber, int pinNumber, string ibankingUserID, string ibankingUserPassword)
    {
        this->payNetAmount = payNetAmount;
        this->cardNumber = cardNumber;
        this->pinNumber = pinNumber;
        this->ibankingUserID = ibankingUserID;
        this->ibankingUserPassword = ibankingUserPassword;
    }

    void setNetPayAmount(double amount)
    {
        this->payNetAmount = amount;
    }

    double getNetPayAmount()
    {
        return payNetAmount;
    }

    void setCardNumber(string cardNumber)
    {
        this->cardNumber = cardNumber;
    }

    string getCardNumber()
    {
        return cardNumber;
    }

    void setPinNumber(int pinNumber)
    {
        this->pinNumber = pinNumber;
    }

    int getPinNumber()
    {
        return pinNumber;
    }

    void setBankingUserID(string ibankingUserID)
    {
        this->ibankingUserID = ibankingUserID;
    }

    string getBankingUserID()
    {
        return ibankingUserID;
    }

    void setBankingUserPassword(string ibankingUserPassword)
    {
        this->ibankingUserPassword = ibankingUserPassword;
    }

    string getBankingUserPassword()
    {
        return ibankingUserPassword;
    }

    string getDigit()
    {
        return digit;
    }

    int getPayment()
    {
        return payment;
    }
};

int main()
{

    Address a = Address("aa", "bb", "cc", "dd");
    // a.setFullAddress();
    cout << a.getFullAddress() << endl;

    return 0;
}