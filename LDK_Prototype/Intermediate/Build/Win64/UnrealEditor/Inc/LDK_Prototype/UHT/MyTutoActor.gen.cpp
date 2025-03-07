// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LDK_Prototype/MyTutoActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyTutoActor() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
LDK_PROTOTYPE_API UClass* Z_Construct_UClass_AMyTutoActor();
LDK_PROTOTYPE_API UClass* Z_Construct_UClass_AMyTutoActor_NoRegister();
UPackage* Z_Construct_UPackage__Script_LDK_Prototype();
// End Cross Module References

// Begin Class AMyTutoActor
void AMyTutoActor::StaticRegisterNativesAMyTutoActor()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyTutoActor);
UClass* Z_Construct_UClass_AMyTutoActor_NoRegister()
{
	return AMyTutoActor::StaticClass();
}
struct Z_Construct_UClass_AMyTutoActor_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MyTutoActor.h" },
		{ "ModuleRelativePath", "MyTutoActor.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__mesh_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyTutoActor.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__mesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyTutoActor>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyTutoActor_Statics::NewProp__mesh = { "_mesh", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyTutoActor, _mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__mesh_MetaData), NewProp__mesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyTutoActor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyTutoActor_Statics::NewProp__mesh,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyTutoActor_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMyTutoActor_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_LDK_Prototype,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyTutoActor_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyTutoActor_Statics::ClassParams = {
	&AMyTutoActor::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AMyTutoActor_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AMyTutoActor_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyTutoActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyTutoActor_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyTutoActor()
{
	if (!Z_Registration_Info_UClass_AMyTutoActor.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyTutoActor.OuterSingleton, Z_Construct_UClass_AMyTutoActor_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyTutoActor.OuterSingleton;
}
template<> LDK_PROTOTYPE_API UClass* StaticClass<AMyTutoActor>()
{
	return AMyTutoActor::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyTutoActor);
AMyTutoActor::~AMyTutoActor() {}
// End Class AMyTutoActor

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyTutoActor_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyTutoActor, AMyTutoActor::StaticClass, TEXT("AMyTutoActor"), &Z_Registration_Info_UClass_AMyTutoActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyTutoActor), 815677422U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyTutoActor_h_3031438570(TEXT("/Script/LDK_Prototype"),
	Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyTutoActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyTutoActor_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
