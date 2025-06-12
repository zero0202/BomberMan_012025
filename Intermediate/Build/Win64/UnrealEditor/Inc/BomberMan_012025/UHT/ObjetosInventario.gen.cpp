// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/ObjetosInventario.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeObjetosInventario() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AObjetosInventario();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AObjetosInventario_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class AObjetosInventario
void AObjetosInventario::StaticRegisterNativesAObjetosInventario()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AObjetosInventario);
UClass* Z_Construct_UClass_AObjetosInventario_NoRegister()
{
	return AObjetosInventario::StaticClass();
}
struct Z_Construct_UClass_AObjetosInventario_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ObjetosInventario.h" },
		{ "ModuleRelativePath", "ObjetosInventario.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AObjetosInventario>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AObjetosInventario_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AObjetosInventario_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AObjetosInventario_Statics::ClassParams = {
	&AObjetosInventario::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AObjetosInventario_Statics::Class_MetaDataParams), Z_Construct_UClass_AObjetosInventario_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AObjetosInventario()
{
	if (!Z_Registration_Info_UClass_AObjetosInventario.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AObjetosInventario.OuterSingleton, Z_Construct_UClass_AObjetosInventario_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AObjetosInventario.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<AObjetosInventario>()
{
	return AObjetosInventario::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AObjetosInventario);
AObjetosInventario::~AObjetosInventario() {}
// End Class AObjetosInventario

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_ObjetosInventario_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AObjetosInventario, AObjetosInventario::StaticClass, TEXT("AObjetosInventario"), &Z_Registration_Info_UClass_AObjetosInventario, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AObjetosInventario), 175175920U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_ObjetosInventario_h_364805810(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_ObjetosInventario_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_ObjetosInventario_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
