#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{
  int pilihan;
  string namaBarang, banyakBarang;

  // Buat Vector
  vector<vector<string>> dataBarang = {
      {
          "1",
          "Laptop Merk A",
          "100",
      },
      {
          "2",
          "Laptop Merk B",
          "200",
      }};

menu:
  cout << "========== Selamat datang di Aplikasi Management Gudang =========="
       << endl
       << "Silahkan Pilih Menu dibawah ini : "
       << endl
       << "1. List Data Barang \n"
       << "2. Input Barang Baru \n"
       << "3. Hapus Barang \n"
       << "4. Cari Barang \n"
       << "6. Keluar"
       << endl
       << "Masukkan nomor menu : ";
  cin >> pilihan;

  system("clear");

  if (pilihan == 1)
  {
    cout << "===== List Data Barang ====="
         << endl
         << endl;

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
         << "| NO \t| Nama\t\t\t\t\t| Jumlah\t|\n"
         << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    for (int i = 0; i < dataBarang.size(); i++)
    {
      cout << "| "
           << i + 1
           << " \t| "
           << dataBarang[i][1]
           << "\t\t\t\t| "
           << dataBarang[i][2]
           << "\t\t|\n";
    }
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
  }
  else if (pilihan == 2)
  {
    cout << "===== Menu Input Data Baru ====="
         << endl
         << "Masukkan nama barang \t: ";
    cin.ignore();
    getline(cin, namaBarang);
    cout << "Masukkan jumlah barang \t: ";
    cin >> banyakBarang;

    int sizeBefore = dataBarang.size();

    vector<string> dataBaru = {
        to_string(stoi(dataBarang.back()[0]) + 1),
        namaBarang,
        banyakBarang,
    };

    dataBarang.push_back(dataBaru);

    if (sizeBefore < dataBarang.size())
    {
      cout << "Barang berhasil dimasukkan.";
    }
  }
  else if (pilihan == 3)
  {
    cout << "===== Menu Hapus Barang ====="
         << endl;
    cout << "Masukkan nama barang : ";
    cin.ignore();
    getline(cin, namaBarang);

    for (int i = 0; i < dataBarang.size(); i++)
    {
      for (int j = 0; j < dataBarang[i].size(); j++)
      {
        if (dataBarang[i][j] == namaBarang)
        {
          dataBarang.erase(dataBarang.begin() + i);
          cout << namaBarang
               << " berhasil dihapus.";
          break;
        }

        if (i == dataBarang.size() - 1 && j == dataBarang[i].size() - 1 && dataBarang[i][j] != namaBarang)
        {
          cout << "Nama Barang tidak ditemukan!";
          break;
        }
      }
    }
  }
  else if (pilihan == 4)
  {
    cout << "===== Menu Cari Barang ====="
         << endl;
    cout << "Masukkan nama barang : ";
    cin.ignore();
    getline(cin, namaBarang);

    vector<vector<string>> hasilCari;

    for (int i = 0; i < dataBarang.size(); i++)
    {
      for (int j = 0; j < dataBarang[i].size(); j++)
      {
        if (dataBarang[i][j] == namaBarang)
        {
          hasilCari.push_back(dataBarang[i]);
          break;
        }
      }
    }

    if (hasilCari.size() > 0)
    {
      cout << endl;
      cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
           << "| NO \t| Nama\t\t\t\t\t| Jumlah\t|\n"
           << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

      for (int i = 0; i < hasilCari.size(); i++)
      {
        cout << "| "
             << i + 1
             << " \t| "
             << hasilCari[i][1]
             << "\t\t\t\t| "
             << hasilCari[i][2]
             << "\t\t|\n";
      }
      cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    }
    else
    {
      cout << "Barang tidak ditemukan";
    }
  }
  else if (pilihan == 6)
  {
    return 0;
  }
  else
  {
    cout << "Nomor Menu yang anda masukkan salah. Silahkan coba lagi";
  }

  cin.ignore();
  cin.get();

  goto menu;
}