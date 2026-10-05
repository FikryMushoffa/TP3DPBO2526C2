# ============================================================================
# SISTEM LOGISTIK PENGIRIMAN MULTIMODA (TP3 DPBO)
# Program Utama dalam Bahasa Pemrograman Python
# ============================================================================

# Import seluruh modul kelas sesuai rancangan
from MesinKendaraan import MesinKendaraan
from KendaraanPengiriman import KendaraanPengiriman
from TrukKargo import TrukKargo
from KapalLaut import KapalLaut
from PesawatKargo import PesawatKargo
from Paket import Paket
from Pengemudi import Pengemudi
from DepoLogistik import DepoLogistik

# ============================================================================
# DEKLARASI KODE WARNA ANSI TERMINAL (UNTUK MEMPERCANTIK OUTPUT)
# ============================================================================
RESET = "\033[0m"
BOLD = "\033[1m"
RED = "\033[31m"
GREEN = "\033[32m"
YELLOW = "\033[33m"
BLUE = "\033[34m"
MAGENTA = "\033[35m"
CYAN = "\033[36m"

# ============================================================================
# FUNGSI-FUNGSI PENAMPIL DATA (VERTIKAL / CARD STYLE)
# ============================================================================

# Fungsi 1: Menampilkan seluruh data kendaraan Truk Kargo secara vertikal
def cetakDaftarTruk(listTruk):
    print(f"{CYAN}--- DAFTAR KENDARAAN TRUK KARGO (TRANSPORTASI DARAT) ---{RESET}")
    if not listTruk:
        print("  (Belum ada data kendaraan Truk Kargo terdaftar)")
    else:
        no = 1
        for t in listTruk:
            print(f"  [Truk #{no}]")
            no += 1
            # Memanggil method polimorfik spesifikasi truk kargo
            t.tampilkanSpesifikasi()
            print("  -------------------------------------------------------")
    print()

# Fungsi 2: Menampilkan seluruh data kendaraan Kapal Laut secara vertikal
def cetakDaftarKapal(listKapal):
    print(f"{BOLD}{BLUE}--- DAFTAR KENDARAAN KAPAL LAUT (TRANSPORTASI LAUT) ---{RESET}")
    if not listKapal:
        print("  (Belum ada data kendaraan Kapal Laut terdaftar)")
    else:
        no = 1
        for k in listKapal:
            print(f"  [Kapal #{no}]")
            no += 1
            # Memanggil method polimorfik spesifikasi kapal laut
            k.tampilkanSpesifikasi()
            print("  -------------------------------------------------------")
    print()

# Fungsi 3: Menampilkan seluruh data kendaraan Pesawat Kargo secara vertikal
def cetakDaftarPesawat(listPesawat):
    print(f"{BOLD}{MAGENTA}--- DAFTAR KENDARAAN PESAWAT KARGO (TRANSPORTASI UDARA) ---{RESET}")
    if not listPesawat:
        print("  (Belum ada data kendaraan Pesawat Kargo terdaftar)")
    else:
        no = 1
        for p in listPesawat:
            print(f"  [Pesawat #{no}]")
            no += 1
            # Memanggil method polimorfik spesifikasi pesawat kargo
            p.tampilkanSpesifikasi()
            print("  -------------------------------------------------------")
    print()

# Fungsi 4: Menampilkan seluruh daftar data Paket Logistik
def cetakDaftarPaket(listPaket):
    print(f"{BOLD}{YELLOW}--- DAFTAR PAKET LOGISTIK ---{RESET}")
    if not listPaket:
        print("  (Belum ada data paket kiriman terdaftar)")
    else:
        no = 1
        for p in listPaket:
            print(f"  [Paket #{no}]")
            no += 1
            print(f"    Nomor Resi       : {p.getNomorResi()}")
            print(f"    Berat Fisik      : {p.getBeratKg():.2f} kg")
            print(f"    Deskripsi Barang : {p.getDeskripsiBarang()}")
            print("  -------------------------------------------------------")
    print()

