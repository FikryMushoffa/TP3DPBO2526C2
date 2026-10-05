// ============================================================================
// KELAS: PesawatKargo (Kelas Anak 3)
// Konsep: Hierarchical Inheritance & Polimorfisme (Method Overriding)
// ============================================================================
// Catatan Arsitektur:
// Header library standar (<iostream>, <string>, dll) dan namespace std
// dideklarasikan terpusat pada file main.cpp karena seluruh program dikompilasi
// dan dieksekusi melalui main.cpp.
// ============================================================================
// PesawatKargo merupakan turunan dari KendaraanPengiriman untuk moda transportasi udara.
// Memiliki atribut unik 'ketinggianMaksimal' dan 'surchargeAvtur', serta meng-override
// method 'tampilkanSpesifikasi()' untuk menampilkan data khas pesawat kargo logistik.
class PesawatKargo : public KendaraanPengiriman {
    private:
        // Atribut spesifik: batas ketinggian terbang jelajah maksimal (kaki / feet)
        int ketinggianMaksimal;

        // Atribut spesifik: biaya surcharge bahan bakar avtur per jadwal penerbangan (Rupiah)
        double surchargeAvtur;

    public:
        // --------------------------------------------------------------------
        // KONSTRUKTOR
        // --------------------------------------------------------------------

        // Konstruktor default: memanggil konstruktor induk dan mengosongkan atribut pesawat
        PesawatKargo() : KendaraanPengiriman() {
            this->ketinggianMaksimal = 0;
            this->surchargeAvtur = 0.0;
        }

        // Konstruktor berparameter: menginisialisasi atribut induk dan atribut spesifik pesawat
        PesawatKargo(string idKendaraan, string merkModel, MesinKendaraan mesin, 
                     int ketinggianMaksimal, double surchargeAvtur)
            : KendaraanPengiriman(idKendaraan, merkModel, mesin) {
            this->ketinggianMaksimal = ketinggianMaksimal;
            this->surchargeAvtur = surchargeAvtur;
        }

        // --------------------------------------------------------------------
        // GETTER (Method Akses Pembaca Data)
        // --------------------------------------------------------------------

        // Mengambil informasi batas ketinggian terbang jelajah maksimal (kaki)
        int getKetinggianMaksimal() const {
            return this->ketinggianMaksimal;
        }

        // Mengambil informasi biaya surcharge bahan bakar avtur per penerbangan
        double getSurchargeAvtur() const {
            return this->surchargeAvtur;
        }

        // --------------------------------------------------------------------
        // SETTER (Method Akses Pengubah Data)
        // --------------------------------------------------------------------

        // Mengubah informasi batas ketinggian terbang jelajah maksimal (kaki)
        void setKetinggianMaksimal(int ketinggianMaksimal) {
            this->ketinggianMaksimal = ketinggianMaksimal;
        }

        // Mengubah informasi biaya surcharge bahan bakar avtur per penerbangan
        void setSurchargeAvtur(double surchargeAvtur) {
            this->surchargeAvtur = surchargeAvtur;
        }

        // --------------------------------------------------------------------
        // METHOD SPESIFIK & POLIMORFISME (OVERRIDE)
        // --------------------------------------------------------------------

        // Menampilkan spesifikasi lengkap khusus kendaraan Pesawat Kargo
        void tampilkanSpesifikasi() const {
            cout << "    ID Kendaraan     : " << this->idKendaraan << endl;
            cout << "    Model Pesawat    : " << this->merkModel << endl;
            cout << "    Ketinggian Maks  : " << this->ketinggianMaksimal << " kaki" << endl;
            cout << "    Surcharge Avtur  : Rp " << fixed << setprecision(0) << this->surchargeAvtur << endl;
            cout << "    Spesifikasi Mesin:" << endl;
            cout << "      - No Seri Mesin: " << this->mesin.getNomorSeriMesin() << endl;
            cout << "      - Tipe Mesin   : " << this->mesin.getTipeMesin() << endl;
            cout << "      - Bahan Bakar  : " << this->mesin.getJenisBahanBakar() << endl;
        }

        // --------------------------------------------------------------------
        // DESTRUKTOR
        // --------------------------------------------------------------------

        // Destruktor kelas PesawatKargo
        ~PesawatKargo() {
        }
};
