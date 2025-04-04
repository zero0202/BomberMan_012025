// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/BloquePegajoso.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBloquePegajoso() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloque();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloquePegajoso();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_ABloquePegajoso_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class ABloquePegajoso
void ABloquePegajoso::StaticRegisterNativesABloquePegajoso()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABloquePegajoso);
UClass* Z_Construct_UClass_ABloquePegajoso_NoRegister()
{
	return ABloquePegajoso::StaticClass();
}
struct Z_Construct_UClass_ABloquePegajoso_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BloquePegajoso.h" },
		{ "ModuleRelativePath", "BloquePegajoso.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABloquePegajoso>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ABloquePegajoso_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ABloque,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABloquePegajoso_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ABloquePegajoso_Statics::ClassParams = {
	&ABloquePegajoso::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABloquePegajoso_Statics::Class_MetaDataParams), Z_Construct_UClass_ABloquePegajoso_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ABloquePegajoso()
{
	if (!Z_Registration_Info_UClass_ABloquePegajoso.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABloquePegajoso.OuterSingleton, Z_Construct_UClass_ABloquePegajoso_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ABloquePegajoso.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<ABloquePegajoso>()
{
	return ABloquePegajoso::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ABloquePegajoso);
ABloquePegajoso::~ABloquePegajoso() {}
// End Class ABloquePegajoso

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloquePegajoso_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ABloquePegajoso, ABloquePegajoso::StaticClass, TEXT("ABloquePegajoso"), &Z_Registration_Info_UClass_ABloquePegajoso, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABloquePegajoso), 109555006U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloquePegajoso_h_2523015270(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloquePegajoso_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_BloquePegajoso_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