# Fungsi 5: Menampilkan data fasilitas Depo Logistik (hanya informasi esensial agregasi)
def cetakDaftarDepo(daftarDepo):
    print(f"{BOLD}{RED}--- DATA FASILITAS DEPO LOGISTIK ---{RESET}")
    if not daftarDepo:
        print("  (Belum ada fasilitas depo logistik yang terdaftar di sistem)")
    else:
        no = 1
        for depo in daftarDepo:
            print(f"  [Depo #{no}: {depo.getKodeDepo()} - {depo.getKotaLokasi()}]")
            no += 1

            # Menampilkan daftar kendaraan Truk yang diagregasikan di depo ini (ID & Merk saja)
            print("    Kendaraan Truk    : ", end="")
            if not depo.getDaftarTruk():
                print("(Kosong)")
            else:
                print()
                for t in depo.getDaftarTruk():
                    print(f"      - {t.getIdKendaraan()} ({t.getMerkModel()})")

            # Menampilkan daftar kendaraan Kapal yang diagregasikan di depo ini (ID & Merk saja)
            print("    Kendaraan Kapal   : ", end="")
            if not depo.getDaftarKapal():
                print("(Kosong)")
            else:
                print()
                for k in depo.getDaftarKapal():
                    print(f"      - {k.getIdKendaraan()} ({k.getMerkModel()})")

            # Menampilkan daftar kendaraan Pesawat yang diagregasikan di depo ini (ID & Merk saja)
            print("    Kendaraan Pesawat : ", end="")
            if not depo.getDaftarPesawat():
                print("(Kosong)")
            else:
                print()
                for p in depo.getDaftarPesawat():
                    print(f"      - {p.getIdKendaraan()} ({p.getMerkModel()})")

            # Menampilkan daftar Paket yang diagregasikan di depo ini (Resi & Berat saja)
            print("    Paket Kiriman     : ", end="")
            if not depo.getDaftarPaket():
                print("(Kosong)")
            else:
                print()
                for p in depo.getDaftarPaket():
                    print(f"      - {p.getNomorResi()} ({p.getBeratKg():.2f} kg)")
            print("  -------------------------------------------------------")
    print()

# Fungsi 6: Menampilkan data Pengemudi dan penugasan kendaraan operasionalnya (Asosiasi)
def cetakDaftarPengemudi(listPenugasan):
    print(f"{BOLD}{GREEN}--- DAFTAR PENGEMUDI & PENUGASAN KENDARAAN ---{RESET}")
    if not listPenugasan:
        print("  (Belum ada data pengemudi dan penugasan kendaraan)")
    else:
        for pengemudi, kendaraan in listPenugasan:
            # Relasi Asosiasi: Pengemudi menerima objek kendaraan lewat parameter tampilkanTugas(kendaraan)
            pengemudi.tampilkanTugas(kendaraan)
    print()

# Fungsi 7: Menampilkan seluruh data sistem secara lengkap dan terstruktur
def cetakSeluruhData(listTruk, listKapal, listPesawat, listPaket, daftarDepo, listPenugasan):
    # 1. Tampilkan masing-masing jenis kendaraan secara terpisah dan lengkap
    cetakDaftarTruk(listTruk)
    cetakDaftarKapal(listKapal)
    cetakDaftarPesawat(listPesawat)

    # 2. Tampilkan daftar paket logistik
    cetakDaftarPaket(listPaket)

    # 3. Tampilkan data Depo Logistik (hanya informasi esensial agregasi kendaraan/paket)
    cetakDaftarDepo(daftarDepo)

    # 4. Tampilkan data Pengemudi dan penugasan kendaraan
    cetakDaftarPengemudi(listPenugasan)

