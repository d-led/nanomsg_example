wget https://github.com/nanomsg/nanomsg/releases/download/0.8-beta/nanomsg-0.8-beta.tar.gz -P tmp
cd tmp
tar -xzvf nanomsg-0.8-beta.tar.gz
./nanomsg-0.8-beta/configure --prefix=`pwd`/../nano
make
make install
cd ..
