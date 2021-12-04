#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
using namespace std;
vector<pair<string, string> > AdminDetails;
map<string, vector<string> > Productlist;
int ProductIdCount = 0;
string ProductOriginId = "P20210"; // to assign unique id to each product
string Catg[] = {"Electronics", "Fashion", "Food", "Books", "Sports", "Others", "Clothes", "Shoes", "Accessories"};
int n = 100;
void GenerateProduct(int n)
{
    string ProductId, ProductPrice, ProductQuantity, ProductCategory, ProductDiscount;
    for (int i = 0; i < n; i++)
    {
        vector<string> Prod;
        ProductId = ProductOriginId;
        ProductId.append(to_string(ProductIdCount));
        ProductIdCount++;
        ProductPrice = to_string(rand() % 1000);
        ProductQuantity = to_string(rand() % 100);
        ProductCategory = Catg[rand() % 9];
        ProductDiscount = to_string(rand() % 100);
        Prod.push_back(ProductPrice);
        Prod.push_back(ProductQuantity);
        Prod.push_back(ProductCategory);
        Prod.push_back(ProductDiscount);
        Productlist[ProductId] = Prod; /// map
    }
}
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
        cout << "ENTER YOUR BLOCK NO.     :\n";
        getline(cin, this->block);
        cout << block << endl;
        cout << "ENTER YOUR HOUSE NAME    :\n";
        getline(cin, this->houseName);
        cout << houseName << endl;
        cout << "ENTER YOUR CITY NAME     :\n";
        getline(cin, this->city);
        cout << city << endl;
        cout << "ENTER YOUR POST CODE     :\n";
        cin >> this->zip;
        cout << zip << endl;
    }

    string getFullAddress()
    {
        return block + ", " + houseName + ", " + city + ", " + zip;
    }
};

