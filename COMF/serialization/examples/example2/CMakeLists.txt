add_executable(serialization_test_0002 serialize_deserialize.cpp)

target_include_directories(serialization_test_0002 PUBLIC ${COMF_DIR}/serialization)

target_link_libraries(serialization_test_0002 "serialization")

