
#include "yoga/common.h"

#include "all.h"

using namespace craft;
using namespace craft::lisp;
using namespace craft::types;
using namespace cultlang::yoga;


#define lMM sem->builtin_implementMultiMethod
#define lC sem->builtin_defineConstant
#define MoD "yoga"

typedef instance<std::string> t_str;
typedef instance<uint32_t> t_u32;
typedef instance<bool> t_bool;
typedef instance<float> t_f32;

typedef instance<lisp::library::List> t_list;

typedef instance<YGNode> t_node;


CRAFT_TYPE_DEFINE(YGSize)
{
	_.add<GraphPropertyName>("yoga/Size");
	_.add<GraphPropertyCppName>("::YGSize");
	_.use<PStringer>().singleton<FunctionalStringer>([](::craft::instance<YGSize> _this) {
		return fmt::format("YGSize<{},{}>", _this->width, _this->height);
	});
	_.use<PRepr>().singleton<FunctionalRepr>([](::craft::instance<YGSize> _this) {
		return fmt::format("(yoga/Size {} {})", _this->width, _this->height);
	});
}

CRAFT_TYPE_DEFINE(YGValue)
{
	_.add<GraphPropertyName>("yoga/Value");
	_.add<GraphPropertyCppName>("::YGValue");
	_.use<PStringer>().singleton<FunctionalStringer>([](::craft::instance<YGValue> _this) {
		return fmt::format("YGValue:{}<{}>", YGUnitToString(_this->unit), _this->value);
	});
	_.use<PRepr>().singleton<FunctionalRepr>([](::craft::instance<YGValue> _this) {
		return fmt::format("(yoga/Value {} {})", int32_t(_this->unit), _this->value);
	});
}

CRAFT_TYPE_DEFINE(YGConfig)
{
	_.add<GraphPropertyName>("yoga/Config");
	_.add<GraphPropertyCppName>("::YGConfig");
	_.use<PStringer>().singleton<FunctionalStringer>([](::craft::instance<YGConfig> _this) {
		return fmt::format("YGConfig");
	});
	_.use<PRepr>().singleton<FunctionalRepr>([](::craft::instance<YGConfig> _this) {
		return fmt::format("(YGConfig)");
	});
}

CRAFT_TYPE_DEFINE(YGNode)
{
	_.add<GraphPropertyName>("yoga/Node");
	_.add<GraphPropertyCppName>("::YGNode");
	_.use<PStringer>().singleton<FunctionalStringer>([](::craft::instance<YGNode> _this) {
		return fmt::format("YGNode");
	});
	_.use<PRepr>().singleton<FunctionalRepr>([](::craft::instance<YGNode> _this) {
		return fmt::format("(YGNode)");
	});
}

