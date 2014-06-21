
function onFinishLaunching() --> void

	magicalLog("lua begin for");
	magicalBeginTimer();
	
	for i=0,20000 do
		magicalLog("for");
	end
	
	local t = magicalEndTimer();
	magicalLog("lua end for : " .. t .. "s");

end