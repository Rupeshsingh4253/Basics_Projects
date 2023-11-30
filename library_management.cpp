#include<iostream>
#include<string> 
#include<vector>
#include<unordered_map>
using namespace std;
class library{
    public:
    string id;
    string book_id;
    string rollnumber;
    char book[20];
    char student[20];
    // string books[10]={"english","math","science","social","hindi"};
    // int nu_of_books=5;

    static vector<string> books;
    static vector<int> nu_of_books;

    // unordered_map<string, int> books;
    // books["english"]=50;
    // books["maths"]=100
    // if(books["maths"]){
    //     books["maths"]=books["maths"]-1;
    // }

    
    void add(string book_name,int n){
        // this->books[nu_of_books++]=book_name;
        // cout<<books;

        books.push_back(book_name);
        nu_of_books.push_back(n);

        for(auto i:books)
            cout<<i<<" ";
            for(auto i:nu_of_books)
                cout<<i<<" ";
        cout<<endl;
        

        // for(int i=0;i<this->books.size();i++)
        //     cout<<this->books[i]<<" ";
        // cout<<endl;
        
    }
};

vector<string> library::books={"english","math","science","social","hindi"};
vector<int> library::nu_of_books={4,5,6,7,2};

int main()
{
    library lib[10];
    library obj;
    string book_name;
    int n;
    int input=0;
    int count=0;
    while (input!=4)
    {
        cout<<"Enter 1: for input details student,id,book,pages"<<endl;
        cout<<"Enter 2: for see your details"<<endl;
        cout<<"Enter 3  for add more book in library"<<endl;
        cout<<"Enter 4: Exit"<<endl;
        cin>>input;

        switch(input)
        {
        case 1:
            start:
            cout<<"Enter Student ID"<<endl;
            cin>>lib[count].id;
            cout<<"Enter Student Name"<<endl;
            cin>>lib[count].student;
            cout<<"Enter Student roll_number"<<endl;
            cin>>lib[count].rollnumber;
            cout<<"Enter book name"<<endl;
            cin>>lib[count].book;
            cout<<"Enter book id"<<endl;
            cin>>lib[count].book_id;
            count++;
            break;
        
        case 2:
            for(int i=0;i<count;i++)
            {
                cout<<"   student ID            "<<lib[i].id<<endl;
                cout<<"   student name          "<<lib[i].student<<endl;
                cout<<"   student roll_number   "<<lib[i].rollnumber<<endl;
                cout<<"   book name             "<<lib[i].book<<endl;
                cout<<"   book id               "<<lib[i].book_id<<endl;
            }
            break;
        case 3:
            cout<<"name the book name"<<endl;
            cin>>book_name;
            cout<<"number of books"<<endl;
            cin>>n;
            obj.add(book_name,n);
            break;
        case 4:
            exit(0);
            cout<<"you are out"<<endl;
            break;
        default:
            cout<<"PLEASE CHOOSE CORRECT NUMBER"<<endl;
            goto start;
        }

    }
}
    