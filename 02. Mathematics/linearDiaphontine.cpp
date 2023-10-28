int egcd(int a, int b, int &x, int &y) {
	if(a == 0) {
		x = 0, y = 1;
		return b;
	}
	int x1, y1;
	int g = egcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return g;
}

//Ax + By = C
bool linearDiophantine (int A, int B, int C, int &x, int &y ) {
	int g = __gcd(A, B);
 	if (C % g != 0 ) return false; //No Solution

 	int a = A / g, b = B / g, c = C / g;
 	g = egcd(a, b, x, y);  //Solve ax + by = 1
 	if (g < 0) {  //Make Sure gcd(a,b) = 1
 		a *= -1; b *= -1; c *= -1;
 	}
 	x *= c; y *= c; //ax + by = c
 	return true; //Solution Exists
 }
 // in main->
 //solution = {x + k * (B / g), y - k * (A / g)}; k = 0, 1, 2, 3, ...