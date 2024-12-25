from py_ecc.optimized_bls12_381 import normalize, FQ

import bls

FLAG = open('flag.txt', 'rb').read()

class Challenge:

    def __init__(self):
        sk, pk = bls.generate_keys()
        self.sk = sk
        self.pk = pk
        self.is_login = False
        self.current_user = None

    def serialize(self, point):
        xy = normalize(point)
        b = int.to_bytes(int(xy[0]), 48, 'big')
        b += int.to_bytes(int(xy[1]), 48, 'big')

        return b.hex()

    def deserialize(self, token):
        token = bytes.fromhex(token)
        assert len(token) == 96

        x = int.from_bytes(token[:48], 'big')
        y = int.from_bytes(token[48:], 'big')

        return (FQ(x), FQ(y), FQ(1))

    def signup(self, username: str):
        
        signature = bls.sign_message(self.sk, username.encode())
        token = self.serialize(signature)

        return token
    
    def signin(self, username: str, token: str):

        try:
            signature = self.deserialize(token)
            is_valid = bls.verify_signature(self.pk, username.encode(), signature)

            if is_valid:
                return True
            else:
                return False
        except Exception:
            return False
        
    def menu(self):

        print(">>>>>>>>>>>>>>>>>>>>")
        print("Select your action:")
        if self.is_login:
            print("1. Whoami")
            print("2. Get flag")
            print("3. Logout")
            print("4. Exit")
            print()

            choice = input("$> ")
            if choice == "1":
                print(self.current_user)
            elif choice == "2":
                if self.current_user == 'admin':
                    print(FLAG)
                else:
                    print("Permission denied!")
            elif choice == "3":
                self.current_user = None
                self.is_login = False
            else:
                exit()
        else:
            print("1. Sign In")
            print("2. Sign Up")
            print("3. Exit")
            print()

            choice = input("$> ")
            if choice == "1":
                username = input("Username: ")
                token = input("Token: ")

                if self.signin(username, token):
                    print("Sign-in success!")
                    self.current_user = username
                    self.is_login = True
                else:
                    print("Invalid credentials!")

            elif choice == "2":
                username = input("Username: ")

                if username == 'admin':
                    print("Username is system-reserved!")
                else:
                    token = self.signup(username)
                    print("Sign-up success!")
                    print("Here's your credential token:", token)
            else:
                exit()
        
if __name__ == '__main__':

    challenge = Challenge()

    while True:
        challenge.menu()