# ============================================================================
# FUNGSI UTAMA (MAIN PROGRAM)
# ============================================================================
def main():
    # ------------------------------------------------------------------------
    # TAHAP 1: KONDISI AWAL KOSONG TOTAL
    # Menyiapkan wadah list kosong untuk membuktikan sistem dapat menangani
    # kondisi awal sebelum penambahan data dilakukan.
    # ------------------------------------------------------------------------
    listTruk = []
    listKapal = []
    listPesawat = []
    listPaket = []
    daftarDepo = []
    daftarPenugasan = []

    # ------------------------------------------------------------------------
    # TAHAP 2: MENAMPILKAN KONDISI SEBELUM DATA DITAMBAHKAN (KOSONG TOTAL)
    # ------------------------------------------------------------------------
    print()
    print("============================================================")
    print(f"{BOLD}{GREEN}=== >> KONDISI DATA SEBELUM DITAMBAHKAN << ==={RESET}")
    print("============================================================\n")

    cetakSeluruhData(listTruk, listKapal, listPesawat, listPaket, daftarDepo, daftarPenugasan)

    # ------------------------------------------------------------------------
    # TAHAP 3: PROSES PENAMBAHAN DATA
    # ------------------------------------------------------------------------

    # A. Fasilitas Depo Logistik (Hub Regional)
    depoMedan = DepoLogistik("DPO-MDN-01", "Medan Hub Sumatera (Pelabuhan Belawan)")
    depoMakassar = DepoLogistik("DPO-MKS-02", "Makassar Hub Timur (Pelabuhan Paotere)")

    # B. Komponen Mesin Kendaraan (Komposisi: tertanam di dalam kendaraan)
    mesinTruk1 = MesinKendaraan("ENG-VO-3310", "Volvo D13K Euro 6", "Bio Solar B35")
    mesinTruk2 = MesinKendaraan("ENG-SC-4100", "Scania DC13 Super 450", "Bio Solar B35")
    mesinTruk3 = MesinKendaraan("ENG-MB-2833", "Mercedes OM457LA BlueTec", "Bio Solar B35")

    mesinKapal1 = MesinKendaraan("ENG-WL-7720", "WinGD X72-B Dual Fuel", "Liquefied Natural Gas")
    mesinKapal2 = MesinKendaraan("ENG-YK-4412", "YanMar 6EY26W Marine", "Marine Diesel Oil")
    mesinKapal3 = MesinKendaraan("ENG-HD-9904", "Hyundai Himsen 9H32/40", "Heavy Fuel Oil")

    mesinPesawat1 = MesinKendaraan("ENG-PW-1100", "Pratt & Whitney PW1100G", "Avtur Jet A-1")
    mesinPesawat2 = MesinKendaraan("ENG-GE-NX01", "GE GEnx-2B67 High-Bypass", "Avtur Jet A-1")
    mesinPesawat3 = MesinKendaraan("ENG-RR-900X", "Rolls-Royce Trent 900", "Avtur Jet A-1")

    # C. Kendaraan Pengiriman (Hierarchical Inheritance & Komposisi)
    # Instansiasi objek Truk Kargo (Moda Darat)
    truk1 = TrukKargo("TRK-501", "Volvo FH16 Globetrotter", mesinTruk1, 12, 9500.0)
    truk2 = TrukKargo("TRK-502", "Scania R500 Heavy Hauler", mesinTruk2, 10, 8800.0)
    truk3 = TrukKargo("TRK-503", "Mercedes-Benz Actros 2642", mesinTruk3, 8, 7900.0)

    # Instansiasi objek Kapal Laut (Moda Laut)
    kapal1 = KapalLaut("KPL-601", "KM Temas Samudera", mesinKapal1, "Open Top & Flat Rack 40ft", 185000000.0)
    kapal2 = KapalLaut("KPL-602", "MV Tanto Bersatu", mesinKapal2, "Insulated Reefer Container", 225000000.0)
    kapal3 = KapalLaut("KPL-603", "KM Spil Nusantara", mesinKapal3, "General Cargo & ISO Tank", 270000000.0)

    # Instansiasi objek Pesawat Kargo (Moda Udara)
    pesawat1 = PesawatKargo("PSW-701", "Airbus A321-200P2F", mesinPesawat1, 39800, 38000000.0)
    pesawat2 = PesawatKargo("PSW-702", "Boeing 747-8F Freighter", mesinPesawat2, 43500, 160000000.0)
    pesawat3 = PesawatKargo("PSW-703", "McDonnell Douglas MD-11F", mesinPesawat3, 42000, 95000000.0)

    # D. Paket Kiriman Logistik (Kelas Data)
    paket1 = Paket("PKG-PY-2026-101", 62.8, "Perangkat Telekomunikasi & Fiber Optik")
    paket2 = Paket("PKG-PY-2026-102", 980.5, "Tekstil Serat Katun Organik Ekspor")
    paket3 = Paket("PKG-PY-2026-103", 5400.0, "Hasil Bumi Rempah Kayu Manis & Cengkeh")
    paket4 = Paket("PKG-PY-2026-104", 410.2, "Vaksin & Obat Kebutuhan Farmasi Lab")
    paket5 = Paket("PKG-PY-2026-105", 18200.0, "Pipa Baja Saluran Gas Minyak Bumi")

    # E. Personil Pengemudi / Operator Logistik (Kelas Operasional)
    pengemudi1 = Pengemudi("DRV-PY-01", "Dedi Setiawan", "SIM B2 Umum (Reg: 3171-4421-901)")
    pengemudi2 = Pengemudi("CPT-PY-02", "Capt. Ridwan Syahputra", "Master Mariner ANT-I (Reg: 6402-8813-112)")
    pengemudi3 = Pengemudi("PLT-PY-03", "Cpt. Fajar Nugraha", "ATPL Pilot License (Reg: 2104-5519-770)")
    pengemudi4 = Pengemudi("DRV-PY-04", "Surya Wijaya", "SIM B2 Umum Tronton (Reg: 3512-6634-802)")

    # Menambahkan objek ke dalam daftar master sistem
    listTruk = [truk1, truk2, truk3]
    listKapal = [kapal1, kapal2, kapal3]
    listPesawat = [pesawat1, pesawat2, pesawat3]
    listPaket = [paket1, paket2, paket3, paket4, paket5]

    # F. Penerapan Konsep AGREGASI: Objek kendaraan & paket dihubungkan ke Depo.
    # Kendaraan lintas rute (truk1, kapal1, pesawat1) diagregasikan pada kedua
    # Depo (Medan & Makassar)!

    # Alokasi ke Depo 1 (Medan Hub)
    depoMedan.tambahTruk(truk1)        # Truk rute bersama Medan - Makassar
    depoMedan.tambahTruk(truk2)        # Truk khusus Medan
    depoMedan.tambahKapal(kapal1)      # Kapal rute bersama Medan - Makassar
    depoMedan.tambahKapal(kapal2)      # Kapal khusus Medan
    depoMedan.tambahPesawat(pesawat1)  # Pesawat rute bersama Medan - Makassar
    depoMedan.tambahPesawat(pesawat2)  # Pesawat khusus Medan
    depoMedan.tambahPaket(paket1)
    depoMedan.tambahPaket(paket2)
    depoMedan.tambahPaket(paket3)

    # Alokasi ke Depo 2 (Makassar Hub)
    depoMakassar.tambahTruk(truk1)     # Truk rute bersama (terdaftar di kedua Depo)
    depoMakassar.tambahTruk(truk3)     # Truk khusus Makassar
    depoMakassar.tambahKapal(kapal1)   # Kapal rute bersama (terdaftar di kedua Depo)
    depoMakassar.tambahKapal(kapal3)   # Kapal khusus Makassar
    depoMakassar.tambahPesawat(pesawat1) # Pesawat rute bersama (terdaftar di kedua Depo)
    depoMakassar.tambahPesawat(pesawat3) # Pesawat khusus Makassar
    depoMakassar.tambahPaket(paket4)
    depoMakassar.tambahPaket(paket5)

    # Mendaftarkan kedua Fasilitas Depo ke dalam Sistem (Agregasi)
    daftarDepo.append(depoMedan)
    daftarDepo.append(depoMakassar)

    # G. Menghubungkan Penugasan Pengemudi dengan Kendaraan (Asosiasi)
    daftarPenugasan.append((pengemudi1, truk1))
    daftarPenugasan.append((pengemudi2, kapal1))
    daftarPenugasan.append((pengemudi3, pesawat1))
    daftarPenugasan.append((pengemudi4, truk3))

    # ------------------------------------------------------------------------
    # TAHAP 4: MENAMPILKAN KONDISI SESUDAH DATA DITAMBAHKAN
    # ------------------------------------------------------------------------
    print()
    print("============================================================")
    print(f"{BOLD}{GREEN}=== >> KONDISI DATA SESUDAH DITAMBAHKAN << ==={RESET}")
    print("============================================================\n")

    cetakSeluruhData(listTruk, listKapal, listPesawat, listPaket, daftarDepo, daftarPenugasan)

# ============================================================================
# ENTRY POINT PROGRAM
# ============================================================================
if __name__ == "__main__":
    main()
