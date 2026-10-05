# Tugas Praktikum 3 - Desain Pemrograman Berorientasi Objek (TP3DPBO2526C2)

## Janji
Saya **R Mohammad Fikry Mushoffa S** dengan NIM **2502049** mengerjakan Tugas Praktikum 3 pada Mata Kuliah Desain dan Pemrograman Berorientasi Objek (DPBO) untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

---

## Deskripsi Program
Program ini merupakan implementasi nyata paradigma **Object-Oriented Programming (OOP)** bertema **Sistem Logistik Pengiriman Multimoda** (*Multimodal Logistics & Supply Chain Management System*) yang dibangun secara komprehensif dalam 3 bahasa pemrograman: **C++**, **Python**, dan **Java**.

Sistem ini merepresentasikan infrastruktur logistik modern yang mengelola pengiriman barang lintas moda transportasi (darat, laut, dan udara) melalui fasilitas depo hub logistik, integrasi komponen mesin pada setiap kendaraan, serta penugasan pengemudi profesional berlisensi resmi.

---

## Struktur Folder

```text
TP3DPBO2526C2/
├── README.md
│
├── CPP/
│   ├── Dokumentasi/
│   │   ├── cppOutput1.png
│   │   ├── cppOutput2.png
│   │   ├── cppOutput3.png
│   │   ├── cppOutput4.png
│   │   └── cppOutput5.png
│   └── Program/
│       ├── MesinKendaraan.cpp
│       ├── KendaraanPengiriman.cpp
│       ├── TrukKargo.cpp
│       ├── KapalLaut.cpp
│       ├── PesawatKargo.cpp
│       ├── Paket.cpp
│       ├── Pengemudi.cpp
│       ├── DepoLogistik.cpp
│       └── main.cpp
│
├── Java/
│   ├── Dokumentasi/
│   │   ├── javaOutput1.png
│   │   ├── javaOutput2.png
│   │   ├── javaOutput3.png
│   │   ├── javaOutput4.png
│   │   └── javaOutput5.png
│   └── Program/
│       ├── MesinKendaraan.java
│       ├── KendaraanPengiriman.java
│       ├── TrukKargo.java
│       ├── KapalLaut.java
│       ├── PesawatKargo.java
│       ├── Paket.java
│       ├── Pengemudi.java
│       ├── DepoLogistik.java
│       └── Main.java
│
└── Python/
    ├── Dokumentasi/
    │   ├── pythonOutput1.png
    │   ├── pythonOutput2.png
    │   ├── pythonOutput3.png
    │   ├── pythonOutput4.png
    │   └── pythonOutput5.png
    └── Program/
        ├── MesinKendaraan.py
        ├── KendaraanPengiriman.py
        ├── TrukKargo.py
        ├── KapalLaut.py
        ├── PesawatKargo.py
        ├── Paket.py
        ├── Pengemudi.py
        ├── DepoLogistik.py
        └── main.py
```

---

## Desain Diagram Program (Class Diagram)

### 1. Referensi Notasi Garis & Relasi UML
Berikut adalah pedoman standar notasi hubungan (*relationship arrows*) dan visibilitas pada diagram kelas UML:

<p align="center">
  <img src="https://github.com/user-attachments/assets/6d8d1897-05c5-4a1e-9deb-ee48abddb549" width="600" alt="Referensi Notasi Relasi UML">
</p>

| Notasi Simbol | Nama Relasi | Simbol Mermaid | Keterangan Hubungan |
|:---:|:---|:---:|:---|
|  `+` | **Public** | `+` | Atribut atau method dapat diakses oleh siapa saja dari luar kelas. |
|  `-` | **Private** | `-` | Atribut atau method hanya dapat diakses dari dalam kelas itu sendiri. |
|  `#` | **Protected** | `#` | Atribut atau method dapat diakses oleh kelas itu sendiri dan kelas-kelas turunannya. |
| **`───◁`** | **Inheritance** | `<|--` | Hubungan pewarisan umum (*is-a*), kelas anak mewarisi atribut & method kelas induk. |
| **`───◆`** | **Composition** | `*--` | Hubungan kepemilikan terikat erat (*part-of*), masa hidup bagian bergantung pada pemilik. |
| **`───◇`** | **Aggregation** | `o--` | Hubungan kepemilikan lepas (*has-a*), bagian dapat eksis independen dari wadahnya. |
| **`───▷`** | **Association** | `-->` / `..>` | Hubungan ketergantungan/penggunaan (*uses-a*), objek berinteraksi lewat parameter method. |

---

### 2. Diagram Kelas Mermaid

