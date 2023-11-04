#include<iostream>
using namespace std;
class Hospital{
    string name;
    int age;
    char sex;
    int phone_number;
    string problem;
    public:
    int date;
    int fees;
    string Dr_name;
    int time;

    void patient_registration()
    {
        cout<<"enter patient name"<<endl;
        cin>>name;
        cout<<"age "<<endl;
        cin>>age;
        cout<<"sex"<<endl;
        cin>>sex;
        cout<<"enter your phone_number"<<endl;
        cin>>phone_number;
        cout<<"enter your problem"<<endl;
        cin>>problem;
    }

    void appointment(int date,int time,int fees,string name){
        this->date=date;
        this->time=time;
        this->fees=fees;
        this->Dr_name=name;
    }

    int medical_record()
    {
        cout<<"patient name  "<<name<<endl;
        cout<<"age           "<<age<<endl;
        cout<<"sex           "<<sex<<endl;
        cout<<"phone_number  "<<phone_number<<endl;
        cout<<"problem       "<<problem<<endl;
        return 0;
    }

};
int main()
{
    Hospital obj;
    int input=0;
    int date;
    int time;
    int fees;
    string name;
    int count=0;
    while (input!=3)
    {
        cout<<"Enter 1: for input details of patient"<<endl;
        cout<<"Enter 2: for appointmnet"<<endl;
        cout<<"Enter 3  for medical record"<<endl;
        cout<<"Enter 4: Exit"<<endl;
        cin>>input;
        switch (input)
        {
        case 1:
            obj.patient_registration();
            count++;
            break;
        case 2:
            cout<<"enter the date and time"<<endl;
            cin>>date;
            cin>>time;
            cout<<"pay the fees"<<endl;
            cin>>fees;
            cout<<"Dr. name: "<<endl;
            cin>>name;
            obj.appointment(date,time,fees,name);
            count++;
            break;
        case 3:
            if(count>=1)
            {
                obj.medical_record();
            }else{
                cout<<"first fill upper details"<<endl;
            }  
            break;
        case 4:
            cout<<"you exit"<<endl;
            exit(4);
        default:
            cout<<"Error"<<endl;
            break;
        }

    }

}