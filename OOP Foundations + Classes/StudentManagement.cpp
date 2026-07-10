// note that in this file, many commits will be there, those are versions which represents the learning prgress how we learnt each thing one by one. try to see all the commits of this file
#include<bits/stdc++.h>
using namespace std;
class Student {
public:   // bcz default is private
    string name;
    int age;
    
    void display();
    void input();
};

// we cannot define below functions inside int main. Function definitions cannot be inside another function. Remember: A function cannot be defined inside another function in C++. Only function calls are allowed inside main().
void Student:: display() {   // compiler internally behaves like void Student::display(Student* this)
    cout<<"Name: "<<name<<endl;
    cout<<"Age: "<<age<<endl;
}
void Student::input() {
    cin>>name>>age;
}


int main() {

    Student s1,s2,s3;

    s1.input();
    
    s1.display();
}