FILE(GLOB_RECURSE SRC ./*.cpp ./*.hpp)

add_library(native SHARED ${SRC} java/lang/Object.hpp java/lang/Class.hpp java/lang/System.hpp java/lang/Float.hpp java/lang/Double.hpp java/lang/String.hpp sun/misc/VM.hpp sun/misc/Unsafe.hpp sun/reflect/Reflection.hpp)