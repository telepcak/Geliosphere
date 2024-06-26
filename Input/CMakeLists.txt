# Set the project name
project (Input)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
set(Input ${SOURCES})  
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O3")

add_library(Input SHARED ${SOURCES}) 
add_library(Input::Basic ALIAS ${PROJECT_NAME})

include(FetchContent)
FetchContent_Declare(
    rapidcsv
    GIT_REPOSITORY https://github.com/d99kris/rapidcsv
    GIT_TAG        v8.82
)
FetchContent_MakeAvailable(rapidcsv)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG        v1.13.0
)
FetchContent_MakeAvailable(spdlog)

FetchContent_Declare(
    toml11
    GIT_REPOSITORY https://github.com/ToruNiina/toml11
    GIT_TAG        v3.7.0
)
FetchContent_MakeAvailable(toml11)

FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11
    GIT_TAG        v1.3.0
)
FetchContent_MakeAvailable(CLI11)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    rapidcsv toml11 spdlog::spdlog_header_only CLI11
)