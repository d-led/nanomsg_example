require 'rufus-scheduler'

scheduler = Rufus::Scheduler.new

def start(what,para)
	p = ''
	p = para unless para.nil?
	pipe = IO.popen(what + ' ' + p)
	pipe.each do |line|
	  puts line.chomp
	end
	pipe.close
end

def start_demo(what,para)
	absolute_path_to_executable = 	(
										(Dir.glob("bin/**/"+ what +".exe")) + 
										(Dir.glob("bin/**/"+ what      ))
									).max_by {|f| File.mtime(f)}

	# puts absolute_path_to_executable
	start(absolute_path_to_executable,para)
end

[
	['1s','worker'],
	['2s','server', 'tcp://localhost:7777 tcp://localhost:7778 tcp://localhost:7779'],
	['3s','worker', 'tcp://*:7778'],
	['3s','server', 'tcp://localhost:7777'],
	['4s','worker', 'tcp://*:7779'],
].each do |task|
	scheduler.in task[0] do
		puts "starting #{task[1]}"
		start_demo(task[1],task[2])
	end
end

scheduler.in '10s' do
  puts 'bye'
  exit
end

scheduler.in '30s' do
  puts 'strange'
  exit
end

scheduler.join
