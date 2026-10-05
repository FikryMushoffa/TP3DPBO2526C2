// ============================================================================
// KELAS: KendaraanPengiriman (Kelas Induk / Base Class)
// Konsep: Hierarchical Inheritance, Komposisi, Polimorfisme
// ============================================================================
// Catatan Arsitektur:
// Header library standar (<iostream>, <string>, dll) dan namespace std
// dideklarasikan terpusat pada file main.cpp karena seluruh program dikompilasi
// dan dieksekusi melalui main.cpp.
// ============================================================================
// Kelas ini mendefinisikan karakteristik dasar seluruh moda transportasi logistik.
// Menerapkan:
// 1. Komposisi: Memiliki atribut 'mesin' bertipe MesinKendaraan yang terikat erat.
// 2. Hierarchical Inheritance: Menjadi induk bagi TrukKargo, KapalLaut, PesawatKargo.
// 3. Polimorfisme: Menyediakan method 'tampilkanSpesifikasi()' untuk dioverride kelas anak.
class KendaraanPengiriman {
    protected:
        // Atribut hak akses protected agar dapat diakses langsung oleh kelas turunan
        // Kode unik identifikasi kendaraan (cth: TRK-001, KPL-101, PSW-201)
        string idKendaraan;

        // Merk dan nama model manufaktur kendaraan (cth: Hino Ranger, KM Meratus)
        string merkModel;

        // Objek komponen mesin (Komposisi: terikat erat dengan siklus hidup kendaraan)
        MesinKendaraan mesin;

    public:
        // --------------------------------------------------------------------
        // KONSTRUKTOR
        // --------------------------------------------------------------------

        // Konstruktor default: menginisialisasi atribut dengan nilai awal kosong
        KendaraanPengiriman() {
            this->idKendaraan = "";
            this->merkModel = "";
            this->mesin = MesinKendaraan();
        }

        // Konstruktor berparameter lengkap: mengisi atribut sesuai data input
        KendaraanPengiriman(string idKendaraan, string merkModel, MesinKendaraan mesin) {
            this->idKendaraan = idKendaraan;
            this->merkModel = merkModel;
            this->mesin = mesin;
        }

        // --------------------------------------------------------------------
        // GETTER (Method Akses Pembaca Data)
        // --------------------------------------------------------------------

        // Mengambil nilai ID kendaraan
        string getIdKendaraan() const {
            return this->idKendaraan;
        }

        // Mengambil nilai merk dan nama model kendaraan
        string getMerkModel() const {
            return this->merkModel;
        }

        // Mengambil objek komponen mesin kendaraan
        MesinKendaraan getMesin() const {
            return this->mesin;
        }

        // --------------------------------------------------------------------
        // SETTER (Method Akses Pengubah Data)
        // --------------------------------------------------------------------

        // Mengubah nilai ID kendaraan
        void setIdKendaraan(const string& idKendaraan) {
            this->idKendaraan = idKendaraan;
        }

        // Mengubah nilai merk dan model kendaraan
        void setMerkModel(const string& merkModel) {
            this->merkModel = merkModel;
        }

        // Mengubah objek mesin kendaraan
        void setMesin(const MesinKendaraan& mesin) {
            this->mesin = mesin;
        }

        // --------------------------------------------------------------------
        // METHOD SPESIFIK & POLIMORFISME
        // --------------------------------------------------------------------

        // Method polimorfik dasar untuk menampilkan spesifikasi umum kendaraan
        // Method ini dioverride oleh kelas-kelas turunan (Truk, Kapal, Pesawat)
        void tampilkanSpesifikasi() const {
            cout << "[Kendaraan Pengiriman Umum]" << endl;
            cout << "  ID Kendaraan    : " << this->idKendaraan << endl;
            cout << "  Merk & Model    : " << this->merkModel << endl;
            cout << "  Detail Mesin    : Seri " << this->mesin.getNomorSeriMesin() 
                 << " | " << this->mesin.getTipeMesin() 
                 << " | Bahan Bakar: " << this->mesin.getJenisBahanBakar() << endl;
        }

        // --------------------------------------------------------------------
        // DESTRUKTOR
        // --------------------------------------------------------------------

        // Destruktor kelas induk KendaraanPengiriman
        ~KendaraanPengiriman() {
        }
};
