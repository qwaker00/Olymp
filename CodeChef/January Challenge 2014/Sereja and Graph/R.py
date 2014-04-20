from fractions import Fraction

def R0(r1,r2,r3,r4,r5):
    i5 = (r2*r3 - r1*r4) / (r4*(r1+r5) + r3*(r4+r5))
    i0 = (r1 + r3) / r3 + (r1+r3+r5) / r3 * i5
    u0 = i5 * r1 + r1 + r2
    return u0 / i0
"""
R1  R2
  R5
R3  R4
"""
print R0(Fraction(1), Fraction(3), Fraction(2), Fraction(1), Fraction(3))
