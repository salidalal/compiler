/% long
comment long
comment %/

func foo1(a, b, y :int; c: char) return bool
{
	var res : bool;
	{
		var x, b : char;
		var y: int;

		b = '&';
		/% a = x; %/ 
		/% b = 8; %/
		a = (y * 7)/a-y;
		/% a = (y * 7)/b-y; %/
		/% a = (y * 7)/a-c; %/

		res = (b == c) && (y > a);
		/% res = (b == c) && (y + a); %/
		/% 3 + 6 = 9; %/
		/% ^x = 6; %/
	}
    	return res ;
}


proc Main() /% return int %/
{
    var a : int;
    a = foo2();
}
