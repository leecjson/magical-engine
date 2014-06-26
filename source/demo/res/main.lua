
function onFinishLaunching() --> void

	magicalBeginTickingAndReport();
	magicalBeginObserveObjectAndReport();

	local o = Object();
	
	magicalEndObserveObjectAndReport(); -- 5
	magicalEndTickingAndReport();
	
	o = Object();
	
	-- local a = function()
		-- print("ok");
	-- end

end

