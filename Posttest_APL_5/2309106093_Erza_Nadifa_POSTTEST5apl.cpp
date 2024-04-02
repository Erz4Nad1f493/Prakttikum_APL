#include <iostream>
#include <limits>

using namespace std;

const int MAX_CLUBS = 100;
const int MAX_PLAYERS_PER_CLUB = 100;

struct Player
{
    string playerName;
};

struct Club
{
    string clubName;
    Player players[MAX_PLAYERS_PER_CLUB];
    int playerCount;
};

struct Database
{
    Club clubs[MAX_CLUBS];
    int clubCount;
};

bool login()
{
    string nama, pass;
    int Login = 0;
    bool loginBerhasil = false;

    while (Login < 3)
    {
        cout << "-Silahkan masukkan username dan password-" << endl;
        cout << "Username: ";
        getline(cin, nama);
        cout << "Password: ";
        getline(cin, pass);

        if (nama == "ersa nadifa" && pass == "2309106093")
        {
            loginBerhasil = true;
            break;
        }
        else
        {
            cout << "Data yang di berikan salah, coba lagi" << endl;
            Login++;
        }
    }

    if (!loginBerhasil)
    {
        cout << "Anda memasukkan data yang salah 3 kali, program dihentikan" << endl;
        return false;
    }

    return true;
}

void addClub(Database *db)
{
    if (db->clubCount < MAX_CLUBS)
    {
        Club newClub;
        cout << "Masukkan nama club: ";
        getline(cin, newClub.clubName);
        newClub.playerCount = 0;
        db->clubs[db->clubCount] = newClub;
        db->clubCount++;
        cout << "Club '" << newClub.clubName << "' berhasil ditambahkan." << endl;
    }
    else
    {
        cout << "Jumlah klub sudah mencapai batas maksimum." << endl;
    }
}

void addPlayer(Database *db)
{
    string clubName;
    cout << "Masukkan nama club: ";
    getline(cin, clubName);

    int clubIndex = -1;
    for (int i = 0; i < db->clubCount; ++i)
    {
        if (db->clubs[i].clubName == clubName)
        {
            clubIndex = i;
            break;
        }
    }

    if (clubIndex != -1)
    {
        if (db->clubs[clubIndex].playerCount < MAX_PLAYERS_PER_CLUB)
        {
            Player newPlayer;
            cout << "Masukkan nama pemain: ";
            getline(cin, newPlayer.playerName);
            db->clubs[clubIndex].players[db->clubs[clubIndex].playerCount] = newPlayer;
            db->clubs[clubIndex].playerCount++;
            cout << "Pemain '" << newPlayer.playerName << "' berhasil ditambahkan ke dalam club '" << clubName << "'." << endl;
        }
        else
        {
            cout << "Jumlah pemain dalam klub '" << clubName << "' sudah mencapai batas maksimum." << endl;
        }
    }
    else
    {
        cout << "Club dengan nama '" << clubName << "' tidak ditemukan." << endl;
    }
}

void displayClubs(const Database *db)
{
    cout << "List Club dan Pemain:" << endl;
    for (int i = 0; i < db->clubCount; ++i)
    {
        cout << "Club: " << db->clubs[i].clubName << endl;

        if (db->clubs[i].playerCount > 0)
        {
            cout << "Pemain:" << endl;
            for (int j = 0; j < db->clubs[i].playerCount; ++j)
            {
                cout << "- " << db->clubs[i].players[j].playerName << endl;
            }
        }
        else
        {
            cout << "Tidak ada pemain." << endl;
        }

        cout << endl;
    }
}

void editClub(Database *db)
{
    string clubName;
    cout << "Masukkan nama club yang ingin diedit: ";
    getline(cin, clubName);

    int clubIndex = -1;
    for (int i = 0; i < db->clubCount; ++i)
    {
        if (db->clubs[i].clubName == clubName)
        {
            clubIndex = i;
            break;
        }
    }

    if (clubIndex != -1)
    {
        cout << "Masukkan nama baru untuk club '" << clubName << "': ";
        getline(cin, db->clubs[clubIndex].clubName);
        cout << "Nama club berhasil diubah menjadi '" << db->clubs[clubIndex].clubName << "'." << endl;
    }
    else
    {
        cout << "Club dengan nama '" << clubName << "' tidak ditemukan." << endl;
    }
}

