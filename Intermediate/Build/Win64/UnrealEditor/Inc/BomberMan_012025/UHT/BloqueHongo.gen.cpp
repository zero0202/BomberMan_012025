// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/BloqueHongo.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueHongo() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloque();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueHongo();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueHongo_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueHongo
void ABloqueHongo::StaticRegisterNativesABloqueHongo()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueHongo);
UClass* Z_Construct_UClass_ABloqueHongo_NoRegister()
{
	return ABloqueHongo::StaticClass();
}
struct Z_Construct_UClass_ABloqueHongo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueHongo.h" },
		{ "ModuleRelativePath", "BloqueHongo.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueHongo>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloqueHongo_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloque,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueHongo_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueHongo_Statics::ClassParams = {
	&ABloqueHongo::StaticClass,
	"Engine",
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueHongo_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueHongo_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueHongo()
{
	if (!Z_Registration_Info_UClass_ABloqueHongo.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueHongo.OuterSingleton, Z_Construct_UClass_ABloqueHongo_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueHongo.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueHongo>()
{
	return ABloqueHongo::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueHongo);
ABloqueHongo::~ABloqueHongo() {}
// End Class ABloqueHongo

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueHongo_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueHongo, ABloqueHongo::StaticClass, TEXT("ABloqueHongo"), &Z_Registration_Info_UClass_ABloqueHongo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueHongo), 1231037528U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueHongo_h_2357826219(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueHongo_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueHongo_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
