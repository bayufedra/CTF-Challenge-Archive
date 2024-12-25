# Writeup Vibe Check List v2

### Main idea
Ada seccomp yang membatasi penggunaan syscall sehingga ga bisa spawn shell. Jadi, cara solvenya pake `ORW`

### How

#### Phase 1
Ada overflow 9 bytes saat manggil fungsi `modifyTask`. Kita bisa overwrite pointer ke next list tapi ada semacam `encryption`. Kita bisa dapet key enkripsinya pada saat alokasi heap pertama kali, karena saat itu pointer nilainya masih 0. Karena kita dah dapet key buat enkripsi pointer, selanjutnya kita bisa dapet base heap address dengan cara dekrip pointer, lalu kurangin dengan offsetnya.Setalah dapet heap base dan key kita bisa control pointer next list kemana aja. Seperti versi sebelumnya, kita bisa memanfaatkan pointer ini untuk mendapatkan `Use-After-Free` meskipun setelah free, pointernya dah di null. Selanjutnya kita leak libc base address. Karena ukuran dari `malloc` kecil, untuk leak libc address di unsorted bin harus bikin fake chunk yang ukurannya lebih dari 0x420.

#### Phase 2
Sekarang kita udah dapet semua base address yang dibutuhkan. Tapi karena libc yang dipake versi 2.35 yang udah ga ada `hook`, kita harus ROP ke ret address di stack. Untuk leaks stack address kita bisa FSOP `environ` libc ke `_IO_2_1_stdout_`. Pake tcache poisoning untuk bisa write ke stdout, jangan lupa versi 2.35 ada safe-linking.

#### Phase 3
Lanjut kita ROP `orw` untuk baca file flagnya. Pertama `getdents` untuk dapet file namenya, terus pake `read` untuk baca filenya. Karena ROP chain kita pasti panjang, kita perlu membaginya menjadi 3 karena max input 0x50 bytes. Jangan lupa harus pastiin pointer link kita selalu pointer ke address yang valid, agar tetap bisa fungsi modif dan display task ga looping.

### Additional Notes