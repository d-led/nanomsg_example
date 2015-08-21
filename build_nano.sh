wget https://github.com/nanomsg/nanomsg/releases/download/0.6-beta/nanomsg-0.6-beta.tar.gz
tar -xzvf nanomsg-0.6-beta.tar.gz
./nanomsg-0.6-beta/configure --prefix=`pwd`/nano
make
make install
