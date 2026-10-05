// ============================================================================
// SISTEM LOGISTIK PENGIRIMAN MULTIMODA (TP3 DPBO)
// HEADER (#include):
// Alasan seluruh header library dan namespace hanya diletakkan di main.cpp:
// kata bu rosa, kang daffa, kang bintang
// ============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <utility>

using namespace std;

// ============================================================================
// INCLUDE FILE-FILE KELAS SESUAI URUTAN DEPENDENSI
// ============================================================================

#include "MesinKendaraan.cpp"
#include "KendaraanPengiriman.cpp"
#include "TrukKargo.cpp"
#include "KapalLaut.cpp"
#include "PesawatKargo.cpp"
#include "Paket.cpp"
#include "Pengemudi.cpp"
#include "DepoLogistik.cpp"

// ============================================================================
// DEKLARASI KODE WARNA ANSI TERMINAL (UNTUK MEMPERCANTIK OUTPUT)
// ============================================================================
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

// ============================================================================
// FUNGSI-FUNGSI PENAMPIL DATA (VERTIKAL / CARD STYLE)
// ============================================================================

// Fungsi 1: Menampilkan seluruh data kendaraan Truk Kargo secara vertikal
void cetakDaftarTruk(const vector<TrukKargo *> &listTruk) {
  cout << CYAN
       << "--- DAFTAR KENDARAAN TRUK KARGO (TRANSPORTASI DARAT) ---" << RESET
       << endl;
  if (listTruk.empty()) {
    cout << "  (Belum ada data kendaraan Truk Kargo terdaftar)" << endl;
  } else {
    int no = 1;
    for (const auto *t : listTruk) {
      cout << "  [Truk #" << no++ << "]" << endl;
      // Memanggil method polimorfik spesifikasi truk kargo
      t->tampilkanSpesifikasi();
      cout << "  -------------------------------------------------------"
           << endl;
    }
  }
  cout << endl;
}

// Fungsi 2: Menampilkan seluruh data kendaraan Kapal Laut secara vertikal
void cetakDaftarKapal(const vector<KapalLaut *> &listKapal) {
  cout << BOLD << BLUE
       << "--- DAFTAR KENDARAAN KAPAL LAUT (TRANSPORTASI LAUT) ---" << RESET
       << endl;
  if (listKapal.empty()) {
    cout << "  (Belum ada data kendaraan Kapal Laut terdaftar)" << endl;
  } else {
    int no = 1;
    for (const auto *k : listKapal) {
      cout << "  [Kapal #" << no++ << "]" << endl;
      // Memanggil method polimorfik spesifikasi kapal laut
      k->tampilkanSpesifikasi();
      cout << "  -------------------------------------------------------"
           << endl;
    }
  }
  cout << endl;
}

// Fungsi 3: Menampilkan seluruh data kendaraan Pesawat Kargo secara vertikal
void cetakDaftarPesawat(const vector<PesawatKargo *> &listPesawat) {
  cout << BOLD << MAGENTA
       << "--- DAFTAR KENDARAAN PESAWAT KARGO (TRANSPORTASI UDARA) ---" << RESET
       << endl;
  if (listPesawat.empty()) {
    cout << "  (Belum ada data kendaraan Pesawat Kargo terdaftar)" << endl;
  } else {
    int no = 1;
    for (const auto *p : listPesawat) {
      cout << "  [Pesawat #" << no++ << "]" << endl;
      // Memanggil method polimorfik spesifikasi pesawat kargo
      p->tampilkanSpesifikasi();
      cout << "  -------------------------------------------------------"
           << endl;
    }
  }
  cout << endl;
}

// Fungsi 4: Menampilkan seluruh daftar data Paket Logistik
void cetakDaftarPaket(const vector<Paket *> &listPaket) {
  cout << BOLD << YELLOW << "--- DAFTAR PAKET LOGISTIK ---" << RESET << endl;
  if (listPaket.empty()) {
    cout << "  (Belum ada data paket kiriman terdaftar)" << endl;
  } else {
    int no = 1;
    for (const auto *p : listPaket) {
      cout << "  [Paket #" << no++ << "]" << endl;
      cout << "    Nomor Resi       : " << p->getNomorResi() << endl;
      cout << "    Berat Fisik      : " << fixed << setprecision(2)
           << p->getBeratKg() << " kg" << endl;
      cout << "    Deskripsi Barang : " << p->getDeskripsiBarang() << endl;
      cout << "  -------------------------------------------------------"
           << endl;
    }
  }
  cout << endl;
}

