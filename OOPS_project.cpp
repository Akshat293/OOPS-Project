#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<pair<string, string>> AdminDetails;
map<string, vector<string>> Productlist;
int ProductIdCount = 0;
string ProductOriginId = "P20210"; // to assign unique id to each product
string Catg[] = {"Electronics", "Fashion", "Food", "Books", "Sports", "Others", "Clothes", "Shoes", "Accessories"};
int n = 1000;
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
        Productlist[ProductId] = Prod;
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
        cout << "ENTER YOUR PASSWORD     :" << endl;
        getline(cin, ChkPassword);

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
    {
        string ProductId;
        cout << "Enter Product Id : \n";
        cin >> ProductId;
        cout << ProductId << endl;
        cout << "Product Details\n";
        cout << "Product Id:" << ProductId << "\nProduct Price in Rs:" << Productlist[ProductId][0] << "\nProduct Quanity:" << Productlist[ProductId][1] << "\nProduct category:" << Productlist[ProductId][2] << "\nProduct Discount:" << Productlist[ProductId][3] << endl;
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

    return 0;
}

// Alekhya code
class product
{
private:
    string productID;
    string productName;
    double productPrice;

public:
    Product(string ID = "", string Name = "", double Price = 0.0)
    {
        productID = ID;
        productName = Name;
        productPrice = Price;
    }

    void setID(string i)
    {
        productID = i;
    }

    void setNAME(string n)
    {
        productName = n;
    }

    void setPRICE(double p)
    {
        productPrice = p;
    }

    virtual string getID()
    {
        return productID;
    }

    string getNAME()
    {
        return productName;
    }

    double getPRICE()
    {
        return productPrice;
    }

    void displayProduct()
    {

        cout << setw(10) << productID << setw(20) << productName << setw(20) << productPrice << end1;
    }
};

/= == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == = << ProductList Class >> == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == == = /

                                                                                                                                                                                                                                                                                                                   class ProductList // contain composition task (product class)
{
private:
    vector<Product> productList;

public:
    void products(vector<Product> &p)
    {
        productList = p;
    }

    void displayProductList()
    {
        cout << setw(15) << "ProductID" << setw(17) << "ProductName" << setw(20) << "ProductPrice\n";
        for (int i = 0; i < productList.size(); i++)
        {
            productList[i].displayProduct();
        }
    }
    virtual void addProduct(string i, string n, double p)
    {
        productList.emplace_back(i, n, p);
    }

    void removeProduct(string r)
    {
        int RE;
        for (int i = 0; i < productList.size(); i++)
        {
            if (productList(i).grtID() == r)
            {
                RE = i:
            }
        }
        productList.erase(productList.begin() + RE);
    }
};
