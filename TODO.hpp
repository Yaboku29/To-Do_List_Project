#ifndef TODO_HPP
#define TODO_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "json.hpp" 

using namespace std;
using json=nlohmann::json;

//struct tugas
struct Tugas{
    string deskripsi;
    string deadline;
    string prioritas;
    string selesai;
};

//Fungsi baca dan simpan
json bacaData();
void simpanData(const json &data);

//Fungsi untuk menambah, mengedit, dan menghapus
void tambah_tugas();
void hapus_tugas();
void edit_tugas();
void tampilkan_tugas();
void tandai_selesai();
void cari_tugas();
void filter_tugas();

#endif 