import sys, re

n = sys.stdin.readline()
lines = """001100 *01100
001100 00110*
001100 101100
001100 001100**
001100 **001100
001100 *001*100
001100 001101
001100 001*100*
001100 *001*100*
001100 0011001
""".split('\n')[:-1]


for line in lines:
    string, pat = line.split(' ')
    pat = re.compile(pat.replace('?', '[A-z]').replace('*', '.*'))
    found = re.search(pat, string)
    if found:
        print(True)
    else:
        print(False)