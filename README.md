## nanomsg example ##

== [cppnanomsg](https://github.com/nanomsg/cppnanomsg) + [sole (uuid)](https://github.com/r-lyeh/sole) + [premake](https://github.com/d-led/premake-meta-cpp)

[premake5.lua](premake5.lua) `->` `premake/premake5` `->` build `->` [`ruby demo.rb`](https://travis-ci.org/d-led/nanomsg_example/jobs/77043092#L989-L1029)

[![Build Status](https://travis-ci.org/d-led/nanomsg_example.svg?branch=master)](https://travis-ci.org/d-led/nanomsg_example)
[![Build status](https://ci.appveyor.com/api/projects/status/roe73s0fn9bs68t4/branch/master?svg=true)](https://ci.appveyor.com/project/d-led/nanomsg-example/branch/master)



```
starting worker
2MIvN8f4At9-vnrR34evgH (worker) -> tcp://*:7777
starting server
2PHLnTudPYh-1rWZ3vM6lKT (server): connecting to: tcp://localhost:7777
2PHLnTudPYh-1rWZ3vM6lKT (server): connecting to: tcp://localhost:7778
2PHLnTudPYh-1rWZ3vM6lKT (server): connecting to: tcp://localhost:7779
2PHLnTudPYh-1rWZ3vM6lKT <- 2MIvN8f4At9-vnrR34evgH: 1
starting server
starting worker
2SChYsokE8R-MHyifgLONt (server): connecting to: tcp://localhost:7777
2SFm5VT1gp9-3o2WhjGC4oL (worker) -> tcp://*:7778
2PHLnTudPYh-1rWZ3vM6lKT <- 2MIvN8f4At9-vnrR34evgH: 2
2SChYsokE8R-MHyifgLONt <- 2MIvN8f4At9-vnrR34evgH: 2
starting worker
2VHH0Civ2LT-15wyD9l2E3F (worker) -> tcp://*:7779
2PHLnTudPYh-1rWZ3vM6lKT <- 2SFm5VT1gp9-3o2WhjGC4oL: 1
2PHLnTudPYh-1rWZ3vM6lKT <- 2MIvN8f4At9-vnrR34evgH: 3
2SChYsokE8R-MHyifgLONt <- 2MIvN8f4At9-vnrR34evgH: 3
2PHLnTudPYh-1rWZ3vM6lKT <- 2VHH0Civ2LT-15wyD9l2E3F: 1
2PHLnTudPYh-1rWZ3vM6lKT <- 2SFm5VT1gp9-3o2WhjGC4oL: 2
2PHLnTudPYh-1rWZ3vM6lKT <- 2MIvN8f4At9-vnrR34evgH: 4
2SChYsokE8R-MHyifgLONt <- 2MIvN8f4At9-vnrR34evgH: 4
2PHLnTudPYh-1rWZ3vM6lKT <- 2VHH0Civ2LT-15wyD9l2E3F: 2
2PHLnTudPYh-1rWZ3vM6lKT <- 2SFm5VT1gp9-3o2WhjGC4oL: 3
2PHLnTudPYh-1rWZ3vM6lKT <- 2MIvN8f4At9-vnrR34evgH: 5
2SChYsokE8R-MHyifgLONt <- 2MIvN8f4At9-vnrR34evgH: 5
2PHLnTudPYh-1rWZ3vM6lKT <- 2VHH0Civ2LT-15wyD9l2E3F: 3
2PHLnTudPYh-1rWZ3vM6lKT <- 2SFm5VT1gp9-3o2WhjGC4oL: 4
2PHLnTudPYh-1rWZ3vM6lKT <- 2MIvN8f4At9-vnrR34evgH: 6
2SChYsokE8R-MHyifgLONt <- 2MIvN8f4At9-vnrR34evgH: 6
2PHLnTudPYh-1rWZ3vM6lKT <- 2VHH0Civ2LT-15wyD9l2E3F: 4
2PHLnTudPYh-1rWZ3vM6lKT <- 2SFm5VT1gp9-3o2WhjGC4oL: 5
2SChYsokE8R-MHyifgLONt <- 2MIvN8f4At9-vnrR34evgH: 7
2PHLnTudPYh-1rWZ3vM6lKT <- 2MIvN8f4At9-vnrR34evgH: 7
2PHLnTudPYh-1rWZ3vM6lKT <- 2VHH0Civ2LT-15wyD9l2E3F: 5
2PHLnTudPYh-1rWZ3vM6lKT <- 2SFm5VT1gp9-3o2WhjGC4oL: 6
2PHLnTudPYh-1rWZ3vM6lKT <- 2MIvN8f4At9-vnrR34evgH: 8
2SChYsokE8R-MHyifgLONt <- 2MIvN8f4At9-vnrR34evgH: 8
2PHLnTudPYh-1rWZ3vM6lKT <- 2VHH0Civ2LT-15wyD9l2E3F: 6
2PHLnTudPYh-1rWZ3vM6lKT <- 2SFm5VT1gp9-3o2WhjGC4oL: 7
bye
```
