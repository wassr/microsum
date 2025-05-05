#!/usr/bin/env python3

import sys
from pathlib import Path

if len(sys.argv) != 2:
    exit(1)

base = Path(sys.argv[1])

head = base / '.git' / 'HEAD'

with open(head, 'r') as f:
    head_ref = f.readline().strip().split()[-1]

commit = base / '.git' / head_ref

with open(commit, 'r') as f:
    commit_hash = f.readline().strip()

print(commit_hash, end='')
