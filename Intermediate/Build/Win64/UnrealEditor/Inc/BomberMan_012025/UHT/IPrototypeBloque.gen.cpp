// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/IPrototypeBloque.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIPrototypeBloque() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_UIPrototypeBloque();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_UIPrototypeBloque_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Interface UIPrototypeBloque
void UIPrototypeBloque::StaticRegisterNativesUIPrototypeBloque()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UIPrototypeBloque);
UClass* Z_Construct_UClass_UIPrototypeBloque_NoRegister()
{
	return UIPrototypeBloque::StaticClass();
}
struct Z_Construct_UClass_UIPrototypeBloque_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "IPrototypeBloque.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IIPrototypeBloque>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UIPrototypeBloque_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UIPrototypeBloque_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UIPrototypeBloque_Statics::ClassParams = {
	&UIPrototypeBloque::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UIPrototypeBloque_Statics::Class_MetaDataParams), Z_Construct_UClass_UIPrototypeBloque_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UIPrototypeBloque()
{
	if (!Z_Registration_Info_UClass_UIPrototypeBloque.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UIPrototypeBloque.OuterSingleton, Z_Construct_UClass_UIPrototypeBloque_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UIPrototypeBloque.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<UIPrototypeBloque>()
{
	return UIPrototypeBloque::StaticClass();
}
UIPrototypeBloque::UIPrototypeBloque(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UIPrototypeBloque);
UIPrototypeBloque::~UIPrototypeBloque() {}
// End Interface UIPrototypeBloque

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_IPrototypeBloque_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UIPrototypeBloque, UIPrototypeBloque::StaticClass, TEXT("UIPrototypeBloque"), &Z_Registration_Info_UClass_UIPrototypeBloque, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UIPrototypeBloque), 154007193U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_IPrototypeBloque_h_4189947435(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_IPrototypeBloque_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_IPrototypeBloque_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