```mermaid
classDiagram
    direction TB

    class MesinKendaraan {
        - string nomorSeriMesin
        - string tipeMesin
        - string jenisBahanBakar
        + MesinKendaraan()
        + MesinKendaraan(nomorSeriMesin: string, tipeMesin: string, jenisBahanBakar: string)
        + getNomorSeriMesin() string
        + getTipeMesin() string
        + getJenisBahanBakar() string
        + setNomorSeriMesin(nomorSeriMesin: string) void
        + setTipeMesin(tipeMesin: string) void
        + setJenisBahanBakar(jenisBahanBakar: string) void
        + ~MesinKendaraan()
    }

    class KendaraanPengiriman {
        # string idKendaraan
        # string merkModel
        # MesinKendaraan mesin
        + KendaraanPengiriman()
        + KendaraanPengiriman(idKendaraan: string, merkModel: string, mesin: MesinKendaraan)
        + getIdKendaraan() string
        + getMerkModel() string
        + getMesin() MesinKendaraan
        + setIdKendaraan(idKendaraan: string) void
        + setMerkModel(merkModel: string) void
        + setMesin(mesin: MesinKendaraan) void
        + tampilkanSpesifikasi() void
        + ~KendaraanPengiriman()
    }

    class TrukKargo {
        - int jumlahRoda
        - double tarifPerKmDarat
        + TrukKargo()
        + TrukKargo(idKendaraan: string, merkModel: string, mesin: MesinKendaraan, jumlahRoda: int, tarifPerKmDarat: double)
        + getJumlahRoda() int
        + getTarifPerKmDarat() double
        + setJumlahRoda(jumlahRoda: int) void
        + setTarifPerKmDarat(tarifPerKmDarat: double) void
        + tampilkanSpesifikasi() void
        + ~TrukKargo()
    }

    class KapalLaut {
        - string tipeKontainer
        - double biayaSewaSektor
        + KapalLaut()
        + KapalLaut(idKendaraan: string, merkModel: string, mesin: MesinKendaraan, tipeKontainer: string, biayaSewaSektor: double)
        + getTipeKontainer() string
        + getBiayaSewaSektor() double
        + setTipeKontainer(tipeKontainer: string) void
        + setBiayaSewaSektor(biayaSewaSektor: double) void
        + tampilkanSpesifikasi() void
        + ~KapalLaut()
    }

    class PesawatKargo {
        - int ketinggianMaksimal
        - double surchargeAvtur
        + PesawatKargo()
        + PesawatKargo(idKendaraan: string, merkModel: string, mesin: MesinKendaraan, ketinggianMaksimal: int, surchargeAvtur: double)
        + getKetinggianMaksimal() int
        + getSurchargeAvtur() double
        + setKetinggianMaksimal(ketinggianMaksimal: int) void
        + setSurchargeAvtur(surchargeAvtur: double) void
        + tampilkanSpesifikasi() void
        + ~PesawatKargo()
    }

    class Paket {
        - string nomorResi
        - double beratKg
        - string deskripsiBarang
        + Paket()
        + Paket(nomorResi: string, beratKg: double, deskripsiBarang: string)
        + getNomorResi() string
        + getBeratKg() double
        + getDeskripsiBarang() string
        + setNomorResi(nomorResi: string) void
        + setBeratKg(beratKg: double) void
        + setDeskripsiBarang(deskripsiBarang: string) void
        + ~Paket()
    }

    class Pengemudi {
        - string idPengemudi
        - string nama
        - string nomorLisensi
        + Pengemudi()
        + Pengemudi(idPengemudi: string, nama: string, nomorLisensi: string)
        + getIdPengemudi() string
        + getNama() string
        + getNomorLisensi() string
        + setIdPengemudi(idPengemudi: string) void
        + setNama(nama: string) void
        + setNomorLisensi(nomorLisensi: string) void
        + tampilkanTugas(kendaraan: KendaraanPengiriman) void
        + ~Pengemudi()
    }

    class DepoLogistik {
        - string kodeDepo
        - string kotaLokasi
        - vector~TrukKargo*~ daftarTruk
        - vector~KapalLaut*~ daftarKapal
        - vector~PesawatKargo*~ daftarPesawat
        - vector~Paket*~ daftarPaket
        + DepoLogistik()
        + DepoLogistik(kodeDepo: string, kotaLokasi: string)
        + getKodeDepo() string
        + getKotaLokasi() string
        + getDaftarTruk() vector~TrukKargo*~
        + getDaftarKapal() vector~KapalLaut*~
        + getDaftarPesawat() vector~PesawatKargo*~
        + getDaftarPaket() vector~Paket*~
        + setKodeDepo(kodeDepo: string) void
        + setKotaLokasi(kotaLokasi: string) void
        + setDaftarTruk(daftarTruk: vector~TrukKargo*~) void
        + setDaftarKapal(daftarKapal: vector~KapalLaut*~) void
        + setDaftarPesawat(daftarPesawat: vector~PesawatKargo*~) void
        + setDaftarPaket(daftarPaket: vector~Paket*~) void
        + tambahTruk(truk: TrukKargo*) void
        + tambahKapal(kapal: KapalLaut*) void
        + tambahPesawat(pesawat: PesawatKargo*) void
        + tambahPaket(paket: Paket*) void
        + tampilkanInformasiDepo() void
        + ~DepoLogistik()
    }

    %% Hubungan Komposisi (Composition)
    KendaraanPengiriman *-- MesinKendaraan : Memiliki Komponen (Komposisi)

    %% Hubungan Hierarchical Inheritance
    KendaraanPengiriman <|-- TrukKargo : Mewarisi (Moda Darat)
    KendaraanPengiriman <|-- KapalLaut : Mewarisi (Moda Laut)
    KendaraanPengiriman <|-- PesawatKargo : Mewarisi (Moda Udara)

    %% Hubungan Agregasi (Aggregation)
    DepoLogistik o-- TrukKargo : Mengagregasikan
    DepoLogistik o-- KapalLaut : Mengagregasikan
    DepoLogistik o-- PesawatKargo : Mengagregasikan
    DepoLogistik o-- Paket : Mengagregasikan

    %% Hubungan Asosiasi (Association)
    Pengemudi ..> KendaraanPengiriman : Mengendarai (Asosiasi)
```

