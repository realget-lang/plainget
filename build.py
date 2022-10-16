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



# checks if there is a folder called 'build'
# if not, then create one.

if os.path.exists("build"):
    pass
else:
    os.mkdir("build")
    
# actually builds and checks if the build was
# successful or not, if not then prints
# the error code.

status = os.system(f"clang++ {argString} -o build/main")

if status == 0:
    print("\n>> Build successful!")
else:
    print("\nfailed with status", status)
