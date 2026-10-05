// ============================================================================
// KELAS: KapalLaut (Kelas Anak 2)
// Konsep: Hierarchical Inheritance & Polimorfisme (Method Overriding)
// ============================================================================
// Catatan Arsitektur:
// Header library standar (<iostream>, <string>, dll) dan namespace std
// dideklarasikan terpusat pada file main.cpp karena seluruh program dikompilasi
// dan dieksekusi melalui main.cpp.
// ============================================================================
// KapalLaut merupakan turunan dari KendaraanPengiriman untuk moda transportasi laut.
// Memiliki atribut unik 'tipeKontainer' dan 'biayaSewaSektor', serta meng-override
// method 'tampilkanSpesifikasi()' untuk menampilkan data khas kapal kargo logistik.
class KapalLaut : public KendaraanPengiriman {
    private:
        // Atribut spesifik: tipe kontainer yang didukung (cth: Dry Container 20/40ft, Reefer)
        string tipeKontainer;

        // Atribut spesifik: biaya sewa slot pengiriman laut per sektor pelayaran (Rupiah)
        double biayaSewaSektor;

    public:
        // --------------------------------------------------------------------
        // KONSTRUKTOR
        // --------------------------------------------------------------------

        // Konstruktor default: memanggil konstruktor induk dan mengosongkan atribut kapal
        KapalLaut() : KendaraanPengiriman() {
            this->tipeKontainer = "";
            this->biayaSewaSektor = 0.0;
        }

        // Konstruktor berparameter: menginisialisasi atribut induk dan atribut spesifik kapal
        KapalLaut(string idKendaraan, string merkModel, MesinKendaraan mesin, 
                  string tipeKontainer, double biayaSewaSektor)
            : KendaraanPengiriman(idKendaraan, merkModel, mesin) {
            this->tipeKontainer = tipeKontainer;
            this->biayaSewaSektor = biayaSewaSektor;
        }

        // --------------------------------------------------------------------
        // GETTER (Method Akses Pembaca Data)
        // --------------------------------------------------------------------

        // Mengambil informasi jenis/tipe kontainer kapal
        string getTipeKontainer() const {
            return this->tipeKontainer;
        }

        // Mengambil informasi biaya sewa rute per sektor pelayaran
        double getBiayaSewaSektor() const {
            return this->biayaSewaSektor;
        }

        // --------------------------------------------------------------------
        // SETTER (Method Akses Pengubah Data)
        // --------------------------------------------------------------------

        // Mengubah informasi jenis/tipe kontainer kapal
        void setTipeKontainer(const string& tipeKontainer) {
            this->tipeKontainer = tipeKontainer;
        }

        // Mengubah informasi biaya sewa rute per sektor pelayaran
        void setBiayaSewaSektor(double biayaSewaSektor) {
            this->biayaSewaSektor = biayaSewaSektor;
        }

        // --------------------------------------------------------------------
        // METHOD SPESIFIK & POLIMORFISME (OVERRIDE)
        // --------------------------------------------------------------------

        // Menampilkan spesifikasi lengkap khusus kendaraan Kapal Laut
        void tampilkanSpesifikasi() const {
            cout << "    ID Kendaraan     : " << this->idKendaraan << endl;
            cout << "    Nama / Model     : " << this->merkModel << endl;
            cout << "    Tipe Kontainer   : " << this->tipeKontainer << endl;
            cout << "    Biaya Sewa Rute  : Rp " << fixed << setprecision(0) << this->biayaSewaSektor << " / sektor" << endl;
            cout << "    Spesifikasi Mesin:" << endl;
            cout << "      - No Seri Mesin: " << this->mesin.getNomorSeriMesin() << endl;
            cout << "      - Tipe Mesin   : " << this->mesin.getTipeMesin() << endl;
            cout << "      - Bahan Bakar  : " << this->mesin.getJenisBahanBakar() << endl;
        }

        // --------------------------------------------------------------------
        // DESTRUKTOR
        // --------------------------------------------------------------------

        // Destruktor kelas KapalLaut
        ~KapalLaut() {
        }
};
