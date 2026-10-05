# ============================================================================
# KELAS: KapalLaut (Kelas Anak 2)
# Konsep: Hierarchical Inheritance & Polimorfisme (Method Overriding)
# ============================================================================
# KapalLaut merupakan turunan dari KendaraanPengiriman untuk moda transportasi laut.
# Memiliki atribut unik 'tipeKontainer' dan 'biayaSewaSektor', serta meng-override
# method 'tampilkanSpesifikasi()' untuk menampilkan data khas kapal kargo logistik.
# ============================================================================

from KendaraanPengiriman import KendaraanPengiriman

class KapalLaut(KendaraanPengiriman):
    # ------------------------------------------------------------------------
    # KONSTRUKTOR
    # ------------------------------------------------------------------------

    # Konstruktor default & berparameter: menginisialisasi atribut induk dan atribut spesifik kapal
    def __init__(self, idKendaraan="", merkModel="", mesin=None, tipeKontainer="", biayaSewaSektor=0.0):
        super().__init__(idKendaraan, merkModel, mesin)
        # Atribut spesifik: tipe kontainer yang didukung (cth: Dry Container 20/40ft, Reefer)
        self.__tipeKontainer = tipeKontainer

        # Atribut spesifik: biaya sewa slot pengiriman laut per sektor pelayaran (Rupiah)
        self.__biayaSewaSektor = float(biayaSewaSektor)

    # ------------------------------------------------------------------------
    # GETTER (Method Akses Pembaca Data)
    # ------------------------------------------------------------------------

    # Mengambil informasi jenis/tipe kontainer kapal
    def getTipeKontainer(self):
        return self.__tipeKontainer

    # Mengambil informasi biaya sewa rute per sektor pelayaran
    def getBiayaSewaSektor(self):
        return self.__biayaSewaSektor

    # ------------------------------------------------------------------------
    # SETTER (Method Akses Pengubah Data)
    # ------------------------------------------------------------------------

    # Mengubah informasi jenis/tipe kontainer kapal
    def setTipeKontainer(self, tipeKontainer):
        self.__tipeKontainer = tipeKontainer

    # Mengubah informasi biaya sewa rute per sektor pelayaran
    def setBiayaSewaSektor(self, biayaSewaSektor):
        self.__biayaSewaSektor = float(biayaSewaSektor)

    # ------------------------------------------------------------------------
    # METHOD SPESIFIK & POLIMORFISME (OVERRIDE)
    # ------------------------------------------------------------------------

    # Menampilkan spesifikasi lengkap khusus kendaraan Kapal Laut
    def tampilkanSpesifikasi(self):
        print(f"    ID Kendaraan     : {self._idKendaraan}")
        print(f"    Nama / Model     : {self._merkModel}")
        print(f"    Tipe Kontainer   : {self.__tipeKontainer}")
        print(f"    Biaya Sewa Rute  : Rp {self.__biayaSewaSektor:.0f} / sektor")
        print("    Spesifikasi Mesin:")
        print(f"      - No Seri Mesin: {self._mesin.getNomorSeriMesin()}")
        print(f"      - Tipe Mesin   : {self._mesin.getTipeMesin()}")
        print(f"      - Bahan Bakar  : {self._mesin.getJenisBahanBakar()}")
