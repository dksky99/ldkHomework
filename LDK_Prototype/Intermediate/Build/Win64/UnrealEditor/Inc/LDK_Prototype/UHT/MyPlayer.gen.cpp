// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LDK_Prototype/MyPlayer.h"
#include "EnhancedInput/Public/InputActionValue.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyPlayer() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
ENHANCEDINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FInputActionValue();
LDK_PROTOTYPE_API UClass* Z_Construct_UClass_AMyCharacter();
LDK_PROTOTYPE_API UClass* Z_Construct_UClass_AMyPlayer();
LDK_PROTOTYPE_API UClass* Z_Construct_UClass_AMyPlayer_NoRegister();
LDK_PROTOTYPE_API UClass* Z_Construct_UClass_UMyInvenComponent_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_LDK_Prototype();
// End Cross Module References

// Begin Class AMyPlayer Function Attack
struct Z_Construct_UFunction_AMyPlayer_Attack_Statics
{
	struct MyPlayer_eventAttack_Parms
	{
		FInputActionValue value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyPlayer_Attack_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPlayer_eventAttack_Parms, value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_value_MetaData), NewProp_value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyPlayer_Attack_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayer_Attack_Statics::NewProp_value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_Attack_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayer_Attack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayer, nullptr, "Attack", nullptr, nullptr, Z_Construct_UFunction_AMyPlayer_Attack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_Attack_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMyPlayer_Attack_Statics::MyPlayer_eventAttack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_Attack_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayer_Attack_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMyPlayer_Attack_Statics::MyPlayer_eventAttack_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMyPlayer_Attack()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayer_Attack_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayer::execAttack)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Attack(Z_Param_Out_value);
	P_NATIVE_END;
}
// End Class AMyPlayer Function Attack

// Begin Class AMyPlayer Function Drop
struct Z_Construct_UFunction_AMyPlayer_Drop_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayer_Drop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayer, nullptr, "Drop", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_Drop_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayer_Drop_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AMyPlayer_Drop()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayer_Drop_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayer::execDrop)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Drop();
	P_NATIVE_END;
}
// End Class AMyPlayer Function Drop

// Begin Class AMyPlayer Function DropItem
struct Z_Construct_UFunction_AMyPlayer_DropItem_Statics
{
	struct MyPlayer_eventDropItem_Parms
	{
		FInputActionValue value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyPlayer_DropItem_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPlayer_eventDropItem_Parms, value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_value_MetaData), NewProp_value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyPlayer_DropItem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayer_DropItem_Statics::NewProp_value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_DropItem_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayer_DropItem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayer, nullptr, "DropItem", nullptr, nullptr, Z_Construct_UFunction_AMyPlayer_DropItem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_DropItem_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMyPlayer_DropItem_Statics::MyPlayer_eventDropItem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_DropItem_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayer_DropItem_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMyPlayer_DropItem_Statics::MyPlayer_eventDropItem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMyPlayer_DropItem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayer_DropItem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayer::execDropItem)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->DropItem(Z_Param_Out_value);
	P_NATIVE_END;
}
// End Class AMyPlayer Function DropItem

// Begin Class AMyPlayer Function InvenOpen
struct Z_Construct_UFunction_AMyPlayer_InvenOpen_Statics
{
	struct MyPlayer_eventInvenOpen_Parms
	{
		FInputActionValue value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyPlayer_InvenOpen_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPlayer_eventInvenOpen_Parms, value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_value_MetaData), NewProp_value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyPlayer_InvenOpen_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayer_InvenOpen_Statics::NewProp_value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_InvenOpen_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayer_InvenOpen_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayer, nullptr, "InvenOpen", nullptr, nullptr, Z_Construct_UFunction_AMyPlayer_InvenOpen_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_InvenOpen_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMyPlayer_InvenOpen_Statics::MyPlayer_eventInvenOpen_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_InvenOpen_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayer_InvenOpen_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMyPlayer_InvenOpen_Statics::MyPlayer_eventInvenOpen_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMyPlayer_InvenOpen()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayer_InvenOpen_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayer::execInvenOpen)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->InvenOpen(Z_Param_Out_value);
	P_NATIVE_END;
}
// End Class AMyPlayer Function InvenOpen

