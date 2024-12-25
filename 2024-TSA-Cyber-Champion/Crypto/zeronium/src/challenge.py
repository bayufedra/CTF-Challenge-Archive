from utils import get_random_int, bytes_to_point, point_to_bytes, serialize_proof, deserialize_proof, curve
from range_proof import RangeProof

FLAG = open('flag.txt', 'rb').read()

zk = RangeProof(32)

def prove():
    value = int(input("value: ")) % curve.P256.q
    v_blinding = get_random_int()
    print("Your secret blinding value is:", v_blinding)

    commitment = zk.commit(value, v_blinding)
    proof = zk.prove(value, v_blinding)

    print("Commitment:", point_to_bytes(commitment).hex())
    print("Proof:", serialize_proof(*proof))

def verify():
    commitment = bytes_to_point(bytes.fromhex(input("Commitment: ")))
    proof = deserialize_proof(input("Proof: "))

    if zk.verify(*proof, commitment):
        print("Your Proof is valid!")
        print()
        print("Do you want to reveal your value?")
        choice = input("(y/n)> ")

        if choice == "y":
            value = int(input("value: ")) % curve.P256.q
            blind_value = int(input("blinding value: ")) % curve.P256.q

            commitment = zk.commit(value, blind_value)

            if zk.verify(*proof, commitment):
                print("You are honest prover")

                if value > 2**32-1:
                    print("Wow! How do you do that?")
                    print(FLAG)
            else:
                print("You're liar!")

    else:
        print("Invalid proof! You must be lying about your value!")

if __name__ == '__main__':

    print("Welcome to zero-knowledge proof system \nwhere you can prove and verify that you know value v \nsuch that v is in range [0, 2**32-1] without revealing v")

    while True:
        print()
        print("Select menu:")
        print("1. Prove")
        print("2. Verify")
        print("3. Exit")

        print()
        choice = input("$> ")

        if choice == "1":
            try:
                prove()
            except Exception:
                print("No cheating allowed!")
                exit()
        elif choice == "2":
            try:
                verify()
            except Exception:
                print("No cheating allowed!")
                exit()
        else:
            break