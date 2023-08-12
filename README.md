# RPC远程调用框架

### 依赖
编译需要依赖`protobuf`库
```
sudo apt install protobuf-compiler libprotobuf-dev
```

### 编译
编译源文件
```
./make.sh
```

### 使用
将`include`和`lib`文件夹下的文件移动到相应位置，如：
```
sudo mv include/* /usr/local/include
sudo mv lib/* /usr/local/lib
```

在编译时添加库：
```
g++ main.cpp -lrpc
```

### 运行
在`rpc.conf`填写相应的配置信息，详看`rpc.conf`文件
运行服务器
```
./userprovider -i server.conf
./userconsumer -i server.conf
```



