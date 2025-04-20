# Mathematical Formulas Commonly Used in Competitive Programming

This document lists many important formulas and identities frequently encountered in competitive programming problems. Note that “all formulas” is vast, so below are some of the most common ones grouped by category.

---

## 1. Arithmetic & Series

- **Sum of the First n Natural Numbers**  
  S = n(n + 1) / 2

- **Arithmetic Progression (AP) Sum**  
  S = n/2 * [2a + (n – 1)d]  
  where a is the first term, d is the common difference.

- **Geometric Progression (GP) Sum**  
  S = a(1 – r^n) / (1 – r)  (for |r| ≠ 1)

---

## 2. Combinatorics

- **Permutations**
  P(n, r) = n! / (n - r)!

- **Combinations (Binomial Coefficient)**  
  C(n, k) = n! / (k! (n - k)!)  
  Often computed modulo a prime using precomputed factorials.

- **Binomial Theorem**  
  (x + y)^n = Σ (n choose k) * x^(n-k) * y^k,  for k = 0 to n

---

## 3. Number Theory

- **Greatest Common Divisor (Euclidean Algorithm)**  
  gcd(a, b) = gcd(b, a mod b)  
  with gcd(a, 0) = a

- **Least Common Multiple**  
  lcm(a, b) = |a * b| / gcd(a, b)

- **Modular Arithmetic Basics**  
  - (a + b) mod m = ((a mod m) + (b mod m)) mod m  
  - (a * b) mod m = ((a mod m) * (b mod m)) mod m  
  - (a - b) mod m = ((a mod m) - (b mod m) + m) mod m

- **Fast Modular Exponentiation**  
  Computes a^b mod m in O(log b) time.

- **Modular Multiplicative Inverse**  
  If m is prime, then a^(m-2) mod m is the inverse of a mod m.  
  Alternatively, use the Extended Euclidean Algorithm.

- **Euler's Totient Function**  
  φ(n) = n * ∏ (1 - 1/p) for each prime p dividing n

---

## 4. Geometry

- **Euclidean Distance**  
  d = sqrt((x2 - x1)^2 + (y2 - y1)^2)

- **Manhattan Distance**  
  d = |x2 - x1| + |y2 - y1|

- **Area of a Triangle (Using Coordinates)**  
  Area = |(x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)) / 2|

- **Line Equation (Two-Point Form)**  
  (y - y1) = ((y2 - y1)/(x2 - x1)) * (x - x1)

---

## 5. Recurrence Relations & Dynamic Programming

- **Fibonacci Sequence Recurrence**  
  F(n) = F(n-1) + F(n-2) with F(0)=0, F(1)=1  
  Often computed using matrix exponentiation for efficiency.

- **Matrix Exponentiation**  
  To solve linear recurrences in O(log n).  
  For example, Fibonacci numbers can be computed using:  
  | F(n+1) F(n)   | = |1 1|^n  
  | F(n)   F(n-1) |   |1 0|

---

## 6. Important Summation Formulas

- **Sum of Squares**  
  S = n(n + 1)(2n + 1) / 6

- **Sum of Cubes**  
  S = [n(n + 1)/2]^2

---

## 7. Logarithms & Exponents

- **Properties of Logarithms**  
  - log_b (xy) = log_b x + log_b y  
  - log_b (x/y) = log_b x - log_b y  
  - log_b (x^k) = k * log_b x


