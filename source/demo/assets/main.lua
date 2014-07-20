--require("debugger")("127.0.0.1", 10000, "luaidekey")

function onCreate() --> void

    magicalBeginObserve();

    local data = Data:create();
    data:malloc(56);

    local fff = data;
    data = nil;
    fff = nil;
    collectgarbage();

    magicalEndObserve();
end

onCreate();

function go() --> void
    local a = 5;
    local b = a;
end









