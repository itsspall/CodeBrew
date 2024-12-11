# Save the README content into a file
# CodeBrew Cafe Management System

## Deskripsi
**CodeBrew** adalah aplikasi manajemen kafe sederhana berbasis terminal yang dibuat menggunakan bahasa C. Aplikasi ini memungkinkan pengguna untuk melakukan berbagai fungsi, seperti:
1. Pemesanan menu makanan dan minuman.
2. Reservasi meja.
3. Pembayaran dengan metode cash atau cashless.
4. Menyimpan data transaksi ke dalam file rekapitulasi untuk pelaporan.

Aplikasi ini dirancang untuk membantu operasional kafe dengan antarmuka sederhana dan sistem yang mudah digunakan.

---

## Cara Menggunakan

### 1. Menjalankan Aplikasi
Untuk menjalankan aplikasi, ikuti langkah berikut:
1. Kompilasi semua file `.c` menggunakan **GCC**:
   ```bash
   gcc main.c customer.c reservation.c payment.c menu.c welcome.c rekapitulasi.c -o codebrew
2. Jalankan program yang sudah dikompilasi
      ```bash
   ./codebrew

### 2. Fitur Utama
Setelah aplikasi dijalankan, Anda akan diarahkan ke menu utama. Berikut adalah fitur-fitur yang tersedia:
# 1. Login
   Masukkan username dan password.
   Default login:
   - Username: admin
   - Password: 1234
   Jika login berhasil, Anda akan diarahkan ke menu utama.
# 2. Pilih Menu
   - Pilih opsi 1. Pilih Menu di menu utama.
   - Masukkan nama pelanggan.
   - Lihat daftar menu yang tersedia dan pilih makanan atau minuman yang diinginkan.
   - Sistem akan menghitung total.
   - Lanjutkan ke pembayaran.

### 3. Pembayaran
Setelah memesan menu, Anda akan diminta untuk memilih metode pembayaran:
# 1. Cash:
   - Masukkan jumlah uang tunai.
   - Jika uang lebih besar dari total harga, sistem akan memberikan kembalian.
   - Jika uang kurang, ulangi pembayaran.
# 2. Cashless:
   - Masukkan nama akun pembayaran.
   - Masukkan password (maksimal 3 percobaan).
   - Jika saldo mencukupi, transaksi berhasil.
   - Jika saldo tidak mencukupi, Anda dapat memilih untuk:
      - Membatalkan pesanan.
      - Mengubah metode pembayaran menjadi cash.

### 4. Reservasi Meja
   - Pilih opsi 2. Reservasi Meja di menu utama.
   - Masukkan nomor meja yang ingin dipesan.
   - Masukkan nama pelanggan.
   - Tentukan waktu mulai dan selesai reservasi.
   - Sistem akan memvalidasi waktu dan menyimpan reservasi.
   - **Catatan:**
      - Jika waktu reservasi belum dimulai, meja akan ditandai sebagai **Sudah Dipesan.**
      - Jika waktu reservasi sedang berlangsung, meja akan ditandai sebagai **Sedang Dipesan.**
   - Setelah waktu reservasi selesai, meja akan otomatis kembali menjadi **Tersedia.**

### 5. Rekapitulasi
   - Pilih opsi 3. Rekapitulasi di menu utama.
   - Sistem akan menampilkan daftar transaksi yang telah disimpan ke dalam file rekapitulasi.txt.

### 6. Keluar
   - Pilih opsi 4. Keluar untuk keluar dari aplikasi.



# Struktur File
Aplikasi ini menggunakan pendekatan modular. Berikut adalah struktur file utama:

   - main.c: Fungsi utama yang menghubungkan semua fitur aplikasi.
   - customer.c: Berisi data pelanggan dan fungsi validasi akun untuk pembayaran cashless.
   - reservation.c: Berisi fungsi untuk reservasi meja.
   - payment.c: Berisi fungsi pembayaran (cash dan cashless).
   - menu.c: Berisi fungsi untuk menampilkan menu dan pemesanan.
   - welcome.c: Menampilkan layar sambutan.
   - admin.c: fungsi login
   - rekapitulasi.c: Menyimpan data transaksi ke file rekapitulasi.txt.

# Format Output Rekapitulasi
Transaksi yang berhasil akan disimpan ke dalam file rekapitulasi.txt dengan format sebagai berikut:

Nama Pelanggan: [Nama Pelanggan]
Waktu: [DD-MM-YYYY HH:MM:SS]
Pesanan: [Rincian Pesanan]
Total Harga: Rp [Total Harga]
Metode Pembayaran: [Cash/Cashless]
Nama Akun Pembayaran (jika cashless): [Nama Akun Pembayaran]
====================================
