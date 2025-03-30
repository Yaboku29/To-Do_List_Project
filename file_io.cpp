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

    json data;

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
            
            if (!deskripsi.empty() && deskripsi.front() == '"' && deskripsi.back() == '"')
                deskripsi.erase(0, 1), deskripsi.pop_back();
            if (!deadline.empty() && deadline.front() == '"' && deadline.back() == '"')
                deadline.erase(0, 1), deadline.pop_back();
            if (!prioritas.empty() && prioritas.front() == '"' && prioritas.back() == '"')
                prioritas.erase(0, 1), prioritas.pop_back();
            if (!status.empty() && status.front() == '"' && status.back() == '"')
                status.erase(0, 1), status.pop_back();

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

            if (!deskripsi.empty() && deskripsi.front() == '"' && deskripsi.back() == '"')
                deskripsi.erase(0, 1), deskripsi.pop_back();
            if (!deadline.empty() && deadline.front() == '"' && deadline.back() == '"')
                deadline.erase(0, 1), deadline.pop_back();
            if (!prioritas.empty() && prioritas.front() == '"' && prioritas.back() == '"')
                prioritas.erase(0, 1), prioritas.pop_back();
            if (!status.empty() && status.front() == '"' && status.back() == '"')
                status.erase(0, 1), status.pop_back();

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

    ofstream outFile("todolist.json");
    if(!outFile.is_open()){
        cout<<"Gagal menyimpan data ke JSON!\n";
        return;
    }
    outFile<<data.dump(4);
    outFile.close();

    cout<<"Data berhasil diimpor dan disimpan!\n";
    //simpanData(data);
}