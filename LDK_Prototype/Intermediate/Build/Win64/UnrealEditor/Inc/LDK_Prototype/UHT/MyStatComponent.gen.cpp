// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LDK_Prototype/MyStatComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyStatComponent() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTableRowBase();
LDK_PROTOTYPE_API UClass* Z_Construct_UClass_UMyStatComponent();
LDK_PROTOTYPE_API UClass* Z_Construct_UClass_UMyStatComponent_NoRegister();
LDK_PROTOTYPE_API UScriptStruct* Z_Construct_UScriptStruct_FMyStatData();
UPackage* Z_Construct_UPackage__Script_LDK_Prototype();
// End Cross Module References

// Begin ScriptStruct FMyStatData
static_assert(std::is_polymorphic<FMyStatData>() == std::is_polymorphic<FTableRowBase>(), "USTRUCT FMyStatData cannot be polymorphic unless super FTableRowBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_MyStatData;
class UScriptStruct* FMyStatData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_MyStatData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_MyStatData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FMyStatData, (UObject*)Z_Construct_UPackage__Script_LDK_Prototype(), TEXT("MyStatData"));
	}
	return Z_Registration_Info_UScriptStruct_MyStatData.OuterSingleton;
}
template<> LDK_PROTOTYPE_API UScriptStruct* StaticStruct<FMyStatData>()
{
	return FMyStatData::StaticStruct();
}
struct Z_Construct_UScriptStruct_FMyStatData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyStatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_level_MetaData[] = {
		{ "Category", "MyStatData" },
		{ "ModuleRelativePath", "MyStatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_hp_MetaData[] = {
		{ "Category", "MyStatData" },
		{ "ModuleRelativePath", "MyStatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_atk_MetaData[] = {
		{ "Category", "MyStatData" },
		{ "ModuleRelativePath", "MyStatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_exp_MetaData[] = {
		{ "Category", "MyStatData" },
		{ "ModuleRelativePath", "MyStatComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp_level;
	static const UECodeGen_Private::FIntPropertyParams NewProp_hp;
	static const UECodeGen_Private::FIntPropertyParams NewProp_atk;
	static const UECodeGen_Private::FIntPropertyParams NewProp_exp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMyStatData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMyStatData_Statics::NewProp_level = { "level", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyStatData, level), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_level_MetaData), NewProp_level_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMyStatData_Statics::NewProp_hp = { "hp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyStatData, hp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_hp_MetaData), NewProp_hp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMyStatData_Statics::NewProp_atk = { "atk", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyStatData, atk), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_atk_MetaData), NewProp_atk_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMyStatData_Statics::NewProp_exp = { "exp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FMyStatData, exp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_exp_MetaData), NewProp_exp_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMyStatData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyStatData_Statics::NewProp_level,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyStatData_Statics::NewProp_hp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyStatData_Statics::NewProp_atk,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMyStatData_Statics::NewProp_exp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyStatData_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMyStatData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_LDK_Prototype,
	Z_Construct_UScriptStruct_FTableRowBase,
	&NewStructOps,
	"MyStatData",
	Z_Construct_UScriptStruct_FMyStatData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyStatData_Statics::PropPointers),
	sizeof(FMyStatData),
	alignof(FMyStatData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMyStatData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FMyStatData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FMyStatData()
{
	if (!Z_Registration_Info_UScriptStruct_MyStatData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_MyStatData.InnerSingleton, Z_Construct_UScriptStruct_FMyStatData_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_MyStatData.InnerSingleton;
}
// End ScriptStruct FMyStatData

// Begin Class UMyStatComponent
void UMyStatComponent::StaticRegisterNativesUMyStatComponent()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyStatComponent);
UClass* Z_Construct_UClass_UMyStatComponent_NoRegister()
{
	return UMyStatComponent::StaticClass();
}
struct Z_Construct_UClass_UMyStatComponent_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MyStatComponent.h" },
		{ "ModuleRelativePath", "MyStatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__level_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyStatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__curHp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyStatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__maxHp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyStatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__atk_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyStatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__speed_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyStatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__curExp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyStatComponent.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__maxExp_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Stat" },
		{ "ModuleRelativePath", "MyStatComponent.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FIntPropertyParams NewProp__level;
	static const UECodeGen_Private::FIntPropertyParams NewProp__curHp;
	static const UECodeGen_Private::FIntPropertyParams NewProp__maxHp;
	static const UECodeGen_Private::FIntPropertyParams NewProp__atk;
	static const UECodeGen_Private::FFloatPropertyParams NewProp__speed;
	static const UECodeGen_Private::FIntPropertyParams NewProp__curExp;
	static const UECodeGen_Private::FIntPropertyParams NewProp__maxExp;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyStatComponent>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyStatComponent_Statics::NewProp__level = { "_level", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyStatComponent, _level), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__level_MetaData), NewProp__level_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyStatComponent_Statics::NewProp__curHp = { "_curHp", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyStatComponent, _curHp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__curHp_MetaData), NewProp__curHp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyStatComponent_Statics::NewProp__maxHp = { "_maxHp", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyStatComponent, _maxHp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__maxHp_MetaData), NewProp__maxHp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyStatComponent_Statics::NewProp__atk = { "_atk", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyStatComponent, _atk), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__atk_MetaData), NewProp__atk_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMyStatComponent_Statics::NewProp__speed = { "_speed", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyStatComponent, _speed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__speed_MetaData), NewProp__speed_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyStatComponent_Statics::NewProp__curExp = { "_curExp", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyStatComponent, _curExp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__curExp_MetaData), NewProp__curExp_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMyStatComponent_Statics::NewProp__maxExp = { "_maxExp", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyStatComponent, _maxExp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__maxExp_MetaData), NewProp__maxExp_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyStatComponent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyStatComponent_Statics::NewProp__level,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyStatComponent_Statics::NewProp__curHp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyStatComponent_Statics::NewProp__maxHp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyStatComponent_Statics::NewProp__atk,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyStatComponent_Statics::NewProp__speed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyStatComponent_Statics::NewProp__curExp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyStatComponent_Statics::NewProp__maxExp,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyStatComponent_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMyStatComponent_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UActorComponent,
	(UObject* (*)())Z_Construct_UPackage__Script_LDK_Prototype,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyStatComponent_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyStatComponent_Statics::ClassParams = {
	&UMyStatComponent::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UMyStatComponent_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UMyStatComponent_Statics::PropPointers),
	0,
	0x00B000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyStatComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyStatComponent_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyStatComponent()
{
	if (!Z_Registration_Info_UClass_UMyStatComponent.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyStatComponent.OuterSingleton, Z_Construct_UClass_UMyStatComponent_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyStatComponent.OuterSingleton;
}
template<> LDK_PROTOTYPE_API UClass* StaticClass<UMyStatComponent>()
{
	return UMyStatComponent::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyStatComponent);
UMyStatComponent::~UMyStatComponent() {}
// End Class UMyStatComponent

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyStatComponent_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FMyStatData::StaticStruct, Z_Construct_UScriptStruct_FMyStatData_Statics::NewStructOps, TEXT("MyStatData"), &Z_Registration_Info_UScriptStruct_MyStatData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FMyStatData), 240486731U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyStatComponent, UMyStatComponent::StaticClass, TEXT("UMyStatComponent"), &Z_Registration_Info_UClass_UMyStatComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyStatComponent), 2846105387U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyStatComponent_h_4037774307(TEXT("/Script/LDK_Prototype"),
	Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyStatComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyStatComponent_h_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyStatComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyStatComponent_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
