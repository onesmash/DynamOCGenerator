set(LLVM_LINK_COMPONENTS support)

add_clang_executable(DynamOCGenerator
  main.cpp
  )
target_link_libraries(DynamOCGenerator
  clangTooling
  clangBasic
  clangASTMatchers
  )
