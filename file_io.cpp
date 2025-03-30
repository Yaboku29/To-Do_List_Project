#include "file_io.hpp"
#include "Utilitas.hpp"
#include <fstream>
#include <sstream>
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
    string filename;
    cout<<"Masukkan nama file yang ingin diimpor(termasuk ekstensi): ";
    cin.ignore();
    getline(cin,filename);
    ifstream file(filename);
    if(!file.is_open()){
        cout<<"Gagal membuka file!\n Pastikan nama dan ekstensi benar!\n";
        return;
    }

    json data=bacaData();

    size_t dotPos=filename.find_last_of(".");
    if(dotPos==string::npos){
        cout<<"Format file tidak dikenali!\n";
        return;
    }
    string ext=filename.substr(dotPos);

    if(ext==".txt"){
        string line;
        while(getline(file,line)){
            stringstream ss(line);
            string deskripsi,deadline,prioritas,status;

            getline(ss,deskripsi,'|');
            getline(ss,deadline,'|');
            getline(ss,prioritas,'|');
            getline(ss,status,'|');

            json tugas={
                {"deskripsi",deskripsi},
                {"deadline",deadline},
                {"prioritas",prioritas},
                {"status",status}
            };

            data.push_back(tugas);
        }
    }
    else if(ext==".csv"){
        string line;
        bool isHeader=true;
        while(getline(file,line)){
            if(isHeader){
                isHeader=false;
                continue;
            }

            stringstream ss(line);
            string deskripsi,deadline,prioritas,status;

            getline(ss,deskripsi,',');
            getline(ss,deadline,',');
            getline(ss,prioritas,',');
            getline(ss,status,',');

            json tugas={
                {"deskripsi",deskripsi},
                {"deadline",deadline},
                {"prioritas",prioritas},
                {"status",status}
            };

            data.push_back(tugas);
        }
    }
    else {
        cout<<"Format file tidak didukung!\nHanya mendukung .txt dan .csv\n";
        return;
    }

    file.close();
    simpanData(data);
}