class Payment
{
    double payNetAmount;
    string cardNumber, cvv, ibankingUserID, ibankingUserPassword, payment;
    int pinNumber;

public:
    Payment(){};
    void setPaymentDetails()
    {
        cout << "ENTER YOUR CARD NUMBER :\n";
        cin >> cardNumber;
        cout << cardNumber << endl;
        cout << "ENTER YOUR cvv       :\n";
        cin >> cvv;
        cout << cvv << endl;
        cout << "ENTER YOUR PIN NUMBER  :\n";
        cin >> pinNumber;
        cout << pinNumber << endl;
        cout << "ENTER YOUR IBANKING USER ID :\n";
        cin >> ibankingUserID;
        cout << ibankingUserID << endl;
        cout << "ENTER YOUR IBANKING USER PASSWORD :\n";
        cin >> ibankingUserPassword;
        cout << ibankingUserPassword << endl;
        cout << "ENTER YOUR PAYMENT MODE :\n";
        cin >> payment;
        cout << payment << endl;
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

    string getcvv()
    {
        return cvv;
    }

    string getPayment()
    {
        return payment;
    }
};
class Register
{
    Address d; // Aggregation

private:
    string Username, Password, Email, Phone, Gender, Hashcode, Userid;

public:
    Register()
    {
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
    void SignUp()
    {
        int num;
        cout << " _____________________________________________\n";
        cout << "|                                             |\n";
        cout << "|          Welcome to ZepyShop                |\n";
        cout << "|_____________________________________________|\n";
        cout << "Enter 1 to SignUp or 2 to Login\n";
        cin >> num;
        cin.ignore();
        if (num == 1)
        {
            cout << "ENTER YOUR USER NAME    :" << endl;
            getline(cin, Username);
            cout << Username << endl;
            cout << "ENTER YOUR PASSWORD     :" << endl;
            getline(cin, Password);
            cout << Password << endl;
            cout << "ENTER YOUR EMAIL        :" << endl;
            getline(cin, Email);
            cout << Email << endl;
            cout << "ENTER YOUR PHONE NUMBER :" << endl;
            getline(cin, Phone);
            cout << Phone << endl;
            cout << "ENTER YOUR ADDRESS :" << endl;
            setAddress();
            cin.ignore();
        }
        else
        {

            Login();
        }
    }

    void Login()
    {

        string ChkUsername, ChkPassword;
        cout << "--------------------------------------\n";
        cout << "Welcome to Login Portal\n";
        cout << "ENTER YOUR USER NAME    :" << endl;
        getline(cin, ChkUsername);
        cout << ChkUsername << endl;
        cout << "ENTER YOUR PASSWORD     :" << endl;
        getline(cin, ChkPassword);
        cout << ChkPassword << endl;

        if (Username == ChkUsername && Password == ChkPassword)
        {
            cout << "LOGIN SUCCESSFULLY" << endl;
        }
        else
        {
            cout << "LOGIN FAILED" << endl;
        }
    }
};
class Administrator
{
private:
    string UserId;
    string Password;

public:
    void setUserId(string userId)
    {
        this->UserId = userId;
    }
    void setPassword(string password)
    {
        this->Password = password;
    }
    string getUserId()
    {
        return UserId;
    }
    string getPassword()
    {
        return Password;
    }
    void setAdminDetail()
    {
        string LoginTime;
        cout << "Enter your Login Time : \n";
        cin >> LoginTime;
        AdminDetails.push_back(make_pair(UserId, LoginTime));
    }
    void addProduct()
    {
        cout << "--------------------------------------\n";
        // New Product to add or Edit Existing product
        string ProductId, ProductPrice, ProductQuantity, ProductCategory, ProductDiscount;
        vector<string> Prod;
        cout << "Enter Product Name : \n";
        ProductId = ProductOriginId;
        ProductId.append(to_string(++ProductIdCount));
        cout << ProductId << endl;
        cout << "Enter Product Price : \n";
        cin >> ProductPrice;
        cout << ProductPrice << endl;
        Prod.push_back(ProductPrice);
        cout << "Enter Product Quantity : \n";
        cin >> ProductQuantity;
        cout << ProductQuantity << endl;
        Prod.push_back(ProductQuantity);
        cout << "Enter Product Category : \n";
        cin >> ProductCategory;
        cout << ProductCategory << endl;
        Prod.push_back(ProductCategory);
        cout << "Enter Product Discount : \n";
        cin >> ProductDiscount;
        cout << ProductDiscount << endl;
        Prod.push_back(ProductDiscount);
        Productlist[ProductId] = Prod;
    }
    void PrintProductlist()
    {
        cout << "--------------------------------------\n";
        cout << "Available Products In The Store" << endl;
        cout << "  | Product Id | Price | Quantity |  Category       | Discount(%)|" << endl;
        cout << "--------------------------------------------------------------" << endl;

        for (auto i : Productlist)
        {
            printf("  | %-10s | %-5s | %-8s | %-15s | %-10s |\n", i.first.c_str(), i.second[0].c_str(), i.second[1].c_str(), i.second[2].c_str(), i.second[3].c_str());
        }
        cout << "-----------------------------------------------------------------\n";
    }
    void setDiscount()
    {
        string ProductId, Discount;
        cout << "Enter Product Id : \n";
        cin >> ProductId;
        cout << ProductId << endl;
        cout << "Enter Discount : \n";
        cin >> Discount;
        cout << Discount << endl;
        Productlist[ProductId][3] = Discount;
    }
    void searchProduct()
    {  // Searching in O(logn)
        string ProductId;
        cout << "Enter Product Id : \n";
        cin >> ProductId;
        cout << ProductId << endl;
        cout << "Product Details\n";
        cout << "Product Id:" << ProductId << "\nProduct Price in Rs:" << Productlist[ProductId][0] << "\nProduct Quanity:" << Productlist[ProductId][1] << "\nProduct category:" << Productlist[ProductId][2] << "\nProduct Discount:" << Productlist[ProductId][3] << endl;
    }
};
class Product
{
private:
    string ProductId, ProductName, ProductPrice;

public:
    void setProductId(string productId)
    {
        this->ProductId = productId;
    }
    string getProductId()
    {
        return ProductId;
    }
    void setProductName(string productName)
    {
        this->ProductName = productName;
    }
    string getProductName()
    {
        return ProductName;
    }
    void setProductPrice(string productPrice)
    {
        this->ProductPrice = productPrice;
    }
    string getProductPrice()
    {
        return ProductPrice;
    }
    void displayProduct()
    {
        cout << "Product Id:" << ProductId << "\nProduct Name:" << ProductName << "\nProduct Price:" << ProductPrice << endl;
    }
};
map<string, vector<string> > Productlist1;
class productlist
{
private:
    string ProductId, ProductPrice;
    int ProductQuantity;

public:
    void addProduct(map<string, vector<string> > &Productlist1)
    {
        cout << "--------------------------------------\n";
        // New Product to add or Edit Existing product
        // reference to the cart
        cout << "Enter the Product ID to Add the Cart\n";
        cin >> ProductId;
        cout << ProductId << endl;
        cout << "The number of pieces of Product left is " << Productlist[ProductId][1] << endl;
        cout << "Enter the number of pieces of Product you want to add to the Cart\n";
        cin >> ProductQuantity;
        cout << ProductQuantity << endl;
        if (stoi(Productlist[ProductId][1]) >= ProductQuantity)
        {
            Productlist1[ProductId].push_back(Productlist[ProductId][0]);
            Productlist1[ProductId].push_back(to_string(ProductQuantity));
            Productlist1[ProductId].push_back(Productlist[ProductId][2]);
            Productlist1[ProductId].push_back(Productlist[ProductId][3]); // product discount
            Productlist[ProductId][1] = to_string(stoi(Productlist[ProductId][1]) - ProductQuantity);
            cout << "The number of pieces of Product left is " << Productlist[ProductId][1] << endl;
        }
        else
        {
            cout << "The number of pieces of Product left is " << Productlist[ProductId][1] << endl;
            cout << "The number of pieces of Product you want to add to the Cart is more than the number of pieces of Product left in the store\n";
        }
    }
    void displayProduct()
    {
        double NetDiscount = 0.0, NetAmount = 0.0;
        cout << "--------------------------------------\n";
        cout << "Product Id | Product Price | Product Quantity | Product Category | Product Discount |" << endl;
        cout << "--------------------------------------------------------------" << endl;
        for (auto i : Productlist1)
        {
            printf("  | %-10s | %-5s | %-8s | %-15s | %-10s |\n", i.first.c_str(), i.second[0].c_str(), i.second[1].c_str(), i.second[2].c_str(), i.second[3].c_str());
            NetDiscount += stoi(i.second[3]) * stoi(i.second[1]) * stoi(i.second[0]) / 100;
            NetAmount += stoi(i.second[1]) * stoi(i.second[0]);
        }

        cout << "---------------------------------------------------------------\n";
        double TotalAmount = NetAmount - NetDiscount;
        cout << "Total Amount : " << NetAmount << endl;
        cout << "Total Discount : " << NetDiscount << endl;
        cout << "Final Amount : " << TotalAmount << endl;
    }
    void removeProduct()
    {
        string ProductId;
        cout << "Enter the Product ID to Remove the Cart\n";
        cin >> ProductId;
        cout << ProductId << endl;
        Productlist1.erase(ProductId);
    }

