// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLDK_Prototype_init() {}
	LDK_PROTOTYPE_API UFunction* Z_Construct_UDelegateFunction_LDK_Prototype_DMDTest__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_LDK_Prototype;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_LDK_Prototype()
	{
		if (!Z_Registration_Info_UPackage__Script_LDK_Prototype.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_LDK_Prototype_DMDTest__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/LDK_Prototype",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x8AC55835,
				0xF2661CC4,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_LDK_Prototype.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_LDK_Prototype.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_LDK_Prototype(Z_Construct_UPackage__Script_LDK_Prototype, TEXT("/Script/LDK_Prototype"), Z_Registration_Info_UPackage__Script_LDK_Prototype, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x8AC55835, 0xF2661CC4));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
