cd %~dp0../tolua++
toluapp-win32 -n common -L toluapp-basic.lua -o ../../source/magical-engine/src/magical-lua/binding/BindCommon.cpp ../magical-common/Include.pkg
pause