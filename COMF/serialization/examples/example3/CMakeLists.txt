add_executable(serialization_test_0003 serialize_deserialize.cpp TestClass.cpp)

target_include_directories(serialization_test_0003 PUBLIC ${COMF_DIR}/serialization)

target_link_libraries(serialization_test_0003 "udp")

