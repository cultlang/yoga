
#pragma once
#include "yoga/common.h"


namespace cultlang {
namespace yoga 
{
  extern craft::lisp::BuiltinModuleDescription BuiltinYoga;

  CULTLANG_YOGA_EXPORTED void make_bindings(craft::instance<craft::lisp::Module> ret);

}}  

CRAFT_TYPE_DECLARE(CULTLANG_YOGA_EXPORTED, YGSize)
CRAFT_TYPE_DECLARE(CULTLANG_YOGA_EXPORTED, YGValue)
CRAFT_TYPE_DECLARE(CULTLANG_YOGA_EXPORTED, YGConfig)
CRAFT_TYPE_DECLARE(CULTLANG_YOGA_EXPORTED, YGNode)