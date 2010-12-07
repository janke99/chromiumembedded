# Copyright (c) 2010 The Chromium Embedded Framework Authors. All rights
# reserved. Use of this source code is governed by a BSD-style license that
# can be found in the LICENSE file.

from cef_parser import *

def make_ctocpp_impl_proto(clsname, name, func, parts):
    proto = parts['retval']+' '+clsname
    const = ''
    if isinstance(func, obj_function_virtual):
        proto += 'CToCpp'
        if func.is_const():
            const = ' const'
    
    proto += '::'+name+'('+string.join(parts['args'], ', ')+')'+const
    return wrap_code(proto)

def make_ctocpp_impl_existing(clsname, name, func, impl):
    # retrieve the C++ prototype parts
    parts = func.get_cpp_parts(True)
    
    changes = format_translation_changes(impl, parts)
    if len(changes) > 0:
        if isinstance(func, obj_function_virtual):
            notify('Changed prototype for '+clsname+'CToCpp::'+name)
        else:
            notify('Changed prototype for '+clsname+'::'+name)
    
    return make_ctocpp_impl_proto(clsname, name, func, parts)+'{'+ \
           changes+impl['body']+'\n}\n\n'

def make_ctocpp_impl_new(clsname, name, func):
    if isinstance(func, obj_function_virtual):
        notify('Added implementation for '+clsname+'CToCpp::'+name)
    else:
        notify('Added implementation for '+clsname+'::'+name)
    
    # retrieve the C++ prototype parts
    parts = func.get_cpp_parts(True)
    result = make_ctocpp_impl_proto(clsname, name, func, parts)+'{'
    
    result += '\n  // BEGIN DELETE BEFORE MODIFYING'
    result += '\n  // AUTO-GENERATED CONTENT'
    
    result += '\n  #pragma message("Warning: "__FILE__": '+name+' is not implemented")'

    result += '\n  // END DELETE BEFORE MODIFYING'
    
    result += '\n}\n\n'
    return result

def make_ctocpp_impl(header, clsname, impl):
    cls = header.get_class(clsname)
    if cls is None:
        raise Exception('Class does not exist: '+clsname)
    
    capiname = cls.get_capi_name()
    
    # retrieve the existing virtual function implementations
    existing = get_function_impls(impl, clsname+'CToCpp::')
    
    # generate virtual functions
    virtualimpl = ''
    funcs = cls.get_virtual_funcs()
    for func in funcs:
        name = func.get_name()
        value = get_next_function_impl(existing, name)
        if not value is None \
            and value['body'].find('// AUTO-GEN') < 0:
            # an implementation exists that was not auto-generated
            virtualimpl += make_ctocpp_impl_existing(clsname, name, func,
                value)
        else:
            virtualimpl += make_ctocpp_impl_new(clsname, name, func)
    
    if len(virtualimpl) > 0:
        virtualimpl = '\n// VIRTUAL METHODS - Body may be edited by hand.\n\n'+virtualimpl
      
    # retrieve the existing static function implementations
    existing = get_function_impls(impl, clsname+'::')
    
    # generate static functions
    staticimpl = ''
    funcs = cls.get_static_funcs()
    for func in funcs:
        name = func.get_name()
        value = get_next_function_impl(existing, name)
        if not value is None \
            and value['body'].find('// AUTO-GENERATED CONTENT') < 0:
            # an implementation exists that was not auto-generated
            staticimpl += make_ctocpp_impl_existing(clsname, name, func,
                value)
        else:
            staticimpl += make_ctocpp_impl_new(clsname, name, func)
    
    if len(staticimpl) > 0:
        staticimpl = '\n// STATIC METHODS - Body may be edited by hand.\n\n'+staticimpl
      
    resultingimpl = staticimpl + virtualimpl
    
    # determine what includes are required by identifying what translation
    # classes are being used
    includes = format_translation_includes(resultingimpl)
        
    # build the final output
    result = \
"""// Copyright (c) 2010 The Chromium Embedded Framework Authors. All rights
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

"""
    
    result += includes+'\n'+resultingimpl+'\n'
    
    result += wrap_code('#ifdef _DEBUG\n'+ \
              'template<> long CefCToCpp<'+clsname+'CToCpp, '+clsname+', '+capiname+'>::DebugObjCt = 0;\n'+ \
              '#endif\n')

    return result


def write_ctocpp_impl(header, clsname, dir, backup):
    file = dir+os.sep+get_capi_name(clsname[3:], False)+'_ctocpp.cc'
    
    if file_exists(file):
        oldcontents = read_file(file)
    else:
        oldcontents = ''
    
    newcontents = make_ctocpp_impl(header, clsname, oldcontents)
    if newcontents != oldcontents:
        if backup and oldcontents != '':
            backup_file(file)
        write_file(file, newcontents)
        return True
    
    return False


# test the module
if __name__ == "__main__":
    import sys
    
    # verify that the correct number of command-line arguments are provided
    if len(sys.argv) < 4:
        sys.stderr.write('Usage: '+sys.argv[0]+' <infile> <classname> <existing_impl>')
        sys.exit()
        
    # create the header object
    header = obj_header(sys.argv[1])
    
    # read the existing implementation file into memory
    try:
        f = open(sys.argv[3], 'r')
        data = f.read()
    except IOError, (errno, strerror):
        raise Exception('Failed to read file '+sys.argv[3]+': '+strerror)
    else:
        f.close()
    
    # dump the result to stdout
    sys.stdout.write(make_ctocpp_impl(header, sys.argv[2], data))
