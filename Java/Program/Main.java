// ============================================================================
// SISTEM LOGISTIK PENGIRIMAN MULTIMODA (TP3 DPBO)
// Program Utama dalam Bahasa Pemrograman Java
// ============================================================================

import java.util.ArrayList;
import java.util.List;

public class Main {
    // ========================================================================
    // DEKLARASI KODE WARNA ANSI TERMINAL (UNTUK MEMPERCANTIK OUTPUT)
    // ========================================================================
    public static final String RESET = "\u001B[0m";
    public static final String BOLD = "\u001B[1m";
    public static final String RED = "\u001B[31m";
    public static final String GREEN = "\u001B[32m";
    public static final String YELLOW = "\u001B[33m";
    public static final String BLUE = "\u001B[34m";
    public static final String MAGENTA = "\u001B[35m";
    public static final String CYAN = "\u001B[36m";

    // ========================================================================
    // KELAS STRUKTUR PENUGASAN (HELPER ASOSIASI PENGEMUDI & KENDARAAN)
    // ========================================================================
    public static class Penugasan {
        private Pengemudi pengemudi;
        private KendaraanPengiriman kendaraan;

        public Penugasan(Pengemudi pengemudi, KendaraanPengiriman kendaraan) {
            this.pengemudi = pengemudi;
            this.kendaraan = kendaraan;
        }

        public Pengemudi getPengemudi() {
            return this.pengemudi;
        }

        public KendaraanPengiriman getKendaraan() {
            return this.kendaraan;
        }
    }

    // ========================================================================
    // FUNGSI-FUNGSI PENAMPIL DATA (VERTIKAL / CARD STYLE)
    // ========================================================================

    // Fungsi 1: Menampilkan seluruh data kendaraan Truk Kargo secara vertikal
    public static void cetakDaftarTruk(List<TrukKargo> listTruk) {
        System.out.println(CYAN + "--- DAFTAR KENDARAAN TRUK KARGO (TRANSPORTASI DARAT) ---" + RESET);
        if (listTruk.isEmpty()) {
            System.out.println("  (Belum ada data kendaraan Truk Kargo terdaftar)");
        } else {
            int no = 1;
            for (TrukKargo t : listTruk) {
                System.out.println("  [Truk #" + (no++) + "]");
                // Memanggil method polimorfik spesifikasi truk kargo
                t.tampilkanSpesifikasi();
                System.out.println("  -------------------------------------------------------");
            }
        }
        System.out.println();
    }

    // Fungsi 2: Menampilkan seluruh data kendaraan Kapal Laut secara vertikal
    public static void cetakDaftarKapal(List<KapalLaut> listKapal) {
        System.out.println(BOLD + BLUE + "--- DAFTAR KENDARAAN KAPAL LAUT (TRANSPORTASI LAUT) ---" + RESET);
        if (listKapal.isEmpty()) {
            System.out.println("  (Belum ada data kendaraan Kapal Laut terdaftar)");
        } else {
            int no = 1;
            for (KapalLaut k : listKapal) {
                System.out.println("  [Kapal #" + (no++) + "]");
                // Memanggil method polimorfik spesifikasi kapal laut
                k.tampilkanSpesifikasi();
                System.out.println("  -------------------------------------------------------");
            }
        }
        System.out.println();
    }

    // Fungsi 3: Menampilkan seluruh data kendaraan Pesawat Kargo secara vertikal
    public static void cetakDaftarPesawat(List<PesawatKargo> listPesawat) {
        System.out.println(BOLD + MAGENTA + "--- DAFTAR KENDARAAN PESAWAT KARGO (TRANSPORTASI UDARA) ---" + RESET);
        if (listPesawat.isEmpty()) {
            System.out.println("  (Belum ada data kendaraan Pesawat Kargo terdaftar)");
        } else {
            int no = 1;
            for (PesawatKargo p : listPesawat) {
                System.out.println("  [Pesawat #" + (no++) + "]");
                // Memanggil method polimorfik spesifikasi pesawat kargo
                p.tampilkanSpesifikasi();
                System.out.println("  -------------------------------------------------------");
            }
        }
        System.out.println();
    }