// Fungsi 5: Menampilkan data fasilitas Depo Logistik (hanya informasi esensial
// agregasi)
void cetakDaftarDepo(const vector<DepoLogistik *> &daftarDepo) {
  cout << BOLD << RED << "--- DATA FASILITAS DEPO LOGISTIK ---" << RESET
       << endl;
  if (daftarDepo.empty()) {
    cout << "  (Belum ada fasilitas depo logistik yang terdaftar di sistem)"
         << endl;
  } else {
    int no = 1;
    for (const auto *depo : daftarDepo) {
      cout << "  [Depo #" << no++ << ": " << depo->getKodeDepo() << " - "
           << depo->getKotaLokasi() << "]" << endl;

      // Menampilkan daftar kendaraan Truk yang diagregasikan di depo ini (ID &
      // Merk saja)
      cout << "    Kendaraan Truk    : ";
      if (depo->getDaftarTruk().empty()) {
        cout << "(Kosong)" << endl;
      } else {
        cout << endl;
        for (const auto *t : depo->getDaftarTruk()) {
          cout << "      - " << t->getIdKendaraan() << " (" << t->getMerkModel()
               << ")" << endl;
        }
      }

      // Menampilkan daftar kendaraan Kapal yang diagregasikan di depo ini (ID &
      // Merk saja)
      cout << "    Kendaraan Kapal   : ";
      if (depo->getDaftarKapal().empty()) {
        cout << "(Kosong)" << endl;
      } else {
        cout << endl;
        for (const auto *k : depo->getDaftarKapal()) {
          cout << "      - " << k->getIdKendaraan() << " (" << k->getMerkModel()
               << ")" << endl;
        }
      }

      // Menampilkan daftar kendaraan Pesawat yang diagregasikan di depo ini (ID
      // & Merk saja)
      cout << "    Kendaraan Pesawat : ";
      if (depo->getDaftarPesawat().empty()) {
        cout << "(Kosong)" << endl;
      } else {
        cout << endl;
        for (const auto *p : depo->getDaftarPesawat()) {
          cout << "      - " << p->getIdKendaraan() << " (" << p->getMerkModel()
               << ")" << endl;
        }
      }

      // Menampilkan daftar Paket yang diagregasikan di depo ini (Resi & Berat
      // saja)
      cout << "    Paket Kiriman     : ";
      if (depo->getDaftarPaket().empty()) {
        cout << "(Kosong)" << endl;
      } else {
        cout << endl;
        for (const auto *p : depo->getDaftarPaket()) {
          cout << "      - " << p->getNomorResi() << " (" << fixed
               << setprecision(2) << p->getBeratKg() << " kg)" << endl;
        }
      }
      cout << "  -------------------------------------------------------"
           << endl;
    }
  }
  cout << endl;
}

// Fungsi 6: Menampilkan data Pengemudi dan penugasan kendaraan operasionalnya
// (Asosiasi)
void cetakDaftarPengemudi(
    const vector<pair<Pengemudi *, KendaraanPengiriman *>> &listPenugasan) {
  cout << BOLD << GREEN << "--- DAFTAR PENGEMUDI & PENUGASAN KENDARAAN ---"
       << RESET << endl;
  if (listPenugasan.empty()) {
    cout << "  (Belum ada data pengemudi dan penugasan kendaraan)" << endl;
  } else {
    for (const auto &item : listPenugasan) {
      // Relasi Asosiasi: Pengemudi menerima objek kendaraan lewat parameter
      // tampilkanTugas(kendaraan)
      item.first->tampilkanTugas(*(item.second));
    }
  }
  cout << endl;
}

// Fungsi 7: Menampilkan seluruh data sistem secara lengkap dan terstruktur
void cetakSeluruhData(
    const vector<TrukKargo *> &listTruk, const vector<KapalLaut *> &listKapal,
    const vector<PesawatKargo *> &listPesawat, const vector<Paket *> &listPaket,
    const vector<DepoLogistik *> &daftarDepo,
    const vector<pair<Pengemudi *, KendaraanPengiriman *>> &listPenugasan) {
  // 1. Tampilkan masing-masing jenis kendaraan kendaraan secara terpisah dan
  // lengkap
  cetakDaftarTruk(listTruk);
  cetakDaftarKapal(listKapal);
  cetakDaftarPesawat(listPesawat);

  // 2. Tampilkan daftar paket logistik
  cetakDaftarPaket(listPaket);

  // 3. Tampilkan data Depo Logistik (hanya informasi esensial agregasi
  // kendaraan/paket)
  cetakDaftarDepo(daftarDepo);

  // 4. Tampilkan data Pengemudi dan penugasan kendaraan
  cetakDaftarPengemudi(listPenugasan);
}

