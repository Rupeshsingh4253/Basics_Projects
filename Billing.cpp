#include<iostream>
#include<fstream>
using namespace std;

class shopping
{
    int pcode;
    float price;
    float dis;
    string name;

    public:
    void menu();
    void admistration();
    void buyer();
    void add();
    void edit();
    void rename();
    void list();
    void receipt();
    
};
void shopping::menu()
{
    m;
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t____________________________\n";
    cout<<"\t\t\t\t                            \n";
    cout<<"\t\t\t\t     Supermarket menu        \n";
    cout<<"\t\t\t\t                             \n";
    cout<<"\t\t\t\t____________________________\n";
    cout<<"\t\t\t\t|    1:Admistration    |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|    2:Buyer           |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t|    3:Exit            |\n";
    cout<<"\t\t\t\t|                      |\n";
    cout<<"\t\t\t\t please selsect! ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"\t\t\t\t please login \n";
            cout<<"\t\t\t\t Enter Email   \n";
            cin>>email;
            cout<<"\t\t\t\t Password      \n";
            cin>>password;
            if(email="rupeshsingh4253@gmail.com" && password="63870377")
            {
                admistration();
            }
            else{
                cout<<"Invalid email/password";
            }
            break;
    }
    case 2:
    {
        buyer();
    }

    case 3:
    {
        exit(0);
    }

    default:
    {
        cout<<"PLESE SELECT FROM THE GIVEN OPTION";
    }
goto m;
}

void shoppping::admistration()
{
    m;
    int choice;
    cout<<"\t\t\t\t Admistration Menu";
    cout<<"\t\t\t\t|_____1 add the product____|\n";
    cout<<"\t\t\t\t|                          |\n";
    cout<<"\t\t\t\t|_____2 Modify the product__|\n";
    cout<<"\t\t\t\t|                          |\n";
    cout<<"\t\t\t\t|_____3 Delete the product__|\n";
    cout<<"\t\t\t\t|                          |\n";
    cout<<"\t\t\t\t|_____4 Back to main menu __|\n";

    cout<<"\t\t\t\t please enter your choice ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rename();
        break;
    case 4:
        menu();
        break;
    
    default:
        cout<<"Invalid Choice";
        break;
    }
goto m;
}

void shopping :: buyer()
{
    m;
    int chioce;
    cout<<"\t\t\t\t buyer \n";
    cout<<"\t\t\t\t|__________________________|\n";
    cout<<"\t\t\t\t|                          |\n";
    cout<<"\t\t\t\t|_____1: Buy the product__|\n";
    cout<<"\t\t\t\t|                          |\n";
    cout<<"\t\t\t\t|_____2:  Go Back        __|\n";
    cout<<"\t\t\t\t Enter your choice :\n";

    cin>>choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
    
    default:
        cout<<"Invalid Choice";
    }
goto m;
}

void shopping :: add()
{
    m;
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product ";
    cout<<"\n\n\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n\t Name of the Product";
    cin>>pname;
    cout<<"\n\n\t Price of the Product";
    cin>>price;
    cout<<"\n\n\t Discount on Product";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while (!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        
    }
    if(token==1){
        goto m; 
    }
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();

    }
    cout<<"\n\n\t\t Record  Inserted !";
}

void shoping:: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t Modify the record";
    cout<<"\n\n\t\t Product code :";
    cin>>pkey;

    data.open("database.txt",ios::in);

    if(!data)
    {
        cout<<"\n\nFile doesn't exist! ";
    }
    else{
        data.open("database.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while (!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\n\t Product new code ";
                cin>>c;
                cout<<"\n\n\t Name of the Product";
                cin>>n;
                cout<<"\n\n\t Price of the Product";
                cin>>p;
                cout<<"\n\n\t Discount on Product";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<cout<<"\n\n\t\t Record edited:";
                token++;
            }
            else{
                data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found sorry!";
        }
    }
}

void shopping:: rename()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n Delete the product";
    cout<<"\n\n Product code ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"file doen't exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while (!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\n\t Product deleted succesfully ";
                token++;
            }
            else{
                data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";              
            }
            data>>pcode>>pname>>price>>dis;
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt","database.txt");

    if(token==0)
    {
        cout<<"\n\n Record can not found sorry!";
    }       
}}

