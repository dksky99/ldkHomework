// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LDK_Prototype/MyTutoPawn.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyTutoPawn() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_APawn();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
LDK_PROTOTYPE_API UClass* Z_Construct_UClass_AMyTutoPawn();
LDK_PROTOTYPE_API UClass* Z_Construct_UClass_AMyTutoPawn_NoRegister();
UPackage* Z_Construct_UPackage__Script_LDK_Prototype();
// End Cross Module References

// Begin Class AMyTutoPawn Function Temp
struct Z_Construct_UFunction_AMyTutoPawn_Temp_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyTutoPawn.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyTutoPawn_Temp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyTutoPawn, nullptr, "Temp", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyTutoPawn_Temp_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyTutoPawn_Temp_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMyTutoPawn_Temp()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyTutoPawn_Temp_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyTutoPawn::execTemp)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Temp();
	P_NATIVE_END;
}
// End Class AMyTutoPawn Function Temp

// Begin Class AMyTutoPawn
void AMyTutoPawn::StaticRegisterNativesAMyTutoPawn()
{
	UClass* Class = AMyTutoPawn::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Temp", &AMyTutoPawn::execTemp },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyTutoPawn);
UClass* Z_Construct_UClass_AMyTutoPawn_NoRegister()
{
	return AMyTutoPawn::StaticClass();
}
struct Z_Construct_UClass_AMyTutoPawn_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyTutoPawn.h" },
		{ "ModuleRelativePath", "MyTutoPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__locationMarker_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyTutoPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__mesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyTutoPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__moveSpeed_MetaData[] = {
		{ "Category", "Speed" },
		{ "ModuleRelativePath", "MyTutoPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__rotSpeed_MetaData[] = {
		{ "Category", "Speed" },
		{ "ModuleRelativePath", "MyTutoPawn.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__moveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyTutoPawn.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__locationMarker;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__mesh;
	static const UECodeGen_Private::FFloatPropertyParams NewProp__moveSpeed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp__rotSpeed;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__moveAction;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyTutoPawn_Temp, "Temp" }, // 1345820942
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyTutoPawn>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyTutoPawn_Statics::NewProp__locationMarker = { "_locationMarker", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyTutoPawn, _locationMarker), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__locationMarker_MetaData), NewProp__locationMarker_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyTutoPawn_Statics::NewProp__mesh = { "_mesh", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyTutoPawn, _mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__mesh_MetaData), NewProp__mesh_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyTutoPawn_Statics::NewProp__moveSpeed = { "_moveSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyTutoPawn, _moveSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__moveSpeed_MetaData), NewProp__moveSpeed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyTutoPawn_Statics::NewProp__rotSpeed = { "_rotSpeed", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyTutoPawn, _rotSpeed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__rotSpeed_MetaData), NewProp__rotSpeed_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyTutoPawn_Statics::NewProp__moveAction = { "_moveAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyTutoPawn, _moveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__moveAction_MetaData), NewProp__moveAction_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyTutoPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyTutoPawn_Statics::NewProp__locationMarker,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyTutoPawn_Statics::NewProp__mesh,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyTutoPawn_Statics::NewProp__moveSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyTutoPawn_Statics::NewProp__rotSpeed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyTutoPawn_Statics::NewProp__moveAction,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyTutoPawn_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMyTutoPawn_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APawn,
	(UObject* (*)())Z_Construct_UPackage__Script_LDK_Prototype,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyTutoPawn_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyTutoPawn_Statics::ClassParams = {
	&AMyTutoPawn::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMyTutoPawn_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMyTutoPawn_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyTutoPawn_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyTutoPawn_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyTutoPawn()
{
	if (!Z_Registration_Info_UClass_AMyTutoPawn.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyTutoPawn.OuterSingleton, Z_Construct_UClass_AMyTutoPawn_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyTutoPawn.OuterSingleton;
}
template<> LDK_PROTOTYPE_API UClass* StaticClass<AMyTutoPawn>()
{
	return AMyTutoPawn::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyTutoPawn);
AMyTutoPawn::~AMyTutoPawn() {}
// End Class AMyTutoPawn

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyTutoPawn_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyTutoPawn, AMyTutoPawn::StaticClass, TEXT("AMyTutoPawn"), &Z_Registration_Info_UClass_AMyTutoPawn, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyTutoPawn), 1364238848U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyTutoPawn_h_3744559062(TEXT("/Script/LDK_Prototype"),
	Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyTutoPawn_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyTutoPawn_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