// Begin Class AMyPlayer Function Look
struct Z_Construct_UFunction_AMyPlayer_Look_Statics
{
	struct MyPlayer_eventLook_Parms
	{
		FInputActionValue value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyPlayer_Look_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPlayer_eventLook_Parms, value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_value_MetaData), NewProp_value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyPlayer_Look_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayer_Look_Statics::NewProp_value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_Look_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayer_Look_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayer, nullptr, "Look", nullptr, nullptr, Z_Construct_UFunction_AMyPlayer_Look_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_Look_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMyPlayer_Look_Statics::MyPlayer_eventLook_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_Look_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayer_Look_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMyPlayer_Look_Statics::MyPlayer_eventLook_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMyPlayer_Look()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayer_Look_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayer::execLook)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Look(Z_Param_Out_value);
	P_NATIVE_END;
}
// End Class AMyPlayer Function Look

// Begin Class AMyPlayer Function Move
struct Z_Construct_UFunction_AMyPlayer_Move_Statics
{
	struct MyPlayer_eventMove_Parms
	{
		FInputActionValue value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Called every frame\n" },
#endif
		{ "ModuleRelativePath", "MyPlayer.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Called every frame" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyPlayer_Move_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPlayer_eventMove_Parms, value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_value_MetaData), NewProp_value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyPlayer_Move_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayer_Move_Statics::NewProp_value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_Move_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayer_Move_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayer, nullptr, "Move", nullptr, nullptr, Z_Construct_UFunction_AMyPlayer_Move_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_Move_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMyPlayer_Move_Statics::MyPlayer_eventMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_Move_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayer_Move_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMyPlayer_Move_Statics::MyPlayer_eventMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMyPlayer_Move()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayer_Move_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayer::execMove)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Move(Z_Param_Out_value);
	P_NATIVE_END;
}
// End Class AMyPlayer Function Move

// Begin Class AMyPlayer Function TryJump
struct Z_Construct_UFunction_AMyPlayer_TryJump_Statics
{
	struct MyPlayer_eventTryJump_Parms
	{
		FInputActionValue value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMyPlayer_TryJump_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyPlayer_eventTryJump_Parms, value), Z_Construct_UScriptStruct_FInputActionValue, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_value_MetaData), NewProp_value_MetaData) }; // 494646648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyPlayer_TryJump_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyPlayer_TryJump_Statics::NewProp_value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_TryJump_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyPlayer_TryJump_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyPlayer, nullptr, "TryJump", nullptr, nullptr, Z_Construct_UFunction_AMyPlayer_TryJump_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_TryJump_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMyPlayer_TryJump_Statics::MyPlayer_eventTryJump_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMyPlayer_TryJump_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMyPlayer_TryJump_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AMyPlayer_TryJump_Statics::MyPlayer_eventTryJump_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AMyPlayer_TryJump()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMyPlayer_TryJump_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AMyPlayer::execTryJump)
{
	P_GET_STRUCT_REF(FInputActionValue,Z_Param_Out_value);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->TryJump(Z_Param_Out_value);
	P_NATIVE_END;
}
// End Class AMyPlayer Function TryJump

// Begin Class AMyPlayer
void AMyPlayer::StaticRegisterNativesAMyPlayer()
{
	UClass* Class = AMyPlayer::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "Attack", &AMyPlayer::execAttack },
		{ "Drop", &AMyPlayer::execDrop },
		{ "DropItem", &AMyPlayer::execDropItem },
		{ "InvenOpen", &AMyPlayer::execInvenOpen },
		{ "Look", &AMyPlayer::execLook },
		{ "Move", &AMyPlayer::execMove },
		{ "TryJump", &AMyPlayer::execTryJump },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMyPlayer);
