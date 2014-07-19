------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
-- magical type declaration list

local magical_reg_objs = {
	"Reference",
	"Data",
};

------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------



_is_functions = _is_functions or {}
_to_functions = _to_functions or {}
_push_functions = _push_functions or {}

_to_functions["LuaFunctionRef"] = "tolua_ext_tofunction"
_is_functions["LuaFunctionRef"] = "tolua_ext_isfunction"

local toWrite = {}
local currentString = ''
local out
local WRITE, OUTPUT = write, output

function output(s)
    out = _OUTPUT
    output = OUTPUT -- restore
    output(s)
end

function write(a)
    if out == _OUTPUT then
        currentString = currentString .. a
        if string.sub(currentString,-1) == '\n'  then
            toWrite[#toWrite+1] = currentString
            currentString = ''
        end
    else
        WRITE(a)
    end
end

function post_output_hook(package)
    local result = table.concat(toWrite)
    local function replace(pattern, replacement)
        local k = 0
        local nxt, currentString = 1, ''
        repeat
            local s, e = string.find(result, pattern, nxt, true)
            if e then
                currentString = currentString .. string.sub(result, nxt, s-1) .. replacement
                nxt = e + 1
                k = k + 1
            end
        until not e
        result = currentString..string.sub(result, nxt)
        if k == 0 then print('Pattern not replaced', pattern .. "\n") end
    end
	replace([[*((LuaFunctionRef*)]], [[(]])
	replace([[#ifndef TOLUA_RELEASE]], [[#ifdef MAG_DEBUG]])
	
	local size = table.getn(magical_reg_objs);
	for i=1,size do
		-- replace([[Mtolua_new((]] .. magical_reg_objs[i] ..  [[)())]], [[new]] .. magical_reg_objs[i] .. [[_LuaGC()]]);
		-- replace(
		-- [[const ]] .. magical_reg_objs[i] .. [[* self = (const ]] .. magical_reg_objs[i] .. [[*)  tolua_tousertype(tolua_S,1,0)]],
		-- [[const ]] .. magical_reg_objs[i] .. [[_t* self = ((const ]] .. magical_reg_objs[i] .. [[*) tolua_tousertype(tolua_S,1,0))->get()]]);
		
		replace(
		[[tolua_pushusertype(tolua_S,(void*)tolua_ret,"]] .. magical_reg_objs[i] .. [[");]],
		[[tolua_ret->retain();]] .. "\n" .. [[    tolua_pushusertype(tolua_S,(void*)(tolua_ret.get()),"]] .. magical_reg_objs[i] .. [[");]] .. "\n" ..  [[    tolua_register_gc(tolua_S,lua_gettop(tolua_S));]]);
		
		-- replace(magical_reg_objs[i] .. [[* tolua_ret = (]] .. magical_reg_objs[i] .. [[*)  ]] .. magical_reg_objs[i] .. [[::create();]],
		-- magical_reg_objs[i] .. [[* tolua_ret = (]] .. magical_reg_objs[i] .. [[*)  ]] .. magical_reg_objs[i] .. [[::create();]] .. "\n    " .. [[Shared<]] 
		-- .. magical_reg_objs[i] .. [[> auto_release = ]] .. [[Initializer<]] .. magical_reg_objs[i] .. [[>(tolua_ret);]])
		
		replace(
		magical_reg_objs[i] .. [[* tolua_ret = (]] ..  magical_reg_objs[i] .. [[*)]],
		[[Shared<]] .. magical_reg_objs[i] .. [[> tolua_ret = (Shared<]] .. magical_reg_objs[i] .. [[>)]]
		);

		replace(
		magical_reg_objs[i] .. [[* self = (]] .. magical_reg_objs[i] .. [[*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);]],
		magical_reg_objs[i] .. [[* self = (]] .. magical_reg_objs[i] .. [[*) tolua_tousertype(tolua_S,1,0);
	self->release();]]
		);
	end
	
    WRITE(result)
end

-- function print_lua_table (lua_table, indent)
	-- indent = indent or 0
	-- for k, v in pairs(lua_table) do
		-- if type(k) == "string" then
			-- k = string.format("%q", k)
		-- end
		-- local szSuffix = ""
		-- if type(v) == "table" then
			-- szSuffix = "{"
		-- end
		-- local szPrefix = string.rep("    ", indent)
		-- formatting = szPrefix.."["..k.."]".." = "..szSuffix
		-- if type(v) == "table" then
			-- print(formatting)
			-- print_lua_table(v, indent + 1)
			-- print(szPrefix.."},")
		-- else
			-- local szValue = ""
			-- if type(v) == "string" then
				-- szValue = string.format("%q", v)
			-- else
				-- szValue = tostring(v)
			-- end
			-- print(formatting..szValue..",")
		-- end
	-- end
-- end

-- function echo(t,n,saved)
-- saved = saved or {}
-- n = n or 0
-- for k in pairs(t) do
   -- local str = ''
   -- if n~=0 then
    -- local fmt = '%' .. 2*n .. 's'
    -- str = string.format(fmt, '')
   -- end
   -- io.write(str,tostring(k), ' = ')
   -- if type(t[k])=='table' then
    -- local m = n
    -- m = m+1
    -- if saved[t[k]] then
     -- io.write(saved[t[k]], '\n')
    -- else
     -- saved[t[k]] = k
     -- io.write('{\n')
     -- echo(t[k], m, saved)
     -- io.write(str,'}\n')
    -- end
   -- else
    -- io.write(tostring(t[k]),'\n')
   -- end
-- end
-- end

-- called right after processing the $[ichl]file directives,
-- right before processing anything else
-- takes the package object as the parameter
-- function preprocess_hook(p)
	-- -- p.code has all the input code from the pkg
	-- print("------------------------------------------\n\n\n")
	-- print_lua_table(p, nil);
	-- print("\n\n\n------------------------------------------")
-- end

-- called for every $ifile directive
-- takes a table with a string called 'code' inside, the filename, and any extra arguments
-- passed to $ifile. no return value
-- function include_file_hook(t, filename, ...)
	-- -- print("------------------------------------------\n\n\n")
	-- -- print_lua_table(t, nil);
	-- -- print("\n\n\n------------------------------------------")
-- end

-- called after processing anything that's not code (like '$renaming', comments, etc)
-- and right before parsing the actual code.
-- takes the Package object with all the code on the 'code' key. no return value
-- function preparse_hook(package)
	-- print("------------------------------------------\n\n\n")
	-- echo(package,nil, nil);
	-- print("\n\n\n------------------------------------------")
-- end

-- function echo_e(t,n,saved)
		-- saved = saved or {}
		-- n = n or 0
		-- for k in pairs(t) do
		   
		   -- if k == "type" 
		   -- and t["lname"] ~= nil
		   -- and t["cname"] ~= nil
		   -- and t["args"] ~= nil
		    -- and t["original_name"] ~= nil
		   -- then
			  -- if t["name"] ~= "delete" and t["name"] ~= "new" then
			     -- t["name"] = "get()->" .. t["name"];
			  -- end
		   -- end
		   
		   -- local str = ''
		   -- if n~=0 then
			-- local fmt = '%' .. 2*n .. 's'
			-- str = string.format(fmt, '')
		   -- end
		   -- io.write(str,tostring(k), ' = ')
		   -- if type(t[k])=='table' then
			-- local m = n
			-- m = m+1
			-- if saved[t[k]] then
			 -- io.write(saved[t[k]], '\n')
			-- else
			 -- saved[t[k]] = k
			 -- io.write('{\n')
			 -- echo_e(t[k], m, saved)
			 -- io.write(str,'}\n')
			-- end
		   -- else
			-- io.write(tostring(t[k]),'\n')
		   -- end
		-- end
		-- end

-- called before starting output
function pre_output_hook(package)
	-- function find_func( pkg )
		-- for i=1, #pkg  do
			-- if( pkg[i]["name"] ~= nil 
				-- and pkg[i]["lname"] ~= nil 
				-- and pkg[i]["type"] ~= nil
				-- and pkg[i]["original_name"] ~= nil ) then
				
				-- for j=1, #magical_reg_objs do
					-- if( pkg[i]["name"] == magical_reg_objs[j]
						-- and pkg[i]["lname"] == magical_reg_objs[j]
						-- and pkg[i]["type"] == magical_reg_objs[j]
						-- and pkg[i]["original_name"] == magical_reg_objs[j]) then
						
						-- local cls = pkg[i];
						-- for k=1, #cls do
							-- if( cls[k]["kind"] ~= nil 
								-- and cls[k]["kind"] == "func"
								-- and cls[k]["mod"] ~= nil 
								-- and cls[k]["mod"] ~= "static") then
								
								-- if( cls[k]["name"] ~= "delete" and cls[k]["name"] ~= "new"
									-- and cls[k]["lname"] ~= "delete" and cls[k]["lname"] ~= "new" ) then
									-- cls[k]["name"] = "get()->" .. cls[k]["name"];
								-- end
								
							-- end
						-- end
						
					-- end
				-- end
				
			-- end
		-- end
	-- end
	-- find_func( package );
	
	-- echo_e(package,nil,nil);
	-- package:print();
end

-- called from 'get_property_methods' to get the methods to retrieve a property
-- according to its type
-- function get_property_methods_hook(property_type, name)
	-- -- print("------------------------------------------\n\n\n")
	-- -- print("property_type: ".. property_type .. "   name: " .. name)
	-- -- print("\n\n\n------------------------------------------")
-- end

-- called from ClassContainer:doparse with the string being parsed
-- return nil, or a substring
-- function parser_hook(s)
	-- -- print("------------------------------------------\n\n\n")
	-- -- print(s);
	-- -- print("\n\n\n------------------------------------------")
	-- return nil
-- end

-- called from classFunction:supcode, before the call to the function is output
-- function pre_call_hook(f)
	-- -- print("------------------------------------------\n\n\n")
	-- -- echo(f,nil, nil);
	-- -- print("\n\n\n------------------------------------------")
-- end

-- called from classFunction:supcode, after the call to the function is output
-- function post_call_hook(f)
	-- -- print("------------------------------------------\n\n\n")
	-- -- echo(f,nil, nil);
	-- -- print("\n\n\n------------------------------------------")
-- end

-- called before the register code is output
-- function pre_register_hook(package)
	-- -- print("------------------------------------------\n\n\n")
	-- -- echo(package,nil, nil);
	-- -- print("\n\n\n------------------------------------------")
-- end

