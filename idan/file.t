func foo1(a:bool) return bool
{
	return a;
}

proc Main() /% return int %/
{
    var a : bool;
    a = foo1(a);
}
