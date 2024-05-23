# logi_parser

logi_parser is a simple script to extract messages and their respective sequence number from the logi.bin file.

## Running script
Below is a example running the script on Linux Ubuntu.

```bash
python3 logi_parser.py ../logi.bin 
+-----------------+------------------------------------------+
| Sequence Number | Message                                  |
+-----------------+------------------------------------------+
  0               | Hello, welcome to Logitech!
+-----------------+------------------------------------------+
  1               | Open and Ourselves
                  | Hungry but Humble
                  | Collaborate but Challenge
                  | Decide and Do
                  | Equality and Environment
+-----------------+------------------------------------------+
  2               | This is the final message, Goodbye
+-----------------+------------------------------------------+

```
