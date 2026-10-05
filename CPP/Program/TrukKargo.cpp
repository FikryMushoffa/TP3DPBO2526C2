// ============================================================================
// KELAS: TrukKargo (Kelas Anak 1)
// Konsep: Hierarchical Inheritance & Polimorfisme (Method Overriding)
// ============================================================================
// Catatan Arsitektur:
// Header library standar (<iostream>, <string>, dll) dan namespace std
// dideklarasikan terpusat pada file main.cpp karena seluruh program dikompilasi
// dan dieksekusi melalui main.cpp.
// ============================================================================
// TrukKargo merupakan turunan dari KendaraanPengiriman untuk moda transportasi darat.
// Memiliki atribut unik 'jumlahRoda' dan 'tarifPerKmDarat', serta meng-override
// method 'tampilkanSpesifikasi()' untuk menampilkan data khas truk logistik.
class TrukKargo : public KendaraanPengiriman {
    private:
        // Atribut spesifik: jumlah roda pada kendaraan truk (cth: 6, 10, 18 roda)
        int jumlahRoda;

        // Atribut spesifik: tarif dasar pengiriman per kilometer jalan darat (Rupiah)
        double tarifPerKmDarat;

    public:
        // --------------------------------------------------------------------
        // KONSTRUKTOR
        // --------------------------------------------------------------------

        // Konstruktor default: memanggil konstruktor induk dan mengosongkan atribut truk
        TrukKargo() : KendaraanPengiriman() {
            this->jumlahRoda = 0;
            this->tarifPerKmDarat = 0.0;
        }

        // Konstruktor berparameter: menginisialisasi atribut induk dan atribut spesifik truk
        TrukKargo(string idKendaraan, string merkModel, MesinKendaraan mesin, 
                  int jumlahRoda, double tarifPerKmDarat)
            : KendaraanPengiriman(idKendaraan, merkModel, mesin) {
            this->jumlahRoda = jumlahRoda;
            this->tarifPerKmDarat = tarifPerKmDarat;
        }

        // --------------------------------------------------------------------
        // GETTER (Method Akses Pembaca Data)
        // --------------------------------------------------------------------

        // Mengambil informasi jumlah roda truk
        int getJumlahRoda() const {
            return this->jumlahRoda;
        }

        // Mengambil informasi tarif pengiriman darat per kilometer
        double getTarifPerKmDarat() const {
            return this->tarifPerKmDarat;
        }

        // --------------------------------------------------------------------
        // SETTER (Method Akses Pengubah Data)
        // --------------------------------------------------------------------

        // Mengubah informasi jumlah roda truk
        void setJumlahRoda(int jumlahRoda) {
            this->jumlahRoda = jumlahRoda;
        }

        // Mengubah informasi tarif pengiriman darat per kilometer
        void setTarifPerKmDarat(double tarifPerKmDarat) {
            this->tarifPerKmDarat = tarifPerKmDarat;
        }

        // --------------------------------------------------------------------
        // METHOD SPESIFIK & POLIMORFISME (OVERRIDE)
        // --------------------------------------------------------------------

        // Menampilkan spesifikasi lengkap khusus kendaraan Truk Kargo
        void tampilkanSpesifikasi() const {
            cout << "    ID Kendaraan     : " << this->idKendaraan << endl;
            cout << "    Merk & Model     : " << this->merkModel << endl;
            cout << "    Konfigurasi Roda : " << this->jumlahRoda << " roda" << endl;
            cout << "    Tarif per Km     : Rp " << fixed << setprecision(0) << this->tarifPerKmDarat << endl;
            cout << "    Spesifikasi Mesin:" << endl;
            cout << "      - No Seri Mesin: " << this->mesin.getNomorSeriMesin() << endl;
            cout << "      - Tipe Mesin   : " << this->mesin.getTipeMesin() << endl;
            cout << "      - Bahan Bakar  : " << this->mesin.getJenisBahanBakar() << endl;
        }

        // --------------------------------------------------------------------
        // DESTRUKTOR
        // --------------------------------------------------------------------

        // Destruktor kelas TrukKargo
        ~TrukKargo() {
        }
};
