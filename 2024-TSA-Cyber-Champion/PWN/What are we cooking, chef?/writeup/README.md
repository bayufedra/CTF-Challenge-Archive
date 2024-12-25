# Writeup What are we cooking, chef?

### Main idea
Gain shell access

### How
Pertama leak libc address buat tau versi libcnya. Terus leak pie base dan stack. Overwrite tcache struct thread selanjutnya untuk point ke stack address. ROP ret2libc untuk dapet shell

### Additional Notes