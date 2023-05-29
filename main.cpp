#include "user.h"
#include "message.h"
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;


int main(){
    User user1("Dmitriy", "zel", "12345");
    User user2("Svetlana", "svetik", "qwerty");
    User user3("Anna", "ania", "qazwsx");
    Message message1("Hi everibody", "zel", "all");
    Message message2("Hi, Dmitriy!", "svetik", "zel");
    Message message3("Hello, zel!", "ania", "zel");

    fstream user_file = fstream("user_file.txt", ios::in | ios::out);
    if(!user_file)
        user_file = fstream("user_file.txt", ios::in | ios::out 
                                                             | ios::trunc);
    fs::permissions("user_file.txt",
                   fs::perms::group_all |
                   fs::perms::others_all,
                   fs::perm_options::remove);

    fstream message_file = fstream("message_file.txt", ios::in | ios::out);
    if(!message_file)
        message_file = fstream("message_file.txt", ios::in | ios::out 
                                                             | ios::trunc);
    fs::permissions("message_file.txt",
                    fs::perms::group_all |
                    fs::perms::others_all,
                    fs::perm_options::remove);
    
    user_file << user1 << endl
              << user2 << endl
              << user3 << endl;
    user_file.seekg(0, ios_base::beg);

    message_file << message1 << endl
                 << message2 << endl
                 << message3 << endl;
    message_file.seekg(0, ios_base::beg);


    string tmp;
    cout << "File user_file:" << endl;
    while(getline(user_file, tmp, '\n')) {
        cout << tmp;
        cout << endl;
        tmp ="";
    }
    user_file.close();

    cout << "File message_file:" << endl;
    while(getline(message_file, tmp, '\n')) {
        cout << tmp;
        cout << endl;
        tmp ="";
    }
    message_file.close();
        
    return 0;
}



