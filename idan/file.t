func foo4() return int
{
    {   
	var x : int;
	var y : int*;
	x = 5;
	y = &x;
	x = 6;
	if (&x == y && ^y == x){
		x = 9;
	}
     	{
		var x : char*;
		var y : string[ 10];
		var z : char;
		y = "foobar";
		x = &y[ 5];         

		y = "barfoo"; 
   		{
			var x : char;
			var y : int*;
			var z : char*;
			var g : char;
			/% y = &(1+3);
			y = &x;             
			z = &(&g); %/
    		}
	}
     }
    return 0;
}

