// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/FabricaBloqueClasico.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFabricaBloqueClasico() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AFabricaBloqueClasico();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AFabricaBloqueClasico_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class AFabricaBloqueClasico
void AFabricaBloqueClasico::StaticRegisterNativesAFabricaBloqueClasico()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AFabricaBloqueClasico);
UClass* Z_Construct_UClass_AFabricaBloqueClasico_NoRegister()
{
	return AFabricaBloqueClasico::StaticClass();
}
struct Z_Construct_UClass_AFabricaBloqueClasico_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "FabricaBloqueClasico.h" },
		{ "ModuleRelativePath", "FabricaBloqueClasico.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFabricaBloqueClasico>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AFabricaBloqueClasico_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AFabricaBloqueClasico_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AFabricaBloqueClasico_Statics::ClassParams = {
	&AFabricaBloqueClasico::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AFabricaBloqueClasico_Statics::Class_MetaDataParams), Z_Construct_UClass_AFabricaBloqueClasico_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AFabricaBloqueClasico()
{
	if (!Z_Registration_Info_UClass_AFabricaBloqueClasico.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AFabricaBloqueClasico.OuterSingleton, Z_Construct_UClass_AFabricaBloqueClasico_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AFabricaBloqueClasico.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<AFabricaBloqueClasico>()
{
	return AFabricaBloqueClasico::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AFabricaBloqueClasico);
AFabricaBloqueClasico::~AFabricaBloqueClasico() {}
// End Class AFabricaBloqueClasico

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_FabricaBloqueClasico_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AFabricaBloqueClasico, AFabricaBloqueClasico::StaticClass, TEXT("AFabricaBloqueClasico"), &Z_Registration_Info_UClass_AFabricaBloqueClasico, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AFabricaBloqueClasico), 4189910248U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_FabricaBloqueClasico_h_4025063293(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_FabricaBloqueClasico_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_FabricaBloqueClasico_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
