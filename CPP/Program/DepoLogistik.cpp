// ============================================================================
// KELAS: DepoLogistik (Kelas Pengelola)
// Konsep: Agregasi (Aggregation) & Array of Objects
// ============================================================================
// Catatan Arsitektur:
// Header library standar (<iostream>, <string>, dll) dan namespace std
// dideklarasikan terpusat pada file main.cpp karena seluruh program dikompilasi
// dan dieksekusi melalui main.cpp.
// ============================================================================
// DepoLogistik mengelola sekumpulan kendaraan dan paket yang ditempatkan di suatu kota.
// Penerapan Konsep:
// 1. Agregasi: Depo memiliki hubungan kepemilikan bebas (has-a) dengan kendaraan
//    dan paket. Depo hanya menyimpan referensi (pointer) objek. Jika objek Depo
//    dihancurkan/ditutup, kendaraan dan paket tetap ada dan dapat dialokasikan ke depo lain.
// 2. Array of Objects: Menggunakan array/vector objek terpisah untuk tiap kelas:
//    - daftarTruk    : Array of TrukKargo
//    - daftarKapal   : Array of KapalLaut
//    - daftarPesawat : Array of PesawatKargo
//    - daftarPaket   : Array of Paket
class DepoLogistik {
    private:
        // Atribut kode identifikasi unik fasilitas depo logistik (cth: DPO-SUB-01)
        string kodeDepo;

        // Atribut nama kota operasional lokasi fasilitas depo berada (cth: Surabaya)
        string kotaLokasi;

        // Array of Objects: kumpulan pointer referensi ke kendaraan Truk Kargo (Agregasi)
        vector<TrukKargo*> daftarTruk;

        // Array of Objects: kumpulan pointer referensi ke kendaraan Kapal Laut (Agregasi)
        vector<KapalLaut*> daftarKapal;

        // Array of Objects: kumpulan pointer referensi ke kendaraan Pesawat Kargo (Agregasi)
        vector<PesawatKargo*> daftarPesawat;

        // Array of Objects: kumpulan pointer referensi ke paket logistik (Agregasi)
        vector<Paket*> daftarPaket;

    public:
        // --------------------------------------------------------------------
        // KONSTRUKTOR
        // --------------------------------------------------------------------

        // Konstruktor default: menginisialisasi atribut depo dengan nilai awal kosong
        DepoLogistik() {
            this->kodeDepo = "";
            this->kotaLokasi = "";
        }

        // Konstruktor berparameter: menginisialisasi kode depo dan kota lokasi
        DepoLogistik(string kodeDepo, string kotaLokasi) {
            this->kodeDepo = kodeDepo;
            this->kotaLokasi = kotaLokasi;
        }

        // --------------------------------------------------------------------
        // GETTER (Method Akses Pembaca Data Sesuai Desain)
        // --------------------------------------------------------------------

        // Mengambil informasi kode unik depo
        string getKodeDepo() const {
            return this->kodeDepo;
        }

        // Mengambil informasi nama kota lokasi fasilitas depo
        string getKotaLokasi() const {
            return this->kotaLokasi;
        }

        // Mengambil daftar referensi seluruh kendaraan truk yang ada di depo
        vector<TrukKargo*> getDaftarTruk() const {
            return this->daftarTruk;
        }

        // Mengambil daftar referensi seluruh kendaraan kapal yang ada di depo
        vector<KapalLaut*> getDaftarKapal() const {
            return this->daftarKapal;
        }

        // Mengambil daftar referensi seluruh kendaraan pesawat yang ada di depo
        vector<PesawatKargo*> getDaftarPesawat() const {
            return this->daftarPesawat;
        }

        // Mengambil daftar referensi seluruh paket kiriman yang ada di depo
        vector<Paket*> getDaftarPaket() const {
            return this->daftarPaket;
        }

        // --------------------------------------------------------------------
        // SETTER (Method Akses Pengubah Data Sesuai Desain)
        // --------------------------------------------------------------------

