// ============================================================================
// KELAS: Paket (Kelas Data)
// Konsep: Entitas Data & Agregasi (Aggregated Entity)
// ============================================================================
// Catatan Arsitektur:
// Header library standar (<iostream>, <string>, dll) dan namespace std
// dideklarasikan terpusat pada file main.cpp karena seluruh program dikompilasi
// dan dieksekusi melalui main.cpp.
// ============================================================================
// Kelas Paket merepresentasikan data kargo/barang kiriman yang dikelola oleh depo
// logistik. Paket memiliki siklus hidup independen dan diagregasikan oleh DepoLogistik.
class Paket {
    private:
        // Atribut unik nomor pelacakan resi kiriman (cth: PKG-ID-2026-001)
        string nomorResi;

        // Atribut berat fisik kargo barang (satuan kilogram)
        double beratKg;

        // Atribut deskripsi / manifest kategori muatan barang
        string deskripsiBarang;

    public:
        // --------------------------------------------------------------------
        // KONSTRUKTOR
        // --------------------------------------------------------------------

        // Konstruktor default: menginisialisasi atribut paket dengan nilai awal kosong
        Paket() {
            this->nomorResi = "";
            this->beratKg = 0.0;
            this->deskripsiBarang = "";
        }

        // Konstruktor berparameter lengkap: mengisi data resi, berat, dan deskripsi paket
        Paket(string nomorResi, double beratKg, string deskripsiBarang) {
            this->nomorResi = nomorResi;
            this->beratKg = beratKg;
            this->deskripsiBarang = deskripsiBarang;
        }

        // --------------------------------------------------------------------
        // GETTER (Method Akses Pembaca Data)
        // --------------------------------------------------------------------

        // Mengambil informasi nomor resi paket
        string getNomorResi() const {
            return this->nomorResi;
        }

        // Mengambil informasi berat fisik paket (kg)
        double getBeratKg() const {
            return this->beratKg;
        }

        // Mengambil informasi rincian deskripsi barang kiriman
        string getDeskripsiBarang() const {
            return this->deskripsiBarang;
        }

        // --------------------------------------------------------------------
        // SETTER (Method Akses Pengubah Data)
        // --------------------------------------------------------------------

        // Mengubah nomor resi paket
        void setNomorResi(const string& nomorResi) {
            this->nomorResi = nomorResi;
        }

        // Mengubah berat fisik paket (kg)
        void setBeratKg(double beratKg) {
            this->beratKg = beratKg;
        }

        // Mengubah rincian deskripsi barang kiriman
        void setDeskripsiBarang(const string& deskripsiBarang) {
            this->deskripsiBarang = deskripsiBarang;
        }

        // --------------------------------------------------------------------
        // DESTRUKTOR
        // --------------------------------------------------------------------

        // Destruktor: membersihkan alokasi objek Paket
        ~Paket() {
        }
};
