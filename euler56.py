#!/usr/bin/env python

print max((sum(int(i) for i in str(a**b)) for a in range(90,101) for b in range(90,101)))
