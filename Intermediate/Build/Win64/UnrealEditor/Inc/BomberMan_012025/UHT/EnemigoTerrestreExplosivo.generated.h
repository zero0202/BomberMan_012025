// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EnemigoTerrestreExplosivo.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef BOMBERMAN_012025_EnemigoTerrestreExplosivo_generated_h
#error "EnemigoTerrestreExplosivo.generated.h already included, missing '#pragma once' in EnemigoTerrestreExplosivo.h"
#endif
#define BOMBERMAN_012025_EnemigoTerrestreExplosivo_generated_h

#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoTerrestreExplosivo_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnOverlapBegin);


#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoTerrestreExplosivo_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemigoTerrestreExplosivo(); \
	friend struct Z_Construct_UClass_AEnemigoTerrestreExplosivo_Statics; \
public: \
	DECLARE_CLASS(AEnemigoTerrestreExplosivo, AEnemigo, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BomberMan_012025"), NO_API) \
	DECLARE_SERIALIZER(AEnemigoTerrestreExplosivo)


#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoTerrestreExplosivo_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AEnemigoTerrestreExplosivo(AEnemigoTerrestreExplosivo&&); \
	AEnemigoTerrestreExplosivo(const AEnemigoTerrestreExplosivo&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemigoTerrestreExplosivo); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemigoTerrestreExplosivo); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemigoTerrestreExplosivo) \
	NO_API virtual ~AEnemigoTerrestreExplosivo();


#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoTerrestreExplosivo_h_13_PROLOG
#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoTerrestreExplosivo_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_BomberMan_012025_Source_BomberMan_012025_EnemigoTerrestreExplosivo_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_BomberMan_012025_Source_BomberMan_012025_EnemigoTerrestreExplosivo_h_16_INCLASS_NO_PURE_DECLS \
	FID_BomberMan_012025_Source_BomberMan_012025_EnemigoTerrestreExplosivo_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BOMBERMAN_012025_API UClass* StaticClass<class AEnemigoTerrestreExplosivo>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_BomberMan_012025_Source_BomberMan_012025_EnemigoTerrestreExplosivo_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
