include 'premake'

make_solution 'nanomsg_example'

nanomsg_root = 'deps/nanomsg-0.6'

function post_build_deploy(what)
	local command
	if os.get() == 'windows' then
		command = [[xcopy "]]..path.getabsolute(what):gsub('/','\\')..[[" "$(TargetDir)" /s /d /y]]
	else
		command = 'cp ' .. path.getabsolute(what) .. [[ "$(TARGETDIR)"]]
	end
	-- print(command)
	postbuildcommands {
		command
	}
end

filter { 'system:windows', 'architecture:x86' }
	includedirs { path.join(nanomsg_root,'win32/include') }
	libdirs { path.join(nanomsg_root,'win32/lib') }
	post_build_deploy(path.join(nanomsg_root,'win32/bin/*.dll'))
filter {}
	includedirs { './nano/include' }
	libdirs { './nano/lib' }

make_console_app('cppnanomsg_check',{ 'deps/cppnanomsg/binding.cpp' })
links { 'nanomsg' }
