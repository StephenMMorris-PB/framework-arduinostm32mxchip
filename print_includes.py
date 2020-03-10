import os

dirs = []

for root, _, files in os.walk("."):
    for name in files:
        if name.endswith(".h"):
            if root not in dirs:
                dirs.append(root)
                continue

for d in dirs:
    print d