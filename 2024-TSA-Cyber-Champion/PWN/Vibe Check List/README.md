# Vibe Check List

by Lychnobyte

---

## Flag

```
TSA{y0u_4r3_my_h0m1e_n0w_b3c4us3_y0u_4r3_v1b1ng_4nd_g0t_s0m3_r1zz_t00_beb340723a}
```

## Description
Lemme check if you are vibing or nay

`nc <ip> 20048`

## Difficulty
Tingkat kesulitan soal: medium-hard

## Hints
> Intentionally left empty

## Tags
Off-By-Null, Tcache Poisoning, Safe Linking

## Deployment
- Install docker engine>=19.03.12 and docker-compose>=1.26.2.
- Run the container using:
    ```
    docker-compose up --build --detach
    ```

## Notes
Pakai GLIBC 2.33 milik ubuntu (libc6_2.33-0ubuntu9_amd64)