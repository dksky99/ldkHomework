// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LDK_Prototype/MyInvenUI.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyInvenUI() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
LDK_PROTOTYPE_API UClass* Z_Construct_UClass_UMyInvenUI();
LDK_PROTOTYPE_API UClass* Z_Construct_UClass_UMyInvenUI_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUniformGridPanel_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_LDK_Prototype();
// End Cross Module References

// Begin Class UMyInvenUI Function SetTextBox
struct Z_Construct_UFunction_UMyInvenUI_SetTextBox_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyInvenUI.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyInvenUI_SetTextBox_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyInvenUI, nullptr, "SetTextBox", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyInvenUI_SetTextBox_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyInvenUI_SetTextBox_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_UMyInvenUI_SetTextBox()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyInvenUI_SetTextBox_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UMyInvenUI::execSetTextBox)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextBox();
	P_NATIVE_END;
}
// End Class UMyInvenUI Function SetTextBox

// Begin Class UMyInvenUI
void UMyInvenUI::StaticRegisterNativesUMyInvenUI()
{
	UClass* Class = UMyInvenUI::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "SetTextBox", &UMyInvenUI::execSetTextBox },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyInvenUI);
UClass* Z_Construct_UClass_UMyInvenUI_NoRegister()
{
	return UMyInvenUI::StaticClass();
}
struct Z_Construct_UClass_UMyInvenUI_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "MyInvenUI.h" },
		{ "ModuleRelativePath", "MyInvenUI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Grid_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "MyInvenUI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyInvenUI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Drop_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "MyInvenUI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyInvenUI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ItemInfo_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "MyInvenUI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyInvenUI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__slotButton_MetaData[] = {
		{ "Category", "MyInvenUI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyInvenUI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__slotImages_MetaData[] = {
		{ "Category", "MyInvenUI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyInvenUI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__potionTexture_MetaData[] = {
		{ "ModuleRelativePath", "MyInvenUI.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__defaultTexture_MetaData[] = {
		{ "ModuleRelativePath", "MyInvenUI.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Grid;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Drop;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ItemInfo;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__slotButton_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp__slotButton;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__slotImages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp__slotImages;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__potionTexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__defaultTexture;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyInvenUI_SetTextBox, "SetTextBox" }, // 257075118
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyInvenUI>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyInvenUI_Statics::NewProp_Grid = { "Grid", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyInvenUI, Grid), Z_Construct_UClass_UUniformGridPanel_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Grid_MetaData), NewProp_Grid_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyInvenUI_Statics::NewProp_Drop = { "Drop", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyInvenUI, Drop), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Drop_MetaData), NewProp_Drop_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyInvenUI_Statics::NewProp_ItemInfo = { "ItemInfo", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyInvenUI, ItemInfo), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ItemInfo_MetaData), NewProp_ItemInfo_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyInvenUI_Statics::NewProp__slotButton_Inner = { "_slotButton", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMyInvenUI_Statics::NewProp__slotButton = { "_slotButton", nullptr, (EPropertyFlags)0x001000800000000d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyInvenUI, _slotButton), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__slotButton_MetaData), NewProp__slotButton_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyInvenUI_Statics::NewProp__slotImages_Inner = { "_slotImages", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UMyInvenUI_Statics::NewProp__slotImages = { "_slotImages", nullptr, (EPropertyFlags)0x001000800000000d, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyInvenUI, _slotImages), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__slotImages_MetaData), NewProp__slotImages_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyInvenUI_Statics::NewProp__potionTexture = { "_potionTexture", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyInvenUI, _potionTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__potionTexture_MetaData), NewProp__potionTexture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMyInvenUI_Statics::NewProp__defaultTexture = { "_defaultTexture", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMyInvenUI, _defaultTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__defaultTexture_MetaData), NewProp__defaultTexture_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMyInvenUI_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInvenUI_Statics::NewProp_Grid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInvenUI_Statics::NewProp_Drop,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInvenUI_Statics::NewProp_ItemInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInvenUI_Statics::NewProp__slotButton_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInvenUI_Statics::NewProp__slotButton,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInvenUI_Statics::NewProp__slotImages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInvenUI_Statics::NewProp__slotImages,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInvenUI_Statics::NewProp__potionTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMyInvenUI_Statics::NewProp__defaultTexture,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyInvenUI_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UMyInvenUI_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_LDK_Prototype,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyInvenUI_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyInvenUI_Statics::ClassParams = {
	&UMyInvenUI::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UMyInvenUI_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UMyInvenUI_Statics::PropPointers),
	0,
	0x00B010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyInvenUI_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyInvenUI_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyInvenUI()
{
	if (!Z_Registration_Info_UClass_UMyInvenUI.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyInvenUI.OuterSingleton, Z_Construct_UClass_UMyInvenUI_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyInvenUI.OuterSingleton;
}
template<> LDK_PROTOTYPE_API UClass* StaticClass<UMyInvenUI>()
{
	return UMyInvenUI::StaticClass();
}
UMyInvenUI::UMyInvenUI(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyInvenUI);
UMyInvenUI::~UMyInvenUI() {}
// End Class UMyInvenUI

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyInvenUI_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyInvenUI, UMyInvenUI::StaticClass, TEXT("UMyInvenUI"), &Z_Registration_Info_UClass_UMyInvenUI, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyInvenUI), 4197182515U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyInvenUI_h_1645637685(TEXT("/Script/LDK_Prototype"),
	Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyInvenUI_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyInvenUI_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
