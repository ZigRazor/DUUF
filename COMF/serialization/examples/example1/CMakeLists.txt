add_executable(serialization_test_0001 serialize_deserialize.cpp)

target_include_directories(serialization_test_0001 PUBLIC ${COMF_DIR}/serialization)

target_link_libraries(serialization_test_0001 "udp")

