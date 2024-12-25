"""
source: https://chatgpt.com/share/6729a0f4-ebd0-800e-96bd-d2e2522210bb
"""
from py_ecc.optimized_bls12_381 import G1, G2, add, multiply, pairing, is_on_curve, neg
from py_ecc.optimized_bls12_381.optimized_curve import curve_order
import hashlib
import random

# Helper function to hash a message to a point on G1
def hash_to_G1(message: bytes) -> tuple:
    hash_val = int.from_bytes(hashlib.sha256(message).digest(), 'big') % curve_order
    return multiply(G1, hash_val)  # G1 is the generator point on the curve

# Generate a private key and corresponding public key
def generate_keys():
    sk = random.randint(1, curve_order - 1)  # Private key: a random integer in [1, curve_order - 1]
    pk = multiply(G2, sk)  # Public key: sk * G2
    return sk, pk

# Sign a message
def sign_message(sk: int, message: bytes) -> tuple:
    H_m = hash_to_G1(message)  # Hash message to a point on G1
    sigma = multiply(H_m, sk)  # Signature: sk * H(m)
    return sigma

# Verify a signature
def verify_signature(pk: tuple, message: bytes, signature: tuple) -> bool:
    H_m = hash_to_G1(message)  # Recompute H(m) on G1
    # Check if e(pk, H(m)) == e(G2, sigma)
    lhs = pairing(pk, H_m)      # Pairing of pk and H(m), ordered as (G2, G1)
    rhs = pairing(G2, signature) # Pairing of G2 and sigma
    return lhs == rhs

# Testing the implementation
if __name__ == "__main__":
    # Generate keys
    sk, pk = generate_keys()
    print("Private key:", sk)
    print("Public key:", pk)

    # Sign a message
    message = b"Hello, BLS!"
    signature = sign_message(sk, message)
    print("Signature:", signature)

    # Verify the signature
    is_valid = verify_signature(pk, message, signature)
    print("Signature valid:", is_valid)
