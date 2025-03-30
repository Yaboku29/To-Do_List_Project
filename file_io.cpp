#include "file_io.hpp"
#include "Utilitas.hpp"
#include <fstream>
using json=nlohmann::json;
using namespace std;

void eksporData(){
    json data=bacaData();
    clearScreen();
    if(data.empty()){
        cout<<"Tidak ada data untuk diekspor!\n";
        return;
    }
    int pilihan;
    string filename;

    cout<<"Pilih format ekspor:\n";
    cout<<"1. .txt (Teks biasa)\n";
    cout<<"2. .csv (Bisa dibuka di Excel)\n";
    cout<<"Pilihan: ";
    cin>>pilihan;
    cin.ignore();
    cout<<"Masukkan nama file: ";
    getline(cin,filename);
    if(pilihan<1||pilihan>2){
        cout<<"Input invalid\n";
        return;
    }
    if(pilihan==1) filename+=".txt";
    else filename+=".csv";
    ofstream file(filename);
    if(!file.is_open()){
        cout<<"Gagal membuka file!\n";
        return;
    }
    if(pilihan==1){
        for(const auto& tugas : data){
            file<<tugas["deskripsi"]<<" | "
                <<tugas["deadline"]<<" | "
                <<tugas["prioritas"]<<" | "
                <<tugas["status"]<<"\n";
        }
    }
    else {
        file <<"Deskripsi, Deadline, Prioritas, Status\n";
        for(const auto& tugas : data){
            file<<"\""<<tugas["deskripsi"]<<"\","
                <<"\""<<tugas["deadline"]<<"\","
                <<"\""<<tugas["prioritas"]<<"\","
                <<"\""<<tugas["status"]<<"\"\n";
        }
    }
    file.close();
    cout<<"Data berhasil diekspor ke "<<filename<<"!\n";
}
void imporData(){

}