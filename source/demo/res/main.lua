


function onFinishLaunching() --> void

	local o = Object();
	magicalLog(o:toString());
	
	local n = tolua.cast(o, "Node");
	magicalLog(n:toString());
	
	-- local n = Node();
	-- local o = 

end

