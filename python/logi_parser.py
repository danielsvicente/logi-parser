
import os
import sys

logi_file = sys.argv[1]
file_size = os.path.getsize(logi_file)

print('+-----------------+------------------------------------------+')
print('| Sequence Number | Message                                  |')
print('+-----------------+------------------------------------------+')

with open(logi_file, 'rb') as file:
    while file_size > 0:
        payload_size = int.from_bytes(file.read(4), 'little')       # PAYLOAD_HEADER
        sequece_number = int.from_bytes(file.read(4), 'little')     # SEQUENCE_NUMBER
        message = str(file.read(payload_size), encoding='utf-8')    # MESSAGE
        message = message.replace("\n", "\n                  | ")
        file_size = file_size - 4 - 4 - payload_size
        print(f'  {sequece_number}               | {message}')
        print('+-----------------+------------------------------------------+')
