#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;

#include <cstdlib>

void clear_screen()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

vector<string> login(vector<vector<string>> users, string username, string password)
{
  vector<string> userData = {"not_logged_in"};
  for (int i = 0; i < users.size(); i++)
  {
    if (username == users[i][1] && password == users[i][3])
    {
      userData = {
          "logged_in",
          users[i][0],
          users[i][2],
          users[i][4],
      };
    }
  }

  return userData;
}

vector<vector<string>> getSubData(vector<vector<string>> mainData, string code)
{
  vector<vector<string>> subData;
  if (code == "-")
  {
    subData = mainData;
  }
  else
  {
    for (auto item : mainData)
    {
      if (item[4] == code)
      {
        subData.push_back(item);
      }
      else if (item[4] == code)
      {
        subData.push_back(item);
      }
      else if (item[4] == code)
      {
        subData.push_back(item);
      }
    }
  }

  return subData;
}

void showData(vector<vector<string>> mainData)
{
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
       << "| NO \t| Nama\t\t\t\t| Jumlah| Harga \t| Lokasi| Tanggal Masuk\t| Tanggal Update\t|\n"
       << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

  if (mainData.size() > 0)
  {
    for (int i = 0; i < mainData.size(); i++)
    {
      cout << "| "
           << i + 1
           << " \t| "
           << mainData[i][1]
           << "\t\t\t| "
           << mainData[i][2]
           << "\t|"
           << mainData[i][3]
           << "\t\t|"
           << mainData[i][4]
           << "\t|"
           << mainData[i][5]
           << "\t|"
           << mainData[i][6]
           << "\t\t|\n";
    }
  }
  else
  {
    cout << "|\t\t\t\t\t Barang Tidak Ditemukan! \t\t\t\t\t\t|\n";
  }
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
}

vector<string> searchDataByName(vector<vector<string>> mainData, string itemName)
{
  vector<string> searchResult;
  for (int i = 0; i < mainData.size(); i++)
  {
    if (mainData[i][1] == itemName)
    {
      searchResult = mainData[i];
      searchResult.push_back(to_string(i));
    }
  }

  return searchResult;
}

vector<vector<string>> searchDataByNameV2(vector<vector<string>> mainData, string itemName)
{
  vector<vector<string>> hasilCari;
  for (int i = 0; i < mainData.size(); i++)
  {
    if (mainData[i][1].find(itemName) != std::string::npos)
    {
      hasilCari.push_back(mainData[i]);
    }
  }

  return hasilCari;
}

vector<vector<string>> sortData(vector<vector<string>> mainData, int sortBy, string typeSort)
{
  cout << typeSort;
  if (typeSort == "asc")
  {
    sort(mainData.begin(), mainData.end(), [&](vector<string> &A, vector<string> &B)
         { return A[sortBy] > B[sortBy]; });
  }
  else if (typeSort == "desc")
  {
    sort(mainData.begin(), mainData.end(), [&](vector<string> &A, vector<string> &B)
         { return A[sortBy] < B[sortBy]; });
  }

  return mainData;
}

string getTimeNow()
{
  char s[80];
  time_t t = time(0);
  strftime(s, 80, "%d/%m/%Y", localtime(&t));

  return s;
}