---

### 3. Penjelasan Lengkap Garis dan Panah Diagram

1. **Komposisi (`KendaraanPengiriman *-- MesinKendaraan`)**:
   - **Simbol**: Garis berujung belah ketupat hitam pejal (*filled diamond*) menempel pada `KendaraanPengiriman`.
   - **Makna**: Hubungan kepemilikan erat (*strong ownership / part-of*). Setiap kendaraan wajib memiliki objek mesin (`MesinKendaraan`) sebagai komponen intinya. Siklus hidup mesin terikat mati pada kendaraan; jika kendaraan dihapus dari memori, objek mesin di dalamnya juga otomatis hancur.
2. **Hierarchical Inheritance (`KendaraanPengiriman <|-- TrukKargo, KapalLaut, PesawatKargo`)**:
   - **Simbol**: Garis berujung panah segitiga kosong (*closed hollow arrow*) menunjuk dari kelas anak menuju ke kelas induk `KendaraanPengiriman`.
   - **Makna**: Hubungan pewarisan hirarki satu induk banyak anak (*is-a*). `KendaraanPengiriman` bertindak sebagai *superclass* yang mewariskan atribut umum (`idKendaraan`, `merkModel`, `mesin`) serta method `tampilkanSpesifikasi()` kepada ketiga *subclass*-nya (`TrukKargo`, `KapalLaut`, dan `PesawatKargo`). Masing-masing kelas turunan menambahkan atribut dan fungsionalitas unik sesuai moda transportasinya.
3. **Agregasi (`DepoLogistik o-- TrukKargo, KapalLaut, PesawatKargo, Paket`)**:
   - **Simbol**: Garis berujung belah ketupat putih kosong (*hollow diamond*) menempel pada kelas pemilik/kontainer `DepoLogistik`.
   - **Makna**: Hubungan kepemilikan lepas (*has-a / collection*). Fasilitas `DepoLogistik` mengelola dan menampung daftar kendaraan serta paket. Namun, jika fasilitas depo ditutup/dihancurkan, armada truk, kapal, pesawat, maupun paket tidak ikut hancur. Objek-objek tersebut tetap eksis secara independen dan dapat dipindahkan/dialokasikan ke depo lain.
4. **Asosiasi (`Pengemudi ..> KendaraanPengiriman`)**:
   - **Simbol**: Garis panah putus-putus/terbuka (*open arrow / dependency*) dari `Pengemudi` menunjuk ke `KendaraanPengiriman`.
   - **Makna**: Hubungan ketergantungan operasional lepas (*uses-a*). Personil `Pengemudi` tidak menyimpan kendaraan sebagai atribut kepemilikan permanen di dalam kelasnya. Pengemudi hanya berinteraksi dengan `KendaraanPengiriman` secara temporer melalui parameter pada method `tampilkanTugas(const KendaraanPengiriman& kendaraan)` saat menjalankan penugasan pengiriman barang.

---

## Penjelasan Desain Program & Konsep OOP

Program ini dirancang secara khusus untuk memenuhi seluruh kriteria konsep utama Pemrograman Berorientasi Objek (*Object-Oriented Programming*):

### 1. Hierarchical Inheritance (Pewarisan Hirarkis)
- **Definisi**: Bentuk pewarisan di mana satu kelas induk (*base/parent class*) diwariskan secara langsung ke lebih dari satu kelas anak (*derived/child classes*).
- **Penerapan pada Program**:
  - Kelas `KendaraanPengiriman` menjadi kelas induk bersama bagi tiga moda transportasi:
    1. `TrukKargo` (Moda Transportasi Darat)
    2. `KapalLaut` (Moda Transportasi Laut)
    3. `PesawatKargo` (Moda Transportasi Udara)
- **Alasan Desain**:
  Seluruh armada logistik di dunia nyata memiliki kesamaan identitas dasar berupa kode identifikasi registrasi, merk/model pabrikan, dan komponen mesin penggerak. Dengan *Hierarchical Inheritance*, seluruh atribut umum ini didefinisikan satu kali di `KendaraanPengiriman` (menggunakan hak akses `protected`), sehingga menghilangkan redundansi kode (*clean code & DRY principle*) sekaligus memberikan kebebasan bagi kelas turunan untuk mendefinisikan atribut spesifiknya masing-masing.

### 2. Komposisi (Composition)
- **Definisi**: Hubungan antar-objek yang bersifat ketergantungan penuh (*strong association / "part-of"*), di mana masa hidup (*lifecycle*) objek bagian bergantung seutuhnya pada objek induk.
- **Penerapan pada Program**:
  - Kelas `KendaraanPengiriman` memiliki atribut `mesin` bertipe objek `MesinKendaraan`.
  - Objek `MesinKendaraan` tertanam secara utuh (*embedded by value*) di dalam `KendaraanPengiriman`.
