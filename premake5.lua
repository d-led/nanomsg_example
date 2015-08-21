include 'premake'

make_solution 'nanomsg_example'

nanomsg_root = 'deps/nanomsg-0.6'

function post_build_deploy(what)
	postbuildcommands {
		[[xcopy "]]..path.getabsolute(what):gsub('/','\\')..[[" "$(TargetDir)" /s /d /y]]
	}
end

filter { 'system:windows', 'architecture:x86' }
	includedirs { path.join(nanomsg_root,'win32/include') }
	libdirs { path.join(nanomsg_root,'win32/lib') }
	post_build_deploy(path.join(nanomsg_root,'win32/bin/*.dll'))
filter {}

make_console_app('cppnanomsg_check',{ 'deps/cppnanomsg/binding.cpp' })
links { 'nanomsg' }
run_target_after_build()
