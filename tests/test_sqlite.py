from subprocess import PIPE, Popen
import os


class TestSQLite:

    CONNECT_COMMAND = ["./db.out", "test_db.db"]

    SELECT_BYTES = bytes("select\n", 'utf-8')
    BTREE_BYTES = bytes(".btree\n", 'utf-8')
    EXIT_BYTES = bytes(".exit\n", 'utf-8')

    DEFAULT_TEST_SIZE = 15  # Default to 15

    # 2 leaf btree
    TWO_LEAF_BYTES_LIST = [
        "$ Tree:",
        "- internal (size 1)",
        "  - leaf (size 7)",
        "    - 1",
        "    - 2",
        "    - 3",
        "    - 4",
        "    - 5",
        "    - 6",
        "    - 7",
        "  - key 7",
        "  - leaf (size 8)",
        "    - 8",
        "    - 9",
        "    - 10",
        "    - 11",
        "    - 12",
        "    - 13",
        "    - 14",
        "    - 15",
        "$ "
    ]
    TWO_LEAF_BTREE_BYTES = bytes("\n".join(TWO_LEAF_BYTES_LIST), 'utf-8')

    def generate_select_result(self) -> bytes:
        """
        Result for select command
        """
        result = ["$ "]
        for i in range(1, self.DEFAULT_TEST_SIZE + 1):
            result.append(f"> ({i}, user{i}, person{i}@gmail.com)\n")

        result.append("> Executed.\n$ ")
        result_bytes = bytes("".join(result), 'utf-8')
        return result_bytes

    def generate_process(self, *argv) -> Popen:
        """
        Create a process with multiple inputs
        """
        proc = Popen(self.CONNECT_COMMAND, stdin=PIPE, stdout=PIPE)
        for arg in argv:
            proc.stdin.write(arg)
        proc.stdin.close()
        return proc

    def set_up(self) -> None:
        """
        Set up and populate the database
        """
        os.system("make compile")
        proc = Popen(self.CONNECT_COMMAND, stdin=PIPE, stdout=PIPE)
        for i in range(1, self.DEFAULT_TEST_SIZE + 1):
            proc.stdin.write(
                bytes(f"insert {i} user{i} person{i}@gmail.com\n", 'utf-8'))
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
        # set up
        self.set_up()

        # test
        proc: Popen = self.generate_process(self.SELECT_BYTES, self.EXIT_BYTES)
        output = proc.stdout.read()
        assert (output == self.generate_select_result())
        proc.stdout.close()

        # tear down
        self.tear_down()

    def test_btree(self) -> None:
        """
        Test the structure of btree
        """
        # set up
        self.set_up()

        # test
        proc = self.generate_process(self.BTREE_BYTES, self.EXIT_BYTES)
        output = proc.stdout.read()
        assert(output == self.TWO_LEAF_BTREE_BYTES)
        proc.stdout.close()

        # tear down
        self.tear_down()


if __name__ == "__main__":
    test = TestSQLite()
    test.test_btree()
