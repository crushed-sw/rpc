aux_source_directory(. SRC_LIST)

add_executable(userconsumer ${SRC_LIST} ../user.pb.cc)

target_link_libraries(userconsumer rpc protobuf)
