# Save the README content into a file
readme_content = """
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
1. Login
   Masukkan username dan password.
   Default login:
   - Username: admin
   - Password: 1234
   Jika login berhasil, Anda akan diarahkan ke menu utama.
2. Pilih Menu
   - Pilih opsi 1. Pilih Menu di menu utama.
   - Masukkan nama pelanggan.
   - Lihat daftar menu yang tersedia dan pilih makanan atau minuman yang diinginkan.
   - Sistem akan menghitung total.
   - Lanjutkan ke pembayaran.
