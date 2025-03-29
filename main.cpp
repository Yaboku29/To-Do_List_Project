#include "TODO.hpp"

// void setColor(const string &color);
void menu();

int main(){
    menu();
    return 0;
}

// void setColor(const string &color){
//     cout<<color;
// }

void menu(){
    system("cls");
    int pilihan;
    cout<<BLUE_BG;
    cout<<"\n===>>> TO-DO LIST <<<===\n";
    setColor(BLUE);
    cout<<"1. Tampilkan Tugas\n";
    cout<<"2. Tambah Tugas\n";
    cout<<"3. Hapus Tugas\n";
    cout<<"4. Edit tugas\n";
    cout<<"5. Ubah status\n";
    cout<<"6. Cari Tugas\n";
    cout<<"7. Filter Tugas\n";
    setColor(RED);
    cout<<"8. Keluar\n";
    setColor(GREEN);
    cout<<"Pilih menu: ";
    cin>>pilihan;

    switch (pilihan)
    {
    case 1:
        tampilkan_tugas();
        system("pause");
        menu();
        break;
    case 2:
        tambah_tugas();
        system("pause");
        menu();
        break;
    case 3:
        hapus_tugas();
        system("pause");
        menu();
        break;
    case 8:
        cout<<"Keluar dari program...\n";
        break;
    case 4:
        edit_tugas();
        system("pause");
        menu();
        break;
    case 5:
        tandai_selesai();
        system("pause");
        menu();
        break;
    case 6:
        cari_tugas();
        system("pause");
        menu();
        break;
    case 7:
        filter_tugas();
        system("pause");
        menu();
        break;
    default:
        cout<<"Pilihan tidak valid, coba lagi.\n";
        system("pause");
        menu();
        break;
    }
}