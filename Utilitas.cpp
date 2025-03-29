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
        d888888b  .d88b.  d8888b.  .d88b.  
        ```88``` d8P  Y8b 88   8D d8P  Y8b
           88    8P    Y8 88   88 8P    Y8
           88    8b    d8 88   88 8b    d8
           88    Y8b   dB 88   8D Y8b   dB
           YP     `Y88P'  Y8888D`  `Y88P'
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