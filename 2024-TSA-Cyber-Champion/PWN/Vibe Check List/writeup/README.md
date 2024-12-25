# Writeup Vibe Check List

### Main idea
Isi free_hook dengan `system` lalu `free("/bin/sh")` untuk dapat akses shell

### How
#### Phase 1
Ada off-by-null karena input menggunakan `scanf` dan panjang = ukuran buffer. Off-by-null ini bakal overwrite next list pointer, jadi kita bisa atur ngarah kemana. Formulanya, sebut index yang punya address `xx00` sebagai index-X. Pertama free index-X - 1, kemudian free index-X, terus off-by-null pointer di index-X + 2. Sekarang kita punya `Use-After-Free` di index-X.

#### Phase 2
Dengan formula di phase 1, kita bisa leak heap address. Untuk leak libc address, kita perlu ngisi unsorted bins. Tapi karena malloc kita static sizenya 0x70 kita perlu bikin fake chunk yang ukurannya > 0x420. Tapi karena libc address di unsorted bin ada `0x00` atau null, jadi perlu kita ubah dulu jadi small bins, biar libc addressnya ngga ada null. Ada 2 cara yaitu bikin fake chunk di antara chunks dengan memperhatikan struct list atau edit chunk size di metadata. Di writeup aku pake cara 1.

#### Phase 3
Setelah dapet leak libc, kita tinggal pake tcache poisoning buat ngisi `free_hook` sama `system`. Caranya, edit index yang kita pake untuk leak heap untuk ngarah ke `free_hook`. Terus add task `/bin/sh` terus delete index yang berisi `/bin/sh`

### Additional Notes