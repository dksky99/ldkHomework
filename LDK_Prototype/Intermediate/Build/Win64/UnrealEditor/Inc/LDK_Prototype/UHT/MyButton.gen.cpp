// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LDK_Prototype/MyButton.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyButton() {}

// Begin Cross Module References
LDK_PROTOTYPE_API UClass* Z_Construct_UClass_UMyButton();
LDK_PROTOTYPE_API UClass* Z_Construct_UClass_UMyButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton();
UPackage* Z_Construct_UPackage__Script_LDK_Prototype();
// End Cross Module References

// Begin Class UMyButton Function SetCurIndex
struct Z_Construct_UFunction_UMyButton_SetCurIndex_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyButton.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyButton_SetCurIndex_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyButton, nullptr, "SetCurIndex", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyButton_SetCurIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyButton_SetCurIndex_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMyButton_SetCurIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyButton_SetCurIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyButton::execSetCurIndex)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetCurIndex();
	P_NATIVE_END;
}
// End Class UMyButton Function SetCurIndex

// Begin Class UMyButton
void UMyButton::StaticRegisterNativesUMyButton()
{
	UClass* Class = UMyButton::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SetCurIndex", &UMyButton::execSetCurIndex },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyButton);
UClass* Z_Construct_UClass_UMyButton_NoRegister()
{
	return UMyButton::StaticClass();
}
struct Z_Construct_UClass_UMyButton_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MyButton.h" },
		{ "ModuleRelativePath", "MyButton.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyButton_SetCurIndex, "SetCurIndex" }, // 2730070815
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyButton>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMyButton_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UButton,
	(UObject* (*)())Z_Construct_UPackage__Script_LDK_Prototype,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyButton_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyButton_Statics::ClassParams = {
	&UMyButton::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x00B000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyButton_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyButton_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyButton()
{
	if (!Z_Registration_Info_UClass_UMyButton.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyButton.OuterSingleton, Z_Construct_UClass_UMyButton_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyButton.OuterSingleton;
}
template<> LDK_PROTOTYPE_API UClass* StaticClass<UMyButton>()
{
	return UMyButton::StaticClass();
}
UMyButton::UMyButton(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyButton);
UMyButton::~UMyButton() {}
// End Class UMyButton

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyButton_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyButton, UMyButton::StaticClass, TEXT("UMyButton"), &Z_Registration_Info_UClass_UMyButton, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyButton), 3620197405U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyButton_h_1689505283(TEXT("/Script/LDK_Prototype"),
	Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyButton_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyButton_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
