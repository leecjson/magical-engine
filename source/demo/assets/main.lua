--require("debugger")("127.0.0.1", 10000, "luaidekey")

A = {
	a = "a field";
}

function A:go()
	print( self.a );
end

GA = nil;


function onCreate( a, b ) --> void

	magicalLog( "onCreate" .. a .. b );
	local q = Quaternion:createIdentity();

	local data = Data:create();

	A:go();

	--magicalLog( "GA: " .. GA );
	--magicalLog( string.format("%d", g_A) );

	--collectgarbage();


	return "return value", 333, 77.777;
    
end









