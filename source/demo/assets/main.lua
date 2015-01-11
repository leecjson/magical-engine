--require("debugger")("127.0.0.1", 10000, "luaidekey")

A = {
	a = "a field";
}

B = { 
	b = 5;
	aref = nil;
}

function onCreate() --> void

	B.aref = A.a
	B.aref = "haha";

	magicalLog( "onCreate" .. B.aref .. A.a );

end









