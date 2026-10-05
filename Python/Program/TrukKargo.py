# ============================================================================
# KELAS: TrukKargo (Kelas Anak 1)
# Konsep: Hierarchical Inheritance & Polimorfisme (Method Overriding)
# ============================================================================
# TrukKargo merupakan turunan dari KendaraanPengiriman untuk moda transportasi darat.
# Memiliki atribut unik 'jumlahRoda' dan 'tarifPerKmDarat', serta meng-override
# method 'tampilkanSpesifikasi()' untuk menampilkan data khas truk logistik.
# ============================================================================

from KendaraanPengiriman import KendaraanPengiriman

class TrukKargo(KendaraanPengiriman):
    # ------------------------------------------------------------------------
    # KONSTRUKTOR
    # ------------------------------------------------------------------------

    # Konstruktor default & berparameter: menginisialisasi atribut induk dan atribut spesifik truk
    def __init__(self, idKendaraan="", merkModel="", mesin=None, jumlahRoda=0, tarifPerKmDarat=0.0):
        super().__init__(idKendaraan, merkModel, mesin)
        # Atribut spesifik: jumlah roda pada kendaraan truk (cth: 6, 10, 18 roda)
        self.__jumlahRoda = jumlahRoda

        # Atribut spesifik: tarif dasar pengiriman per kilometer jalan darat (Rupiah)
        self.__tarifPerKmDarat = float(tarifPerKmDarat)

    # ------------------------------------------------------------------------
    # GETTER (Method Akses Pembaca Data)
    # ------------------------------------------------------------------------

    # Mengambil informasi jumlah roda truk
    def getJumlahRoda(self):
        return self.__jumlahRoda

    # Mengambil informasi tarif pengiriman darat per kilometer
    def getTarifPerKmDarat(self):
        return self.__tarifPerKmDarat

    # ------------------------------------------------------------------------
    # SETTER (Method Akses Pengubah Data)
    # ------------------------------------------------------------------------

    # Mengubah informasi jumlah roda truk
    def setJumlahRoda(self, jumlahRoda):
        self.__jumlahRoda = jumlahRoda

    # Mengubah informasi tarif pengiriman darat per kilometer
    def setTarifPerKmDarat(self, tarifPerKmDarat):
        self.__tarifPerKmDarat = float(tarifPerKmDarat)

    # ------------------------------------------------------------------------
    # METHOD SPESIFIK & POLIMORFISME (OVERRIDE)
    # ------------------------------------------------------------------------

    # Menampilkan spesifikasi lengkap khusus kendaraan Truk Kargo
    def tampilkanSpesifikasi(self):
        print(f"    ID Kendaraan     : {self._idKendaraan}")
        print(f"    Merk & Model     : {self._merkModel}")
        print(f"    Konfigurasi Roda : {self.__jumlahRoda} roda")
        print(f"    Tarif per Km     : Rp {self.__tarifPerKmDarat:.0f}")
        print("    Spesifikasi Mesin:")
        print(f"      - No Seri Mesin: {self._mesin.getNomorSeriMesin()}")
        print(f"      - Tipe Mesin   : {self._mesin.getTipeMesin()}")
        print(f"      - Bahan Bakar  : {self._mesin.getJenisBahanBakar()}")
