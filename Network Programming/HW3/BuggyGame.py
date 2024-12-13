class BuggyGame:
    def __init__(self):
        pass

    def main(self, tcp_server):
        print("This is a buggy game")
        raise Exception("This is a bug")