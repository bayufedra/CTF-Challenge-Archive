# Vibe Check List v2

by Lychnobyte

---

## Flag

```
TSA{1_d0n7_kn0w_h0w_y0u_c4n_r34d_7h1s_bu7_1_kn0w_y0ur_4ur4_1s_+1000000_5b27789b2a}
```

## Description
I got some reports that some hackers managed to get shells in previous versions. So, I decided to release a more secure version!

`nc <ip> 20058`

## Difficulty
Tingkat kesulitan soal: hard

## Hints
> Intentionally left empty

## Tags
Safe Linking, Use-After-Free, Tcache Poisoning, FSOP, ROP, Heap

## Deployment
- Install docker engine>=19.03.12 and docker-compose>=1.26.2.
- Run the container using:
    ```
    docker-compose up --build --detach
    ```

## Notes
Pakai GLIBC 2.35 Ubuntu 22.04.01 LTS (ada safe linking protection).