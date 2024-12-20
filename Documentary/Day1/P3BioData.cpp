#include<iostream>
using namespace std;   
int main()
{
    string n,aoi,h,uid,dob;
    int ly,sec;
    float cgpa;
    cout<<"Enter bio data:"<<endl;
    cout<<"Name : ";
    cin>>n;
    cout<<"UID : ";
    cin>>uid;
    cout<<"Section : ";
    cin>>sec;
    cout<<"CGPA : ";
    cin>>cgpa;
    cout<<"Area Of Interest : ";
    cin>>aoi;
    cout<<"Last Year : ";
    cin>>ly;
    cout<<"Date of birth in DD/MM/YYYY format : ";
    cin>>dob;
    cout<<"Hometown : ";
    cin>>h;
    cout<<"Name             : "<<n<<endl;
    cout<<"UID              : "<<uid<<endl;
    cout<<"Section          : "<<sec<<endl;
    cout<<"CGPA             : "<<cgpa<<endl;
    cout<<"Area Of Interest : "<<aoi<<endl;
    cout<<"Last Year        : "<<ly<<endl;
    cout<<"DOB              : "<<dob<<endl;
    cout<<"Hometown         : "<<h<<endl;

}