- **Alasan Desain**:
  Sebuah armada logistik (baik truk, kapal, maupun pesawat) tidak dapat beroperasi secara fisik tanpa adanya unit mesin penggerak di dalamnya. Jika suatu kendaraan dimusnahkan/keluar dari memori, maka mesin yang terpasang di dalamnya ikut musnah dari konteks operasional.

### 3. Agregasi (Aggregation)
- **Definisi**: Hubungan kepemilikan longgar (*weak association / "has-a"*), di mana objek yang ditampung (*part*) memiliki siklus hidup independen dan tidak terikat mati dengan objek penampungnya (*whole*).
- **Penerapan pada Program**:
  - Kelas `DepoLogistik` menyimpan kumpulan referensi/pointer ke objek `TrukKargo`, `KapalLaut`, `PesawatKargo`, dan `Paket`.
  - Satu unit armada kendaraan lintas rute (seperti `truk1`, `kapal1`, dan `pesawat1`) bahkan dapat diagregasikan sekaligus di dua fasilitas depo yang berbeda (Depo Surabaya dan Depo Jakarta sebagai rute bersama).
- **Alasan Desain**:
  Fasilitas depo logistik hanyalah titik kumpul transit dan pangkalan operasional. Apabila suatu depo mengalami renovasi atau ditutup, armada truk, kapal, pesawat, dan paket-paket kiriman yang berada di depo tersebut tidak ikut musnah, melainkan dipindahkan ke depo logistik lainnya.

### 4. Asosiasi (Association)
- **Definisi**: Hubungan struktural fungsional antara dua kelas yang berdiri sendiri (*"uses-a"*), di mana satu objek memanfaatkan fungsionalitas objek lain tanpa adanya relasi kepemilikan (*non-ownership*).
- **Penerapan pada Program**:
  - Hubungan antara kelas `Pengemudi` dengan `KendaraanPengiriman`.
  - Objek `Pengemudi` tidak menyimpan instans `KendaraanPengiriman` di dalam atribut kelasnya. Hubungan terjadi melalui pemanggilan method:
    - **C++**: `void tampilkanTugas(const KendaraanPengiriman& kendaraan)`
    - **Python**: `def tampilkanTugas(self, kendaraan: KendaraanPengiriman)`
    - **Java**: `public void tampilkanTugas(KendaraanPengiriman kendaraan)`
- **Alasan Desain**:
  Seorang supir, kapten kapal, atau pilot adalah tenaga kerja lepas yang ditugaskan mengoperasikan kendaraan tertentu sesuai jadwal giliran kerja (*shift*). Lisensi pengemudi melekat pada personilnya, sedangkan kendaraan dimiliki oleh perusahaan logistik.

### 5. Polimorfisme (Polymorphism)
- **Definisi**: Kemampuan suatu method untuk memiliki banyak bentuk implementasi perilaku yang berbeda sesuai konteks kelas pemanggilnya.
- **Penerapan pada Program**:
  - **Method Overriding (Dynamic Polymorphism)**:
    - Method `tampilkanSpesifikasi()` didefinisikan pada superclass `KendaraanPengiriman`.
    - Method ini kemudian di-*override* secara unik pada:
      - `TrukKargo`: menampilkan jumlah roda konfigurasi sasis dan tarif operasional jalan darat per kilometer.
      - `KapalLaut`: menampilkan klasifikasi tipe kontainer kargo dan biaya sewa slot rute pelayaran per sektor.
      - `PesawatKargo`: menampilkan batas ketinggian jelajah terbang maksimum dan biaya surcharge bahan bakar avtur per penerbangan.
  - **Method Overloading**:
    - Pada kelas `Pengemudi`, method `tampilkanTugas` menerima referensi objek maupun pointer objek kendaraan.

### 6. Array of Objects
- **Definisi**: Pengorganisasian sejumlah objek sejenis ke dalam struktur data koleksi berindeks dinamis.
- **Penerapan pada Program**:
  - **C++**: Menggunakan template container `std::vector<T*>` (`vector<TrukKargo*>`, `vector<KapalLaut*>`, `vector<PesawatKargo*>`, `vector<Paket*>`, `vector<DepoLogistik*>`).
  - **Python**: Menggunakan koleksi dinamis `list` bawaan Python (`self.__daftarTruk = []`, dll).
  - **Java**: Menggunakan framework koleksi `java.util.ArrayList<T>` (`ArrayList<TrukKargo>`, dll).

---

## Penjelasan Atribut dan Methods Setiap Kelas

Berikut adalah rincian lengkap atribut dan method untuk ke-8 kelas yang diimplementasikan pada program:

### 1. Kelas `MesinKendaraan` (Kelas Komponen Komposisi)
Merepresentasikan spesifikasi unit mesin yang tertanam di dalam kendaraan pengiriman.

