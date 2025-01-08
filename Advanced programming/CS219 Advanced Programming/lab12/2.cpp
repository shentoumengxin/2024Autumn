#include <iostream>
#include <memory>
using namespace std;
int main()
{
    shared_ptr<double>p_reg=make_shared<double>(5);
    shared_ptr<double> pd;
    pd = p_reg;
    cout << "*pd =" << *pd << endl;
    shared_ptr<double> pshared = p_reg;
    cout << "*pshred =" << *pshared << endl;
    shared_ptr<string> pstr = make_shared<string>("Hello World!");
    cout << "*pstr =" << *pstr << endl;
    return 0;
}