// Copyright (c) 2010 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// A portion of this file was generated by the CEF translator tool.  When
// making changes by hand only do so within the body of existing static and
// virtual method implementations. See the translator.README.txt file in the
// tools directory for more information.
//

#include "libcef_dll/ctocpp/scheme_handler_ctocpp.h"
#include "libcef_dll/ctocpp/scheme_handler_factory_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

CefRefPtr<CefSchemeHandler> CefSchemeHandlerFactoryCToCpp::Create()
{
  if(CEF_MEMBER_MISSING(struct_, create))
    return NULL;

  _cef_scheme_handler_t* rv = struct_->create(struct_);

  return CefSchemeHandlerCToCpp::Wrap(rv);
}


#ifdef _DEBUG
template<> long CefCToCpp<CefSchemeHandlerFactoryCToCpp,
    CefSchemeHandlerFactory, cef_scheme_handler_factory_t>::DebugObjCt = 0;
#endif

