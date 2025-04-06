// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "EnemigoSubterraneoEmboscador.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UPrimitiveComponent;
struct FHitResult;
#ifdef BOMBERMAN_012025_EnemigoSubterraneoEmboscador_generated_h
#error "EnemigoSubterraneoEmboscador.generated.h already included, missing '#pragma once' in EnemigoSubterraneoEmboscador.h"
#endif
#define BOMBERMAN_012025_EnemigoSubterraneoEmboscador_generated_h

#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoSubterraneoEmboscador_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnCollisionWithPlayer);


#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoSubterraneoEmboscador_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAEnemigoSubterraneoEmboscador(); \
	friend struct Z_Construct_UClass_AEnemigoSubterraneoEmboscador_Statics; \
public: \
	DECLARE_CLASS(AEnemigoSubterraneoEmboscador, AEnemigo, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BomberMan_012025"), NO_API) \
	DECLARE_SERIALIZER(AEnemigoSubterraneoEmboscador)


#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoSubterraneoEmboscador_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AEnemigoSubterraneoEmboscador(AEnemigoSubterraneoEmboscador&&); \
	AEnemigoSubterraneoEmboscador(const AEnemigoSubterraneoEmboscador&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AEnemigoSubterraneoEmboscador); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AEnemigoSubterraneoEmboscador); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AEnemigoSubterraneoEmboscador) \
	NO_API virtual ~AEnemigoSubterraneoEmboscador();


#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoSubterraneoEmboscador_h_12_PROLOG
#define FID_BomberMan_012025_Source_BomberMan_012025_EnemigoSubterraneoEmboscador_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_BomberMan_012025_Source_BomberMan_012025_EnemigoSubterraneoEmboscador_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_BomberMan_012025_Source_BomberMan_012025_EnemigoSubterraneoEmboscador_h_15_INCLASS_NO_PURE_DECLS \
	FID_BomberMan_012025_Source_BomberMan_012025_EnemigoSubterraneoEmboscador_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BOMBERMAN_012025_API UClass* StaticClass<class AEnemigoSubterraneoEmboscador>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_BomberMan_012025_Source_BomberMan_012025_EnemigoSubterraneoEmboscador_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
