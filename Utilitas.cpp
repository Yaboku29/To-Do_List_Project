#include "Utilitas.hpp"

using namespace std;

void tampilkanHeader(){
    cout<<CYAN<<BOLD;
    cout << R"(  
        _______   ___   ____    ___
       |__   __| / _ \ |  _ \  / _ \
          | |   | | | || | | || | | |
          | |   | |_| || |_| || |_| |
          |_|    \___/ |____/  \___/
        Made by:
          )";
    cout<<RED;
    cout<<"Yaboku29";
    cout << RESET << endl;  // Kembali ke warna default
}

void clearScreen(){
    cout<<"\033[2J";
    cout<<"\033[1;1H";
    tampilkanHeader();
}