    // Fungsi 4: Menampilkan seluruh daftar data Paket Logistik
    public static void cetakDaftarPaket(List<Paket> listPaket) {
        System.out.println(BOLD + YELLOW + "--- DAFTAR PAKET LOGISTIK ---" + RESET);
        if (listPaket.isEmpty()) {
            System.out.println("  (Belum ada data paket kiriman terdaftar)");
        } else {
            int no = 1;
            for (Paket p : listPaket) {
                System.out.println("  [Paket #" + (no++) + "]");
                System.out.println("    Nomor Resi       : " + p.getNomorResi());
                System.out.printf("    Berat Fisik      : %.2f kg%n", p.getBeratKg());
                System.out.println("    Deskripsi Barang : " + p.getDeskripsiBarang());
                System.out.println("  -------------------------------------------------------");
            }
        }
        System.out.println();
    }

    // Fungsi 5: Menampilkan data fasilitas Depo Logistik (hanya informasi esensial agregasi)
    public static void cetakDaftarDepo(List<DepoLogistik> daftarDepo) {
        System.out.println(BOLD + RED + "--- DATA FASILITAS DEPO LOGISTIK ---" + RESET);
        if (daftarDepo.isEmpty()) {
            System.out.println("  (Belum ada fasilitas depo logistik yang terdaftar di sistem)");
        } else {
            int no = 1;
            for (DepoLogistik depo : daftarDepo) {
                System.out.println("  [Depo #" + (no++) + ": " + depo.getKodeDepo() + " - " + depo.getKotaLokasi() + "]");

                // Menampilkan daftar kendaraan Truk yang diagregasikan di depo ini (ID & Merk saja)
                System.out.print("    Kendaraan Truk    : ");
                if (depo.getDaftarTruk().isEmpty()) {
                    System.out.println("(Kosong)");
                } else {
                    System.out.println();
                    for (TrukKargo t : depo.getDaftarTruk()) {
                        System.out.println("      - " + t.getIdKendaraan() + " (" + t.getMerkModel() + ")");
                    }
                }

                // Menampilkan daftar kendaraan Kapal yang diagregasikan di depo ini (ID & Merk saja)
                System.out.print("    Kendaraan Kapal   : ");
                if (depo.getDaftarKapal().isEmpty()) {
                    System.out.println("(Kosong)");
                } else {
                    System.out.println();
                    for (KapalLaut k : depo.getDaftarKapal()) {
                        System.out.println("      - " + k.getIdKendaraan() + " (" + k.getMerkModel() + ")");
                    }
                }

                // Menampilkan daftar kendaraan Pesawat yang diagregasikan di depo ini (ID & Merk saja)
                System.out.print("    Kendaraan Pesawat : ");
                if (depo.getDaftarPesawat().isEmpty()) {
                    System.out.println("(Kosong)");
                } else {
                    System.out.println();
                    for (PesawatKargo p : depo.getDaftarPesawat()) {
                        System.out.println("      - " + p.getIdKendaraan() + " (" + p.getMerkModel() + ")");
                    }
                }

                // Menampilkan daftar Paket yang diagregasikan di depo ini (Resi & Berat saja)
                System.out.print("    Paket Kiriman     : ");
                if (depo.getDaftarPaket().isEmpty()) {
                    System.out.println("(Kosong)");
                } else {
                    System.out.println();
                    for (Paket p : depo.getDaftarPaket()) {
                        System.out.printf("      - %s (%.2f kg)%n", p.getNomorResi(), p.getBeratKg());
                    }
                }
                System.out.println("  -------------------------------------------------------");
            }
        }
        System.out.println();
    }

