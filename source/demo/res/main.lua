function go()
print("ok");
end

function onFinishLaunching() --> void

	magicalBeginObserveObject();

	local o = Object();
	o = Object();
	o = Object();
	o = Object();
	o = Object();
	o = nil;
	
	-- collectgarbage();
	
	magicalEndObserveObject(); -- 5
	
	o = Object();
	
	-- local a = function()
		-- print("ok");
	-- end
	
	o:getlua( go );

end

