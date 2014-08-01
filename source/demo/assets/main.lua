--require("debugger")("127.0.0.1", 10000, "luaidekey")

function onCreate() --> void

	local mat = Mat4();
	
	mat[0] = 5;
	
	print( mat[0] );
    
end

function go()
	
	MatrixStack:use( kModelView );
	MatrixStack:push();
	
	MatrixStack:pop();

end










