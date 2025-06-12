// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/EnemigoTerrestreTortuga.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemigoTerrestreTortuga() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigo();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoTerrestreTortuga();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoTerrestreTortuga_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class AEnemigoTerrestreTortuga
void AEnemigoTerrestreTortuga::StaticRegisterNativesAEnemigoTerrestreTortuga()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemigoTerrestreTortuga);
UClass* Z_Construct_UClass_AEnemigoTerrestreTortuga_NoRegister()
{
	return AEnemigoTerrestreTortuga::StaticClass();
}
struct Z_Construct_UClass_AEnemigoTerrestreTortuga_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EnemigoTerrestreTortuga.h" },
		{ "ModuleRelativePath", "EnemigoTerrestreTortuga.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemigoTerrestreTortuga>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AEnemigoTerrestreTortuga_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEnemigo,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoTerrestreTortuga_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemigoTerrestreTortuga_Statics::ClassParams = {
	&AEnemigoTerrestreTortuga::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoTerrestreTortuga_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemigoTerrestreTortuga_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEnemigoTerrestreTortuga()
{
	if (!Z_Registration_Info_UClass_AEnemigoTerrestreTortuga.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemigoTerrestreTortuga.OuterSingleton, Z_Construct_UClass_AEnemigoTerrestreTortuga_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEnemigoTerrestreTortuga.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<AEnemigoTerrestreTortuga>()
{
	return AEnemigoTerrestreTortuga::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemigoTerrestreTortuga);
AEnemigoTerrestreTortuga::~AEnemigoTerrestreTortuga() {}
// End Class AEnemigoTerrestreTortuga

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoTerrestreTortuga_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEnemigoTerrestreTortuga, AEnemigoTerrestreTortuga::StaticClass, TEXT("AEnemigoTerrestreTortuga"), &Z_Registration_Info_UClass_AEnemigoTerrestreTortuga, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemigoTerrestreTortuga), 3312582908U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoTerrestreTortuga_h_3542918709(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoTerrestreTortuga_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoTerrestreTortuga_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
