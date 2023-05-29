#include <string>
using namespace std;

class Message {
    string _text;
    string _sender;
    string _reciver;
public:
    Message(const string& t, const string& s, const string& r)
        : _text(t), _sender (s), _reciver(r) {}
    string text() const  {return _text;}
    string sender() const  {return _sender;}
    string reciver() const  {return _reciver;}

    friend fstream& operator >> (fstream& is, Message& obj) {
    is >> obj._text;
    is >> obj._sender;
    is >> obj._reciver;
    return is;
    }
    friend ostream& operator << (ostream& os, const Message& obj) {
    os << obj._text;
    os << ' ';
    os << obj._sender;
    os << ' ';
    os << obj._reciver;
    os << ' ';
    return os;
    }
};