void editPlayer(Database *db)
{
    string clubName, playerName;
    cout << "Masukkan nama club: ";
    getline(cin, clubName);

    int clubIndex = -1;
    for (int i = 0; i < db->clubCount; ++i)
    {
        if (db->clubs[i].clubName == clubName)
        {
            clubIndex = i;
            break;
        }
    }

    if (clubIndex != -1)
    {
        cout << "Masukkan nama pemain yang ingin diedit: ";
        getline(cin, playerName);

        int playerIndex = -1;
        for (int i = 0; i < db->clubs[clubIndex].playerCount; ++i)
        {
            if (db->clubs[clubIndex].players[i].playerName == playerName)
            {
                playerIndex = i;
                break;
            }
        }

        if (playerIndex != -1)
        {
            cout << "Masukkan nama baru untuk pemain '" << playerName << "': ";
            getline(cin, db->clubs[clubIndex].players[playerIndex].playerName);
            cout << "Nama pemain berhasil diubah menjadi '" << db->clubs[clubIndex].players[playerIndex].playerName << "'." << endl;
        }
        else
        {
            cout << "Pemain dengan nama '" << playerName << "' tidak ditemukan dalam club '" << clubName << "'." << endl;
        }
    }
    else
    {
        cout << "Club dengan nama '" << clubName << "' tidak ditemukan." << endl;
    }
}

void deleteClub(Database *db)
{
    string clubName;
    cout << "Masukkan nama club yang ingin dihapus: ";
    getline(cin, clubName);

    int clubIndex = -1;
    for (int i = 0; i < db->clubCount; ++i)
    {
        if (db->clubs[i].clubName == clubName)
        {
            clubIndex = i;
            break;
        }
    }

    if (clubIndex != -1)
    {
        for (int i = clubIndex; i < db->clubCount - 1; ++i)
        {
            db->clubs[i] = db->clubs[i + 1];
        }
        db->clubCount--;

        cout << "Club '" << clubName << "' berhasil dihapus." << endl;
    }
    else
    {
        cout << "Club dengan nama '" << clubName << "' tidak ditemukan." << endl;
    }
}

void deletePlayer(Database *db)
{
    string clubName, playerName;
    cout << "Masukkan nama club: ";
    getline(cin, clubName);

    int clubIndex = -1;
    for (int i = 0; i < db->clubCount; ++i)
    {
        if (db->clubs[i].clubName == clubName)
        {
            clubIndex = i;
            break;
        }
    }

    if (clubIndex != -1)
    {
        cout << "Masukkan nama pemain yang ingin dihapus: ";
        getline(cin, playerName);

        int playerIndex = -1;
        for (int i = 0; i < db->clubs[clubIndex].playerCount; ++i)
        {
            if (db->clubs[clubIndex].players[i].playerName == playerName)
            {
                playerIndex = i;
                break;
            }
        }

        if (playerIndex != -1)
        {
            for (int i = playerIndex; i < db->clubs[clubIndex].playerCount - 1; ++i)
            {
                db->clubs[clubIndex].players[i] = db->clubs[clubIndex].players[i + 1];
            }
            db->clubs[clubIndex].playerCount--;
            cout << "Pemain '" << playerName << "' berhasil dihapus dari club '" << clubName << "'." << endl;
        }
        else
        {
            cout << "Pemain dengan nama '" << playerName << "' tidak ditemukan dalam club '" << clubName << "'." << endl;
        }
    }
    else
    {
        cout << "Club dengan nama '" << clubName << "' tidak ditemukan." << endl;
    }
}

void menu(Database *db)
{
    cout << "Menu:" << endl;
    cout << "1. Tambah Club" << endl;
    cout << "2. Tambah Pemain ke Club" << endl;
    cout << "3. Tampilkan List Club dan Pemain" << endl;
    cout << "4. Edit Nama Club" << endl;
    cout << "5. Edit Nama Pemain" << endl;
    cout << "6. Hapus Club" << endl;
    cout << "7. Hapus Pemain dari Club" << endl;
    cout << "0. Keluar" << endl;

    int choice;
    cout << "Pilihan Anda: ";
    cin >> choice;

    cin.ignore(); // Membersihkan buffer input

    switch (choice)
    {
    case 1:
        addClub(db);
        cout << "Tekan Enter untuk melanjutkan";
        cin.get();
        break;
    case 2:
        addPlayer(db);
        cout << "Tekan Enter untuk melanjutkan";
        cin.get();
        break;
    case 3:
        displayClubs(db);
        cout << "Tekan Enter untuk melanjutkan";
        cin.get();
        break;
    case 4:
        editClub(db);
        cout << "Tekan Enter untuk melanjutkan";
        cin.get();
        break;
    case 5:
        editPlayer(db);
        cout << "Tekan Enter untuk melanjutkan";
        cin.get();
        break;
    case 6:
        deleteClub(db);
        cout << "Tekan Enter untuk melanjutkan";
        cin.get();
        break;
    case 7:
        deletePlayer(db);
        cout << "Tekan Enter untuk melanjutkan";
        cin.get();
        break;
    case 0:
        cout << "Program selesai." << endl;
        return;
    default:
        cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
    }

    system("cls"); // Membersihkan layar konsol
    menu(db);
}

int main()
{
    if (!login())
    {
        return 0;
    }

    Database *db = new Database;
    db->clubCount = 0;
    menu(db);
    delete db;
    return 0;
}