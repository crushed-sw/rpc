mkdir build
cd build
cmake ..
make
cd ..
cd bin
echo "# rpcserverip
rpcserverip = 127.0.0.1
# rpcserverport
rpcserverport = 9999" > rpc.conf
