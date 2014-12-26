--require("debugger")("127.0.0.1", 10000, "luaidekey")

function onCreate() --> void

	
    
end

function v( g )
end

function onCreate()

end


function onUpdate()

end

function 

end

function go()

	local q = Quaternion:createIdentity();
	local q2 = Quaternion:createAxisRotationX( 50 );

	local q3 = q * q2;

	local ea = q3:toEulerA();
	ea.yaw = 5;
	ea.pitch = 4;
	ea.roll = 2;

	q:getRotationAxis();
	q:getRotationAngle();

	local a = q:rotationAngle();

	local axis = q:GetrotationAxis();
	local angle = q:rotationAngle();

end










