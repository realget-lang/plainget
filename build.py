from dataclasses import field
import sys
import os

toCompile = []
argString = ""

# collects all the .cpp files and builds with them :sung:

for i in os.walk("realget"):
    parentDir = i[0]
    files = i[2]
    for f in files:
        if f.endswith(".cpp"):
            toCompile.append(f'{parentDir}/{f}')
            argString += f'{parentDir}/{f} '



#print(f"clang++ {argString} -o build/main")
if os.path.exists("build"):
    os.system(f"clang++ {argString} -o build/main")
else:
    os.mkdir("build")
    os.system(f"clang++ {argString} -o build/main")


