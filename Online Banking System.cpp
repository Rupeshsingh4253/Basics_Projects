#include <iostream>
using namespace std;

class Banking {
private:
    float account_balance = 5000;
    int pin_number=9452;
    float last_transiction=0;
    string name="RUPESH SINGH";
    int last_pin=NULL;

public:
    float capacity;
    float amount;

    void credit(int pin) {
        if (this->pin_number == pin) {
            cout << "ENTER THE AMOUNT: ";
            cin >> amount;
            if (amount <= account_balance) {
                account_balance -= amount;
                last_transiction=amount;
                cout << "Transaction successful" << endl;
            } else {
                cout << "Don't have enough Money" << endl;
                cout << "Your current balance: " << account_balance << endl;
            }
        } else {
            cout << "SORRY Wrong Pin Number!" << endl;
        }
    }
    void deposite(int pin)
    {
        if (this->pin_number == pin) {
            cout << "ENTER THE AMOUNT: ";
            cin >> amount;
            account_balance+=amount;
        }
        else{
           cout << "SORRY Wrong Pin Number!" << endl;
        }
    }
    void change_details(int pin){
        if(pin_number==pin)
        {
                last_pin=pin;
                cout<<"ENTER NEW PIN"<<endl;
                cin>>pin;
                cout<<"ENTER NEW NAME OF CARD HOLDER"<<endl;
                cin>>name;
                this->name=name;
                this->pin_number=pin;
                cout<<"change of details done Successfully"<<endl;
        }
        else{
            cout << "SORRY Wrong Pin Number!" << endl;
        }

    }
    void card_holder_detail(int pin)
    {
        if(pin_number==pin)
        {
            cout<<"name of the card_Holder :"<<name<<endl;
            cout<<"Last PIN Number         :"<<last_pin<<endl;
            cout<<" PIN Number             :"<<pin_number<<endl;
            cout<<" Account Balanced       :"<<account_balance<<endl;
            cout<<" Last transiction       :"<<last_transiction<<endl;
        }else{
            cout << "SORRY Wrong Pin Number!" << endl;
        }
        
    }

};
int main() {
    Banking obj;
    int input = 0;
    int pin;
    while (input != 10) {
        cout << "Enter 1: Credit Amount" << endl;
        cout << "Enter 2: Deposit Amount" << endl;
        cout << "Enter 3: Details of card Holder" << endl;
        cout << "Enter 4: Change Details of card holder"<<endl;
        cout << "Enter 5: Exit" << endl;
        cin >> input;

        switch (input) {
            case 1:
                cout << "Enter your PIN number: ";
                cin >> pin;
                obj.credit(pin);
                break;
            case 2:
                cout << "Enter your PIN number: ";
                cin >> pin;
                obj.deposite(pin);
                break;
            case 3:
                cout << "Enter your PIN number: ";
                cin >> pin;
                obj.card_holder_detail(pin);
                break;
            case 4:
                cout << "Enter your PIN number: ";
                cin >> pin;
                obj.change_details(pin);
                break;
            case 5:
                cout<<"you exit"<<endl;
                exit(5);  
            default:
                cout << "Error: Invalid option" << endl;
                break;
        }
    }
    return 0;
}