UClass* Z_Construct_UClass_AMyPlayer_NoRegister()
{
	return AMyPlayer::StaticClass();
}
struct Z_Construct_UClass_AMyPlayer_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyPlayer.h" },
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__moveAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__lookAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__jumpAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__attackAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__itemDropAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__invenAction_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__camera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__springArm_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__InvenComponent_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Input" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp__invenWidget_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Item" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MyPlayer.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp__moveAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__lookAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__jumpAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__attackAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__itemDropAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__invenAction;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__camera;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__springArm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__InvenComponent;
	static const UECodeGen_Private::FObjectPropertyParams NewProp__invenWidget;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyPlayer_Attack, "Attack" }, // 3856583915
		{ &Z_Construct_UFunction_AMyPlayer_Drop, "Drop" }, // 1458026462
		{ &Z_Construct_UFunction_AMyPlayer_DropItem, "DropItem" }, // 2968698394
		{ &Z_Construct_UFunction_AMyPlayer_InvenOpen, "InvenOpen" }, // 1780298486
		{ &Z_Construct_UFunction_AMyPlayer_Look, "Look" }, // 2844395973
		{ &Z_Construct_UFunction_AMyPlayer_Move, "Move" }, // 344632220
		{ &Z_Construct_UFunction_AMyPlayer_TryJump, "TryJump" }, // 3401814335
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyPlayer>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyPlayer_Statics::NewProp__moveAction = { "_moveAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayer, _moveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__moveAction_MetaData), NewProp__moveAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyPlayer_Statics::NewProp__lookAction = { "_lookAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayer, _lookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__lookAction_MetaData), NewProp__lookAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyPlayer_Statics::NewProp__jumpAction = { "_jumpAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayer, _jumpAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__jumpAction_MetaData), NewProp__jumpAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyPlayer_Statics::NewProp__attackAction = { "_attackAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayer, _attackAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__attackAction_MetaData), NewProp__attackAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyPlayer_Statics::NewProp__itemDropAction = { "_itemDropAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayer, _itemDropAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__itemDropAction_MetaData), NewProp__itemDropAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyPlayer_Statics::NewProp__invenAction = { "_invenAction", nullptr, (EPropertyFlags)0x0040000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayer, _invenAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__invenAction_MetaData), NewProp__invenAction_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyPlayer_Statics::NewProp__camera = { "_camera", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayer, _camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__camera_MetaData), NewProp__camera_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyPlayer_Statics::NewProp__springArm = { "_springArm", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayer, _springArm), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__springArm_MetaData), NewProp__springArm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyPlayer_Statics::NewProp__InvenComponent = { "_InvenComponent", nullptr, (EPropertyFlags)0x004000000008001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayer, _InvenComponent), Z_Construct_UClass_UMyInvenComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__InvenComponent_MetaData), NewProp__InvenComponent_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyPlayer_Statics::NewProp__invenWidget = { "_invenWidget", nullptr, (EPropertyFlags)0x00400000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMyPlayer, _invenWidget), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp__invenWidget_MetaData), NewProp__invenWidget_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyPlayer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayer_Statics::NewProp__moveAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayer_Statics::NewProp__lookAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayer_Statics::NewProp__jumpAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayer_Statics::NewProp__attackAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayer_Statics::NewProp__itemDropAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayer_Statics::NewProp__invenAction,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayer_Statics::NewProp__camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayer_Statics::NewProp__springArm,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayer_Statics::NewProp__InvenComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyPlayer_Statics::NewProp__invenWidget,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayer_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AMyPlayer_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AMyCharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_LDK_Prototype,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayer_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AMyPlayer_Statics::ClassParams = {
	&AMyPlayer::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AMyPlayer_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayer_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMyPlayer_Statics::Class_MetaDataParams), Z_Construct_UClass_AMyPlayer_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AMyPlayer()
{
	if (!Z_Registration_Info_UClass_AMyPlayer.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMyPlayer.OuterSingleton, Z_Construct_UClass_AMyPlayer_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AMyPlayer.OuterSingleton;
}
template<> LDK_PROTOTYPE_API UClass* StaticClass<AMyPlayer>()
{
	return AMyPlayer::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AMyPlayer);
AMyPlayer::~AMyPlayer() {}
// End Class AMyPlayer

// Begin Registration
struct Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyPlayer_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AMyPlayer, AMyPlayer::StaticClass, TEXT("AMyPlayer"), &Z_Registration_Info_UClass_AMyPlayer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMyPlayer), 3691024997U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyPlayer_h_2102188796(TEXT("/Script/LDK_Prototype"),
	Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyPlayer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Git_ldkHomework_ldkHomework_LDK_Prototype_Source_LDK_Prototype_MyPlayer_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
