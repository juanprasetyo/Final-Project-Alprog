#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
#include <ctime>

using namespace std;

void clear_screen() {
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif 
}

vector<string> login(string username, string password, vector<vector<string>> users) {
  vector<string> result;
  for (int i = 0; i < users.size(); i++) {
    if (users[i][1] == username && users[i][3] == password) {
      result = users[i];
      break;
    }
  }

  return result;
}

int checkUsername(string username, vector<vector<string>> users) {
  int result = 0;
  for (int i = 0; i < users.size(); i++) {
    if (users[i][1] == username) {
      result = 1;
      break;
    }
  }

  return result;
}

vector<vector<string>> getSubData(string role, vector<vector<string>> mainData) {
  vector<vector<string>> result;
  if (role == "-") {
    result = mainData;
  } else {
    for (int i = 0; i < mainData.size(); i++) {
      if (mainData[i][4] == role) {
        result.push_back(mainData[i]);
      }
    }
  }

  return result;
}

void showData(vector<vector<string>> data) {
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"
       << "| "
       << setiosflags(ios::left)
       << setw(3) << "No"
       << " | "
       << setiosflags(ios::left)
       << setw(25) << "Nama"
       << " | "
       << setiosflags(ios::left)
       << setw(6) << "Jumlah"
       << " | "
       << setiosflags(ios::left)
       << setw(10) << "Harga"
       << " | "
       << setiosflags(ios::left)
       << setw(6) << "Lokasi"
       << " | "
       << setiosflags(ios::left)
       << setw(15) << "Tanggal Masuk"
       << " | "
       << setiosflags(ios::left)
       << setw(15) << "Tanggal Update"
       << " |\n"
       << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

  if (data.size() > 0) {
    for (int i = 0; i < data.size(); i++) {
      cout << setiosflags(ios::left)
           << "| "
           << setw(3) << i + 1
           << " | "
           << setw(25) << data[i][1]
           << " | "
           << setw(6) << data[i][2]
           << " | "
           << setw(10) << data[i][3]
           << " | "
           << setw(6) << data[i][4]
           << " | "
           << setw(15) << data[i][5]
           << " | "
           << setw(15) << data[i][6]
           << " |\n";
    }
  } else {
    cout << "|\t\t\t\t\t Barang Tidak Ditemukan! \t\t\t\t\t\t|\n";
  }
  cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
}

vector<vector<string>> sortData(vector<vector<string>> subData, int sortBy, string typeSort)
{
  if (sortBy == 2 || sortBy == 3) {
    if (typeSort == "asc") {
      sort(subData.begin(), subData.end(), [&](vector<string> &A, vector<string> &B)
           { return stoi(A[sortBy]) < stoi(B[sortBy]); });
    }
    else if (typeSort == "desc") {
      sort(subData.begin(), subData.end(), [&](vector<string> &A, vector<string> &B)
           { return stoi(A[sortBy]) > stoi(B[sortBy]); });
    }
  } else {
    if (typeSort == "asc") {
      sort(subData.begin(), subData.end(), [&](vector<string> &A, vector<string> &B)
           { return A[sortBy] < B[sortBy]; });
    }
    else if (typeSort == "desc") {
      sort(subData.begin(), subData.end(), [&](vector<string> &A, vector<string> &B)
           { return A[sortBy] > B[sortBy]; });
    }
  }

  return subData;
}

vector<string> searchDataByName(vector<vector<string>> data, string itemName)
{
  vector<string> result;
  for (int i = 0; i < data.size(); i++) {
    if (data[i][1] == itemName) {
      result = data[i];
      result.push_back(to_string(i));
    }
  }

  return result;
}

vector<vector<string>> searchDataByNameV2(vector<vector<string>> data, string itemName) {
  vector<vector<string>> result;
  for (int i = 0; i < data.size(); i++) {
    if (data[i][1].find(itemName) != std::string::npos) {
      result.push_back(data[i]);
    }
  }

  return result;
}

string getDateNow()
{
  char s[80];
  time_t t = time(0);
  strftime(s, 80, "%d/%m/%Y", localtime(&t));

  return s;
}