    // Fungsi 6: Menampilkan data Pengemudi dan penugasan kendaraan operasionalnya (Asosiasi)
    public static void cetakDaftarPengemudi(List<Penugasan> listPenugasan) {
        System.out.println(BOLD + GREEN + "--- DAFTAR PENGEMUDI & PENUGASAN KENDARAAN ---" + RESET);
        if (listPenugasan.isEmpty()) {
            System.out.println("  (Belum ada data pengemudi dan penugasan kendaraan)");
        } else {
            for (Penugasan item : listPenugasan) {
                // Relasi Asosiasi: Pengemudi menerima objek kendaraan lewat parameter tampilkanTugas(kendaraan)
                item.getPengemudi().tampilkanTugas(item.getKendaraan());
            }
        }
        System.out.println();
    }

    // Fungsi 7: Menampilkan seluruh data sistem secara lengkap dan terstruktur
    public static void cetakSeluruhData(List<TrukKargo> listTruk, List<KapalLaut> listKapal,
                                        List<PesawatKargo> listPesawat, List<Paket> listPaket,
                                        List<DepoLogistik> daftarDepo, List<Penugasan> listPenugasan) {
        // 1. Tampilkan masing-masing jenis kendaraan secara terpisah dan lengkap
        cetakDaftarTruk(listTruk);
        cetakDaftarKapal(listKapal);
        cetakDaftarPesawat(listPesawat);

        // 2. Tampilkan daftar paket logistik
        cetakDaftarPaket(listPaket);

        // 3. Tampilkan data Depo Logistik (hanya informasi esensial agregasi kendaraan/paket)
        cetakDaftarDepo(daftarDepo);

        // 4. Tampilkan data Pengemudi dan penugasan kendaraan
        cetakDaftarPengemudi(listPenugasan);
    }

