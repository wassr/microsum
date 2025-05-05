#!/usr/bin/env python3

import datetime

now = datetime.datetime.now(datetime.timezone.utc)
print(now.date(), end='')
