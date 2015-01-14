--require("debugger")("127.0.0.1", 10000, "luaidekey")

gint = 5;
gdouble = 5.5
gstring = "gaaaafddsd";

MainCamera = { 
	x = 5.5,

	onCreate = function( self )
		magicalDebugLog( "MainCamera:onCreate " .. self.x );
	end
}

-- function MainCamera:onCreate( )
	
-- 	magicalDebugLog( "MainCamera:onCreate " .. self.x );
-- end

function func2( str_cpp )
	magicalDebugLog( str_cpp );
end

vec2 = nil;

function onCreate() --> void

	magicalDebugLog( vec2.x .. "  " .. vec2.y );
	--return func2;

	return true;
	--collectgarbage();
end









