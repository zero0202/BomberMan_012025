// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/BloqueMovil.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloqueMovil() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloque();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueMovil();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloqueMovil_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloqueMovil
void ABloqueMovil::StaticRegisterNativesABloqueMovil()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloqueMovil);
UClass* Z_Construct_UClass_ABloqueMovil_NoRegister()
{
	return ABloqueMovil::StaticClass();
}
struct Z_Construct_UClass_ABloqueMovil_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloqueMovil.h" },
		{ "ModuleRelativePath", "BloqueMovil.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloqueMovil>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloqueMovil_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloque,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueMovil_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloqueMovil_Statics::ClassParams = {
	&ABloqueMovil::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloqueMovil_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloqueMovil_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloqueMovil()
{
	if (!Z_Registration_Info_UClass_ABloqueMovil.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloqueMovil.OuterSingleton, Z_Construct_UClass_ABloqueMovil_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloqueMovil.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloqueMovil>()
{
	return ABloqueMovil::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloqueMovil);
ABloqueMovil::~ABloqueMovil() {}
// End Class ABloqueMovil

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueMovil_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloqueMovil, ABloqueMovil::StaticClass, TEXT("ABloqueMovil"), &Z_Registration_Info_UClass_ABloqueMovil, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloqueMovil), 409271507U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueMovil_h_783846467(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueMovil_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloqueMovil_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
