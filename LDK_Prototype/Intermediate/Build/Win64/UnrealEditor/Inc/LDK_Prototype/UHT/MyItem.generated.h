// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyItem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef LDK_PROTOTYPE_MyItem_generated_h
#error "MyItem.generated.h already included, missing '#pragma once' in MyItem.h"
#endif
#define LDK_PROTOTYPE_MyItem_generated_h

#define FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyItem_h_22_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMyItemInfo_Statics; \
	LDK_PROTOTYPE_API static class UScriptStruct* StaticStruct();


template<> LDK_PROTOTYPE_API UScriptStruct* StaticStruct<struct FMyItemInfo>();

#define FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyItem_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnlyCharacterOverlap);


#define FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyItem_h_37_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyItem(); \
	friend struct Z_Construct_UClass_AMyItem_Statics; \
public: \
	DECLARE_CLASS(AMyItem, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/LDK_Prototype"), NO_API) \
	DECLARE_SERIALIZER(AMyItem)


#define FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyItem_h_37_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AMyItem(AMyItem&&); \
	AMyItem(const AMyItem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyItem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyItem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyItem) \
	NO_API virtual ~AMyItem();


#define FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyItem_h_34_PROLOG
#define FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyItem_h_37_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyItem_h_37_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyItem_h_37_INCLASS_NO_PURE_DECLS \
	FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyItem_h_37_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LDK_PROTOTYPE_API UClass* StaticClass<class AMyItem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyItem_h


#define FOREACH_ENUM_MYITEMTYPE(op) \
	op(MyItemType::NONE) \
	op(MyItemType::POTION) 

enum class MyItemType;
template<> struct TIsUEnumClass<MyItemType> { enum { Value = true }; };
template<> LDK_PROTOTYPE_API UEnum* StaticEnum<MyItemType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
