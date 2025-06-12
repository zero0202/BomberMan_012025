// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/IElementoInventario.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIElementoInventario() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_UIElementoInventario();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_UIElementoInventario_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Interface UIElementoInventario
void UIElementoInventario::StaticRegisterNativesUIElementoInventario()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UIElementoInventario);
UClass* Z_Construct_UClass_UIElementoInventario_NoRegister()
{
	return UIElementoInventario::StaticClass();
}
struct Z_Construct_UClass_UIElementoInventario_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "IElementoInventario.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IIElementoInventario>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UIElementoInventario_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UIElementoInventario_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UIElementoInventario_Statics::ClassParams = {
	&UIElementoInventario::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UIElementoInventario_Statics::Class_MetaDataParams), Z_Construct_UClass_UIElementoInventario_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UIElementoInventario()
{
	if (!Z_Registration_Info_UClass_UIElementoInventario.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UIElementoInventario.OuterSingleton, Z_Construct_UClass_UIElementoInventario_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UIElementoInventario.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<UIElementoInventario>()
{
	return UIElementoInventario::StaticClass();
}
UIElementoInventario::UIElementoInventario(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UIElementoInventario);
UIElementoInventario::~UIElementoInventario() {}
// End Interface UIElementoInventario

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_IElementoInventario_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UIElementoInventario, UIElementoInventario::StaticClass, TEXT("UIElementoInventario"), &Z_Registration_Info_UClass_UIElementoInventario, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UIElementoInventario), 2843675054U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_IElementoInventario_h_1161256037(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_IElementoInventario_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_IElementoInventario_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