| No | Nama Atribut | Tipe Data | Hak Akses | Keterangan |
|:---:|:---|:---:|:---:|:---|
| 1 | `nomorSeriMesin` | String | `private` | Kode nomor seri identifikasi pabrik mesin (cth: "ENG-HN-7890") |
| 2 | `tipeMesin` | String | `private` | Konfigurasi/tipe mesin (cth: "J08E-WD Turbo", "CFM56-7B Turbofan") |
| 3 | `jenisBahanBakar` | String | `private` | Jenis bahan bakar yang dikonsumsi (cth: "Solar CN-51", "Avtur Jet A-1") |

**Methods:**
- `MesinKendaraan()`: Konstruktor default untuk inisialisasi string kosong.
- `MesinKendaraan(nomorSeriMesin, tipeMesin, jenisBahanBakar)`: Konstruktor berparameter lengkap.
- `getNomorSeriMesin(): String` & `setNomorSeriMesin(nomorSeriMesin: String): void`: Mengakses & memodifikasi nomor seri mesin.
- `getTipeMesin(): String` & `setTipeMesin(tipeMesin: String): void`: Mengakses & memodifikasi model konfigurasi mesin.
- `getJenisBahanBakar(): String` & `setJenisBahanBakar(jenisBahanBakar: String): void`: Mengakses & memodifikasi jenis bahan bakar.

---

### 2. Kelas `KendaraanPengiriman` (Kelas Induk / Base Class)
Mendefinisikan entitas dasar seluruh kendaraan logistik dengan akses `protected` untuk mendukung pewarisan hirarki.

| No | Nama Atribut | Tipe Data | Hak Akses | Keterangan |
|:---:|:---|:---:|:---:|:---|
| 1 | `idKendaraan` | String | `protected` | Kode unik registrasi kendaraan (cth: "TRK-001", "KPL-101", "PSW-201") |
| 2 | `merkModel` | String | `protected` | Merk dan varian pabrikan kendaraan (cth: "Hino Ranger", "Boeing 737") |
| 3 | `mesin` | MesinKendaraan | `protected` | Objek mesin kendaraan yang tertanam langsung (*Komposisi*) |

**Methods:**
- `KendaraanPengiriman()`: Konstruktor default menginisialisasi atribut kosong dan mesin default.
- `KendaraanPengiriman(idKendaraan, merkModel, mesin)`: Konstruktor berparameter lengkap.
- `getIdKendaraan(): String` & `setIdKendaraan(idKendaraan: String): void`: Mengakses & mengubah ID kendaraan.
- `getMerkModel(): String` & `setMerkModel(merkModel: String): void`: Mengakses & mengubah merk model kendaraan.
- `getMesin(): MesinKendaraan` & `setMesin(mesin: MesinKendaraan): void`: Mengakses & mengubah objek mesin.
- `tampilkanSpesifikasi(): void`: Method polimorfik dasar untuk menampilkan informasi umum spesifikasi kendaraan.

---

### 3. Kelas `TrukKargo` (Kelas Anak 1 - Moda Darat)
Mewarisi `KendaraanPengiriman` dan menambahkan atribut khusus pengiriman jalur darat.

| No | Nama Atribut | Tipe Data | Hak Akses | Keterangan |
|:---:|:---|:---:|:---:|:---|
| 1 | `jumlahRoda` | int | `private` | Jumlah konfigurasi roda sasis truk (cth: 6, 10 roda) |
| 2 | `tarifPerKmDarat` | double | `private` | Tarif dasar operasional darat per kilometer dalam Rupiah (cth: Rp 8.500) |

**Methods:**
- `TrukKargo()`: Konstruktor default memanggil superclass.
- `TrukKargo(idKendaraan, merkModel, mesin, jumlahRoda, tarifPerKmDarat)`: Konstruktor berparameter lengkap menginisialisasi atribut induk dan anak.
- `getJumlahRoda(): int` & `setJumlahRoda(jumlahRoda: int): void`: Mengakses & memodifikasi jumlah roda.
- `getTarifPerKmDarat(): double` & `setTarifPerKmDarat(tarifPerKmDarat: double): void`: Mengakses & memodifikasi tarif per km darat.
- `tampilkanSpesifikasi(): void`: *(Override)* Menampilkan data lengkap identitas truk, roda, tarif per km, dan rincian mesin.

---

### 4. Kelas `KapalLaut` (Kelas Anak 2 - Moda Laut)
Mewarisi `KendaraanPengiriman` dan menambahkan atribut khusus pengiriman rute laut antar-pulau.

| No | Nama Atribut | Tipe Data | Hak Akses | Keterangan |
|:---:|:---|:---:|:---:|:---|
| 1 | `tipeKontainer` | String | `private` | Kategori peti kemas yang didukung (cth: "Dry Container 20/40ft", "Reefer") |
| 2 | `biayaSewaSektor` | double | `private` | Biaya sewa slot muatan pelayaran per sektor dalam Rupiah (cth: Rp 175.000.000) |

