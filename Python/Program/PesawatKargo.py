# ============================================================================
# KELAS: PesawatKargo (Kelas Anak 3)
# Konsep: Hierarchical Inheritance & Polimorfisme (Method Overriding)
# ============================================================================
# PesawatKargo merupakan turunan dari KendaraanPengiriman untuk moda transportasi udara.
# Memiliki atribut unik 'ketinggianMaksimal' dan 'surchargeAvtur', serta meng-override
# method 'tampilkanSpesifikasi()' untuk menampilkan data khas pesawat kargo logistik.
# ============================================================================

from KendaraanPengiriman import KendaraanPengiriman

class PesawatKargo(KendaraanPengiriman):
    # ------------------------------------------------------------------------
    # KONSTRUKTOR
    # ------------------------------------------------------------------------

    # Konstruktor default & berparameter: menginisialisasi atribut induk dan atribut spesifik pesawat
    def __init__(self, idKendaraan="", merkModel="", mesin=None, ketinggianMaksimal=0, surchargeAvtur=0.0):
        super().__init__(idKendaraan, merkModel, mesin)
        # Atribut spesifik: batas ketinggian terbang jelajah maksimal (kaki / feet)
        self.__ketinggianMaksimal = int(ketinggianMaksimal)

        # Atribut spesifik: biaya surcharge bahan bakar avtur per jadwal penerbangan (Rupiah)
        self.__surchargeAvtur = float(surchargeAvtur)

    # ------------------------------------------------------------------------
    # GETTER (Method Akses Pembaca Data)
    # ------------------------------------------------------------------------

    # Mengambil informasi batas ketinggian terbang jelajah maksimal (kaki)
    def getKetinggianMaksimal(self):
        return self.__ketinggianMaksimal

    # Mengambil informasi biaya surcharge bahan bakar avtur per penerbangan
    def getSurchargeAvtur(self):
        return self.__surchargeAvtur

    # ------------------------------------------------------------------------
    # SETTER (Method Akses Pengubah Data)
    # ------------------------------------------------------------------------

    # Mengubah informasi batas ketinggian terbang jelajah maksimal (kaki)
    def setKetinggianMaksimal(self, ketinggianMaksimal):
        self.__ketinggianMaksimal = int(ketinggianMaksimal)

    # Mengubah informasi biaya surcharge bahan bakar avtur per penerbangan
    def setSurchargeAvtur(self, surchargeAvtur):
        self.__surchargeAvtur = float(surchargeAvtur)

    # ------------------------------------------------------------------------
    # METHOD SPESIFIK & POLIMORFISME (OVERRIDE)
    # ------------------------------------------------------------------------

    # Menampilkan spesifikasi lengkap khusus kendaraan Pesawat Kargo
    def tampilkanSpesifikasi(self):
        print(f"    ID Kendaraan     : {self._idKendaraan}")
        print(f"    Model Pesawat    : {self._merkModel}")
        print(f"    Ketinggian Maks  : {self.__ketinggianMaksimal} kaki")
        print(f"    Surcharge Avtur  : Rp {self.__surchargeAvtur:.0f}")
        print("    Spesifikasi Mesin:")
        print(f"      - No Seri Mesin: {self._mesin.getNomorSeriMesin()}")
        print(f"      - Tipe Mesin   : {self._mesin.getTipeMesin()}")
        print(f"      - Bahan Bakar  : {self._mesin.getJenisBahanBakar()}")
