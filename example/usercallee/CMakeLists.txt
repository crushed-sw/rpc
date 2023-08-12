aux_source_directory(. SRC_LIST)

add_executable(userprovider ${SRC_LIST} ../user.pb.cc)

target_link_libraries(userprovider rpc protobuf)
