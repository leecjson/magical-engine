function go()
print("ok");
end

a = {};

function onFinishLaunching() --> void

	magicalBeginTickingAndReport();
	magicalBeginObserveObjectAndReport();
	
	local o = Object();
	o = Object();
	o = Object();
	o = Object();
	o = Object();
	o = nil;
	-- collectgarbage();
	
	magicalEndObserveObjectAndReport(); -- 5
	magicalEndTickingAndReport();
	
	o = Object();
	
	-- local a = function()
		-- print("ok");
	-- end

end