void cultlang::yoga::make_bindings(craft::instance<craft::lisp::Module> ret)
{

	auto sem = ret->require<lisp::CultSemantics>();

	//Yoga Enums
	lC(MoD"/Align/Auto", t_u32::make(YGAlignAuto));
	lC(MoD"/Align/FlexStart", t_u32::make(YGAlignFlexStart));
	lC(MoD"/Align/Center", t_u32::make(YGAlignCenter));
	lC(MoD"/Align/FlexEnd", t_u32::make(YGAlignFlexEnd));
	lC(MoD"/Align/Stretch", t_u32::make(YGAlignStretch));
	lC(MoD"/Align/Baseline", t_u32::make(YGAlignBaseline));
	lC(MoD"/Align/SpaceBetween", t_u32::make(YGAlignSpaceBetween));
	lC(MoD"/Align/SpaceAround", t_u32::make(YGAlignSpaceAround));
	
	lC(MoD"/Dimension/Width", t_u32::make(YGDimensionWidth));
	lC(MoD"/Dimension/Height", t_u32::make(YGDimensionHeight));
	
	lC(MoD"/Direction/Inherit", t_u32::make(YGDirectionInherit));
	lC(MoD"/Direction/LTR", t_u32::make(YGDirectionLTR));
	lC(MoD"/Direction/RTL", t_u32::make(YGDirectionRTL));

	lC(MoD"/Direction/LTR", t_u32::make(YGDirectionLTR));
	lC(MoD"/Direction/RTL", t_u32::make(YGDirectionRTL));

	lC(MoD"/Display/Flex", t_u32::make(YGDisplayFlex));
	lC(MoD"/Display/None", t_u32::make(YGDisplayNone));

	lC(MoD"/Edge/Left", t_u32::make(YGEdgeLeft));
	lC(MoD"/Edge/Top", t_u32::make(YGEdgeTop));
	lC(MoD"/Edge/Right", t_u32::make(YGEdgeRight));
	lC(MoD"/Edge/Bottom", t_u32::make(YGEdgeBottom));
	lC(MoD"/Edge/Start", t_u32::make(YGEdgeStart));
	lC(MoD"/Edge/End", t_u32::make(YGEdgeEnd));
	lC(MoD"/Edge/Horizontal", t_u32::make(YGEdgeHorizontal));
	lC(MoD"/Edge/Vertical", t_u32::make(YGEdgeVertical));
	lC(MoD"/Edge/All", t_u32::make(YGEdgeAll));

	lC(MoD"/ExperimentalFeature/WebFlexBasis", t_u32::make(YGExperimentalFeatureWebFlexBasis));

	lC(MoD"/Direction/Column", t_u32::make(YGFlexDirectionColumn));
	lC(MoD"/Direction/ColumnReverse", t_u32::make(YGFlexDirectionColumnReverse));
	lC(MoD"/Direction/Row", t_u32::make(YGFlexDirectionRow));
	lC(MoD"/Direction/RowReverse", t_u32::make(YGFlexDirectionRowReverse));

	lC(MoD"/Justify/FlexStart", t_u32::make(YGJustifyFlexStart));
	lC(MoD"/Justify/Center", t_u32::make(YGJustifyCenter));
	lC(MoD"/Justify/FlexEnd", t_u32::make(YGJustifyFlexEnd));
	lC(MoD"/Justify/SpaceBetween", t_u32::make(YGJustifySpaceBetween));
	lC(MoD"/Justify/SpaceAround", t_u32::make(YGJustifySpaceAround));
	lC(MoD"/Justify/SpaceEvenly", t_u32::make(YGJustifySpaceEvenly));

	lC(MoD"/LogLevel/Error", t_u32::make(YGLogLevelError));
	lC(MoD"/LogLevel/Warn", t_u32::make(YGLogLevelWarn));
	lC(MoD"/LogLevel/Info", t_u32::make(YGLogLevelInfo));
	lC(MoD"/LogLevel/Debug", t_u32::make(YGLogLevelDebug));
	lC(MoD"/LogLevel/Verbose", t_u32::make(YGLogLevelVerbose));
	lC(MoD"/LogLevel/Fatal", t_u32::make(YGLogLevelFatal));

	lC(MoD"/MeasureMode/Undefined", t_u32::make(YGMeasureModeUndefined));
	lC(MoD"/MeasureMode/Exactly", t_u32::make(YGMeasureModeExactly));
	lC(MoD"/MeasureMode/AtMost", t_u32::make(YGMeasureModeAtMost));

	lC(MoD"/NodeType/Default", t_u32::make(YGNodeTypeDefault));
	lC(MoD"/NodeType/Text", t_u32::make(YGNodeTypeText));

	lC(MoD"/Overflow/Visible", t_u32::make(YGOverflowVisible));
	lC(MoD"/Overflow/Hidden", t_u32::make(YGOverflowHidden));
	lC(MoD"/Overflow/Scroll", t_u32::make(YGOverflowScroll));

	lC(MoD"/PositionType/Relative", t_u32::make(YGPositionTypeRelative));
	lC(MoD"/PositionType/Absolute", t_u32::make(YGPositionTypeAbsolute));

	lC(MoD"/PrintOptions/Layout", t_u32::make(YGPrintOptionsLayout));
	lC(MoD"/PrintOptions/Style", t_u32::make(YGPrintOptionsStyle));
	lC(MoD"/PrintOptions/Children", t_u32::make(YGPrintOptionsChildren));

	lC(MoD"/Unit/Undefined", t_u32::make(YGUnitUndefined));
	lC(MoD"/Unit/Percent", t_u32::make(YGUnitPercent));
	lC(MoD"/Unit/YGUnitPoint", t_u32::make(YGUnitPoint));
	lC(MoD"/Unit/YGUnitAuto", t_u32::make(YGUnitAuto));

	lC(MoD"/Wrap/NoWrap", t_u32::make(YGWrapNoWrap));
	lC(MoD"/Wrap/Wrap", t_u32::make(YGWrapWrap));
	lC(MoD"/Wrap/WrapReverse", t_u32::make(YGWrapWrapReverse));

	//Nodes
	lMM(MoD"/Node", []() {
		return t_node::makeFromPointerAndMemoryManager(YGNodeNew(), 0);
	});
	lMM(MoD"/Node/free", [](t_node s) {
		return YGNodeFree(s.get());
	});
	lMM(MoD"/Node/free", [](t_node s) {
		return YGNodeFreeRecursive(s.get());
	});
	lMM(MoD"/Node/clone", [](t_node f) {
		return t_node::makeFromPointerAndMemoryManager(f.get(), 0);
	});
	lMM(MoD"/Node/reset", [](t_node f) {return t_node::makeFromPointerAndMemoryManager(f.get(), 0);});
	lMM(MoD"/Node/count", []() {return t_u32::make(YGNodeGetInstanceCount());});

	lMM(MoD"/Node/insert", [](t_node p, t_node c, t_u32 i) {YGNodeInsertChild(p.get(), c.get(), *i);});
	lMM(MoD"/Node/remove", [](t_node p, t_node c) {YGNodeRemoveChild(p.get(), c.get());});
	lMM(MoD"/Node/removeAll", [](t_node p, t_node c) {YGNodeRemoveAllChildren(p.get());});

	lMM(MoD"/Node/owner", [](t_node p) {return t_node::makeFromPointerAndMemoryManager(YGNodeGetOwner(p.get()), 0);});
	lMM(MoD"/Node/parent", [](t_node p) {return t_node::makeFromPointerAndMemoryManager(YGNodeGetParent(p.get()), 0);});

	lMM(MoD"/Node/children", [](t_node p, t_u32 i) {return t_node::makeFromPointerAndMemoryManager(YGNodeGetChild(p.get(), *i), 0);});
	lMM(MoD"/Node/children/count", [](t_node p) {return t_u32::make(YGNodeGetChildCount(p.get()));});
	lMM(MoD"/Node/children", [](t_node p, t_list l) {
		auto res = std::vector<YGNodeRef>();
		for(auto i : l->data())
			res.push_back(i.asType<YGNode>().get());
		YGNodeSetChildren(p.get(), res.data(), res.size());
	});

	lMM(MoD"/Node/dirty", [](t_node p) {YGNodeMarkDirty(p.get());});

	//TODO Fixup Context stuffs
	lMM(MoD"/style/direction", [](t_node p, t_u32 d) {YGNodeStyleSetDirection(p.get(), YGDirection(*d));});
	lMM(MoD"/style/direction", [](t_node p) {t_u32::make(YGNodeStyleGetDirection(p.get()));});
	
	lMM(MoD"/style/flex-direction", [](t_node p, t_u32 d) {YGNodeStyleSetFlexDirection(p.get(), YGFlexDirection(*d));});
	lMM(MoD"/style/flex-direction", [](t_node p) {t_u32::make(YGNodeStyleGetFlexDirection(p.get()));});

	lMM(MoD"/style/justify-content", [](t_node p, t_u32 d) {YGNodeStyleSetJustifyContent(p.get(), YGJustify(*d));});
	lMM(MoD"/style/justify-content", [](t_node p) {t_u32::make(YGNodeStyleGetJustifyContent(p.get()));});

	lMM(MoD"/style/align-content", [](t_node p, t_u32 d) {YGNodeStyleSetAlignContent(p.get(), YGAlign(*d));});
	lMM(MoD"/style/align-content", [](t_node p) {t_u32::make(YGNodeStyleGetAlignContent(p.get()));});

	lMM(MoD"/style/align-items", [](t_node p, t_u32 d) {YGNodeStyleSetAlignItems(p.get(), YGAlign(*d));});
	lMM(MoD"/style/align-items", [](t_node p) {t_u32::make(YGNodeStyleGetAlignItems(p.get()));});

	lMM(MoD"/style/align-self", [](t_node p, t_u32 d) {YGNodeStyleSetAlignSelf(p.get(), YGAlign(*d));});
	lMM(MoD"/style/align-self", [](t_node p) {t_u32::make(YGNodeStyleGetAlignSelf(p.get()));});

	lMM(MoD"/style/position", [](t_node p, t_u32 d) {YGNodeStyleSetPositionType(p.get(), YGPositionType(*d));});
	lMM(MoD"/style/position", [](t_node p) {t_u32::make(YGNodeStyleGetPositionType(p.get()));});

	lMM(MoD"/style/flex-wrap", [](t_node p, t_u32 d) {YGNodeStyleSetFlexWrap(p.get(), YGWrap(*d));});
	lMM(MoD"/style/flex-wrap", [](t_node p) {t_u32::make(YGNodeStyleGetFlexWrap(p.get()));});

	lMM(MoD"/style/overflow", [](t_node p, t_u32 d) {YGNodeStyleSetOverflow(p.get(), YGOverflow(*d));});
	lMM(MoD"/style/overflow", [](t_node p) {t_u32::make(YGNodeStyleGetOverflow(p.get()));});

	lMM(MoD"/style/display", [](t_node p, t_u32 d) {YGNodeStyleSetDisplay(p.get(), YGDisplay(*d));});
	lMM(MoD"/style/display", [](t_node p) {t_u32::make(YGNodeStyleGetDisplay(p.get()));});

	lMM(MoD"/style/flex", [](t_node p, t_f32 d) {YGNodeStyleSetFlex(p.get(), *d);});
	lMM(MoD"/style/flex", [](t_node p) {t_f32::make(YGNodeStyleGetFlex(p.get()));});

	lMM(MoD"/style/flex-grow", [](t_node p, t_f32 d) {YGNodeStyleSetFlexGrow(p.get(), *d);});
	lMM(MoD"/style/flex-grow", [](t_node p) {t_f32::make(YGNodeStyleGetFlexGrow(p.get()));});

	lMM(MoD"/style/flex-shrink", [](t_node p, t_f32 d) {YGNodeStyleSetFlexShrink(p.get(), *d);});
	lMM(MoD"/style/flex-shrink", [](t_node p) {t_f32::make(YGNodeStyleGetFlexShrink(p.get()));});


	lMM(MoD"/style/flex-basis", [](t_node p, t_f32 f) {YGNodeStyleSetFlexBasis(p.get(), *f);});
	lMM(MoD"/style/flex-basis", [](t_node p, t_u32 f) {YGNodeStyleSetFlexBasisPercent(p.get(), float(*f));});
	lMM(MoD"/style/flex-basis/auto", [](t_node p) {YGNodeStyleSetFlexBasisAuto(p.get());});
	lMM(MoD"/style/flex-basis", [](t_node p) {instance<YGValue>::make(YGNodeStyleGetFlexBasis(p.get()));});

	lMM(MoD"/style/position", [](t_node p, t_u32 e, t_f32 d) {YGNodeStyleSetPosition(p.get(), YGEdge(*e), *d);});
	lMM(MoD"/style/position", [](t_node p, t_u32 e, t_u32 d) {YGNodeStyleSetPositionPercent(p.get(), YGEdge(*e), *d);});
	lMM(MoD"/style/position", [](t_node p, t_u32 e) {instance<YGValue>::make(YGNodeStyleGetPosition(p.get(), YGEdge(*e)));});

	lMM(MoD"/style/margin", [](t_node p, t_u32 e, t_f32 f) {YGNodeStyleSetMargin(p.get(), YGEdge(*e), *f);});
	lMM(MoD"/style/margin", [](t_node p, t_u32 e, t_u32 f) {YGNodeStyleSetMarginPercent(p.get(), YGEdge(*e), float(*f));});
	lMM(MoD"/style/margin/auto", [](t_node p, t_u32 e) {YGNodeStyleSetMarginAuto(p.get(), YGEdge(*e));});
	lMM(MoD"/style/margin", [](t_node p, t_u32 e) {instance<YGValue>::make(YGNodeStyleGetMargin(p.get(), YGEdge(*e)));});

	lMM(MoD"/style/padding", [](t_node p, t_u32 e, t_f32 f) {YGNodeStyleSetPadding(p.get(), YGEdge(*e), *f);});
	lMM(MoD"/style/padding", [](t_node p, t_u32 e, t_u32 f) {YGNodeStyleSetPaddingPercent(p.get(), YGEdge(*e), float(*f));});
	lMM(MoD"/style/padding", [](t_node p, t_u32 e) {instance<YGValue>::make(YGNodeStyleGetPadding(p.get(), YGEdge(*e)));});

	lMM(MoD"/style/border", [](t_node p, t_u32 e, t_f32 f) {YGNodeStyleSetBorder(p.get(), YGEdge(*e), *f);});
	lMM(MoD"/style/border", [](t_node p, t_u32 e) {YGNodeStyleGetBorder(p.get(), YGEdge(*e));});

	lMM(MoD"/style/width", [](t_node p, t_f32 f) {YGNodeStyleSetWidth(p.get(), *f);});
	lMM(MoD"/style/width", [](t_node p, t_u32 f) {YGNodeStyleSetWidthPercent(p.get(), float(*f));});
	lMM(MoD"/style/width/auto", [](t_node p) {YGNodeStyleSetWidthAuto(p.get());});
	lMM(MoD"/style/width", [](t_node p) {instance<YGValue>::make(YGNodeStyleGetWidth(p.get()));});

	lMM(MoD"/style/min-width", [](t_node p, t_f32 f) {YGNodeStyleSetMinWidth(p.get(), *f);});
	lMM(MoD"/style/min-width", [](t_node p, t_u32 f) {YGNodeStyleSetMinWidthPercent(p.get(), float(*f));});
	lMM(MoD"/style/min-width", [](t_node p) {instance<YGValue>::make(YGNodeStyleGetMinWidth(p.get()));});

	lMM(MoD"/style/max-width", [](t_node p, t_f32 f) {YGNodeStyleSetMaxWidth(p.get(), *f);});
	lMM(MoD"/style/max-width", [](t_node p, t_u32 f) {YGNodeStyleSetMaxWidthPercent(p.get(), float(*f));});
	lMM(MoD"/style/max-width", [](t_node p) {instance<YGValue>::make(YGNodeStyleGetMaxWidth(p.get()));});

	lMM(MoD"/style/height", [](t_node p, t_f32 f) {YGNodeStyleSetHeight(p.get(), *f);});
	lMM(MoD"/style/height", [](t_node p, t_u32 f) {YGNodeStyleSetHeightPercent(p.get(), float(*f));});
	lMM(MoD"/style/height/auto", [](t_node p) {YGNodeStyleSetHeightAuto(p.get());});
	lMM(MoD"/style/height", [](t_node p) {instance<YGValue>::make(YGNodeStyleGetHeight(p.get()));});

	lMM(MoD"/style/min-height", [](t_node p, t_f32 f) {YGNodeStyleSetMinHeight(p.get(), *f);});
	lMM(MoD"/style/min-height", [](t_node p, t_u32 f) {YGNodeStyleSetMinHeightPercent(p.get(), float(*f));});
	lMM(MoD"/style/min-height", [](t_node p) {instance<YGValue>::make(YGNodeStyleGetMinHeight(p.get()));});

	lMM(MoD"/style/max-height", [](t_node p, t_f32 f) {YGNodeStyleSetMaxHeight(p.get(), *f);});
	lMM(MoD"/style/max-height", [](t_node p, t_u32 f) {YGNodeStyleSetMaxHeightPercent(p.get(), float(*f));});
	lMM(MoD"/style/max-height", [](t_node p) {instance<YGValue>::make(YGNodeStyleGetMaxHeight(p.get()));});

	lMM(MoD"/layout", [](t_node p, t_f32 w, t_f32 h, t_u32 d) {
		YGNodeCalculateLayout(p.get(), *w, *h, YGDirection(*d));
	});

	lMM(MoD"/layout/left", [](t_node p) {YGNodeLayoutGetLeft(p.get());});
	lMM(MoD"/layout/top", [](t_node p) {YGNodeLayoutGetTop(p.get());});
	lMM(MoD"/layout/right", [](t_node p) {YGNodeLayoutGetRight(p.get());});
	lMM(MoD"/layout/bottom", [](t_node p) {YGNodeLayoutGetBottom(p.get());});
	lMM(MoD"/layout/width", [](t_node p) {YGNodeLayoutGetWidth(p.get());});
	lMM(MoD"/layout/height", [](t_node p) {YGNodeLayoutGetHeight(p.get());});
	lMM(MoD"/layout/direction", [](t_node p) {t_u32::make(YGNodeLayoutGetDirection(p.get()));});
	lMM(MoD"/layout/overflowed", [](t_node p) {t_bool::make(YGNodeLayoutGetHadOverflow(p.get()));});

	lMM(MoD"/layout/margin", [](t_node p, t_u32 e) {YGNodeLayoutGetMargin(p.get(), YGEdge(*e));});
	lMM(MoD"/layout/border", [](t_node p, t_u32 e) {YGNodeLayoutGetBorder(p.get(), YGEdge(*e));});
	lMM(MoD"/layout/padding", [](t_node p, t_u32 e) {YGNodeLayoutGetPadding(p.get(), YGEdge(*e));});
}

BuiltinModuleDescription cultlang::yoga::BuiltinYoga("cultlang/yoga", cultlang::yoga::make_bindings);


#include "types/dll_entry.inc"
