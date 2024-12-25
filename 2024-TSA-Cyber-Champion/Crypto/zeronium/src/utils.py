import random
import hashlib
from typing import Union
from fastecdsa import curve
from fastecdsa import point

def get_random_int():
    rand = random.SystemRandom()
    return rand.randint(1, curve.P256.q)

def pedersen_commitment(v: Union[list, int], vprime: Union[list, int], G: Union[list, point.Point], H: Union[list, point.Point]) -> point.Point:
    if isinstance(v, int):
        return v*G + vprime*H
    else:
        pts = G + H
        s = v + vprime

        return multiexp(pts, s) 

def challenge(data: bytes):
    return int.from_bytes(hashlib.sha256(data).digest(), 'big') % curve.P256.q

def point_to_bytes(pt: point.Point):
    return int.to_bytes(pt.x, 32, 'big') + int.to_bytes(pt.y, 32, 'big')

def bytes_to_point(b: bytes):
    assert len(b) == 64
    x = int.from_bytes(b[:32], 'big')
    y = int.from_bytes(b[32:], 'big')

    return point.Point(x, y)

def multiexp(points: list, scalars: list):

    result = scalars[0]*points[0]
    for i in range(1, len(points)):
        result += scalars[i]*points[i]

    return result

def mod_sqrt(n, p):
    assert pow(n, (p - 1) // 2, p) == 1
    return pow(n, (p + 1) // 4, p)

def is_quadratic_residue(n, p):
    return pow(n, (p - 1) // 2, p) == 1

def random_points(seed: bytes, size=1):
    points = []
    for i in range(size):
        while True:
            t = int.from_bytes(hashlib.sha256(seed).digest(), 'big') % curve.P256.p
            seed = hashlib.sha256(seed).digest()

            x = (-curve.P256.b * pow(1 + curve.P256.a * t*t, -1, curve.P256.p)) % curve.P256.p
            rhs = (x**3 + curve.P256.a * x + curve.P256.b) % curve.P256.p

            if is_quadratic_residue(rhs, curve.P256.p):
                y = mod_sqrt(rhs, curve.P256.p)
                points.append(point.Point(x,y))
                break
            else:
                x = (-x) % curve.P256.p
                rhs = (x**3 + curve.P256.a * x + curve.P256.b) % curve.P256.p

                if is_quadratic_residue(rhs, curve.P256.p):
                    y = mod_sqrt(rhs, curve.P256.p)
                    points.append(point.Point(x,y))
                    break


    return points[0] if size == 1 else points

def serialize_proof(A, S, T1, T2, t, t_blinding, e_blinding, a, b, L, R):

    s = point_to_bytes(A)+point_to_bytes(S)+point_to_bytes(T1)+point_to_bytes(T2)
    s += int.to_bytes(t, 32, 'big')
    s += int.to_bytes(t_blinding, 32, 'big')
    s += int.to_bytes(e_blinding, 32, 'big')
    s += int.to_bytes(a, 32, 'big')
    s += int.to_bytes(b, 32, 'big')

    for i in range(len(L)):
        s += point_to_bytes(L[i])
        s += point_to_bytes(R[i])

    return s.hex()

def deserialize_proof(hexproof: str):
    data = bytes.fromhex(hexproof)

    n = 64
    A = bytes_to_point(data[:n])
    S = bytes_to_point(data[n:n*2])
    T1 = bytes_to_point(data[n*2:n*3])
    T2 = bytes_to_point(data[n*3:n*4])
    t = int.from_bytes(data[n*4:n*4+32], 'big')
    t_blinding = int.from_bytes(data[n*4+32:n*4+64], 'big')
    e_blinding = int.from_bytes(data[n*4+64:n*4+96], 'big')
    a = int.from_bytes(data[n*4+96:n*4+96+32], 'big')
    b = int.from_bytes(data[n*4+96+32:n*4+96+64], 'big')

    rem = data[n*4+96+64:]

    k = len(rem) // 128
    L = []
    R = []
    for _ in range(k):
        L.append(bytes_to_point(rem[:n*1]))
        R.append(bytes_to_point(rem[n*1:n*2]))

        rem = rem[n*2:]

    return A,S,T1,T2,t,t_blinding,e_blinding,a,b,L,R