    void ChangeQuantity()
    {
        string ProductId;
        int ProductQuantity;
        cout << "Enter the Product ID to Change the Quantity\n";
        cin >> ProductId;
        cout << ProductId << endl;
        cout << "Enter the number of pieces of Product you want to add or remove  to the Cart\n";
        cin >> ProductQuantity;
        cout << ProductQuantity << endl;
        if (ProductQuantity < 0)
        {

            Productlist1[ProductId][1] = to_string(max(0, stoi(Productlist1[ProductId][1]) + ProductQuantity));
            cout << "The number of pieces of Product left is " << Productlist1[ProductId][1] << endl;
        }
        else
        {
            Productlist1[ProductId][1] = to_string(stoi(Productlist1[ProductId][1]) + ProductQuantity);
            cout << "The number of pieces of Product left is " << Productlist1[ProductId][1] << endl;
        }
    }
};
class Customer : public Payment // Inheritance
{
private:
    double NetDiscount = 0.0, NetAmount = 0.0;
    string CustomerName, CustomerPhone, CardNumber;
    Address CustomerAddress; // Agg...
    Payment CustomerPayment;

public:
    Customer(){};
    void setCustomerDetails()
    {
        cout << "Enter your residential name\n";
        cin >> CustomerName;
        cout << CustomerName << endl;
        cout << "Enter your phone number\n";
        cin >> CustomerPhone;
        cout << CustomerPhone << endl;
        cout << "Enter Your Billing  Address\n";
        cin.ignore();
        CustomerAddress.setFullAddress();
        CustomerAddress.getFullAddress();
    }
    void ShoppingCardDetails()
    {

        cout << "Enter your Card You want to Save" << endl;
        int num = 0;
        cout << "Press 1 to save or 0 to Cancel" << endl;
        cin >> num;
        cout << num;
        if (num)
        {
            cin >> CardNumber;
            CustomerPayment.setCardNumber(CardNumber);
        }
        else
        {
            cout << "You have Canceled the process" << endl;
        }
    }
    void PaymentWork()
    {
        CustomerPayment.setPaymentDetails();
    }
    void displayCustomerDetails()
    {
        cout << "Customer Name:" << CustomerName << endl;
        cout << "Customer Phone:" << CustomerPhone << endl;
        CustomerAddress.getFullAddress();
    }
    void Reciept()
    {
        if (CustomerPayment.getCardNumber() != "" && CustomerPayment.getCardNumber() != "" && CustomerPayment.getPinNumber() != 0)
        {
            cout << "---------------------------------" << endl;
            cout << "Your Reciept is as follows" << endl;
            displayCustomerDetails();
            cout << "--------------------------------------\n";
            cout << "Product Id | Product Price | Product Quantity | Product Category | Product Discount |" << endl;
            cout << "--------------------------------------------------------------" << endl;
            for (auto i : Productlist1)
            {
                printf("  | %-10s | %-5s | %-8s | %-15s | %-10s |\n", i.first.c_str(), i.second[0].c_str(), i.second[1].c_str(), i.second[2].c_str(), i.second[3].c_str());
                NetDiscount += stoi(i.second[3]) * stoi(i.second[1]) * stoi(i.second[0]) / 100;
                NetAmount += stoi(i.second[1]) * stoi(i.second[0]);
            }

            cout << "---------------------------------------------------------------\n";
            double TotalAmount = NetAmount - NetDiscount;
            cout << "Total Amount : " << NetAmount << endl;
            cout << "Total Discount : " << NetDiscount << endl;
            cout << "Final Amount : " << TotalAmount << endl;
        }
        else
        {
            cout << "Your Payment has not yet confirmed" << endl;
        }
    }
};
map<string, vector<string> > Cart1;
class ShoppingCart : public productlist
{
private:
    string SelectProduct, name;
    double add, TotalPrice = 0.0, TotalDiscount = 0.0;

public:
    ShoppingCart(){};
    void setadd()
    {
        cout << "Do you want to make a seperate wishlist" << endl;
        cout << "Enter 1 to reply as Yes else 0 for No" << endl;
        cin >> add;
        cout << add << endl;
    }
    void SelectProductWishList()
    {
       if(add){
           addProduct(Cart1);
       }else{
           cout<<"Your Wishlist has yet Not Created\n";
       }
    }
    void CalculateTotalPrice()
    {
        for (auto i : Cart1)
        {
            TotalPrice += stoi(i.second[1]) * stoi(i.second[0]);
            TotalDiscount += stoi(i.second[3]) * stoi(i.second[1]) * stoi(i.second[0]) / 100;
        }
        cout << "Total Price:" << TotalPrice << endl;
        cout << "Total Discount:" << TotalDiscount << endl;
        cout << "Final Amount:" << TotalPrice - TotalDiscount << endl;
    }

    void AddWishList(){
        int chk=0;
        cout<<"Do you want to add Wishlist to the Cart\n";
        cout<<"Select 1 to add or 0 to exit\n";
        cin>>chk;
        cout<<chk;
        if(chk){
            for(auto i:Cart1){
                if( Productlist1[i.first][1]==""){
                  Productlist1[i.first]=i.second;
                }else{
                    int New=stoi(i.second[1]);
                    New+=stoi(  Productlist1[i.first][1]);
                     Productlist1[i.first][1]=to_string(New);
                }
               
            }
        }else{
            cout<<"Exit\n";
        }

    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
#endif
    GenerateProduct(n);
    Register r;
    Administrator ad;
    r.SignUp();
    r.Login();
    ad.addProduct();
    ad.PrintProductlist();
    productlist p;
    p.addProduct(Productlist1);
    p.displayProduct();
    p.ChangeQuantity();
    p.displayProduct();
    Customer c;
    c.setCustomerDetails();
    c.PaymentWork();
    c.Reciept();
    ShoppingCart cart;
    cart.setadd();
    cart.SelectProductWishList();
    cart.AddWishList();
    p.displayProduct();

    return 0;
}
