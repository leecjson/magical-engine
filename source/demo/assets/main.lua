--require("debugger")("127.0.0.1", 10000, "luaidekey")

function onCreate() --> void

	local q = Quaternion:createIdentity();
	magicalLog( string.format( "%f", q.w ) );
	magicalDebugLog( string.format( "%d", kBufferLen ) );
    
end









