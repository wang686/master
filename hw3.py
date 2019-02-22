d = {'A':0, 'B':0, 'C':0, 'D':0, 'E':0, 'F':0, 'G':0, 'H':0, 'I':0, 'J':0, 'K':0, 'L':0, 'M':0, 'N':0, 'O':0, 'P':0, 'Q':0, 'R':0, 'S':0, 'T':0, 'U':0, 'V':0, 'W':0, 'X':0, 'Y':0, 'Z':0}


theString = "KFMYGVVEMAWKYZKFWGRKFMSJJZGXOJMEMDJZMAMSCJGLFEJKTSFGJISTMZSWMKFMEJKBSXGJSFHPMJJIKFMEJKRMSZ"

for element in theString:
    d[element] = d[element] + 1
print(d)


maxD = 0
theElement = ""
for element in theString:
    if d[element] > maxD:
        maxD = d[element]
        theElement = element
print(theElement, maxD)
    
    
