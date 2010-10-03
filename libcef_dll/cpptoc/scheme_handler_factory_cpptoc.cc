// Copyright (c) 2009 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/cpptoc/scheme_handler_cpptoc.h"
#include "libcef_dll/cpptoc/scheme_handler_factory_cpptoc.h"


// MEMBER FUNCTIONS - Body may be edited by hand.

struct _cef_scheme_handler_t* CEF_CALLBACK scheme_handler_factory_create(
    struct _cef_scheme_handler_factory_t* self)
{
  CefRefPtr<CefSchemeHandler> rv =
      CefSchemeHandlerFactoryCppToC::Get(self)->Create();

  return CefSchemeHandlerCppToC::Wrap(rv);
}


// CONSTRUCTOR - Do not edit by hand.

CefSchemeHandlerFactoryCppToC::CefSchemeHandlerFactoryCppToC(
    CefSchemeHandlerFactory* cls)
    : CefCppToC<CefSchemeHandlerFactoryCppToC, CefSchemeHandlerFactory,
        cef_scheme_handler_factory_t>(cls)
{
  struct_.struct_.create = scheme_handler_factory_create;
}

#ifdef _DEBUG
long CefCppToC<CefSchemeHandlerFactoryCppToC, CefSchemeHandlerFactory,
    cef_scheme_handler_factory_t>::DebugObjCt = 0;
#endif

