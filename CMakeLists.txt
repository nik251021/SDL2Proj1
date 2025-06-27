cmake_minimum_required(VERSION 3.10)
project(MySDL2App)

set(CMAKE_CXX_STANDARD 17)

# Путь к SDL2 (обязательно укажи правильный путь, куда распаковал SDL2)
set(SDL2_DIR "C:/SDL2")

# Указываем include и lib пути
include_directories(${SDL2_DIR}/include/SDL2)
link_directories(${SDL2_DIR}/lib)

# Создание исполняемого файла
add_executable(MySDL2App WIN32 main.cpp)

# Линковка SDL2 и нужных системных библиотек
target_link_libraries(MySDL2App
    mingw32
    SDL2main
    SDL2
    winmm
    imm32
    ole32
    oleaut32
    uuid
    version
)

# Копирование SDL2.dll рядом с exe
if (WIN32)
    add_custom_command(TARGET MySDL2App POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL2_DIR}/bin/SDL2.dll"
        $<TARGET_FILE_DIR:MySDL2App>)
endif()
