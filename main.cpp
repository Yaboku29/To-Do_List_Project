#include "TODO.hpp"
#include "Utilitas.hpp"
#include "file_io.hpp"

// void setColor(const string &color);
void menu1();
void menu2();

int main(){
    menu1();
    return 0;
}

// void setColor(const string &color){
//     cout<<color;
// }

void menu1(){
    clearScreen();
    int pilihan;
    //cout<<BLUE_BG;
    cout<<"===>>> TO-DO LIST <<<===\n";
    setColor(BLUE);
    cout<<"1. Tampilkan Tugas\n";
    cout<<"2. Tambah Tugas\n";
    cout<<"3. Hapus Tugas\n";
    cout<<"4. Edit tugas\n";
    cout<<"5. Slide 2\n";
    setColor(RED);
    cout<<"6. Keluar\n";
    setColor(GREEN);
    cout<<"Pilih menu: ";
    cin>>pilihan;

    switch (pilihan)
    {
    case 1:
        tampilkan_tugas();
        system("pause");
        menu1();
        break;
    case 2:
        tambah_tugas();
        system("pause");
        menu1();
        break;
    case 3:
        hapus_tugas();
        system("pause");
        menu1();
        break;
    case 6:
        cout<<"Keluar dari program...\n";
        break;
    case 4:
        edit_tugas();
        system("pause");
        menu1();
        break;
    case 5:
        menu2();
        break;
    default:
        cout<<"Pilihan tidak valid, coba lagi.\n";
        system("pause");
        menu1();
        break;
    }
}

void menu2(){
    clearScreen();
    int pilihan;
    //cout<<BLUE_BG;
    cout<<"===>>> TO-DO LIST <<<===\n";
    setColor(BLUE);
    cout<<"5. Ubah status\n";
    cout<<"6. Cari Tugas\n";
    cout<<"7. Filter Tugas\n";
    cout<<"8. Export File To-Do List\n";
    cout<<"9. Import File To-Do List\n";
    cout<<"10. Balik ke slide 1\n";
    setColor(RED);
    cout<<"11. Keluar\n";
    setColor(GREEN);
    cout<<"Pilih menu: ";
    cin>>pilihan;

    switch (pilihan)
    {
    case 11:
        cout<<"Keluar dari program...\n";
        break;
    case 5:
        tandai_selesai();
        system("pause");
        menu1();
        break;
    case 6:
        cari_tugas();
        system("pause");
        menu1();
        break;
    case 7:
        filter_tugas();
        system("pause");
        menu1();
        break;
    case 8:
        eksporData();
        system("pause");
        menu1();
        break;
    case 9:
        imporData();
        system("pause");
        menu1();
        break;
    case 10:
       // system("pause");
        menu1();
        break;
    default:
        cout<<"Pilihan tidak valid, coba lagi.\n";
        system("pause");
        menu1();
        break;
    }
}