// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MyAnimInstance.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LDK_PROTOTYPE_MyAnimInstance_generated_h
#error "MyAnimInstance.generated.h already included, missing '#pragma once' in MyAnimInstance.h"
#endif
#define LDK_PROTOTYPE_MyAnimInstance_generated_h

#define FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyAnimInstance_h_16_DELEGATE \
LDK_PROTOTYPE_API void FDMDTest_DelegateWrapper(const FMulticastScriptDelegate& DMDTest);


#define FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyAnimInstance_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execDeadEvent); \
	DECLARE_FUNCTION(execAnimNotify_Dead); \
	DECLARE_FUNCTION(execAnimNotify_Fire); \
	DECLARE_FUNCTION(execPlayAnimMontage);


#define FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyAnimInstance_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUMyAnimInstance(); \
	friend struct Z_Construct_UClass_UMyAnimInstance_Statics; \
public: \
	DECLARE_CLASS(UMyAnimInstance, UAnimInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/LDK_Prototype"), NO_API) \
	DECLARE_SERIALIZER(UMyAnimInstance)


#define FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyAnimInstance_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UMyAnimInstance(UMyAnimInstance&&); \
	UMyAnimInstance(const UMyAnimInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UMyAnimInstance); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UMyAnimInstance); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UMyAnimInstance) \
	NO_API virtual ~UMyAnimInstance();


#define FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyAnimInstance_h_18_PROLOG
#define FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyAnimInstance_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyAnimInstance_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyAnimInstance_h_21_INCLASS_NO_PURE_DECLS \
	FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyAnimInstance_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> LDK_PROTOTYPE_API UClass* StaticClass<class UMyAnimInstance>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyAnimInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