        // Mengubah informasi kode unik fasilitas depo
        void setKodeDepo(const string& kodeDepo) {
            this->kodeDepo = kodeDepo;
        }

        // Mengubah informasi nama kota lokasi fasilitas depo
        void setKotaLokasi(const string& kotaLokasi) {
            this->kotaLokasi = kotaLokasi;
        }

        // Mengganti seluruh daftar referensi kendaraan truk di depo
        void setDaftarTruk(const vector<TrukKargo*>& daftarTruk) {
            this->daftarTruk = daftarTruk;
        }

        // Mengganti seluruh daftar referensi kendaraan kapal di depo
        void setDaftarKapal(const vector<KapalLaut*>& daftarKapal) {
            this->daftarKapal = daftarKapal;
        }

        // Mengganti seluruh daftar referensi kendaraan pesawat di depo
        void setDaftarPesawat(const vector<PesawatKargo*>& daftarPesawat) {
            this->daftarPesawat = daftarPesawat;
        }

        // Mengganti seluruh daftar referensi paket kiriman di depo
        void setDaftarPaket(const vector<Paket*>& daftarPaket) {
            this->daftarPaket = daftarPaket;
        }

        // --------------------------------------------------------------------
        // METHOD PENAMBAHAN DATA SATUAN (HELPER OPERASIONAL)
        // --------------------------------------------------------------------

        // Menambahkan satu objek referensi kendaraan Truk Kargo ke dalam depo (Agregasi)
        void tambahTruk(TrukKargo* truk) {
            if (truk != nullptr) {
                this->daftarTruk.push_back(truk);
            }
        }

        // Menambahkan satu objek referensi kendaraan Kapal Laut ke dalam depo (Agregasi)
        void tambahKapal(KapalLaut* kapal) {
            if (kapal != nullptr) {
                this->daftarKapal.push_back(kapal);
            }
        }

        // Menambahkan satu objek referensi kendaraan Pesawat Kargo ke dalam depo (Agregasi)
        void tambahPesawat(PesawatKargo* pesawat) {
            if (pesawat != nullptr) {
                this->daftarPesawat.push_back(pesawat);
            }
        }

        // Menambahkan satu objek referensi Paket kiriman ke dalam depo (Agregasi)
        void tambahPaket(Paket* paket) {
            if (paket != nullptr) {
                this->daftarPaket.push_back(paket);
            }
        }

        // --------------------------------------------------------------------
        // METHOD OPERASIONAL: TAMPILKAN STATUS RINGKASAN DEPO
        // --------------------------------------------------------------------

        // Menampilkan informasi umum dan rekapitulasi jumlah kendaraan serta paket pada fasilitas depo
        void tampilkanInformasiDepo() const {
            cout << "Kode Depo       : " << this->kodeDepo << endl;
            cout << "Kota Lokasi     : " << this->kotaLokasi << endl;
            cout << "Total Kendaraan : " << (daftarTruk.size() + daftarKapal.size() + daftarPesawat.size()) 
                 << " unit (" << daftarTruk.size() << " Truk, " 
                 << daftarKapal.size() << " Kapal, " 
                 << daftarPesawat.size() << " Pesawat)" << endl;
            cout << "Total Paket     : " << daftarPaket.size() << " paket kiriman" << endl;
        }

        // --------------------------------------------------------------------
        // DESTRUKTOR
        // --------------------------------------------------------------------

        // Destruktor: membersihkan vector referensi pointer
        // Pada konsep Agregasi, penghancuran objek DepoLogistik TIDAK menghancurkan
        // objek Truk, Kapal, Pesawat, maupun Paket di memori. Hanya daftar referensi yang dibersihkan.
        ~DepoLogistik() {
            this->daftarTruk.clear();
            this->daftarKapal.clear();
            this->daftarPesawat.clear();
            this->daftarPaket.clear();
        }
};
