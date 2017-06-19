#ifndef KLEE_LLVMEXPROSTREAM_H
#define KLEE_LLVMEXPROSTREAM_H

#include "klee/Expr.h"

namespace llvm {
class raw_ostream;
}

namespace klee {
class ConstraintManager;

class LLVMExprOstream {

public:
  static void printExpr(const ref<Expr> &e);

  static void printConstraints(const ConstraintManager &constraints);

  static void saveExpr(const char *filePath, const ref<Expr> &e);

  static void saveExpr(std::string name, const char *filePath,
                       const ref<Expr> &e);

  static void saveConstraints(const char *filePath,
                              const ConstraintManager &constraints);
};
}

#endif