**Methods:**
- `KapalLaut()`: Konstruktor default memanggil superclass.
- `KapalLaut(idKendaraan, merkModel, mesin, tipeKontainer, biayaSewaSektor)`: Konstruktor berparameter lengkap.
- `getTipeKontainer(): String` & `setTipeKontainer(tipeKontainer: String): void`: Mengakses & memodifikasi tipe kontainer kapal.
- `getBiayaSewaSektor(): double` & `setBiayaSewaSektor(biayaSewaSektor: double): void`: Mengakses & memodifikasi biaya sewa sektor.
- `tampilkanSpesifikasi(): void`: *(Override)* Menampilkan data spesifikasi kapal laut, tipe kontainer, tarif sektor, dan mesin.

---

### 5. Kelas `PesawatKargo` (Kelas Anak 3 - Moda Udara)
Mewarisi `KendaraanPengiriman` dan menambahkan atribut khusus penerbangan kargo cepat jalur udara.

| No | Nama Atribut | Tipe Data | Hak Akses | Keterangan |
|:---:|:---|:---:|:---:|:---|
| 1 | `ketinggianMaksimal` | int | `private` | Batas ketinggian jelajah terbang maksimal dalam kaki / *feet* (cth: 41000 kaki) |
| 2 | `surchargeAvtur` | double | `private` | Biaya penyesuaian bahan bakar avtur per jadwal penerbangan dalam Rupiah |

**Methods:**
- `PesawatKargo()`: Konstruktor default memanggil superclass.
- `PesawatKargo(idKendaraan, merkModel, mesin, ketinggianMaksimal, surchargeAvtur)`: Konstruktor berparameter lengkap.
- `getKetinggianMaksimal(): int` & `setKetinggianMaksimal(ketinggianMaksimal: int): void`: Mengakses & memodifikasi batas ketinggian terbang.
- `getSurchargeAvtur(): double` & `setSurchargeAvtur(surchargeAvtur: double): void`: Mengakses & memodifikasi biaya surcharge avtur.
- `tampilkanSpesifikasi(): void`: *(Override)* Menampilkan spesifikasi pesawat udara, ketinggian jelajah, surcharge, dan mesin.

---

### 6. Kelas `Paket` (Kelas Data Kiriman)
Merepresentasikan entitas kargo muatan barang yang dititipkan untuk didistribusikan.

| No | Nama Atribut | Tipe Data | Hak Akses | Keterangan |
|:---:|:---|:---:|:---:|:---|
| 1 | `nomorResi` | String | `private` | Kode nomor unik pelacakan resi kiriman (cth: "PKG-ID-2026-001") |
| 2 | `beratKg` | double | `private` | Berat massa fisik barang kiriman dalam satuan kilogram (cth: 45.5 kg) |
| 3 | `deskripsiBarang` | String | `private` | Rincian manifes jenis komoditas kargo (cth: "Suku Cadang Elektronik") |

**Methods:**
- `Paket()`: Konstruktor default nilai awal kosong.
- `Paket(nomorResi, beratKg, deskripsiBarang)`: Konstruktor berparameter lengkap.
- `getNomorResi(): String` & `setNomorResi(nomorResi: String): void`: Mengakses & mengubah nomor resi kiriman.
- `getBeratKg(): double` & `setBeratKg(beratKg: double): void`: Mengakses & mengubah berat paket.
- `getDeskripsiBarang(): String` & `setDeskripsiBarang(deskripsiBarang: String): void`: Mengakses & mengubah deskripsi manifes.

---

### 7. Kelas `Pengemudi` (Kelas Personil Operasional)
Merepresentasikan operator atau pengemudi kendaraan yang menerapkan relasi Asosiasi (*uses-a*).

| No | Nama Atribut | Tipe Data | Hak Akses | Keterangan |
|:---:|:---|:---:|:---:|:---|
| 1 | `idPengemudi` | String | `private` | Nomor identitas registrasi pengemudi (cth: "DRV-001", "CPT-002") |
| 2 | `nama` | String | `private` | Nama lengkap pengemudi/kapten/pilot (cth: "Bambang Pratama") |
| 3 | `nomorLisensi` | String | `private` | Sertifikasi lisensi kemudi resmi (cth: "SIM B2 Umum", "Master Mariner ANT-I") |

**Methods:**
- `Pengemudi()`: Konstruktor default.
- `Pengemudi(idPengemudi, nama, nomorLisensi)`: Konstruktor berparameter lengkap.
- `getIdPengemudi(): String` & `setIdPengemudi(idPengemudi: String): void`: Mengakses & mengubah ID pengemudi.
- `getNama(): String` & `setNama(nama: String): void`: Mengakses & mengubah nama personil pengemudi.
- `getNomorLisensi(): String` & `setNomorLisensi(nomorLisensi: String): void`: Mengakses & mengubah nomor lisensi kemudi.
- `tampilkanTugas(kendaraan: KendaraanPengiriman): void`: **Metode Asosiasi**. Menerima objek kendaraan secara temporer lewat parameter untuk menampilkan pengemudi yang sedang mengoperasikan kendaraan tersebut tanpa memilikinya secara permanen.

---

### 8. Kelas `DepoLogistik` (Kelas Fasilitas Hub Pengelola)
Mengelola penampungan armada kendaraan dan paket logistik menggunakan konsep Agregasi dan *Array of Objects*.

