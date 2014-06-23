function onFinishLaunching() --> void

	magicalBeginTickingAndReport();
	magicalBeginObserveObject();

	local o = Object();
	o = Object();
	o = Object();
	o = Object();
	o = Object();
	o = nil;
	
	collectgarbage();
	
	magicalEndObserveObject(); -- 5
	magicalEndTickingAndReport();

end

