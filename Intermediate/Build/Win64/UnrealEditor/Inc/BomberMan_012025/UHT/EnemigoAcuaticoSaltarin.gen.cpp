// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/EnemigoAcuaticoSaltarin.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemigoAcuaticoSaltarin() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigo();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoAcuaticoSaltarin();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoAcuaticoSaltarin_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class AEnemigoAcuaticoSaltarin
void AEnemigoAcuaticoSaltarin::StaticRegisterNativesAEnemigoAcuaticoSaltarin()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemigoAcuaticoSaltarin);
UClass* Z_Construct_UClass_AEnemigoAcuaticoSaltarin_NoRegister()
{
	return AEnemigoAcuaticoSaltarin::StaticClass();
}
struct Z_Construct_UClass_AEnemigoAcuaticoSaltarin_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EnemigoAcuaticoSaltarin.h" },
		{ "ModuleRelativePath", "EnemigoAcuaticoSaltarin.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemigoAcuaticoSaltarin>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AEnemigoAcuaticoSaltarin_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEnemigo,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAcuaticoSaltarin_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemigoAcuaticoSaltarin_Statics::ClassParams = {
	&AEnemigoAcuaticoSaltarin::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAcuaticoSaltarin_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemigoAcuaticoSaltarin_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEnemigoAcuaticoSaltarin()
{
	if (!Z_Registration_Info_UClass_AEnemigoAcuaticoSaltarin.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemigoAcuaticoSaltarin.OuterSingleton, Z_Construct_UClass_AEnemigoAcuaticoSaltarin_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEnemigoAcuaticoSaltarin.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<AEnemigoAcuaticoSaltarin>()
{
	return AEnemigoAcuaticoSaltarin::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemigoAcuaticoSaltarin);
AEnemigoAcuaticoSaltarin::~AEnemigoAcuaticoSaltarin() {}
// End Class AEnemigoAcuaticoSaltarin

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAcuaticoSaltarin_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEnemigoAcuaticoSaltarin, AEnemigoAcuaticoSaltarin::StaticClass, TEXT("AEnemigoAcuaticoSaltarin"), &Z_Registration_Info_UClass_AEnemigoAcuaticoSaltarin, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemigoAcuaticoSaltarin), 2526447458U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAcuaticoSaltarin_h_2818697439(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAcuaticoSaltarin_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAcuaticoSaltarin_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
