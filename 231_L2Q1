cOne = 9
cTwo = 20
pOne = 1
pTwo = 20
resultmul = -1
resultadd = -1

def egcd(a, b):
    """return (g, x, y) such that a*x + b*y = g = gcd(a, b)"""
    if a == 0:
        return (b, 0, 1)
    else:
        g, x, y = egcd(b % a, a)
        return (g, y - (b // a) * x, x)
      

resultmul = ((cTwo - cOne) * egcd(pTwo-pOne,length)[1]) % length
resultadd = ((cOne-(resultmul*pOne)) * egcd(resultmul,length)[1]) % length


def decipher(mul, add,cipher):
  result = ((cipher - (mul*add))*egcd(mul,length)[1]) % length
  return result
  

for i in "TB242520C48GVV4S,0247J,04TB245,JTBZ":
  print(theAlphabet[decipher(5,26,theAlphabet.index(i)+1)-1],end="")