| No | Nama Atribut | Tipe Data | Hak Akses | Keterangan |
|:---:|:---|:---:|:---:|:---|
| 1 | `kodeDepo` | String | `private` | Kode identifikasi fasilitas hub depo (cth: "DPO-SUB-01") |
| 2 | `kotaLokasi` | String | `private` | Nama kota letak fasilitas depo berada (cth: "Surabaya Hub Timur") |
| 3 | `daftarTruk` | Collection of `TrukKargo*` | `private` | Kumpulan referensi kendaraan truk yang diagregasikan ke depo |
| 4 | `daftarKapal` | Collection of `KapalLaut*` | `private` | Kumpulan referensi kendaraan kapal yang diagregasikan ke depo |
| 5 | `daftarPesawat` | Collection of `PesawatKargo*` | `private` | Kumpulan referensi kendaraan pesawat yang diagregasikan ke depo |
| 6 | `daftarPaket` | Collection of `Paket*` | `private` | Kumpulan referensi kargo paket yang disimpan di depo |

**Methods:**
- `DepoLogistik()`: Konstruktor default.
- `DepoLogistik(kodeDepo, kotaLokasi)`: Konstruktor berparameter kode depo dan kota lokasi.
- `getKodeDepo(): String` & `setKodeDepo(kodeDepo: String): void`: Getter & Setter kode depo.
- `getKotaLokasi(): String` & `setKotaLokasi(kotaLokasi: String): void`: Getter & Setter kota lokasi.
- `tambahTruk(truk)` / `getDaftarTruk()` / `setDaftarTruk(...)`: Menambah & mengelola daftar truk kargo di depo (*Agregasi*).
- `tambahKapal(kapal)` / `getDaftarKapal()` / `setDaftarKapal(...)`: Menambah & mengelola daftar kapal laut di depo (*Agregasi*).
- `tambahPesawat(pesawat)` / `getDaftarPesawat()` / `setDaftarPesawat(...)`: Menambah & mengelola daftar pesawat kargo di depo (*Agregasi*).
- `tambahPaket(paket)` / `getDaftarPaket()` / `setDaftarPaket(...)`: Menambah & mengelola daftar paket di depo (*Agregasi*).
- `tampilkanInformasiDepo(): void`: Menampilkan rekapitulasi status depo (kode, kota, jumlah armada, dan total paket).

---

## Penjelasan Alur Program (Program Flow)

Program memiliki alur eksekusi yang seragam, konsisten, dan terstruktur pada ketiga bahasa pemrograman (C++, Python, dan Java):

```text
┌────────────────────────────────────────────────────────────────────────┐
│                             START PROGRAM                              │
└───────────────────────────────────┬────────────────────────────────────┘
                                    │
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│                   TAHAP 1: INISIALISASI WADAH KOSONG                   │
│   Menyiapkan koleksi data (vector/list/ArrayList) dalam keadaan kosong │
└───────────────────────────────────┬────────────────────────────────────┘
                                    │
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│             TAHAP 2: TAMPILKAN KONDISI SEBELUM DITAMBAHKAN             │
│   Mencetak banner kondisi sebelum dan memanggil cetakSeluruhData().    │
│   Sistem memvalidasi kondisi kosong dan mencetak pesan ramah.          │
└───────────────────────────────────┬────────────────────────────────────┘
                                    │
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│               TAHAP 3: PROSES PENAMBAHAN DATA (HARDCODED)              │
│   1. Instansiasi Fasilitas Depo Logistik (Hub Regional)                │
│   2. Instansiasi Objek Komponen Mesin (MesinKendaraan)                 │
│   3. Instansiasi Kendaraan (Truk, Kapal, Pesawat) dengan Komposisi     │
│   4. Instansiasi Paket Kiriman Logistik                                │
│   5. Instansiasi Pengemudi / Operator Logistik                         │
│   6. Agregasikan Kendaraan & Paket ke Depo Logistik                    │
│   7. Hubungkan Penugasan Pengemudi dengan Kendaraan (Asosiasi)         │
└───────────────────────────────────┬────────────────────────────────────┘
                                    │
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│             TAHAP 4: TAMPILKAN KONDISI SESUDAH DITAMBAHKAN             │
│   Mencetak banner kondisi sesudah dan memanggil cetakSeluruhData().    │
│   - Daftar Truk Kargo (Cyan)                                           │
│   - Daftar Kapal Laut (Blue)                                           │
│   - Daftar Pesawat Kargo (Magenta)                                     │
│   - Daftar Paket Logistik (Yellow)                                     │
│   - Data Fasilitas Depo Logistik (Red)                                 │
│   - Data Pengemudi & Penugasan Kendaraan (Green)                       │
└───────────────────────────────────┬────────────────────────────────────┘
                                    │
                                    ▼
┌────────────────────────────────────────────────────────────────────────┐
│                              END PROGRAM                               │
└────────────────────────────────────────────────────────────────────────┘
```

### Rincian Langkah Alur:
1. **Tahap 1: Inisialisasi Wadah Koleksi Kosong**:
   Program mendeklarasikan penampung koleksi dinamis (*vector* pada C++, *list* pada Python, dan *ArrayList* pada Java) untuk seluruh kategori entitas: truk, kapal laut, pesawat kargo, paket, depo logistik, dan daftar penugasan pengemudi tanpa menyisipkan data apa pun.
