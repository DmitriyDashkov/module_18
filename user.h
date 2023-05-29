#include <string>
#include <fstream>
using namespace std;

class User {
    string _name;
    string _login;
    string _pass;
public:
    User(const string& n, const string& l, const string& p)
        : _name(n), _login (l), _pass(p) {}
    string name() const  {return _name;}
    string login() const  {return _login;}
    string pass() const  {return _pass;}

    friend fstream& operator >> (fstream& is, User& obj);
    friend ostream& operator << (ostream& os, const User& obj);
};
fstream& operator >> (fstream& is, User& obj) {
    is >> obj._name;
    is >> obj._login;
    is >> obj._pass;
    return is;
}

ostream& operator << (ostream& os, const User& obj) {
    os << obj._name;
        os << ' ';
        os << obj._login;
        os << ' ';
        os << obj._pass;
        os << ' ';
        return os;
}

