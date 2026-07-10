#include<bits/stdc++.h>
using namespace std;
class Student {
public:   // bcz default is private
    string name;
    int age;
    
    void display() {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
    void input() {
        cin>>name>>age;
    }
};

int main() {
    Student s1,s2,s3;
    
    s1.input();
    
    s1.display();
    s2.display();
    s3.display();
}