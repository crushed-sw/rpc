aux_source_directory(. SRC_LIST)

add_executable(friendprovider ${SRC_LIST} ../friend.pb.cc)

target_link_libraries(friendprovider rpc protobuf)
