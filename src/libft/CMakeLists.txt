# Common sources
file(GLOB SOURCES "*.c" "*.h")

# Arch-specific sources
file(GLOB SOURCES_X86     "arch/x86/*.c" "arch/x86/*.asm" "arch/x86/*.h")
file(GLOB SOURCES_X86_64  "arch/x86_64/*.c" "arch/x86_64/*.asm" "arch/x86_64/*.h")

# Arch detection
if (CMAKE_SYSTEM_PROCESSOR MATCHES "(x86)|(X86)|(amd64)|(AMD64)")
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    list(APPEND SOURCES ${SOURCES_X86_64})
    message("System: x86_64")
  else()
    list(APPEND SOURCES ${SOURCES_X86})
    message("System: x86")
  endif()
else()
  message(ERROR "Unsupported system")
endif()

# Compiler-specific flags
if (CMAKE_C_COMPILER_ID MATCHES "(Clang)|(GNU)")
  add_compile_options("$<$<COMPILE_LANGUAGE:C>:-fvisibility=hidden>")
endif()

add_library(libft_static STATIC ${SOURCES})
add_library(libft_shared SHARED ${SOURCES})

if (UNIX)
  set_target_properties(libft_static PROPERTIES OUTPUT_NAME ft)
  set_target_properties(libft_shared PROPERTIES OUTPUT_NAME ft)
endif()

if (WIN32)
  target_compile_definitions(libft_static PUBLIC FT_STATIC=1)
  target_compile_definitions(libft_shared PRIVATE FT_DLL=1)
endif()
