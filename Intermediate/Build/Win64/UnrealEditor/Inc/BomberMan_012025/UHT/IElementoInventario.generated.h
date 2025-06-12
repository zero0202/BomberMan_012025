// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "IElementoInventario.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BOMBERMAN_012025_IElementoInventario_generated_h
#error "IElementoInventario.generated.h already included, missing '#pragma once' in IElementoInventario.h"
#endif
#define BOMBERMAN_012025_IElementoInventario_generated_h

#define FID_BomberMan_012025_Source_BomberMan_012025_IElementoInventario_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	BOMBERMAN_012025_API UIElementoInventario(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UIElementoInventario(UIElementoInventario&&); \
	UIElementoInventario(const UIElementoInventario&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(BOMBERMAN_012025_API, UIElementoInventario); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UIElementoInventario); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UIElementoInventario) \
	BOMBERMAN_012025_API virtual ~UIElementoInventario();


#define FID_BomberMan_012025_Source_BomberMan_012025_IElementoInventario_h_13_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUIElementoInventario(); \
	friend struct Z_Construct_UClass_UIElementoInventario_Statics; \
public: \
	DECLARE_CLASS(UIElementoInventario, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/BomberMan_012025"), BOMBERMAN_012025_API) \
	DECLARE_SERIALIZER(UIElementoInventario)


#define FID_BomberMan_012025_Source_BomberMan_012025_IElementoInventario_h_13_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_BomberMan_012025_Source_BomberMan_012025_IElementoInventario_h_13_GENERATED_UINTERFACE_BODY() \
	FID_BomberMan_012025_Source_BomberMan_012025_IElementoInventario_h_13_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_BomberMan_012025_Source_BomberMan_012025_IElementoInventario_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IIElementoInventario() {} \
public: \
	typedef UIElementoInventario UClassType; \
	typedef IIElementoInventario ThisClass; \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_BomberMan_012025_Source_BomberMan_012025_IElementoInventario_h_10_PROLOG
#define FID_BomberMan_012025_Source_BomberMan_012025_IElementoInventario_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_BomberMan_012025_Source_BomberMan_012025_IElementoInventario_h_13_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BOMBERMAN_012025_API UClass* StaticClass<class UIElementoInventario>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_BomberMan_012025_Source_BomberMan_012025_IElementoInventario_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