    // ========================================================================
    // FUNGSI UTAMA (MAIN PROGRAM)
    // ========================================================================
    public static void main(String[] args) {
        // --------------------------------------------------------------------
        // TAHAP 1: KONDISI AWAL KOSONG TOTAL
        // Menyiapkan wadah list kosong untuk membuktikan sistem dapat menangani
        // kondisi awal sebelum penambahan data dilakukan.
        // --------------------------------------------------------------------
        List<TrukKargo> listTruk = new ArrayList<>();
        List<KapalLaut> listKapal = new ArrayList<>();
        List<PesawatKargo> listPesawat = new ArrayList<>();
        List<Paket> listPaket = new ArrayList<>();
        List<DepoLogistik> daftarDepo = new ArrayList<>();
        List<Penugasan> daftarPenugasan = new ArrayList<>();

        // --------------------------------------------------------------------
        // TAHAP 2: MENAMPILKAN KONDISI SEBELUM DATA DITAMBAHKAN (KOSONG TOTAL)
        // --------------------------------------------------------------------
        System.out.println();
        System.out.println("============================================================");
        System.out.println(BOLD + GREEN + "=== >> KONDISI DATA SEBELUM DITAMBAHKAN << ===" + RESET);
        System.out.println("============================================================\n");

        cetakSeluruhData(listTruk, listKapal, listPesawat, listPaket, daftarDepo, daftarPenugasan);

        // --------------------------------------------------------------------
        // TAHAP 3: PROSES PENAMBAHAN DATA
        // --------------------------------------------------------------------

        // A. Fasilitas Depo Logistik (Hub Regional)
        DepoLogistik depoSemarang = new DepoLogistik("DPO-SMG-01", "Semarang Hub Jawa Tengah (Pelabuhan Tanjung Emas)");
        DepoLogistik depoBalikpapan = new DepoLogistik("DPO-BPN-02", "Balikpapan Hub Kalimantan (Pelabuhan Semayang)");

        // B. Komponen Mesin Kendaraan (Komposisi: tertanam di dalam kendaraan)
        MesinKendaraan mesinTruk1 = new MesinKendaraan("ENG-MAN-5012", "MAN D2676 Common Rail", "Dexlite CN-51");
        MesinKendaraan mesinTruk2 = new MesinKendaraan("ENG-DAF-6621", "PACCAR MX-13 Multi-Torque", "Dexlite CN-51");
        MesinKendaraan mesinTruk3 = new MesinKendaraan("ENG-UD-8840", "GH11E Clean Diesel", "Dexlite CN-51");

        MesinKendaraan mesinKapal1 = new MesinKendaraan("ENG-WTS-3320", "Wartsila 31DF Multi-Fuel", "Ultra Low Sulfur Fuel");
        MesinKendaraan mesinKapal2 = new MesinKendaraan("ENG-DK-5511", "Daihatsu 6DE-23 Marine", "Marine Gas Oil");
        MesinKendaraan mesinKapal3 = new MesinKendaraan("ENG-MTU-7703", "MTU 20V 4000 M93L", "Marine Diesel");

        MesinKendaraan mesinPesawat1 = new MesinKendaraan("ENG-IAE-2500", "IAE V2500-A5 Turbofan", "Avtur Jet A-1");
        MesinKendaraan mesinPesawat2 = new MesinKendaraan("ENG-CF6-80C2", "General Electric CF6-80C2", "Avtur Jet A-1");
        MesinKendaraan mesinPesawat3 = new MesinKendaraan("ENG-LEAP-1B", "CFM LEAP-1B Eco-Turbofan", "Avtur Jet A-1");

        // C. Kendaraan Pengiriman (Hierarchical Inheritance & Komposisi)
        // Instansiasi objek Truk Kargo (Moda Darat)
        TrukKargo truk1 = new TrukKargo("TRK-801", "MAN TGX 26.540 Individual", mesinTruk1, 10, 9100.0);
        TrukKargo truk2 = new TrukKargo("TRK-802", "DAF XF 480 Super Space", mesinTruk2, 8, 8200.0);
        TrukKargo truk3 = new TrukKargo("TRK-803", "UD Trucks Quester CWE 370", mesinTruk3, 10, 8900.0);

        // Instansiasi objek Kapal Laut (Moda Laut)
        KapalLaut kapal1 = new KapalLaut("KPL-901", "KM Dharma Kencana", mesinKapal1, "Open Top & High Cube 40ft", 190000000.0);
        KapalLaut kapal2 = new KapalLaut("KPL-902", "MV Samudera Borneo", mesinKapal2, "Refrigerated Container 20ft", 230000000.0);
        KapalLaut kapal3 = new KapalLaut("KPL-903", "KM Mentari Mas", mesinKapal3, "Breakbulk & Heavy Project", 285000000.0);

        // Instansiasi objek Pesawat Kargo (Moda Udara)
        PesawatKargo pesawat1 = new PesawatKargo("PSW-301", "Boeing 757-200PCF", mesinPesawat1, 42000, 48000000.0);
        PesawatKargo pesawat2 = new PesawatKargo("PSW-302", "Airbus A300-600RF", mesinPesawat2, 40000, 75000000.0);
        PesawatKargo pesawat3 = new PesawatKargo("PSW-303", "Boeing 737-800SF", mesinPesawat3, 41000, 36000000.0);

        // D. Paket Kiriman Logistik (Kelas Data)
        Paket paket1 = new Paket("PKG-JV-2026-301", 85.0, "Komponen Server Jaringan Komputasi Cloud");
        Paket paket2 = new Paket("PKG-JV-2026-302", 1450.0, "Bahan Baku Keramik Porselen Industri");
        Paket paket3 = new Paket("PKG-JV-2026-303", 6700.0, "Komoditas Minyak Atsiri & Gaharu Alam");
        Paket paket4 = new Paket("PKG-JV-2026-304", 510.5, "Alat Diagnostik Laboratorium Biokimia");
        Paket paket5 = new Paket("PKG-JV-2026-305", 14200.0, "Konstruksi Turbin Pembangkit Listrik");

        // E. Personil Pengemudi / Operator Logistik (Kelas Operasional)
        Pengemudi pengemudi1 = new Pengemudi("DRV-JV-01", "Gunawan Prasetyo", "SIM B2 Umum (Reg: 3374-1102-339)");
        Pengemudi pengemudi2 = new Pengemudi("CPT-JV-02", "Capt. Bagus Wicaksono", "Master Mariner ANT-I (Reg: 7101-5524-819)");
        Pengemudi pengemudi3 = new Pengemudi("PLT-JV-03", "Cpt. Dimas Anggara", "ATPL Pilot License (Reg: 1205-9931-404)");
        Pengemudi pengemudi4 = new Pengemudi("DRV-JV-04", "Tri Hartanto", "SIM B2 Umum Gandeng (Reg: 3404-7718-205)");

        // Menambahkan objek ke dalam daftar master sistem
        listTruk.add(truk1);
        listTruk.add(truk2);
        listTruk.add(truk3);

        listKapal.add(kapal1);
        listKapal.add(kapal2);
        listKapal.add(kapal3);

        listPesawat.add(pesawat1);
        listPesawat.add(pesawat2);
        listPesawat.add(pesawat3);

        listPaket.add(paket1);
        listPaket.add(paket2);
        listPaket.add(paket3);
        listPaket.add(paket4);
        listPaket.add(paket5);

        // F. Penerapan Konsep AGREGASI: Objek kendaraan & paket dihubungkan ke Depo.
        // Kendaraan lintas rute (truk1, kapal1, pesawat1) diagregasikan pada kedua
        // Depo (Semarang & Balikpapan)!

        // Alokasi ke Depo 1 (Semarang Hub)
        depoSemarang.tambahTruk(truk1);        // Truk rute bersama Semarang - Balikpapan
        depoSemarang.tambahTruk(truk2);        // Truk khusus Semarang
        depoSemarang.tambahKapal(kapal1);      // Kapal rute bersama Semarang - Balikpapan
        depoSemarang.tambahKapal(kapal2);      // Kapal khusus Semarang
        depoSemarang.tambahPesawat(pesawat1);  // Pesawat rute bersama Semarang - Balikpapan
        depoSemarang.tambahPesawat(pesawat2);  // Pesawat khusus Semarang
        depoSemarang.tambahPaket(paket1);
        depoSemarang.tambahPaket(paket2);
        depoSemarang.tambahPaket(paket3);

        // Alokasi ke Depo 2 (Balikpapan Hub)
        depoBalikpapan.tambahTruk(truk1);     // Truk rute bersama (terdaftar di kedua Depo)
        depoBalikpapan.tambahTruk(truk3);     // Truk khusus Balikpapan
        depoBalikpapan.tambahKapal(kapal1);   // Kapal rute bersama (terdaftar di kedua Depo)
        depoBalikpapan.tambahKapal(kapal3);   // Kapal khusus Balikpapan
        depoBalikpapan.tambahPesawat(pesawat1); // Pesawat rute bersama (terdaftar di kedua Depo)
        depoBalikpapan.tambahPesawat(pesawat3); // Pesawat khusus Balikpapan
        depoBalikpapan.tambahPaket(paket4);
        depoBalikpapan.tambahPaket(paket5);

        // Mendaftarkan kedua Fasilitas Depo ke dalam Sistem (Agregasi)
        daftarDepo.add(depoSemarang);
        daftarDepo.add(depoBalikpapan);

        // G. Menghubungkan Penugasan Pengemudi dengan Kendaraan (Asosiasi)
        daftarPenugasan.add(new Penugasan(pengemudi1, truk1));
        daftarPenugasan.add(new Penugasan(pengemudi2, kapal1));
        daftarPenugasan.add(new Penugasan(pengemudi3, pesawat1));
        daftarPenugasan.add(new Penugasan(pengemudi4, truk3));

        // --------------------------------------------------------------------
        // TAHAP 4: MENAMPILKAN KONDISI SESUDAH DATA DITAMBAHKAN
        // --------------------------------------------------------------------
        System.out.println();
        System.out.println("============================================================");
        System.out.println(BOLD + GREEN + "=== >> KONDISI DATA SESUDAH DITAMBAHKAN << ===" + RESET);
        System.out.println("============================================================\n");

        cetakSeluruhData(listTruk, listKapal, listPesawat, listPaket, daftarDepo, daftarPenugasan);
    }
}