2. **Tahap 2: Menampilkan Kondisi Sebelum Penambahan Data**:
   Program mencetak banner pembuka:
   `=== >> KONDISI DATA SEBELUM DITAMBAHKAN << ===`
   Lalu memanggil fungsi penampil data lengkap. Karena seluruh wadah masih kosong, sistem secara elegan mencetak pesan status bahwa belum ada data terdaftar untuk masing-masing moda dan entitas.
3. **Tahap 3: Penambahan Data Statis (Hardcode)**:
   - Program membuat instansiasi komponen mesin kendaraan (`MesinKendaraan`).
   - Objek mesin disematkan langsung saat menginstansiasi armada moda darat (`TrukKargo`), laut (`KapalLaut`), dan udara (`PesawatKargo`) membuktikan konsep **Komposisi**.
   - Program membuat objek-objek paket kargo (`Paket`).
   - Program membuat fasilitas hub depo (`DepoLogistik`), kemudian mengagregasikan kendaraan dan paket ke dalam depo menggunakan method `tambahTruk()`, `tambahKapal()`, `tambahPesawat()`, dan `tambahPaket()` membuktikan konsep **Agregasi**. Armada lintas rute diagregasikan pada kedua depo sekaligus.
   - Program membuat personil supir/kapten/pilot (`Pengemudi`), lalu menghubungkan pengemudi dengan kendaraan yang dioperasikannya membuktikan konsep **Asosiasi**.
4. **Tahap 4: Menampilkan Kondisi Sesudah Penambahan Data**:
   Program mencetak pembatas visual dan banner kondisi sesudah:
   `=== >> KONDISI DATA SESUDAH DITAMBAHKAN << ===`
   Fungsi penampil data dipanggil kembali. Kali ini seluruh kartu data tercetak dengan lengkap, terstruktur, rapi, dan menggunakan kode warna ANSI terminal yang memanjakan mata.

---

## Cara Kompilasi dan Menjalankan Program

### 1. Bahasa C++

Masuk ke direktori program C++, kompilasi menggunakan compiler `g++`, lalu jalankan binary output:

```bash
cd CPP/Program
g++ main.cpp -o main
./main
```

### 2. Bahasa Python

Masuk ke direktori program Python, lalu jalankan script menggunakan interpreter `python`:

```bash
cd Python/Program
python main.py
```

### 3. Bahasa Java

Masuk ke direktori program Java, kompilasi seluruh file kelas Java dengan `javac`, lalu jalankan kelas `Main`:

```bash
cd Java/Program
javac *.java
java Main
```

---

## Dokumentasi Output Setiap Bahasa

### 1. Dokumentasi Program C++

<p align="center">
  <img src="./CPP/Dokumentasi/cppOutput1.png" width="750" alt="C++ Output Sebelum Ditambahkan">
</p>

<p align="center">
  <img src="./CPP/Dokumentasi/cppOutput2.png" width="750" alt="C++ Output Truk Kargo">
</p>

<p align="center">
  <img src="./CPP/Dokumentasi/cppOutput3.png" width="750" alt="C++ Output Kapal Laut dan Pesawat Kargo">
</p>

<p align="center">
  <img src="./CPP/Dokumentasi/cppOutput4.png" width="750" alt="C++ Output Paket dan Fasilitas Depo">
</p>

<p align="center">
  <img src="./CPP/Dokumentasi/cppOutput5.png" width="750" alt="C++ Output Penugasan Pengemudi">
</p>

---

### 2. Dokumentasi Program Python

<p align="center">
  <img src="./Python/Dokumentasi/pythonOutput1.png" width="750" alt="Python Output Sebelum Ditambahkan">
</p>

<p align="center">
  <img src="./Python/Dokumentasi/pythonOutput2.png" width="750" alt="Python Output Truk Kargo">
</p>

<p align="center">
  <img src="./Python/Dokumentasi/pythonOutput3.png" width="750" alt="Python Output Kapal Laut dan Pesawat Kargo">
</p>

<p align="center">
  <img src="./Python/Dokumentasi/pythonOutput4.png" width="750" alt="Python Output Paket dan Fasilitas Depo">
</p>

<p align="center">
  <img src="./Python/Dokumentasi/pythonOutput5.png" width="750" alt="Python Output Penugasan Pengemudi">
</p>

---

### 3. Dokumentasi Program Java

<p align="center">
  <img src="./Java/Dokumentasi/javaOutput1.png" width="750" alt="Java Output Sebelum Ditambahkan">
</p>

<p align="center">
  <img src="./Java/Dokumentasi/javaOutput2.png" width="750" alt="Java Output Truk Kargo">
</p>

<p align="center">
  <img src="./Java/Dokumentasi/javaOutput3.png" width="750" alt="Java Output Kapal Laut dan Pesawat Kargo">
</p>

<p align="center">
  <img src="./Java/Dokumentasi/javaOutput4.png" width="750" alt="Java Output Paket dan Fasilitas Depo">
</p>

<p align="center">
  <img src="./Java/Dokumentasi/javaOutput5.png" width="750" alt="Java Output Penugasan Pengemudi">
</p>
