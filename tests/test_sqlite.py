import subprocess
import os

class TestSQLite:

    CONNECT_COMMAND = ["./db.out", "mydb.db"]
    SELECT_BYTES = bytes("select", 'utf-8')
    EXIT_BYTES = bytes(".exit\n", 'utf-8')
    
    def generate_select_result(self, n:int) -> bytes:
        """
        Result for select command
        """
        result = ["$ "]
        for i in range(n):
            result.append(f"> ({i}, user{i}, person{i}@gmail.com)\n") 

        result.append("> Executed.\n$ !!! InputError: Cannot read input\n")
        result_bytes = bytes("".join(result), 'utf-8')
        return result_bytes

    def set_up(self):
        """
        Set up and populate the database
        """
        os.system("make db")
        proc = subprocess.Popen(self.CONNECT_COMMAND, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
        for i in range(20):
            proc.stdin.write(bytes(f"insert {i} user{i} person{i}@gmail.com\n", 'utf-8'))
        proc.stdin.write(self.EXIT_BYTES)
        proc.stdin.close()
        proc.wait()

    def tear_down(self):
        """
        Clean everything through makefile tools
        """
        os.system("make clean")

    def test_select(self):
        """
        Test Select Command
        """
        self.set_up()

        proc = subprocess.Popen(self.CONNECT_COMMAND, stdin=subprocess.PIPE, stdout=subprocess.PIPE)
        proc.stdin.write(self.SELECT_BYTES)
        proc.stdin.write(self.EXIT_BYTES)
        proc.stdin.close()
        output = proc.stdout.read()
        assert(output == self.generate_select_result(20))
        proc.stdout.close()

        self.tear_down()
