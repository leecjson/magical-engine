------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
------------------------------------------------------------------
-- magical type declaration list

local magical_reg_objs = {
	"Object",
	"Node"
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
		replace([[Mtolua_new((]] .. magical_reg_objs[i] ..  [[)())]], [[new]] .. magical_reg_objs[i] .. [[_LuaGC()]]);
		-- replace(
		-- [[const ]] .. magical_reg_objs[i] .. [[* self = (const ]] .. magical_reg_objs[i] .. [[*)  tolua_tousertype(tolua_S,1,0)]],
		-- [[const ]] .. magical_reg_objs[i] .. [[_t* self = ((const ]] .. magical_reg_objs[i] .. [[*) tolua_tousertype(tolua_S,1,0))->get()]]);
	end
	replace([[self->]], [[self->get()->]]);
	
    WRITE(result)
end