#include <iostream>

class Staff
{
private:
    int age;
public:
    virtual void Perform() const = 0;

};

class SeniorStaff :public Staff
{
private:
    int salary;
public:
    virtual void Perform() const { std::cout << "I am only a senior staff." << std::endl; }
};

class JuniorStaff :public SeniorStaff
{
public:
    virtual void Perform() const { std::cout << "I am just a junior staff." << std::endl; }
};

int main()
{
    std::cout << "Hello World!\n"; 
    //Staff staff;  // can not generate a virtual object
    SeniorStaff seniorStaff;
    seniorStaff.Perform();

    //
    JuniorStaff juniorStaff;
    juniorStaff.Perform();

    //
    SeniorStaff* seniorStaffPtr = &juniorStaff;
    seniorStaffPtr->Perform();

    //
    Staff* staffPtr = nullptr;
    staffPtr = &seniorStaff;
    staffPtr->Perform();
    staffPtr = &juniorStaff;
    staffPtr->Perform();

    return 0;
}