int main()
{
  int pilihan;
  string username, password, realName, namaBarang, banyakBarang, hargaBarang, lokasiBarang, tanggalMasuk;
  vector<string> userData;
  vector<vector<string>> subData;

  // Buat Vector Data User
  vector<vector<string>> users = {
      {
          "1",
          "admin",
          "User Admin",
          "12345",
          "-",
      },
      {
          "2",
          "user1",
          "User Gudang A",
          "12345",
          "A",
      },
      {
          "3",
          "user2",
          "User Gudang B",
          "12345",
          "B",
      },
      {
          "4",
          "user3",
          "User Gudang C",
          "12345",
          "C",
      }

  };

  // Buat Vector Data Barang
  vector<vector<string>> mainData = {
      {
          "1",
          "Laptop Merk J",
          "100",
          "Harga",
          "A",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "2",
          "Laptop Merk A",
          "645",
          "Harga",
          "A",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "3",
          "Laptop Merk C",
          "234",
          "Harga",
          "B",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "4",
          "Laptop Merk D",
          "974",
          "Harga",
          "B",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "5",
          "Laptop Merk B",
          "100",
          "Harga",
          "B",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "6",
          "Laptop Merk F",
          "758",
          "Harga",
          "A",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "7",
          "Laptop Merk E",
          "567",
          "Harga",
          "C",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "8",
          "Laptop Merk I",
          "100",
          "Harga",
          "C",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "9",
          "Laptop Merk G",
          "264",
          "Harga",
          "C",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "10",
          "Laptop Merk H",
          "126",
          "Harga",
          "C",
          "05/11/2021",
          "04/12/2021",
      },
  };

landing:
  clear_screen();
  cout << "========== Selamat datang di Aplikasi Management Gudang =========="
       << endl
       << "1. Login \n2. Register \n3. Exit \n"
       << "MASUKKAN NOMOR MENU :";
  cin >> pilihan;
  if (pilihan == 1)
  {
  login:
    clear_screen();
    cout << "===== Menu Login ====="
         << endl;
    cout << "Masukkan Username :";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;
    userData = login(users, username, password);
    clear_screen();
    if (userData[0] == "logged_in")
    {
      subData = getSubData(mainData, userData[3]);
      goto menu;
    }
    else
    {
      cout << "Username atau Password yang anda masukkan salah! Silahkan coba lagi!"
           << endl;
      goto login;
    }
  }
  else if (pilihan == 2)
  {
    cout << "===== Registrasi User Baru ====="
         << endl
         << "Masukkan Nama Anda : ";
    cin.ignore();
    getline(cin, realName);
    cout << "Masukkan Username : ";
    cin >> username;
    cout << "Masukkan Password : ";
    cin >> password;
    cout << "Masukkan Lokasi Bertugas (A/B/C) : ";
    cin >> lokasiBarang;

    int sizeBefore = users.size();
    vector<string> newUser = {
        to_string(stoi(users.back()[0]) + 1),
        username,
        realName,
        password,
        lokasiBarang,
    };
    users.push_back(newUser);

    if (sizeBefore < users.size())
    {
      cout << "User Berhasil dibuat.";
      cin.get();
      goto login;
    }
    else
    {
      cout << "Terjadi kesalahan saat membuat user!";
    }
  }
  else if (pilihan == 3)
  {
    return 0;
  }

menu:
  clear_screen();
  cout << "========== Selamat datang "
       << userData[2]
       << " di Aplikasi Management Gudang =========="
       << endl
       << "Silahkan Pilih Menu dibawah ini : "
       << endl
       << "1. List Data Barang \n"
       << "2. Input Barang Baru \n"
       << "3. Hapus Barang \n"
       << "4. Cari Barang \n"
       << "5. Edit Data Barang \n"
       << "6. Log Out"
       << endl
       << "Masukkan nomor menu : ";
  cin >> pilihan;

  clear_screen();

  if (pilihan == 1)
  {
  listData:
    int subMenuList;
    cout << "===== List Data Barang ====="
         << endl
         << endl;

    showData(subData);
    string sortType = "desc";

  subMenuList:
    cout << endl;
    cout << "1. Sort Table \t\t"
         << "2. Tambah Data \t\t"
         << "3. Hapus Data \t\t"
         << "4. Keluar"
         << endl
         << "Masukkan pilihan : ";
    cin >> subMenuList;

    if (subMenuList == 1)
    {
      int subMenuSort;

      cout << "1. Sort by Name \t\t"
           << "2. Sort by Value \t\t"
           << "3. Sort by Price \t\t"
           << "4. Sort by Place \t\t"
           << "5. Sort by Date of Entry \t\t"
           << "6. Sort by Date Modified \t\t"
           << "7. Batal"
           << endl
           << "Masukkan pilihan : ";
      cin >> subMenuSort;
      if (subMenuSort == 1 || subMenuSort == 2 || subMenuSort == 3 || subMenuSort == 4 || subMenuSort == 5 || subMenuSort == 6)
      {
        vector<vector<string>> sortedData = sortData(subData, subMenuSort, sortType);
        clear_screen();
        showData(sortedData);
        sortType = (sortType == "asc") ? "desc" : "asc";
        goto subMenuList;
      }
      else if (subMenuSort == 7)
      {
        goto listData;
      }
    }
    else if (subMenuList == 2)
    {
      goto insertData;
    }
    else if (subMenuList == 3)
    {
      goto deleteData;
    }
    else if (subMenuList == 4)
    {
      goto menu;
    }
    else
    {
      clear_screen();
      cout << "Menu yang anda masukkan salah!"
           << endl;
      goto listData;
    }
  }
  else if (pilihan == 2)
  {
  insertData:
    cout << "===== Menu Input Data Baru ====="
         << endl
         << "Masukkan nama barang : ";
    cin.ignore();
    getline(cin, namaBarang);
    cout << "Masukkan jumlah barang : ";
    cin >> banyakBarang;
    cout << "Masukkan harga barang : ";
    cin >> hargaBarang;
    if (userData[3] == "-")
    {
      cout << "Masukkan Lokasi Penyimpanan : ";
      cin >> lokasiBarang;
    }
    else if (userData[3] == "A")
    {
      lokasiBarang = "A";
    }
    else if (userData[3] == "B")
    {
      lokasiBarang = "B";
    }
    else if (userData[3] == "C")
    {
      lokasiBarang = "C";
    }
    cout << "Masukkan Tanggal Barang Masuk (dd/mm/yyyy) : ";
    cin >> tanggalMasuk;

    int sizeBefore = mainData.size();

    vector<string> newData = {
        to_string(stoi(mainData.back()[0]) + 1),
        namaBarang,
        banyakBarang,
        hargaBarang,
        lokasiBarang,
        tanggalMasuk,
        getTimeNow(),
    };

    mainData.push_back(newData);

    if (sizeBefore < mainData.size())
    {
      subData = getSubData(mainData, userData[3]);
      cout << "Barang berhasil dimasukkan.";
    }
    else
    {
      cout << "Terjadi kesalahan saat memasukkan data!";
    }
  }
  else if (pilihan == 3)
  {
  deleteData:
    cout << "===== Menu Hapus Barang ====="
         << endl;
    cout << "Masukkan nama barang : ";
    cin.ignore();
    getline(cin, namaBarang);

    vector<string> searchResult = searchDataByName(subData, namaBarang);
    if (searchResult.size() > 0)
    {
      searchResult = searchDataByName(mainData, namaBarang);
      if (searchResult.size() > 0)
      {
        mainData.erase(mainData.begin() + stoi(searchResult[7]));
        subData = getSubData(mainData, userData[3]);
        cout << namaBarang
             << " berhasil dihapus.";
      }
      else
      {
        cout << "Terjadi kesalahan saat menghapus data!";
      }
    }
    else
    {
      cout << "Nama Barang Tidak Ditemukan!";
    }
  }
  else if (pilihan == 4)
  {
    cout << "===== Menu Cari Barang ====="
         << endl;
    cout << "Masukkan nama barang : ";
    cin.ignore();
    getline(cin, namaBarang);
    vector<vector<string>> searchResult = searchDataByNameV2(subData, namaBarang);
    showData(searchResult);
  }
  else if (pilihan == 5)
  {
  edit:
    cout << "===== Menu Edit Data ====="
         << endl
         << "Masukkan nama barang : ";
    cin.ignore();
    getline(cin, namaBarang);
    vector<string> searchResult = searchDataByName(subData, namaBarang);
    if (searchResult.size() > 0)
    {
      showData({searchResult});

      cout << "Tekan enter jika data tidak diubah. \n";
      cout << "Masukkan Nama Baru: ";
      getline(cin, namaBarang);
      cout << "Masukkan Banyak Barang Baru: ";
      getline(cin, banyakBarang);
      cout << "Masukkan Harga Barang Baru: ";
      getline(cin, hargaBarang);
      if (userData[3] == "-")
      {
        cout << "Masukkan Lokasi Barang Baru: ";
        getline(cin, lokasiBarang);
      }
      else
      {
        lokasiBarang = searchResult[4];
      }
      cout << "Masukkan Tanggal Masuk Baru: ";
      getline(cin, tanggalMasuk);

      // set default value jika input tidak diisi
      namaBarang = namaBarang.empty() ? searchResult[1] : namaBarang;
      banyakBarang = banyakBarang.empty() ? searchResult[2] : banyakBarang;
      hargaBarang = hargaBarang.empty() ? searchResult[3] : hargaBarang;
      lokasiBarang = lokasiBarang.empty() ? searchResult[4] : lokasiBarang;
      tanggalMasuk = tanggalMasuk.empty() ? searchResult[5] : tanggalMasuk;

      vector<string> newData = {
          searchResult[0],
          namaBarang,
          banyakBarang,
          hargaBarang,
          lokasiBarang,
          tanggalMasuk,
          getTimeNow(),
      };

      searchResult = searchDataByName(mainData, namaBarang);
      mainData[stoi(searchResult[7])] = newData;
      subData = getSubData(mainData, userData[3]);

      cout << "Data Berhasil di Update!";
    }
    else
    {
      cout << "Nama Barang Tidak Ditemukan!";
    }
  }
  else if (pilihan == 6)
  {
    goto landing;
  }
  else
  {
    cout << "Nomor Menu yang anda masukkan salah. Silahkan coba lagi";
  }

  cin.ignore();
  cin.get();
  clear_screen();
  goto menu;
}