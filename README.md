# CCipher

Simple Caesar cipher program to encrypt and decrypt text files.

Use `make` or the task in the .vscode to build the project, then `build/ccipher [encrypt | decrypt] <file path>`.

Try with `build/ccipher encrypt test_directory/sample.txt` then `build/ccipher decrypt test_directory/sample.txt`. Reset the test directory with `make clean`.

```bash
$ build/ccipher encrypt test_directory/sample.txt

=> Wklv lv d vdpsoh whaw iloh iru hqfubswlrq.

build/ccipher decrypt test_directory/sample.txt

=> This is a sample text file for encryption.

```
