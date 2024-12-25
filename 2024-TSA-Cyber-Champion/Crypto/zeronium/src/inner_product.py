from utils import *

def inner_product(a, b):
    return sum(a * b for a, b in zip(a, b)) % curve.P256.q

def split_half(data):
    mid_index = len(data) // 2
    return data[:mid_index], data[mid_index:]

def inner_product_prove(a: list, b: list, G: list, H: list, Q: point.Point):

    assert len(a) == len(b) == len(G) == len(H)

    transcript = b""

    for g in G:
        transcript += point_to_bytes(g)
    for h in H:
        transcript += point_to_bytes(h)

    ab = inner_product(a, b)

    commitment = pedersen_commitment(a, b, G, H) + ab * Q

    L_list = []
    R_list = []
    u_list = []

    n = len(a)
    while n != 1:
        n //= 2

        a_low, a_hi = split_half(a)
        b_low, b_hi = split_half(b)
        G_low, G_hi = split_half(G)
        H_low, H_hi = split_half(H)

        L = multiexp(G_hi, a_low) + multiexp(H_low, b_hi) + inner_product(a_low, b_hi) * Q
        R = multiexp(G_low, a_hi) + multiexp(H_hi, b_low) + inner_product(a_hi, b_low) * Q

        L_list.append(L)
        R_list.append(R)

        transcript += point_to_bytes(L)
        transcript += point_to_bytes(R)

        u = challenge(transcript)
        u_inv = pow(u, -1, curve.P256.q)
        u_list.append(u)

        for i in range(n):
            a_low[i] = (a_low[i] * u + a_hi[i] * u_inv) % curve.P256.q
            b_low[i] = (b_low[i] * u_inv + b_hi[i] * u) % curve.P256.q

            G_low[i] = multiexp([G_low[i], G_hi[i]], [u_inv, u])
            H_low[i] = multiexp([H_low[i], H_hi[i]], [u, u_inv])

        a = a_low
        b = b_low

        G = G_low
        H = H_low

    a = a[0]
    b = b[0]

    return a, b, L_list, R_list, commitment