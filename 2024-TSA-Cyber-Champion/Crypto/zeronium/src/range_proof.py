from utils import *
from inner_product import inner_product_prove, inner_product

def delta(y,z,p,n):
    sum_pow_2_y = sum([pow(y, i, p) for i in range(n)]) % p
    z_pow_3 = pow(z, 3, p)
    sum_2 = sum([pow(2, i, p) for i in range(n)]) % p
    return (((z - pow(z, 2, p)) * sum_pow_2_y) - (z_pow_3 * sum_2)) % p
    

class RangeProof:

    def __init__(self, size: int):
        self.n = 1 << (size - 1).bit_length()
        self.G = random_points(b'G', self.n)
        self.H = random_points(b'H', self.n)
        self.B = random_points(b'B', 1)
        self.B_blinding = random_points(b'B_blinding', 1)

        self.transcript = b""

    def commit(self, v: int, v_blinding: int):
        commitment = pedersen_commitment(v, v_blinding, self.B, self.B_blinding)
        self.transcript += point_to_bytes(commitment)

        return commitment
        

    def prove(self, v: int, v_blinding: int):
        
        p = curve.P256.q

        v = v % p

        a = [(v >> i) & 1 for i in range(self.n)]
        a_l = []
        a_r = []
        for ai in a:
            a_l += [ai]
            a_r += [(ai - 1) % p]

        s_l = [get_random_int() for _ in range(self.n)]
        s_r = [get_random_int() for _ in range(self.n)]

        a_blinding = get_random_int()
        s_blinding = get_random_int()

        A = multiexp(self.G, a_l) + multiexp(self.H, a_r) + a_blinding * self.B_blinding
        S = multiexp(self.G, s_l) + multiexp(self.H, s_r) + s_blinding * self.B_blinding

        self.transcript = point_to_bytes(A)
        self.transcript += point_to_bytes(S)

        y = challenge(self.transcript+b'y')
        z = challenge(self.transcript+b'z')

        l_0 = []
        l_1 = []
        r_0 = []
        r_1 = []
        exp_2 = 1
        exp_y = 1
        for i in range(self.n):
            l_0.append((a_l[i] - z) % p)
            l_1.append(s_l[i])

            r_0.append((exp_y * (a_r[i] + z) + z*z * exp_2) % p)
            r_1.append(exp_y * s_r[i] % p)

            exp_y *= y
            exp_2 += exp_2

        l_vecpoly = []
        r_vecpoly = []
        for i in range(self.n):
            l_vecpoly += [[l_0[i], l_1[i]]]
            r_vecpoly += [[r_0[i], r_1[i]]]

        t0 = inner_product(l_0, r_0)
        t2 = inner_product(l_1, r_1)

        l0_plus_l1 = [(a + b) % p for a,b in zip(l_0, l_1)]
        r0_plus_r1 = [(a + b) % p for a,b in zip(r_0, r_1)]

        t1 = (inner_product(l0_plus_l1, r0_plus_r1) - t0 - t2) % p
        t_poly = [t0, t1, t2]

        t1_blinding = get_random_int()
        t2_blinding = get_random_int()

        T1 = pedersen_commitment(t1, t1_blinding, self.B, self.B_blinding)
        T2 = pedersen_commitment(t2, t2_blinding, self.B, self.B_blinding)
        self.transcript += point_to_bytes(T1)
        self.transcript += point_to_bytes(T2)

        x = challenge(self.transcript+b'x')

        l_list = [(poly[0] + poly[1]*x) % p for poly in l_vecpoly]
        r_list = [(poly[0] + poly[1]*x) % p for poly in r_vecpoly]

        t = (t_poly[0] + t_poly[1]*x + t_poly[2]*x*x) % p

        t_blinding = (z*z * v_blinding + t1_blinding*x + t2_blinding*x*x) % p
        e_blinding = (a_blinding + s_blinding*x) % p

        self.transcript += int.to_bytes(t, 32, 'big')
        self.transcript += int.to_bytes(t_blinding, 32, 'big')
        self.transcript += int.to_bytes(e_blinding, 32, 'big')

        w = challenge(self.transcript+b'w')
        Q = w*self.B

        G = self.G
        Hprime = [pow(y, -i, p) * self.H[i] for i in range(self.n)]

        a,b,L,R,_ = inner_product_prove(l_list, r_list, G, Hprime, Q)

        return A,S,T1,T2,t,t_blinding,e_blinding,a,b,L,R

    def verify(self, A, S, T1, T2, t, t_blinding, e_blinding, a, b, L, R, commitment):

        p = curve.P256.q
        
        self.transcript = point_to_bytes(A)
        self.transcript += point_to_bytes(S)

        y = challenge(self.transcript+b'y')
        z = challenge(self.transcript+b'z')

        self.transcript += point_to_bytes(T1)
        self.transcript += point_to_bytes(T2)

        x = challenge(self.transcript+b'x')

        self.transcript += int.to_bytes(t, 32, 'big')
        self.transcript += int.to_bytes(t_blinding, 32, 'big')
        self.transcript += int.to_bytes(e_blinding, 32, 'big')

        w = challenge(self.transcript+b'w')
        c = get_random_int()

        ipa_transcript = b''
        for g in self.G:
            ipa_transcript += point_to_bytes(g)
        for i, h in enumerate(self.H):
            hprime = pow(y, -i, p) * h
            ipa_transcript += point_to_bytes(hprime)

        k = len(L)
        challenges = []
        challenges_inv = []

        all_inv = 1
        for i in range(k):
            ipa_transcript += point_to_bytes(L[i])
            ipa_transcript += point_to_bytes(R[i])

            u = challenge(ipa_transcript)
            challenges.append(pow(u, 2, p))
            challenges_inv.append(pow(u, -2, p))
            all_inv *= pow(u, -1, p)

        s = [all_inv]
        for i in range(1, self.n):
            lg_i = (32 - 1 - (32 - i.bit_length()))
            l = 1 << lg_i

            u_lg_i_sq = challenges[(k - 1) - lg_i]
            s.append(s[i - l] * u_lg_i_sq)

        scalar_mul_g = [(-z - a*s[i]) % p for i in range(self.n)]
        scalar_mul_h = []
        for i in range(self.n):
            s_inv = pow(s[i], -1, p)
            rhs = z*z * pow(2, i, p) - b * s_inv

            scalar_mul_h += [(z + pow(y, -i, p) * rhs) % p]

        points = [
            A,
            S,
            commitment,
            T1,
            T2,
            self.B,
            self.B_blinding,
        ] + self.G + self.H + L + R

        scalars = [
            1,
            x,
            c * z*z % p,
            c * x % p,
            c * x*x % p,
            (w*(t - a*b) + c*(delta(y, z, p, self.n) - t)) % p,
            (-e_blinding - c*t_blinding) % p,
        ] + scalar_mul_g + scalar_mul_h + challenges + challenges_inv

        check = multiexp(points, scalars)

        return check == point.Point.IDENTITY_ELEMENT