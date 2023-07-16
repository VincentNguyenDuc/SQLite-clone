import subprocess
import os

class TestSQLite:

    CONNECT_COMMAND = ["./db.out", "test_db.db"]
    SELECT_BYTES = bytes("select", 'utf-8')
    EXIT_BYTES = bytes(".exit\n", 'utf-8')
    DEFAULT_TEST_SIZE = 15 # Default to 15
    
    def generate_result(self) -> bytes:
        """
        Result for select command
        """
        result = ["$ "]
        for i in range(self.DEFAULT_TEST_SIZE):
            result.append(f"> ({i}, user{i}, person{i}@gmail.com)\n") 

        result.append("> Executed.\n$ !!! InputError: Cannot read input\n") # Need add this due to the wrong format when execute multiple commands at a time 
        result_bytes = bytes("".join(result), 'utf-8')
        return result_bytes

    def set_up(self) -> None:
        """
        Set up and populate the database
        """
        os.system("make compile")
        proc = subprocess.Popen(self.CONNECT_COMMAND, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
        for i in range(self.DEFAULT_TEST_SIZE):
            proc.stdin.write(bytes(f"insert {i} user{i} person{i}@gmail.com\n", 'utf-8'))
        proc.stdin.write(self.EXIT_BYTES)
        proc.stdin.close()
        proc.wait()

    def tear_down(self) -> None:
        """
        Clean everything through makefile tools
        """
        os.system("make clean")

    def test_simple(self) -> None:
        """
        A simple test 
        """
        self.set_up()

        proc = subprocess.Popen(self.CONNECT_COMMAND, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
        proc.stdin.write(self.SELECT_BYTES)
        proc.stdin.write(self.EXIT_BYTES)
        proc.stdin.close()
        output = proc.stdout.read()
        print(output.decode())
        assert(output == self.generate_result())
        proc.stdout.close()

        self.tear_down()

if __name__ == "__main__":
    test = TestSQLite()
    test.test_simple()