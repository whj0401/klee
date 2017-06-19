/*
 * LLVMExprOstream.cpp
 *
 *  Created on: Mar 17, 2016
 *      Author: fish
 */

#include "klee/util/LLVMExprOstream.h"
#include "klee/util/ExprPPrinter.h"

using namespace klee;

void LLVMExprOstream::printExpr(const ref<Expr> &e) {
  std::string s;
  llvm::raw_ostream *screenStream = new llvm::raw_fd_ostream("-", s);
  ExprPPrinter::printExpr(*screenStream, e);
}

void LLVMExprOstream::printConstraints(const ConstraintManager &constraints) {
  std::string s;
  llvm::raw_ostream *screenStream = new llvm::raw_fd_ostream("-", s);
  ExprPPrinter::printSymbolicConstraints(*screenStream, constraints);
}

void LLVMExprOstream::saveExpr(const char *filePath, const ref<Expr> &e) {
  std::string s;
  llvm::raw_ostream *fileStream = new llvm::raw_fd_ostream(filePath, s);
  ExprPPrinter::printExpr(*fileStream, e);
}

void LLVMExprOstream::saveExpr(std::string name, const char *filePath,
                               const ref<Expr> &e) {
  std::string s;
  llvm::raw_ostream *fileStream =
      new llvm::raw_fd_ostream(filePath, s, llvm::sys::fs::F_Append);
  *fileStream << name << " = ";
  ExprPPrinter::printExpr(*fileStream, e);
  *fileStream << "\n\n---------------------------------------------------------"
                 "------------------------------\n";
  fileStream->flush();
}

void LLVMExprOstream::saveConstraints(const char *filePath,
                                      const ConstraintManager &constraints) {
  std::string s;
  llvm::raw_ostream *fileStream =
      new llvm::raw_fd_ostream(filePath, s, llvm::sys::fs::F_Append);
  ExprPPrinter::printSymbolicConstraints(*fileStream, constraints);
  *fileStream << "\n";
  fileStream->flush();
}
