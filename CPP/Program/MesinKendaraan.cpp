// ============================================================================
// KELAS: MesinKendaraan (Kelas Komponen)
// Konsep: Komposisi (Composition Component)
// ============================================================================
// Catatan Arsitektur:
// Header library standar (<iostream>, <string>, dll) dan namespace std
// dideklarasikan terpusat pada file main.cpp karena seluruh program dikompilasi
// dan dieksekusi melalui main.cpp.
// ============================================================================
// Kelas MesinKendaraan berfungsi sebagai bagian integral/komponen mesin dari
// kendaraan pengiriman. Dalam relasi Komposisi, masa hidup objek mesin terikat
// sepenuhnya pada objek kendaraan yang memilikinya.
class MesinKendaraan {
    private:
        // Atribut nomor seri unik manufaktur mesin
        string nomorSeriMesin;

        // Atribut model/tipe konfigurasi mesin (cth: J08E Turbo, CFM56 Turbofan)
        string tipeMesin;

        // Atribut tipe bahan bakar yang digunakan mesin (cth: Solar CN-51, Avtur Jet A-1)
        string jenisBahanBakar;

    public:
        // --------------------------------------------------------------------
        // KONSTRUKTOR
        // ------------------------------------------------------------------------

        // Konstruktor default: menginisialisasi atribut dengan nilai string kosong
        MesinKendaraan() {
            this->nomorSeriMesin = "";
            this->tipeMesin = "";
            this->jenisBahanBakar = "";
        }

        // Konstruktor berparameter: menginisialisasi atribut mesin sesuai argumen input
        MesinKendaraan(string nomorSeriMesin, string tipeMesin, string jenisBahanBakar) {
            this->nomorSeriMesin = nomorSeriMesin;
            this->tipeMesin = tipeMesin;
            this->jenisBahanBakar = jenisBahanBakar;
        }

        // --------------------------------------------------------------------
        // GETTER (Method Akses Pembaca Data)
        // --------------------------------------------------------------------

        // Mengambil informasi nomor seri mesin
        string getNomorSeriMesin() const {
            return this->nomorSeriMesin;
        }

        // Mengambil informasi tipe/konfigurasi mesin
        string getTipeMesin() const {
            return this->tipeMesin;
        }

        // Mengambil informasi jenis bahan bakar mesin
        string getJenisBahanBakar() const {
            return this->jenisBahanBakar;
        }

        // --------------------------------------------------------------------
        // SETTER (Method Akses Pengubah Data)
        // --------------------------------------------------------------------

        // Mengubah informasi nomor seri mesin
        void setNomorSeriMesin(const string& nomorSeriMesin) {
            this->nomorSeriMesin = nomorSeriMesin;
        }

        // Mengubah informasi tipe/konfigurasi mesin
        void setTipeMesin(const string& tipeMesin) {
            this->tipeMesin = tipeMesin;
        }

        // Mengubah informasi jenis bahan bakar mesin
        void setJenisBahanBakar(const string& jenisBahanBakar) {
            this->jenisBahanBakar = jenisBahanBakar;
        }

        // --------------------------------------------------------------------
        // DESTRUKTOR
        // --------------------------------------------------------------------

        // Destruktor: membersihkan alokasi objek MesinKendaraan saat keluar dari scope
        ~MesinKendaraan() {
        }
};
