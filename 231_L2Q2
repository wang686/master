theAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,. ;:!"
length = len(theAlphabet)
counter = {}
sortedDict = []
cOne = -1
cTwo = -1
pOne = 39
pTwo = 5
resultmul = -1
resultadd = -1

testinput1 = "ITTISQ"
testinput = "X0N30NL8Q98G4N1T0G8I4M83QNR8WR8D  .8WR8IQNLXWRYLQR,8WR1W4R498X08I4M84PPQWRL0182XW0Z8QZ8LX08R0I82NGPLQ4R4TGLW28KRWL,8SW 9"

def addDict(input):  
  for i in input:
    if i in counter:
      counter[i] = counter[i] + 1
    else:
      counter[i] = 1 #counter = sorted(counter) x.items(), key=lambda kv: kv[1]
      
def egcd(a, b):
    """return (g, x, y) such that a*x + b*y = g = gcd(a, b)"""
    if a == 0:
        return (b, 0, 1)
    else:
        g, x, y = egcd(b % a, a)
        return (g, y - (b // a) * x, x)
def decipher(mul, add,cipher):
  result = ((cipher - (mul*add))*egcd(mul,length)[1]) % length
  return result
  
addDict(testinput)
sortedDict = sorted(counter, key = counter.get, reverse = True)
cOne = theAlphabet.index(sortedDict[0]) + 1
cTwo = theAlphabet.index(sortedDict[1]) + 1

# solve for multiplcative key by multiplying the inverse of (p2-p1) on both side
resultmul = ((cTwo - cOne) * egcd(pTwo-pOne,length)[1]) % length
resultadd = ((cOne-(resultmul*pOne)) * egcd(resultmul,length)[1]) % length

for i in testinput:
  print(theAlphabet[decipher(resultmul,resultadd,theAlphabet.index(i)+1)-1],end="")
