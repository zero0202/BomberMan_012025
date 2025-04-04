// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BomberMan_012025/EnemigoAereoTransportador.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemigoAereoTransportador() {}

// Begin Cross Module References
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoAereo();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoAereoTransportador();
BOMBERMAN_012025_API UClass* Z_Construct_UClass_AEnemigoAereoTransportador_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ACharacter_NoRegister();
UPackage* Z_Construct_UPackage__Script_BomberMan_012025();
// End Cross Module References

// Begin Class AEnemigoAereoTransportador
void AEnemigoAereoTransportador::StaticRegisterNativesAEnemigoAereoTransportador()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemigoAereoTransportador);
UClass* Z_Construct_UClass_AEnemigoAereoTransportador_NoRegister()
{
	return AEnemigoAereoTransportador::StaticClass();
}
struct Z_Construct_UClass_AEnemigoAereoTransportador_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "EnemigoAereoTransportador.h" },
		{ "ModuleRelativePath", "EnemigoAereoTransportador.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Radio_MetaData[] = {
		{ "Category", "Movimiento" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Ruta circular\n" },
#endif
		{ "ModuleRelativePath", "EnemigoAereoTransportador.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Ruta circular" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlturaFlotante_MetaData[] = {
		{ "Category", "Movimiento" },
		{ "ModuleRelativePath", "EnemigoAereoTransportador.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VelocidadAngular_MetaData[] = {
		{ "Category", "Movimiento" },
		{ "ModuleRelativePath", "EnemigoAereoTransportador.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPersonajeMontado_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// grados por segundo\n" },
#endif
		{ "ModuleRelativePath", "EnemigoAereoTransportador.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "grados por segundo" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PersonajeActual_MetaData[] = {
		{ "ModuleRelativePath", "EnemigoAereoTransportador.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radio;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AlturaFlotante;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_VelocidadAngular;
	static void NewProp_bPersonajeMontado_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPersonajeMontado;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_PersonajeActual;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemigoAereoTransportador>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemigoAereoTransportador_Statics::NewProp_Radio = { "Radio", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemigoAereoTransportador, Radio), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Radio_MetaData), NewProp_Radio_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemigoAereoTransportador_Statics::NewProp_AlturaFlotante = { "AlturaFlotante", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemigoAereoTransportador, AlturaFlotante), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlturaFlotante_MetaData), NewProp_AlturaFlotante_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AEnemigoAereoTransportador_Statics::NewProp_VelocidadAngular = { "VelocidadAngular", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemigoAereoTransportador, VelocidadAngular), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VelocidadAngular_MetaData), NewProp_VelocidadAngular_MetaData) };
void Z_Construct_UClass_AEnemigoAereoTransportador_Statics::NewProp_bPersonajeMontado_SetBit(void* Obj)
{
	((AEnemigoAereoTransportador*)Obj)->bPersonajeMontado = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AEnemigoAereoTransportador_Statics::NewProp_bPersonajeMontado = { "bPersonajeMontado", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AEnemigoAereoTransportador), &Z_Construct_UClass_AEnemigoAereoTransportador_Statics::NewProp_bPersonajeMontado_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPersonajeMontado_MetaData), NewProp_bPersonajeMontado_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AEnemigoAereoTransportador_Statics::NewProp_PersonajeActual = { "PersonajeActual", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AEnemigoAereoTransportador, PersonajeActual), Z_Construct_UClass_ACharacter_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PersonajeActual_MetaData), NewProp_PersonajeActual_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AEnemigoAereoTransportador_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigoAereoTransportador_Statics::NewProp_Radio,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigoAereoTransportador_Statics::NewProp_AlturaFlotante,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigoAereoTransportador_Statics::NewProp_VelocidadAngular,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigoAereoTransportador_Statics::NewProp_bPersonajeMontado,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AEnemigoAereoTransportador_Statics::NewProp_PersonajeActual,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAereoTransportador_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AEnemigoAereoTransportador_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AEnemigoAereo,
	(UObject* (*)())Z_Construct_UPackage__Script_BomberMan_012025,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAereoTransportador_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemigoAereoTransportador_Statics::ClassParams = {
	&AEnemigoAereoTransportador::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AEnemigoAereoTransportador_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAereoTransportador_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemigoAereoTransportador_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemigoAereoTransportador_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AEnemigoAereoTransportador()
{
	if (!Z_Registration_Info_UClass_AEnemigoAereoTransportador.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemigoAereoTransportador.OuterSingleton, Z_Construct_UClass_AEnemigoAereoTransportador_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AEnemigoAereoTransportador.OuterSingleton;
}
template<> BOMBERMAN_012025_API UClass* StaticClass<AEnemigoAereoTransportador>()
{
	return AEnemigoAereoTransportador::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemigoAereoTransportador);
AEnemigoAereoTransportador::~AEnemigoAereoTransportador() {}
// End Class AEnemigoAereoTransportador

// Begin Registration
struct Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereoTransportador_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AEnemigoAereoTransportador, AEnemigoAereoTransportador::StaticClass, TEXT("AEnemigoAereoTransportador"), &Z_Registration_Info_UClass_AEnemigoAereoTransportador, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemigoAereoTransportador), 1570581974U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereoTransportador_h_1046044883(TEXT("/Script/BomberMan_012025"),
	Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereoTransportador_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_BomberMan_012025_Source_BomberMan_012025_EnemigoAereoTransportador_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
