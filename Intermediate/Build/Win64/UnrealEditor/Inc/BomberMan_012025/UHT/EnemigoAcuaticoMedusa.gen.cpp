// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/EnemigoAcuaticoMedusa.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemigoAcuaticoMedusa() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigo();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoAcuaticoMedusa();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoAcuaticoMedusa_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class AEnemigoAcuaticoMedusa
void AEnemigoAcuaticoMedusa::StaticRegisterNativesAEnemigoAcuaticoMedusa()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemigoAcuaticoMedusa);
UClass* Z_Construct_UClass_AEnemigoAcuaticoMedusa_NoRegister()
{
	return AEnemigoAcuaticoMedusa::StaticClass();
}
struct Z_Construct_UClass_AEnemigoAcuaticoMedusa_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EnemigoAcuaticoMedusa.h" },
		{ "ModuleRelativePath", "EnemigoAcuaticoMedusa.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemigoAcuaticoMedusa>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AEnemigoAcuaticoMedusa_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEnemigo,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAcuaticoMedusa_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemigoAcuaticoMedusa_Statics::ClassParams = {
	&AEnemigoAcuaticoMedusa::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAcuaticoMedusa_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemigoAcuaticoMedusa_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEnemigoAcuaticoMedusa()
{
	if (!Z_Registration_Info_UClass_AEnemigoAcuaticoMedusa.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemigoAcuaticoMedusa.OuterSingleton, Z_Construct_UClass_AEnemigoAcuaticoMedusa_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEnemigoAcuaticoMedusa.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<AEnemigoAcuaticoMedusa>()
{
	return AEnemigoAcuaticoMedusa::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemigoAcuaticoMedusa);
AEnemigoAcuaticoMedusa::~AEnemigoAcuaticoMedusa() {}
// End Class AEnemigoAcuaticoMedusa

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAcuaticoMedusa_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEnemigoAcuaticoMedusa, AEnemigoAcuaticoMedusa::StaticClass, TEXT("AEnemigoAcuaticoMedusa"), &Z_Registration_Info_UClass_AEnemigoAcuaticoMedusa, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemigoAcuaticoMedusa), 3290751375U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAcuaticoMedusa_h_2548739026(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAcuaticoMedusa_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAcuaticoMedusa_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
