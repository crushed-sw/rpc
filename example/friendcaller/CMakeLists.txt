aux_source_directory(. SRC_LIST)

add_executable(friendcustomer ${SRC_LIST} ../friend.pb.cc)

target_link_libraries(friendcustomer rpc protobuf)
