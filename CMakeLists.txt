set(LLVM_LINK_COMPONENTS support)

add_clang_executable(DynamOCGenerator
  VarDeclGenerator.cpp
  CompoundStatementGenerator.cpp
  ExpressionGenerator.cpp
  IterationStatementGenerator.cpp
  JumpStatementGenerator.cpp
  LabeledStatementGenerator.cpp
  SelectionStatementGenerator.cpp
  StatementGenerator.cpp
  SynchronizedStatementGenerator.cpp
  AutoreleaseStatementGenerator.cpp
  ObjCMethodDeclGenerator.cpp
  main.cpp
  )
target_link_libraries(DynamOCGenerator
  clangTooling
  clangBasic
  clangASTMatchers
  )
