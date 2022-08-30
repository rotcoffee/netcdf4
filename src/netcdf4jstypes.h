#ifndef NETCDF4JSTYPES_H
#define NETCDF4JSTYPES_H

#include <netcdf.h>
#include <node_version.h>

#if NODE_MAJOR_VERSION > 9
#define NC_TYPES(ID) ID < NC_BYTE || (ID > NC_UINT64 && ID != NC_STRING)?"unsupported":netcdf4js::type_names[ID]
#else
#define NC_TYPES(ID) ID < NC_BYTE || (ID > NC_UINT && ID != NC_STRING)?"unsupported":netcdf4js::type_names[ID]
#endif

// Ubuntu 22.04 and Ubuntu 20.04 have a different name for NCZARR file type constant
// So....
#ifdef NC_FORMATX_NCZARR
#define NC_FORMATS(ID) ID < NC_FORMATX_UNDEFINED || ID > NC_FORMATX_NCZARR ?"unsupported":netcdf4js::format_names[ID]
#else
#ifdef NC_FORMATX_ZARR
#define NC_FORMATS(ID) ID < NC_FORMATX_UNDEFINED || ID > NC_FORMATX_ZARR ?"unsupported":netcdf4js::format_names[ID]
#else
#define NC_FORMATS(ID) ID < NC_FORMATX_UNDEFINED || ID > NC_FORMATX_UDF1 ?"unsupported":netcdf4js::format_names[ID]
#endif
#endif

namespace netcdf4js {
    extern const char *type_names[];
    extern const char *format_names[];
}

#endif