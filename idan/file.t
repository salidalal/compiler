func foo() return int
{
	var a : int;
	a = 23;
	if (a == 23)
		a = 10;
	else
		a = 19;
	return a;
}


func fee(a, b : int) return int
{
	var sum1, sum2: int;
	sum1 = 0;
	sum2 = 0;
	while (a < b){
		if (a / 2 == 0 && (a * b < 100 || sum1 >= sum2 - a + b))
			sum1 = sum1 + a;
		else
			sum2 = sum2 + 1;
		a = a + 1;
	}
	return (sum1 + sum2);
}



proc Main()
{
	var a : int;
	var b : int;

	for(a=0; a < 10; a= a * 2) {
		b = foo();
		a = a + b;
		a = a + fee(a, b);
	}
}