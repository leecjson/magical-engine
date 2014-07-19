function onCreate() --> void

	magicalBeginObserve();

	local data = Data.create(Data);
	data:malloc(56);
	
	magicalLog("ok");
	
	fff = data;
	data = nil;
	fff = nil;
	
	collectgarbage();

	magicalEndObserve();

end

onCreate();



