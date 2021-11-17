#include <iostream>
using namespace std;
class Address
{
protected:
    string block, houseName, city, zip;

public:
Address(){};
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
class Register
{
     Address d;
private:
    string Username, Password, Email, Phone, Gender, Hashcode, Userid;
   

public:
     Register(){

     }
    void setUsername(string name)
    {
        this->Username = name;
    }
    void setGender(string gender)
    {
        this->Gender = gender;
    }
    void setEmail(string email)
    {
        this->Email = email;
    }
    void setPhone(string phone)
    {
        this->Phone = phone;
    }
    void setAddress()
    {
        d.setFullAddress();
    }
    void setUserid(string userid)
    {
        this->Userid = userid;
    }
    string getUsername()
    {
        return Username;
    }
    string getGender()
    {
        return Gender;
    }

    string getEmail()
    {
        return Email;
    }
    void getAddress()
    {
        d.getFullAddress();
    }
    void SignUp(){
        int num;
        cout<<"WELCOME TO ZEPY SHOP\n";
        cout<<"Enter 1 to SignUp or 2 to Login\n";
          cin>>num;
          cin.ignore();
          if(num==1){
                cout << "ENTER YOUR USER NAME    :"<<endl;
            getline(cin,Username);
            cout << "ENTER YOUR PASSWORD     :"<<endl;  
            getline(cin,Password);  
            cout << "ENTER YOUR EMAIL        :"<<endl;
            getline(cin,Email);
            cout << "ENTER YOUR PHONE NUMBER :"<<endl;
            getline(cin,Phone);
    
          }else{
               Login();
          }
    }
      
    void Login(){

        string ChkUsername, ChkPassword;
        cout<<"Login Portal\n";
        cout << "ENTER YOUR USER NAME    :"<<endl;
            getline(cin,ChkUsername);
            cout << "ENTER YOUR PASSWORD     :"<<endl;  
            getline(cin,ChkPassword);

            if(Username==ChkUsername && Password==ChkPassword){
                cout << "LOGIN SUCCESSFULLY"<<endl;
            }
            else{
                cout << "LOGIN FAILED"<<endl;
            }





    }
};

int main()
{

    Register r;
    r.SignUp();
    r.Login();


    return 0;
}