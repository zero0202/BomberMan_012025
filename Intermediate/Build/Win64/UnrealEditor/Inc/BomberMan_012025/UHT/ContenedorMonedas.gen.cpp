// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/ContenedorMonedas.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeContenedorMonedas() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AContenedorMonedas();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AContenedorMonedas_NoRegister();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_UIElementoInventario_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class AContenedorMonedas
void AContenedorMonedas::StaticRegisterNativesAContenedorMonedas()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AContenedorMonedas);
UClass* Z_Construct_UClass_AContenedorMonedas_NoRegister()
{
	return AContenedorMonedas::StaticClass();
}
struct Z_Construct_UClass_AContenedorMonedas_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ContenedorMonedas.h" },
		{ "ModuleRelativePath", "ContenedorMonedas.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AContenedorMonedas>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AContenedorMonedas_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AContenedorMonedas_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_AContenedorMonedas_Statics::InterfaceParams[] = {
	{ Z_Construct_UClass_UIElementoInventario_NoRegister, (int32)VTABLE_OFFSET(AContenedorMonedas, IIElementoInventario), false },  // 2843675054
};
const UECodeGen_Private::FClassParams Z_Construct_UClass_AContenedorMonedas_Statics::ClassParams = {
	&AContenedorMonedas::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	InterfaceParams,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	UE_ARRAY_COUNT(InterfaceParams),
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AContenedorMonedas_Statics::Class_MetaDataParams), Z_Construct_UClass_AContenedorMonedas_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AContenedorMonedas()
{
	if (!Z_Registration_Info_UClass_AContenedorMonedas.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AContenedorMonedas.OuterSingleton, Z_Construct_UClass_AContenedorMonedas_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AContenedorMonedas.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<AContenedorMonedas>()
{
	return AContenedorMonedas::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AContenedorMonedas);
AContenedorMonedas::~AContenedorMonedas() {}
// End Class AContenedorMonedas

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_ContenedorMonedas_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AContenedorMonedas, AContenedorMonedas::StaticClass, TEXT("AContenedorMonedas"), &Z_Registration_Info_UClass_AContenedorMonedas, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AContenedorMonedas), 2011436588U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_ContenedorMonedas_h_1074032651(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_ContenedorMonedas_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_ContenedorMonedas_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
