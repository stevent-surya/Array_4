#include <iostream> // cin, cout
#include <string> // String type data
#include <array> // Container Array
#include <algorithm> // std::sort

using namespace std;

// Struct untuk menyimpan data barang
struct Barang {
	string kode; // Kode barang
	string nama; // Nama barang
	int stock;	 // Jumlah stock barang dalam pcs
};

// Fungsi untuk menampilkan daftar barang di Swalayan
void showBarang(const array<Barang, 6> &barang) {
	cout << "=======================================================" << endl;
	cout << "=================== Daftar Barang =====================" << endl;
	cout << "=======================================================" << endl << endl;
	cout << "Kode \t Nama Barang \t Stock (pcs)" << endl;

	// Loop untuk menampilkan semua barang
	for (const auto& item : barang) {
		cout << item.kode << "\t" << item.nama << "\t\t" << item.stock << endl;
	}
}

void sortBarang(array<Barang, 6>& barang) {
	// Proses sorting dengan algorithm
	sort(barang.begin(), barang.end(), [](const Barang& a, const Barang& b) {
		return a.stock < b.stock; // Mengurutkan berdasarkan stock
		});

	cout << "\nBarang berhasil diurutkan berdasarkan banyaknya stock!" << endl;
 }

void searchBarang(const array<Barang, 6>& barang, const string& namaBarang) {
	bool ditemukan = false; // Sebagai tanda barang ditemukan atau belum

	// Proses looping pencarian barang sampai ketemu barang yang dicari
	for (const auto& item : barang) {
		if (item.nama == namaBarang) {
			cout << "\nBarang ditemukan!" << endl;
			cout << "Kode	: " << item.kode << endl;
			cout << "Nama	: " << item.nama << endl;
			cout << "Stock  : " << item.stock << " pcs" << endl;
			ditemukan = true; // Flag ditemukan menjadi true supaya tidak looping mencari terus walaupun sudah ketemu barangnya
			break; // Untuk keluar dari loop setelah barang ditemukan
		}
	}

	// Handler barang jika tidak ditemukan
	if (!ditemukan) {
		cout << "\nBarang dengan nama '" << namaBarang << "' tidak ditemukan." << endl;
	}
}

// Fungsi awal untuk proses input barang
void awal() {
	// Deklarasi array barang dengan ukuran tetap yaitu 6
	array<Barang, 6> barang;

	// Inisialisasi nama barang
	string namaBarang[6] = {
		"sabun mandi", "shampoo", "sikat gigi", "minyak goreng", "kecap", "gula"
	};

	// Input data barang dari user
	cout << "====================================================" << endl;
	cout << "================= Input Data Barang ================" << endl;
	cout << "====================================================" << endl << endl;
	for (int i = 0; i < 6; i++) {
		// Buat kode barang otomatis dari B1 - seterusnya (B6)
		barang[i].kode = "B" + to_string(i + 1);

		// Menyimpan nama barang
		barang[i].nama = namaBarang[i];

		// Meminta user untuk memasukkan stock barang dalam pcs
		cout << "Masukkan stock untuk " << barang[i].nama << ": ";
		cin >> barang[i].stock;
	}

	// Menampilkan daftar barang setelah di input oleh user
	showBarang(barang);

	// Mengurutkan barang berdasarkan stock dari rendah ke tinggi
	sortBarang(barang);

	// Menampilkan daftar barang setelah diurutkan
	showBarang(barang);

	// User mencari barang berdasarkan nama
	string nameSearch;
	cout << "===================================================" << endl;
	cout << "================= Pencarian Barang ================" << endl;
	cout << "===================================================" << endl << endl;
	cin.ignore(); // Menahan program sebelum getline
	getline(cin, nameSearch); // Menerima input nama barang dengan spasi

	// Memanggil fungsi pencarian barang
	searchBarang(barang, nameSearch);
}

void ahkir() {
	cout << "\nTerimakasi atas support anda beri rating 5 di PlayStev!" << endl;
}

int main() {
	char yt;

	do {
		// Memanggil fungsi awal untuk proses penjalanan program
		system("CLS");
		awal();

		// Pertanyaan pengulangan program
		cout << "\nApakah Anda ingin memasukkan data baru? (y/t): ";
		cin >> yt;

		// Input check
		while (yt != 'Y' && yt != 'y' && yt != 'T' && yt != 't') {
			cout << "Input tidak valid. Masukkan 'y' untuk lanjut atau 't' untuk close: ";
			cin >> yt;
		}

	} while (yt == 'Y' || yt == 'y'); // Kembali lagi ke awal

	// Selesai ketika user memilih t
	ahkir();

	return 0; // Program selesai
}