// ============================================================================
// FUNGSI UTAMA (MAIN PROGRAM)
// ============================================================================
int main() {
  // ------------------------------------------------------------------------
  // TAHAP 1: KONDISI AWAL KOSONG TOTAL
  // Menyiapkan wadah vector kosong untuk membuktikan sistem dapat menangani
  // kondisi awal sebelum penambahan data dilakukan.
  // ------------------------------------------------------------------------
  vector<TrukKargo *> listTruk;
  vector<KapalLaut *> listKapal;
  vector<PesawatKargo *> listPesawat;
  vector<Paket *> listPaket;
  vector<DepoLogistik *> daftarDepo;
  vector<pair<Pengemudi *, KendaraanPengiriman *>> daftarPenugasan;

  // ------------------------------------------------------------------------
  // TAHAP 2: MENAMPILKAN KONDISI SEBELUM DATA DITAMBAHKAN (KOSONG TOTAL)
  // ------------------------------------------------------------------------
  cout << endl;
  cout << "============================================================" << endl;
  cout << BOLD << GREEN << "=== >> KONDISI DATA SEBELUM DITAMBAHKAN << ===" << RESET << endl;
  cout << "============================================================" << endl
       << endl;

  cetakSeluruhData(listTruk, listKapal, listPesawat, listPaket, daftarDepo,
                   daftarPenugasan);

  // ------------------------------------------------------------------------
  // PROSES PERALIHAN / PEMISAH DENGAN JARAK YANG JELAS
  // Memberikan jarak visual atas dan bawah agar perbedaan kondisi sebelum
  // dan sesudah penambahan data terlihat jelas pada terminal.
  // ------------------------------------------------------------------------

  // ------------------------------------------------------------------------
  // TAHAP 3: PROSES PENAMBAHAN DATA
  // ------------------------------------------------------------------------

  // A. Fasilitas Depo Logistik (Hub Regional)
  DepoLogistik depoSurabaya("DPO-SUB-01", "Surabaya Hub Timur (Tanjung Perak)");
  DepoLogistik depoJakarta("DPO-JKT-02", "Jakarta Hub Barat (Tanjung Priok)");

  // B. Komponen Mesin Kendaraan (Komposisi: tertanam di dalam kendaraan)
  MesinKendaraan mesinTruk1("ENG-HN-7890", "J08E-WD Turbo", "Solar CN-51");
  MesinKendaraan mesinTruk2("ENG-IS-4521", "6HK1-TCS Heavy Duty",
                            "Solar CN-51");
  MesinKendaraan mesinTruk3("ENG-FS-6819", "6M60 Common Rail Turbo",
                            "Solar CN-51");

  MesinKendaraan mesinKapal1("ENG-MN-1123", "MAN B&W 6S50ME-C Marine",
                             "Heavy Fuel Oil");
  MesinKendaraan mesinKapal2("ENG-CAT-9901", "Caterpillar MaK 8M32C",
                             "Marine Gas Oil");
  MesinKendaraan mesinKapal3("ENG-WR-5510", "Wartsila 12V46F Marine",
                             "Heavy Fuel Oil");

  MesinKendaraan mesinPesawat1("ENG-CFM-567B", "CFM56-7B27 Dual Turbofan",
                               "Avtur Jet A-1");
  MesinKendaraan mesinPesawat2("ENG-RR-7000", "Rolls-Royce Trent 700",
                               "Avtur Jet A-1");
  MesinKendaraan mesinPesawat3("ENG-GE-90B", "GE90-110B1L Turbofan",
                               "Avtur Jet A-1");

  // C. Kendaraan Pengiriman (Hierarchical Inheritance & Komposisi)
  // Instansiasi objek Truk Kargo (Moda Darat)
  TrukKargo truk1("TRK-001", "Hino Ranger FM 260 JD", mesinTruk1, 10, 8500.0);
  TrukKargo truk2("TRK-002", "Isuzu Giga FVR 34 P", mesinTruk2, 6, 7000.0);
  TrukKargo truk3("TRK-003", "Fuso Fighter FN 62 F", mesinTruk3, 10, 9200.0);

  // Instansiasi objek Kapal Laut (Moda Laut)
  KapalLaut kapal1("KPL-101", "KM Meratus Benoa", mesinKapal1,
                   "Dry Container 20/40ft", 175000000.0);
  KapalLaut kapal2("KPL-102", "MV Samudera Pasifik", mesinKapal2,
                   "Reefer (Berpendingin)", 210000000.0);
  KapalLaut kapal3("KPL-103", "KM Nusantara Sejahtera", mesinKapal3,
                   "Bulk & Heavy Machinery", 260000000.0);

  // Instansiasi objek Pesawat Kargo (Moda Udara)
  PesawatKargo pesawat1("PSW-201", "Boeing 737-800BCF", mesinPesawat1, 41000,
                        35000000.0);
  PesawatKargo pesawat2("PSW-202", "Airbus A330-300P2F", mesinPesawat2, 42500,
                        82000000.0);
  PesawatKargo pesawat3("PSW-203", "Boeing 777-200F", mesinPesawat3, 43100,
                        145000000.0);

  // D. Paket Kiriman Logistik (Kelas Data)
  Paket paket1("PKG-ID-2026-001", 45.5,
               "Komponen Suku Cadang Elektronik Industri");
  Paket paket2("PKG-ID-2026-002", 1250.0, "Bahan Kimia Tekstil Non-Hazardous");
  Paket paket3("PKG-ID-2026-003", 8200.0,
               "Komoditas Ekspor Kopi & Teh Java Robusta");
  Paket paket4("PKG-ID-2026-004", 320.0,
               "Perangkat Medis & Diagnostic Hospital");
  Paket paket5("PKG-ID-2026-005", 15800.0,
               "Baja Fabrikasi Konstruksi Jembatan");

  // E. Personil Pengemudi / Operator Logistik (Kelas Operasional)
  Pengemudi pengemudi1("DRV-001", "Bambang Pratama",
                       "SIM B2 Umum (Reg: 3204-8971-001)");
  Pengemudi pengemudi2("CPT-002", "Capt. Hendra Gunawan",
                       "Master Mariner ANT-I (Reg: 5201-9982-042)");
  Pengemudi pengemudi3("PLT-003", "Cpt. Kevin Adiputra",
                       "ATPL Pilot License (Reg: 1102-4456-088)");
  Pengemudi pengemudi4("DRV-004", "Agus Budiman",
                       "SIM B2 Umum Multi-Axle (Reg: 3301-7712-005)");

  // Menambahkan objek ke dalam daftar master sistem
  listTruk = {&truk1, &truk2, &truk3};
  listKapal = {&kapal1, &kapal2, &kapal3};
  listPesawat = {&pesawat1, &pesawat2, &pesawat3};
  listPaket = {&paket1, &paket2, &paket3, &paket4, &paket5};

  // F. Penerapan Konsep AGREGASI: Objek kendaraan & paket dihubungkan ke Depo.
  // Kendaraan lintas rute (truk1, kapal1, pesawat1) diagregasikan pada kedua
  // Depo (Surabaya & Jakarta)!

  // Alokasi ke Depo 1 (Surabaya Hub)
  depoSurabaya.tambahTruk(&truk1);   // Truk rute bersama Surabaya - Jakarta
  depoSurabaya.tambahTruk(&truk2);   // Truk khusus Surabaya
  depoSurabaya.tambahKapal(&kapal1); // Kapal rute bersama Surabaya - Jakarta
  depoSurabaya.tambahKapal(&kapal2); // Kapal khusus Surabaya
  depoSurabaya.tambahPesawat(
      &pesawat1); // Pesawat rute bersama Surabaya - Jakarta
  depoSurabaya.tambahPesawat(&pesawat2); // Pesawat khusus Surabaya
  depoSurabaya.tambahPaket(&paket1);
  depoSurabaya.tambahPaket(&paket2);
  depoSurabaya.tambahPaket(&paket3);

  // Alokasi ke Depo 2 (Jakarta Hub)
  depoJakarta.tambahTruk(&truk1); // Truk rute bersama (terdaftar di kedua Depo)
  depoJakarta.tambahTruk(&truk3); // Truk khusus Jakarta
  depoJakarta.tambahKapal(
      &kapal1); // Kapal rute bersama (terdaftar di kedua Depo)
  depoJakarta.tambahKapal(&kapal3); // Kapal khusus Jakarta
  depoJakarta.tambahPesawat(
      &pesawat1); // Pesawat rute bersama (terdaftar di kedua Depo)
  depoJakarta.tambahPesawat(&pesawat3); // Pesawat khusus Jakarta
  depoJakarta.tambahPaket(&paket4);
  depoJakarta.tambahPaket(&paket5);

  // Mendaftarkan kedua Fasilitas Depo ke dalam Sistem (Agregasi)
  daftarDepo.push_back(&depoSurabaya);
  daftarDepo.push_back(&depoJakarta);

  // G. Menghubungkan Penugasan Pengemudi dengan Kendaraan (Asosiasi)
  daftarPenugasan.push_back({&pengemudi1, &truk1});
  daftarPenugasan.push_back({&pengemudi2, &kapal1});
  daftarPenugasan.push_back({&pengemudi3, &pesawat1});
  daftarPenugasan.push_back({&pengemudi4, &truk3});

  // ------------------------------------------------------------------------
  // TAHAP 4: MENAMPILKAN KONDISI SESUDAH DATA DITAMBAHKAN
  // ------------------------------------------------------------------------
  cout << endl;
  cout << "============================================================" << endl;
  cout << BOLD << GREEN << "=== >> KONDISI DATA SESUDAH DITAMBAHKAN << ===" << RESET << endl;
  cout << "============================================================" << endl
       << endl;

  cetakSeluruhData(listTruk, listKapal, listPesawat, listPaket, daftarDepo,
                   daftarPenugasan);

  return 0;
}
