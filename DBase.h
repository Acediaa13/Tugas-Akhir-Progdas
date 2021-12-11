#ifndef DATABASE_FUNCTION_H_INCLUDED
#define DATABASE_FUNCTION_H_INCLUDED
#include <iostream>
#include <fstream>

using namespace std;

class Mobil{
    public:
        string nomor;
        string jenis;
        string harga;
        string plat;
        string status;

    Mobil(string nomor, string jenis, string harga, string plat, string status = "A"){
        Mobil::nomor = nomor;
        Mobil::jenis = jenis;
        Mobil::harga = harga;
        Mobil::plat = plat;
        Mobil::status = status;
    }

    string stringify(){
        return "\n" + nomor + " " + status + " " + jenis + " " + harga + " " + plat;
    }
};

class User{
    public:
        string nama;
        string NIK;
        string nomor;

    User(string nama, string NIK, string nomor){
        User::nama = nama;
        User::NIK = NIK;
        User::nomor = nomor;
    }

    string stringify(){
        return "\n" + nama + " " + NIK + " " + nomor;
    }

};

class Dbase{
    public:
        ifstream in;
        ofstream out;
        fstream inout;
        string fileName;

        Dbase(const char* fileName){
            Dbase::fileName = fileName;
        }


        void saveMobil(Mobil data){
        Dbase::out.open(Dbase::fileName, ios::app);
        Dbase::out << data.stringify();
        Dbase::out.close();
        }

        void saveUser(User data){
        Dbase::out.open(Dbase::fileName, ios::app);
        Dbase::out << data.stringify();
        Dbase::out.close();
        }

        void showAllMobil(){
            Dbase::in.open(Dbase::fileName, ios::in);
            string nomor;
            string jenis, harga, plat, status;

            while(!Dbase::in.eof()){
                Dbase::in >> nomor;
                Dbase::in >> status;
                Dbase::in >> jenis;
                Dbase::in >> harga;
                Dbase::in >> plat;
                cout << nomor << " " << status << " " << jenis << " " << harga << " "<< plat << endl;
            }

            Dbase::in.close();
        }

        void showAllUser(){
            Dbase::in.open(Dbase::fileName, ios::in);
            string nama, NIK, nomor;

            int index = 1;

            while(!Dbase::in.eof()){
                Dbase::in >> nama;
                Dbase::in >> NIK;
                Dbase::in >> nomor;
                cout << index++ << ". " << nama << " " << NIK << " " << nomor << endl;
            }

            Dbase::in.close();
        }

        void addMobil(){
        string jenis, harga, plat;
        string nomor;
        char status;

        cout << "Masukkan nomor kode mobil: " << endl;
        cin >> nomor;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Masukkan jenis mobil: " << endl;
        getline(cin, jenis);
        cout << "Masukkan harga sewa: " << endl;
        getline(cin, harga);
        cout << "Masukkan plat nomor (tanpa spasi): " << endl;
        getline(cin, plat);

        Mobil dataMobil(nomor, jenis, harga, plat);
        Dbase database = Dbase("DataMobil.txt");
        database.saveMobil(dataMobil);
        }

        void addUser(){
        string nama, NIK, nomor;

        cout << "Masukkan Nama pelanggan: " << endl;
        getline(cin, nama);
        cout << "Masukkan NIK: " << endl;
        getline(cin, NIK);
        cout << "Masukkan nomor telepon: " << endl;
        getline(cin, nomor);

        User dataUser(nama, NIK, nomor);
        Dbase database = Dbase("DataUser.txt");
        database.saveUser(dataUser);
        }

        void changeStatusMobil(){

        fstream file, file1;
        string updateIndex;
        string nomor, jenistemp, hargatemp, plattemp, statustemp;
        int found = 0;
        file.open("DataMobil.txt", ios::in);
        if (!file)
        {
            cout << "\n\t\t\tNo Data is Present..";
        }
        else
        {
            cout << "\nMasukkan kode nomor yang akan diupdate: ";
            cin >> updateIndex;
            file1.open("temp.txt", ios::app | ios::out);

            while(!file.eof()){
            file >> nomor >> statustemp >> jenistemp >> hargatemp >> plattemp;

            if(nomor != updateIndex){
                file1 << "\n" << nomor << " " << statustemp << " " << jenistemp << " " << hargatemp << " " << plattemp;
            }else{
                if(statustemp == "A"){
                    statustemp = "R";
                }else if(statustemp == "R"){
                    statustemp = "A";
                }
                file1 << "\n" << nomor << " " << statustemp << " " << jenistemp << " " << hargatemp << " " << plattemp;
            }
            }

            file1.close();
            file.close();
            remove("DataMobil.txt");
            rename("temp.txt", "DataMobil.txt");
        }
}

        void deleteMobil(){
        fstream file, file1;
        string updateIndex;
        string nomor, jenistemp, hargatemp, plattemp, statustemp;
        int found = 0;
        file.open("DataMobil.txt", ios::in);
        if (!file)
        {
            cout << "\n\t\t\tNo Data is Present..";
        }
        else
        {
            cout << "\nMasukkan kode nomor yang akan dihapus: ";
            cin >> updateIndex;
            file1.open("temp.txt", ios::app | ios::out);

            while(!file.eof()){
            file >> nomor >> statustemp >> jenistemp >> hargatemp >> plattemp;

            if(nomor != updateIndex){
                file1 << "\n" << nomor << " " << statustemp << " " << jenistemp << " " << hargatemp << " " << plattemp;
            }
            }

            file1.close();
            file.close();
            remove("DataMobil.txt");
            rename("temp.txt", "DataMobil.txt");
        }
        }


};

#endif // DATABASE_FUNCTION_H_INCLUDED
