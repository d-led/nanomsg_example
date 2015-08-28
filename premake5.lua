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

function os_dependent_links()
	filter { 'system:linux' }
		links 'pthread'
	filter {}
end

filter { 'system:windows', 'architecture:x86' }
	includedirs { path.join(nanomsg_root,'win32/include') }
	libdirs { path.join(nanomsg_root,'win32/lib') }
	post_build_deploy(path.join(nanomsg_root,'win32/bin/*.dll'))
filter {}
	includedirs { './nano/include' }
	libdirs { './nano/lib' }

includedirs {
	'deps/cppnanomsg',
	'deps/sole'
}

make_console_app('cppnanomsg_check',{ 'deps/cppnanomsg/binding.cpp' })
links { 'nanomsg' }

make_console_app('worker',{
	'src/worker/worker.cpp',
	'deps/sole/sole.cpp',
	'src/common/*.h',
	'src/common/system_info.cpp',
})
links { 'nanomsg' }
os_dependent_links()
use_standard 'c++11'

make_console_app('server',{ 'src/server/server.cpp', 'deps/sole/sole.cpp' })
links { 'nanomsg' }
use_standard 'c++11'

make_console_app('stop_all',{ 'src/common/stop_all.cpp' })
links { 'nanomsg' }
use_standard 'c++11'
