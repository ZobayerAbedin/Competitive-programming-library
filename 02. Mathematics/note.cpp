n = p1 ^ a1 * p2 ^ a2 * p3 ^a3 ...pk ^ ak

NOD(n) = (a1 + 1) * (a2 + 1) * ... (ak + 1)
SOD(n) = (p1 ^ (a1 + 1) - 1) / (p1 - 1) 
		* (p2 ^ (a2 + 1) - 1) / (p2 - 1) 
		* ... (pk ^ (ak + 1) - 1) / (pk - 1)
phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ...(1 - 1/pn)

// Euler's Thm, a ^ phi(m) = 1 mod m; a and m are coprime
Inverse of a number under mod = a^(-1) = a ^ (m- 2) mod m 
nCk = (n / k) * (n-1)C(k-1)

Stirling number of second kind: 
1 						  k = 1, n
S(n-1, k-1) + k*S(n-1, k) otherwise

O(1) formula with O(n) precalculation:
{n, k}=(1/k!)*for i=0 to k: (-1)^i * (kCi) * (k-i)^n

Catalan number:
Cn = 2nCn / (n + 1)

Derangement number:
0						  n = 1
1						  n = 2
(n-1) * dA(n-1) + dA(n-2) otherwise,
