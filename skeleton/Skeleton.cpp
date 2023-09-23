#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
// #include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

namespace {
  struct SkeletonPass : public FunctionPass {
    static char ID;
    SkeletonPass() : FunctionPass(ID) {}

    virtual bool runOnFunction(Function &F) {
      errs() << "I saw a function called " << F.getName() << "!\n";
      return false;
    }
  };
}

// https://llvm.org/docs/WritingAnLLVMPass.html
char SkeletonPass::ID = 0;
static RegisterPass<SkeletonPass> X("Skeleton", "Skeleton Function Pass",
				    false /* Only looks at CFG */,
				    false /* Analysis Pass */);

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
/*
static void registerSkeletonPass(const PassManagerBuilder &,
                         legacy::PassManagerBase &PM) {
  PM.add(new SkeletonPass());
}
static RegisterStandardPasses
  RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                 registerSkeletonPass);
*/