int main() {
  int menu;
  string username, password, realName, location, itemName, itemValue, itemPrice, itemLocation, dateIn;

  //Vector Data Users
  vector<vector<string>> users = {
    {
        "1",            //Id User
        "admin",        //Username
        "User Admin",   //Real Name
        "12345",        //Password
        "-",            //Role "-" == Admin, selain itu pekerja biasa
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

  //Vector Data Barang
  vector<vector<string>> mainData = {
      {
          "1",
          "Laptop Merk J",
          "100",
          "6000000",
          "A",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "2",
          "Laptop Merk A",
          "645",
          "3500000",
          "A",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "3",
          "Laptop Merk C",
          "234",
          "7990000",
          "B",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "4",
          "Laptop Merk D",
          "974",
          "9555000",
          "B",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "5",
          "Laptop Merk B",
          "100",
          "15000000",
          "B",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "6",
          "Laptop Merk F",
          "758",
          "7990000",
          "A",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "7",
          "Laptop Merk E",
          "567",
          "25000000",
          "C",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "8",
          "Laptop Merk I",
          "100",
          "19500000",
          "C",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "9",
          "Laptop Merk G",
          "264",
          "4500000",
          "C",
          "05/11/2021",
          "04/12/2021",
      },
      {
          "10",
          "Laptop Merk H",
          "126",
          "35000000",
          "C",
          "05/11/2021",
          "04/12/2021",
      },
  };
  
  vector<string> userData;
  vector<vector<string>> subData;

  landing:
  clear_screen();
  cout << "```````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n"
       << "``````````WWW```````WWW```````WWW``EEEEEEEE``LLL```````CCCCCCCC``OOOOOOOO``````MMM``````MMM``````EEEEEEEE``````````\n"
       << "```````````WWW`````WWWWW`````WWW```EEE```````LLL```````CCC```````OO````OO`````MMMMM````MMMMM`````EEE```````````````\n"
       << "````````````WWW```WWW`WWW```WWW````EEEEEE````LLL```````CCC```````OO````OO````MMM`MMM``MMM`MMM````EEEEEE````````````\n"
       << "`````````````WWW`WWW```WWW`WWW`````EEE```````LLL```````CCC```````OO````OO```MMM```MMMMMM```MMM```EEE```````````````\n"
       << "``````````````WWWWW`````WWWWW``````EEEEEEEE``LLLLLLLL``CCCCCCCC``OOOOOOOO``MMM`````MMMM`````MMM``EEEEEEEE``````````\n"
       << "```````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n"
       << "```````````````````````````````````````````` APLIKASI MANAGEMENT GUDANG ```````````````````````````````````````````\n"
       << "````````````````````````````````````````````````````BY: KELOMPOK 7 ````````````````````````````````````````````````\n"
       << "```````````````````````````````````````````````````````````````````````````````````````````````````````````````````\n"
       << endl;
  cout << "SILAHKAN PILIH MENU DIBAWAH INI" << endl;
  cout << "1. LOGIN\n"
       << "2. BUAT AKUN\n"
       << "3. KELUAR\n";
  cout << "MASUKKAN NO MENU : ";
  cin  >> menu;

  if (menu == 1) {
    login: 
    clear_screen();
    cout << "========== LOGIN ==========\n";
    cout << "MASUKKAN USERNAME : ";
    cin  >> username;
    cout << "MASUKKAN PASSWORD : ";
    cin  >> password;

    userData = login(username, password, users);
    if (userData.size() > 0) {
      subData = getSubData(userData[4], mainData);
      goto mainMenu;
    } else {
      cout << "USERNAME / PASSWORD YANG ANDA MASUKKAN SALAH!!";
      cin.ignore();
      cin.get();
      goto login;
    }
  } else if (menu == 2) {
    registration:
    char repeat = 'Y';

    do {
      clear_screen();

      cout << "SILAHKAN ISI DATA DIRI ANDA!" << endl;
      cout << "MASUKKAN NAMA ANDA : ";
      cin  >> realName;
      cout << "MASUKKAN USERNAME : ";
      cin  >> username;

      if (checkUsername(username, users) == 1) {
        cout << "USERNAME YANG ANDA MASUKKAN SUDAH DIDAFTARKAN!!";
        cout << "\n\nTEKAN ENTER UNTUK MELANJUTKAN.....";
        cin.ignore();
        cin.get();
        goto registration;
      }

      cout << "MASUKKAN PASSWORD : ";
      cin  >> password;
      cout << "MASUKKAN LOKASI TEMPAT BERTUGAS (A/B/C) : ";
      cin  >> location;
      cout << "\nAPAKAH DATA YANG ANDA MASUKKAN SUDAH BENAR? (Y/T) : ";
      cin  >> repeat;
    } while (repeat == 'T');

    int id = stoi(users.back()[0]) + 1; //Ambil id dari data user terakhir + 1

    //Insert data akun ke vector users
    users.push_back({
      to_string(id),
      username,
      realName,
      password,
      location,
    });

    cout << "USER BERHASIL DIBUAT!!";
    cout << "\n\nTEKAN ENTER UNTUK MELANJUTKAN.....";
    cin.ignore();
    cin.get();
    goto landing;
  } else if (menu == 3) {
    return 0;
  } else {
    cout << "MENU YANG ANDA MASUKKAN SALAH!!";
    cout << "\n\nTEKAN ENTER UNTUK MELANJUTKAN.....";
    cin.ignore();
    cin.get();
    goto landing;
  }

  mainMenu:
  clear_screen();
  cout << "SELAMAT DATANG " << userData[2] << ". SILAHKAN PILIH MENU DIBAWAH INI" << endl;
  cout << "1. LIST DATA BARANG\n"
       << "2. INPUT BARANG BARU\n"
       << "3. HAPUS BARANG\n"
       << "4. CARI BARANG\n"
       << "5. EDIT BARANG\n"
       << "6. LOG OUT"
       << endl;
  cout << "MASUKKAN NO MENU : ";
  cin  >> menu;

  if (menu == 1) {
    listData:
    clear_screen();
    int subMenuList;

    cout << "========== LIST DATA BARANG ==========\n\n";

    showData(subData);
    string sortType = "asc";

    subMenuList:
    cout << endl;
    cout << "1. SORT TABLE\t\t"
         << "2. TAMBAH DATA\t\t"
         << "3. HAPUS DATA\t\t"
         << "4. KELUAR" 
         << endl;
    cout << "MASUKKAN NO MENU : ";
    cin  >> subMenuList;

    if (subMenuList == 1) {
      subMenuSort: 
      int subMenuSort;

      cout << "1. Sort by Name \n"
           << "2. Sort by Value \n"
           << "3. Sort by Price \n"
           << "4. Sort by Place \n"
           << "5. Sort by Date of Entry \n"
           << "6. Sort by Date Modified \n"
           << "7. Batal"
           << endl;
      cout << "MASUKKAN NO MENU : ";
      cin  >> subMenuSort;

      if (subMenuSort == 1 || subMenuSort == 2 || subMenuSort == 3 || subMenuSort == 4 || subMenuSort == 5 || subMenuSort == 6) {
        vector<vector<string>> sortedData = sortData(subData, subMenuSort, sortType);
        clear_screen();
        showData(sortedData);
        sortType = (sortType == "asc") ? "desc" : "asc";
        goto subMenuSort;
      } else if (subMenuSort == 7) {
        goto listData;
      } else {
        cout << "MENU YANG ANDA MASUKKAN SALAH!!";
        cout << "\n\nTEKAN ENTER UNTUK MELANJUTKAN.....";
        cin.ignore();
        cin.get();
        goto subMenuSort;
      }
    } else if (subMenuList == 2) {
      cin.ignore();
      goto insertData;
    } else if (subMenuList == 3) {
      goto deleteData;
    } else if (subMenuList == 4) {
      goto mainMenu;
    } else {
      cout << "MENU YANG ANDA MASUKKAN SALAH!!";
      cout << "\n\nTEKAN ENTER UNTUK MELANJUTKAN.....";
      cin.ignore();
      cin.get();
      goto subMenuList;
    }
  } else if (menu == 2) {
    cin.ignore();
    insertData:
    clear_screen();
    cout << "========== INPUT BARANG ==========\n";
    cout << "MASUKKAN NAMA BARANG : ";
    getline(cin, itemName);

    vector<string> searchResult = searchDataByName(mainData, itemName);
    if (searchResult.size() > 0) {
      cout << "BARANG YANG ANDA MASUKKAN SUDAH ADA!\n";

      int lanjutan;

      lanjutan:
      cout  << "1. LANJUTKAN\t\t" 
            << "2. KELUAR\n" 
            << "MASUKKAN PILIHAN : ";
      cin >> lanjutan;

      if (lanjutan == 1){
        clear_screen();
        cin.ignore();
        goto insertData;
      } else if (lanjutan == 2){
        goto mainMenu;
      }else {
        cout  << "Nomor menu yang anda masukkan salah!\n";
        cin.ignore();
        cin.get();
        clear_screen();
        goto lanjutan;
      }
    }
    cout << "MASUKKKAN BANYAK BARANG : ";
    cin  >> itemValue;
    cout << "MASUKKAN HARGA BARANG : ";
    cin  >> itemPrice;

    if (userData[4] == "-") {
      cout << "Masukkan Lokasi Penyimpanan : ";
      cin  >> itemLocation;
    } else if (userData[4] == "A") {
      itemLocation = "A";
    } else if (userData[4] == "B") {
      itemLocation = "B";
    } else if (userData[4] == "C") {
      itemLocation = "C";
    }

    cout << "MASUKKAN TANGGAL BARANG MASUK (DD/MM/YYYY) : ";
    cin  >> dateIn;

    mainData.push_back({
      to_string(stoi(mainData.back()[0]) + 1),
      itemName,
      itemValue,
      itemPrice,
      itemLocation,
      dateIn,
      getDateNow(),
    });

    subData = getSubData(userData[4], mainData);
    cout << "BARANG BERHASIL DITAMBAHKAN";
    cout << "\n\nTEKAN ENTER UNTUK MELANJUTKAN.....";
    cin.ignore();
    cin.get();
    if (menu == 1) {
      goto listData;
    } else {
      goto mainMenu;
    }
  } else if (menu == 3) {
    deleteData:
    clear_screen();
    cin.ignore();

    cout << "========== HAPUS BARANG ==========\n";
    cout << "MASUKKAN NAMA BARANG : ";
    getline(cin, itemName);
    
    vector<string> searchResult = searchDataByName(subData, itemName);
    if (searchResult.size() > 0) {
      searchResult = searchDataByName(mainData, itemName);
      if (searchResult.size() > 0) {
        mainData.erase(mainData.begin() + stoi(searchResult[7]));
        subData = getSubData(userData[4], mainData);
        cout << itemName << " BERHASIL DIHAPUS!" << endl;
      } else {
        cout << "TERJADI KESALAHAN SAAT MENGHAPUS DATA!!" << endl;
      }
    } else {
      cout << itemName << " TIDAK DITEMUKAN!!" << endl;
    }

    cout << "\nTEKAN ENTER UNTUK MELANJUTKAN.....";
    cin.get();
    
    if (menu == 1) {
      goto listData;
    } else {
      goto mainMenu;
    }
  } else if (menu == 4) {
    searchData:
    clear_screen();
    cin.ignore();

    cout << "========== CARI BARANG ==========\n";
    cout << "MASUKKAN NAMA BARANG : ";
    getline(cin, itemName);

    vector<vector<string>> searchResult = searchDataByNameV2(subData, itemName);
    showData(searchResult);

    cout << "\n\nTEKAN ENTER UNTUK MELANJUTKAN.....";
    cin.get();
    goto mainMenu;
  } else if (menu == 5) {
    cin.ignore();
    editData:
    clear_screen();

    cout << "========== EDIT BARANG ==========\n";
    cout << "MASUKKAN NAMA BARANG : ";
    getline(cin, itemName);

    vector<string> searchResult = searchDataByName(subData, itemName);
    if (searchResult.size() > 0) {
      showData({searchResult});

      inputEdit:
      cout << "TEKAN ENTER JIKA DATA TIDAK DIUBAH" << endl;
      cout << "MASUKKAN NAMA BARU : ";
      getline(cin, itemName);

      int checkNameAvailability = searchDataByName(mainData, itemName).size();
      if (checkNameAvailability > 0) {
        cout << "NAMA TIDAK DAPAT DIGUNAKAN!!";
        cout << "\n\nTEKAN ENTER UNTUK MELANJUTKAN.....";
        cin.get();
        goto inputEdit;
      }

      cout << "MASUKKAN BANYAK BARANG : ";
      getline(cin, itemValue);
      cout << "MASUKKAN HARGA BARANG : ";
      getline(cin, itemPrice);

      if (userData[4] == "-") {
        cout << "MASUKKAN LOKASI BARU : ";
        getline(cin, itemLocation);
      } else {
        itemLocation == searchResult[4];
      }

      cout << "MASUKKAN TANGGAL MASUK BARANG: ";
      getline(cin, dateIn);

      //Set data lama jika input tidak diisi
      itemName  = itemName.empty() ? searchResult[1] : itemName;
      itemValue = itemValue.empty() ? searchResult[2] : itemValue;
      itemPrice = itemPrice.empty() ? searchResult[3] : itemPrice;
      itemLocation = itemLocation.empty() ? searchResult[4] : itemLocation;
      dateIn    = dateIn.empty() ? searchResult[5] : dateIn;

      searchResult = searchDataByName(mainData, searchResult[1]);

      mainData[stoi(searchResult[7])] = {
        searchResult[0],
        itemName,
        itemValue,
        itemPrice,
        itemLocation,
        dateIn,
        getDateNow(),
      };
      subData = getSubData(userData[4], mainData);

      cout << "DATA BERHASIL DIUPDATE";
      cout << "\n\nTEKAN ENTER UNTUK MELANJUTKAN.....";
      cin.get();
      goto mainMenu;
    } else {
      cout << "BARANG TIDAK DITEMUKAN!!" << endl;
      cout << "\n\nTEKAN ENTER UNTUK MELANJUTKAN.....";
      cin.get();
      goto editData;
    }
  } else if (menu == 6) {
    goto landing;
  } else {
    cout << "MENU YANG ANDA PILIH SALAH!!";
    cout << "\n\nTEKAN ENTER UNTUK MELANJUTKAN.....";
    cin.ignore();
    cin.get();
    goto mainMenu;
  }
}